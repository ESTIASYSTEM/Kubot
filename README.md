# Kubot
Dépôt pour tous les codes concernant le Kubot.

![Un petit Kubot](media/Kubot.jpg)

## Démarrage/ getting started
- Les instructions d'utilisations et toutes les informations projet du Kubot se trouve sur le [wiki](https://github.com/ESTIASYSTEM/Kubot/wiki)
- les tickets rapportant les bugs, demandes d'améliorations, demandes d'informations... (cf labels disponibles) peuvent être ouverts dans les [issues](https://github.com/ESTIASYSTEM/Kubot/issues)
- [L'équipe GitHub](https://github.com/orgs/ESTIASYSTEM/teams/kubot) permet de regrouper toutes les personnes, tous les dépots relatifs au projet, les kanbans et d'avoir un "forum" de discussions.
- Le canal de discussion Kubot pour avoir un channel de conversation accessible à tous les adhérents d'ESTIA SYSTEM.

## Kubot_Application_Mobile
Code de l'application pour mobile Android développé pendant le cours de Système Mobile Communicant.
L’interface graphique peut être travaillé via [ce site du MIT](http://appinventor.mit.edu/explore/#).
Ce programme a été écrit par Florent Paulin @FlorentUAV.

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
* [X] faire la fusion des codes de bibliothèques
* [ ] faire une notice pour l'application Bluetooth

## Améliorations futur
chercher un nouveau micro controleur de même taille que l'arduino nano avec plus de mémoire (ou carte sd, module eeprom), plus de puissance (arm)
- [ ] Utiliser le [Nano 33 BLE](https://store.arduino.cc/arduino-nano-33-ble) -> plus de mémoire (1Mo), de puissance de calcul, connectivité intégré (ATTENTION: passage de 5V à 3,3 V sur le circuit logique)
- [ ] Utiliser le [Nano 33 BLE Sense](https://store.arduino.cc/arduino-nano-33-ble-sense) -> comme le BLE simple, avec en plus des capteurs intégrés comme l'IMU. Permet de faire du machine learning (reconnaissance de mouvement, de couleurs)

# Contributeurs
- [Hynek VIGNON](https://fr.linkedin.com/in/hynek-vignon-a86984ba) @K3nyh: idées et conceptions originales, partie pédagogique médiathèque de Biarritz (2017, 2018)
- [Raphaël OLLANDO](https://www.linkedin.com/in/ollando-raph/) @Resethel: idée original, programmation
- [Floran PAULIN](https://fr.linkedin.com/in/paulinflorent) @FlorentUAV: programmation interface sur mobile, connection Bluetooth
- [Flavien DUMAS](https://www.linkedin.com/in/flavien-dumas/) @Aldhra: portage sur MBlock, atelier pédagogique médiathèque de Biarritz (2018, 2019)
- Adrien @adriengauche: suivi du projet

# License
Thanks to [Otto DIY](https://github.com/OttoDIY) project.
* en: All codes specified with a licence in the header or in a file  are under there own conditions, others codes are under GNU GPL.
* fr: Tous les codes spécifiés avec une licence dans l'en-tête ou dans un fichier sont soumis à leurs propres conditions, les autres codes sont sous licence GNU GPL.
