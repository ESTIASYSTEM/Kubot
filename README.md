# Kubot
Dépôt pour tous les codes concernant le Kubot.

![Un petit Kubot](media/Kubot.jpg)

## Démarrage/ getting started
Les instructions d'utilisations du kubot se trouve sur le [wiki]

## Kubot_Application_Mobile
Code de l'application pour mobile Android développé pendant le cours de Système Mobile Communicant.
L’interface graphique peut être travaillé via [ce site du MIT](http://appinventor.mit.edu/explore/#).
Ce programme a été écrit par Florent Paulin.

## Kubot_Scratch
**Utilisable seulement sous mBlock V3**

Bibliothèque du logiciel mBlock V3 développé pour l'animation en partenariat avec la médiathèque de Biarritz. 
Mise en place par Flavien Dumas

Liste des fonctions scratch pour Kubot :
* Initialisation
* Mouvements :
    * Home (retour en position repos)
    * Avancer
    * Reculer
    * Tourner
    * Soulever un pied
    * Pointe des pieds
    * Danser
    * Se pencher

TODO
* [ ] fonction mouvement bras
* [ ] Lever le bras

Capteurs :
Capter la distance avec US

Bluetooth :
* [ ] TODO recevoir/envoyer info bluetooth

Signaux :
* [ ] TODO affichage Matrice LED
* chanter une chanson
* créer une chanson avec des notes


## Librairies
Librairie des robots interactifs Kubot

Développées par Hynek Vignon et Raphaël Ollando

## Programmes
Programmes clés en main à mettre sur la carte Arduino du Kubot

## TODO
* [X] faire la fusion des codes de bibliothèque
* [ ] faire une notice pour l'application Bluetooth

## Améliorations futur
chercher un nouveau micro controleur de même taille que l'arduino nano avec plus de mémoire (ou carte sd, module eeprom), plus de puissance (arm)
- [ ] Utiliser le [Nano 33 BLE](https://store.arduino.cc/arduino-nano-33-ble) -> plus de mémoire (1Mo), de puissance de calcul, connectivité intégré (ATTENTION: passage de 5V à 3,3 V sur le circuit logique)
- [ ] Utiliser le [Nano 33 BLE Sense](https://store.arduino.cc/arduino-nano-33-ble-sense) -> comme le BLE simple, avec en plus des capteurs intégrés comme l'IMU

# License
Thanks to [Otto DIY](https://github.com/OttoDIY) project.
* en: All codes specified with a licence in the header or in a file  are under there own conditions, others codes are under GNU GPL.
* fr: Tous les codes spécifiés avec une licence dans l'en-tête ou dans un fichier sont soumis à leurs propres conditions, les autres codes sont sous licence GNU GPL.