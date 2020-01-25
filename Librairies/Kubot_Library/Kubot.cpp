#include "Kubot.hpp"


void Kubot::initialize(int YL, int YR, int RL, int RR, bool load_calibration, int NoiseSensor, int Buzzer, int USTrigger, int USEcho)
{

  servo_pins[0] = YL;
  servo_pins[1] = YR;
  servo_pins[2] = RL;
  servo_pins[3] = RR;

  attachServos();

  isResting=false;

  if (load_calibration)
  {
    for (int i = 0; i < 4; i++)
    {
      int servo_trim = EEPROM.read(i);
      if (servo_trim > 128) servo_trim -= 256;
      servo[i].SetTrim(servo_trim);
    }
  }

  // Initialisation du capteur ultrason

  us.init(USTrigger, USEcho);

  // Buzzer et Pin de bruit
  pinBuzzer = Buzzer;
  pinMode(Buzzer, OUTPUT);

  pinNoiseSensor = NoiseSensor;
  pinMode(NoiseSensor, INPUT);

  // On met les servos à une position de départ.
  for(int i(0) ; i < 4 ; i++)
  {
    servo[i].SetPosition(90);
    servo_position[i] = 90;
  }

  delay(250);
}

/////////////////////////////////
/// Fonctions Attach et Detach //
/////////////////////////////////

void Kubot::attachServos()
{
      servo[0].attach(servo_pins[0]);
      servo[1].attach(servo_pins[1]);
      servo[2].attach(servo_pins[2]);
      servo[3].attach(servo_pins[3]);
}

void Kubot::detachServos()
{
      servo[0].detach();
      servo[1].detach();
      servo[2].detach();
      servo[3].detach();
}

//////////////////////////////////
/// Réglage des Trim des servo ///
//////////////////////////////////

void Kubot::setTrims(int YL, int YR, int RL, int RR)
{

  servo[0].SetTrim(YL);
  servo[1].SetTrim(YR);
  servo[2].SetTrim(RL);
  servo[3].SetTrim(RR);

}


void Kubot::saveTrimsOnEEPROM()
{
  for(int i(0); i < 4 ; i++)
    EEPROM.write(i, servo[i].getTrim());
}

/////////////////////////////////////
/// Mouvements basiques des servos///
/////////////////////////////////////

void Kubot::moveServos(int duration, int  servo_target[])
{

  setRestState(false);

  float increment[4];
  unsigned long finalTime;
  unsigned long partialTime;

  attachServos();


  if(duration > 10) // Si la durée est suffisament longue
  {
    // on calcul l'incremetation de chaque servo et le temps au quel les servos auront
    // fini de bouger
    // L'incrementation en temps est de 10ms
    for(int i(0); i < 4 ; i++)
      increment[i] = ((servo_target[i] - servo_position[i]))/(duration/10.f);

    finalTime = millis() + duration;

    for (int it(1) ; millis() < finalTime ; it++)
    {
      partialTime = millis() + 10;

      for (int j(0) ; j < 4 ; j++)
      {
        //servo_position[j] += it * increment[j];
        servo[j].SetPosition(servo_position[j] + it * increment[j]);
      }

      while (millis() < partialTime); // on attend qu'au moins 10 ms se soit écouler
    }

  }
  else //// si la durée est trop courte alors on bouge le plus vite possible
  {
    for(int i(0); i < 4 ; ++i)
    {
      servo[i].SetPosition(servo_target[i]);
      servo_position[i] = servo_target[i];
    }
  }

  // Une fois les mouvements effectué, on enregistre la position des servos
  for (int i = 0; i < 4; i++)
    servo_position[i] = servo_target[i];
}



void Kubot::oscillateServos(int A[4], int O[4], int T, double Ph[4], float cycle)
{
  for (int i(0); i<4; i++)
  {
    servo[i].SetO(O[i]);
    servo[i].SetA(A[i]);
    servo[i].SetT(T);
    servo[i].SetPh(Ph[i]);
  }

  float ref(millis());
  float x(ref);

  while(x <= T*cycle+ref)
  {
    for (int i(0); i < 4; i++)
    {
      servo[i].refresh();
    }
    x = millis();
  }

  for (unsigned i(0) ; i < 4 ; ++i)
  {
    //TODO: Recuper la position des servo a la fin du cycle
  }
}



void Kubot::oscillate(int A[4], int O[4], int T, double phase_diff[4], float steps)
{
  attachServos();
  setRestState(false);

  float cycles = trunc(steps);

  if(steps >= 1)
  {
    for(int i(0) ; i < cycles; ++i)
      oscillateServos(A,O,T,phase_diff);
  }

  oscillateServos(A,O,T,phase_diff,steps-cycles);

}





////////////////////////////////////////////////
/// Homing: Controle de la position de repos ///
////////////////////////////////////////////////


// La position de repos (tout les servos à 90)
// En prime, on désactive les servos par soucis
// d'économie d'énergie
void Kubot::home()
{

  if(!isResting)
  {

    int homes[4] = {90,90,90,90};
    moveServos(500,homes);

    setRestState(true);

    // Desactivation des servos.
    detachServos();

  }
}

bool Kubot::getRestState() {return isResting;}
void Kubot::setRestState(bool state) { isResting = state;}



//////////////////////////////////////////////
/// Capteurs: Ultrason et capteur de bruit ///
//////////////////////////////////////////////



// Utilisation du capteur ultrason
float Kubot::getDistance()
{
  return us.read();
}



// On recupere le bruit sur une pin vide. Celà permet de generer des nombres
// aléatoires, etc.
int Kubot::getNoise()
{

  int readingCount(2); // Le nombre de mesures à effectuer toujours > 0
  int noiseLevel(0);

  for (unsigned i(0) ; i < readingCount ; ++i)
    noiseLevel += analogRead(pinNoiseSensor);

  return noiseLevel / readingCount;

}



//////////////////////////////
/// Son: Gestion du buzzer ///
//////////////////////////////

// Permet au Kubot de jouer une certaine frequence pendant un temps donné
void Kubot::_tone(float frequency, long noteDuration, long silenceDuration)
{

  tone(pinBuzzer,frequency,noteDuration);

  // On attend que la note se termine...
  delay(noteDuration);

  // On attend au minimum 1ms avant l'execution d'autres commandes
  if(silenceDuration < 1)
    silenceDuration = 1;

  delay(silenceDuration);

}



// Permet au Kubot de jouer une note courbée
// dans la première itération, le temps par note est fixé à 15ms
/*void Kubot::bendTones(float initFrequency, float finalFrequency, float _step)
{
    bool ascending = (finalFrequency > initFrequency);

    // la pente permet de définir comment la note final sera atteinte.
    float slope = fabs(finalFrequency - initFrequency) / 100.f;

    if (ascending) // Si la frequence final est supérieure
    {
      for (int i(0) ; i <= 100 ; i += _step)
        _tone(initFrequency + slope*i, 15);
    }
    else
    {
      for (int i(100) ; i >= 0 ; i -= _step)
        _tone(initFrequency + slope*i, 15);
    }
}*/

void Kubot::glissando(float initFrequency, float finalFrequency, float duration)
{
  const float noteDuration = 15; // ms. Temps fixé pour faire un beau glissendo

  bool ascending = (finalFrequency > initFrequency);

  float nbPas = duration/noteDuration;
  float step = (finalFrequency-initFrequency)/nbPas;

  if(ascending)
  {
    for(int i = 0 ; i < nbPas ; i++)
        _tone(initFrequency + i*step, noteDuration);

  }
  else
  {
    for(int i = nbPas ; i > 0 ; i--)
      _tone(finalFrequency - i*step, noteDuration);
  }
}



//////////////////////////////
/// Movements spéciaux ///
//////////////////////////////

/***********************************************
 *  \function:  Kubot::jump
 *  \desc       Fait "sauter" le kubot (en tout cas ça en à l'air...) il s'agit
 *              d'un up&down simplifier s'executant une fois à une hauteur prédéterminée
 *              On pourrait la supprimer mais bon...
 *  \param      T: Period
 ***********************************************/
void Kubot::jump(int T)
{
  int up[]={90,90,150,30};
  int down[]={90,90,90,90};


  moveServos(T/2.f,up);
  moveServos(T/2.f,down);
}


/***********************************************
 *  \function:  Kubot::walk
 *  \desc       Le kubot avance ou recule
 *  \param      Steps: Nombre de pas
 *  \param      T: Periode
 *  \param      Dir: Direction: FORWARD / BACKWARD
 ***********************************************/
void Kubot::walk(float steps, int T, int dir)
{
  /*
   * Description de la marche:
   * Les servos des hanches et des pieds sont synchronisés (ils effectues les memes mouvements)
   * mais sont déphasés de 90degrées.le signe donne le sens de marche.
   * Un leger offset sur les pieds permet au kubot de marcher sur ses pointes
   */

   int A[] = {30,30,20,20};
   int O[] = {0,0,4,-4};

   // le signe donne le sens de marche
   double phase_diff[4] = {0, 0, DEG2RAD(dir * -90), DEG2RAD(dir * -90)};

   oscillate(A,O,T,phase_diff,steps);

}



/***********************************************
 *  \function:  Kubot::turn
 *  \desc       Tourne à gauche ou a droite
 *  \param      Steps: Number of steps
 *  \param      T: Period
 *  \param      Dir: Direction: LEFT / RIGHT
 ***********************************************/
void Kubot::turn(float steps, int T, int dir)
{

  /* A peut prêt pareil que pour la marche (cf Kubot::walk)
  * La différence est que l'amplitude de mouvement des deux hanches est différente
  * i.e. Quand le servo droit a une plus grande amplitude les pas à droite sont plus grands
  * et donc le kubot va vers la gauche
  */
  int A[4]= {30, 30, 20, 20};
  int O[4] = {0, 0, 4, -4};
  double phase_diff[4] = {0, 0, DEG2RAD(-90), DEG2RAD(-90)};

  if (dir == LEFT)
  {
    A[0] = 30; // hanche gauche
    A[1] = 10; // hanche droite
  }
  else
  {
    A[0] = 10;
    A[1] = 30;
  }

  oscillate(A, O, T, phase_diff, steps);
}


/***********************************************
 *  \function:  Kubot::up&down
 *  \desc       le Kubot se leve et s'assois
 *  \param      Steps: nombre de répétition
 *  \param      T: Periode
 *  \param      h: Hauteur du mouvement
 ***********************************************/
void Kubot::updown(float steps, int T, int h)
{
   // Tout les servos sont synchronisés et en phase
   int A[] = {0,0,h,h};
   int O[] = {0,0,h,-h};
   double phase_diff[] = {0,0,DEG2RAD(-90),DEG2RAD(90)};

   oscillate(A,O,T,phase_diff,steps);
}



/***********************************************
 *  \function:  Kubot::bend
 *  \desc       Le Kubot se penche d'un côté
 *  \param      Steps: Nombre de "penchage"
 *  \param      T: temps d'attente pendant le penchage
 *  \param      Dir: "direction du penchage: LEFT / RIGHT
 ***********************************************/
void Kubot::bend (int steps, int T, int dir)
{

  //Par defaut le kubot se penche à gauche
  int bend1[4]={90, 90, 62, 35};
  int bend2[4]={90, 90, 62, 105};
  int homes[4]={90, 90, 90, 90};

  //On limite le temps de penchage a 600 pour eviter des penchages trop rapides
  T=max(T, 600);

  // On change de parametres si on se penche a droite
  if(dir==RIGHT)
  {
    bend1[2] = 180-35;
    bend1[3] = 180-60;  // A partir de 65, le kubot tombe
    bend2[2] = 180-105;
    bend2[3] = 180-60;
  }

  //temps d'execution du penchage.
  int Ttravel = 800;

  //Bend movement
  for (int i = 0 ; i < steps ; i++)
  {
    moveServos(Ttravel/2,bend1);
    moveServos(Ttravel/2,bend2);
    delay(T*0.8); // temps d'attempte entre chaque penchage *
    moveServos(500,homes);
  }

}


/***********************************************
 *  \function:  Kubot::shakeLeg
 *  \desc       secoue la jambe, genre comme un ptit chien
 *  \param      Steps: Nombre de sequences
 *  \param      T: Periode
 *  \param      Dir: jambe qui se secoue LEFT / RIGHT
 ***********************************************/
void Kubot::shakeLeg (int steps,int T,int dir)
{

  // Nombre de secousse de jambe
  int numberLegMoves = 2;

  //Parametre par défaut: on secoue la jambe droite
  int shake_leg1[4]={90, 90, 58, 35};
  int shake_leg2[4]={90, 90, 58, 120};
  int shake_leg3[4]={90, 90, 58, 60};
  int homes[4]={90, 90, 90, 90};

  //On secoue la gauche dans le cas contraire
  if(dir==LEFT)
  {
    shake_leg1[2]=180-35;
    shake_leg1[3]=180-58;
    shake_leg2[2]=180-120;
    shake_leg2[3]=180-58;
    shake_leg3[2]=180-60;
    shake_leg3[3]=180-58;
  }

  //temps de penchage
  int Ttravel=1000;

  //temps pour un secouage de jambe.
  T=T-Ttravel;
  T=max(T,200*numberLegMoves);

  for (int j = 0; j < steps; j++)
  {
  //Penchage
  moveServos(Ttravel/2,shake_leg1);
  moveServos(Ttravel/2,shake_leg2);

    //Secouage
    for (int i = 0; i < numberLegMoves; i++)
    {
    moveServos(T/(2*numberLegMoves),shake_leg3);
    moveServos(T/(2*numberLegMoves),shake_leg2);
    }
    moveServos(500,homes); //OHM SWEET OHM
  }

  delay(T);
}


/***********************************************
 *  \function:  Kubot::swing
 *  \desc       Le kubot se balance de droite à gaucher
 *  \param      Steps: Nombre de balancement
 *  \param      T: Periode
 *  \param      h: amplitude des balancements
 ***********************************************/
void Kubot::swing(float steps, int T, int h)
{

   // Les deux pieds sont en phase

  int A[4]= {0, 0, h, h};
  int O[4] = {0, 0, h/2, -h/2};
  double phase_diff[4] = {0, 0, 0, 0};

  oscillate(A, O, T, phase_diff, steps);

}




/***********************************************
 *  \function:  Kubot::tiptoeSwing
 *  \desc       Pareil qu'un swing mais sur la pointe des pieds
 *  \param      Steps: nombre de balancements
 *  \param      T: durée de balancements
 *  \param      h: amplitude des balancements (0 à ~50)
 ***********************************************/
void Kubot::tiptoeSwing(float steps, int T, int h)
{

  // Les deux pieds sont en phase
  // L'offset est différent pour permettre au Kubot de se mettre
  // sur la pointe des pieds

  int A[4]= {0, 0, h, h};
  int O[4] = {0, 0, h, -h};
  double phase_diff[4] = {0, 0, 0, 0};

  oscillate(A, O, T, phase_diff, steps);
}


// Les mouvements si dessous sont directement repris de la librairie
// pour le robot OTTO.

//---------------------------------------------------------
//-- Kubot gait: Jitter
//--  Parameters:
//--    steps: Number of jitters
//--    T: Period of one jitter
//--    h: height (Values between 5 - 25)
//---------------------------------------------------------
void Kubot::jitter(float steps, int T, int h)
{

  //-- Both feet are 180 degrees out of phase
  //-- Feet amplitude and offset are the same
  //-- Initial phase for the right foot is -90, so that it starts
  //--   in one extreme position (not in the middle)
  //-- h is constrained to avoid hit the feets
  h=min(25,h);
  int A[4]= {h, h, 0, 0};
  int O[4] = {0, 0, 0, 0};
  double phase_diff[4] = {DEG2RAD(-90), DEG2RAD(90), 0, 0};

  //-- Let's oscillate the servos!
  oscillate(A, O, T, phase_diff, steps);
}


//---------------------------------------------------------
//-- Kubot gait: Ascending & turn (Jitter while up&down)
//--  Parameters:
//--    steps: Number of bends
//--    T: Period of one bend
//--    h: height (Values between 5 - 15)
//---------------------------------------------------------
void Kubot::ascendingTurn(float steps, int T, int h)
{

  //-- Both feet and legs are 180 degrees out of phase
  //-- Initial phase for the right foot is -90, so that it starts
  //--   in one extreme position (not in the middle)
  //-- h is constrained to avoid hit the feets
  h=min(13,h);
  int A[4]= {h, h, h, h};
  int O[4] = {0, 0, h+4, -h+4};
  double phase_diff[4] = {DEG2RAD(-90), DEG2RAD(90), DEG2RAD(-90), DEG2RAD(90)};

  //-- Let's oscillate the servos!
  oscillate(A, O, T, phase_diff, steps);
}


//---------------------------------------------------------
//-- Kubot gait: Moonwalker. Kubot moves like Michael Jackson
//--  Parameters:
//--    Steps: Number of steps
//--    T: Period
//--    h: Height. Typical valures between 15 and 40
//--    dir: Direction: LEFT / RIGHT
//---------------------------------------------------------
void Kubot::moonwalker(float steps, int T, int h, int dir)
{

  //-- This motion is similar to that of the caterpillar robots: A travelling
  //-- wave moving from one side to another
  //-- The two Kubot's feet are equivalent to a minimal configuration. It is known
  //-- that 2 servos can move like a worm if they are 120 degrees out of phase
  //-- In the example of Kubot, the two feet are mirrored so that we have:
  //--    180 - 120 = 60 degrees. The actual phase difference given to the oscillators
  //--  is 60 degrees.
  //--  Both amplitudes are equal. The offset is half the amplitud plus a little bit of
  //-   offset so that the robot tiptoe lightly

  int A[4]= {0, 0, h, h};
  int O[4] = {0, 0, h/2+2, -h/2 -2};
  int phi = -dir * 90;
  double phase_diff[4] = {0, 0, DEG2RAD(phi), DEG2RAD(-60 * dir + phi)};

  //-- Let's oscillate the servos!
  oscillate(A, O, T, phase_diff, steps);
}


//----------------------------------------------------------
//-- Kubot gait: Crusaito. A mixture between moonwalker and walk
//--   Parameters:
//--     steps: Number of steps
//--     T: Period
//--     h: height (Values between 20 - 50)
//--     dir:  Direction: LEFT / RIGHT
//-----------------------------------------------------------
void Kubot::crusaito(float steps, int T, int h, int dir)
{

  int A[4]= {25, 25, h, h};
  int O[4] = {0, 0, h/2+ 4, -h/2 - 4};
  double phase_diff[4] = {90, 90, DEG2RAD(0), DEG2RAD(-60 * dir)};

  //-- Let's oscillate the servos!
  oscillate(A, O, T, phase_diff, steps);
}


//---------------------------------------------------------
//-- Kubot gait: Flapping
//--  Parameters:
//--    steps: Number of steps
//--    T: Period
//--    h: height (Values between 10 - 30)
//--    dir: direction: FOREWARD, BACKWARD
//---------------------------------------------------------
void Kubot::flapping(float steps, int T, int h, int dir)
{

  int A[4]= {12, 12, h, h};
  int O[4] = {0, 0, h - 10, -h + 10};
  double phase_diff[4] = {DEG2RAD(0), DEG2RAD(180), DEG2RAD(-90 * dir), DEG2RAD(90 * dir)};

  //-- Let's oscillate the servos!
  oscillate(A, O, T, phase_diff, steps);
}




// End of Kubot.cpp
