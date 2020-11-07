//////////////////////////////////////////////////////////////////////////////
// Fichier :     CLVehicule.cpp
// Concepteur :  Samuel Duclos
// Date :        2017/04/18
// Description : Controle du vehicule.
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
#include "CLVehicule.h"

//////////////////////////////////////////////////////////////////////////////
// Constructeur : CLVehicule :: CLVehicule(void)                   
// Concepteur :   Samuel Duclos
// Date :         3 mai 2017
// Description :  NEANT.
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
CLVehicule :: CLVehicule(void) {}

//////////////////////////////////////////////////////////////////////////////
// Constructeur initialisateur:
//               CLVehicule :: CLVehicule(mode choisi, UC ucVitesseMoyenne)
// Concepteur :  Samuel Duclos
// Date :        3 mai 2017
// Description : Initialise les capteurs et les moteurs du vehicule.
//               Arrete les moteurs, initialise la trame de reception, les
//               interruptions, la vitesse moyenne et le mode choisi.
// Compose de :  clCaptDistDroite(CHANNEL0), clCaptDistGauche(CHANNEL1),
//               clSuiveurLigne(ucVitesseMoyenne)
// Constructeur initialisateur appele :
//               CLControleMoteurs(ucVitesseMoyenne)
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
CLVehicule :: CLVehicule(mode choisi, UC ucVitesseMoyenne) :
                                     clCaptDistDroite(CHANNEL2),
                                     clCaptDistGauche(CHANNEL1),
                                     clSuiveurLigne(ucVitesseMoyenne),
                                     CLControleMoteurs(ucVitesseMoyenne) {
  vArretMoteurs();
  ES1 = EA = 1;                  // Active les interruptions
  ucVitesse = ucVitesseMoyenne;  // Set la vitesse du véhicule
  choix = choisi;
}

//////////////////////////////////////////////////////////////////////////////
// Destructeur : CLVehicule :: ~CLVehicule(void)                   
// Concepteur :  Samuel Duclos
// Date :        3 mai 2017
// Description : NEANT.
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
CLVehicule :: ~CLVehicule(void) {}

//////////////////////////////////////////////////////////////////////////////
// Controleur principal : 
//               void CLVehicule :: vControle(void)                   
// Concepteur :  Samuel Duclos
// Date :        3 mai 2017
// Description : Si TEST_MODE_ENABLED, appelle vTest(), sinon appelle le mode 
//               selectionne (AUTOMATIQUE, INCLINOMETRE, CLAVIER ou EVITEMENT).
//               Ensuite, analyse la trame recue et gere l'alimentation de la 
//               pile.
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
void CLVehicule :: vControle(void) {
  #ifndef TEST_MODE_ENABLED
  vAnalyseTrame();  // Lit la trame

    switch (choix) {
      case AUTOMATIQUE:  clSuiveurLigne.vPID();    break;
      case INCLINOMETRE: vInclinometre();          break;
      case CLAVIER:      vClavier();               break;
      case EVITEMENT:    vCapteursEvitement();
    }
    
    vGestionPile();
  #else
    vTest();
  #endif
}

///////////////////////////////////////////////////////////////////////////////
// Compilation conditionnelle pour effecter des tests.
///////////////////////////////////////////////////////////////////////////////
#ifdef TEST_MODE_ENABLED
  /////////////////////////////////////////////////////////////////////////////
  // Controleur de tests : 
  //               void CLVehicule :: vTest(void)                   
  // Concepteur :  Samuel Duclos
  // Date :        3 mai 2017
  // Description : Permet de contourner le controle principal pour effectuer 
  //               des tests, selon le mode et les parametres choisis (voir 
  //               Tests.h). Appelle les tests selectionnes dans le mode 
  //               choisi. Selectionne (AUTOMATIQUE, INCLINOMETRE, CLAVIER ou 
  //               EVITEMENT).
  // Version :     v0.1
  // Compilateur : IAR
  /////////////////////////////////////////////////////////////////////////////
  void CLVehicule :: vTest(void) {
    switch (choix) {
      case AUTOMATIQUE:  while (1) clSuiveurLigne.vPID();
      case INCLINOMETRE: while (1) vInclinometre();
      case CLAVIER:      while (1) vClavier();
      case EVITEMENT:    //vTestCapteurDistance();
                         while (1) vCapteursEvitement();
    }
  }

  /////////////////////////////////////////////////////////////////////////////
  // Test :        void CLVehicule :: vTestCapteurDistance(void)                   
  // Concepteur :  Samuel Duclos
  // Date :        3 mai 2017
  // Description : Permet de tester les valeurs retournees par un capteur de 
  //               distance.
  // Version :     v0.1
  // Compilateur : IAR
  /////////////////////////////////////////////////////////////////////////////
  void CLVehicule :: vTestCapteurDistance(void) {
    unMot unCapteur0;
  
    clEcran.vLcdAffCar('0');
    clEcran.vLcdAffCar('x');
  
    while (1) {
      unCapteur0.Mot = clCaptDistDroite.usiGet();
      clEcran.vLcdPoscurC0L1(2, 1);
      clEcran.vLcdAffCarHex(unCapteur0.Octet.MSB);
      clEcran.vLcdAffCarHex(unCapteur0.Octet.LSB);
    }
  }
#endif

//////////////////////////////////////////////////////////////////////////////
// Controleur d'alimentation de la pile : 
//               void CLVehicule :: vGestionPile(void)                   
// Concepteur :  Samuel Duclos
// Date :        3 mai 2017
// Description : Gere l'alimentation de la pile. Si le pourcentage de charge 
//               de la pile est en-dessous de 50 pourcent, descendre les 
//               moteurs a 25%. Si la pile est en dessous de 10%, eteindre les 
//               moteurs.
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
void CLVehicule :: vGestionPile(void) {
  UC ucPourcent = clPile.ucCharge();
  if (ucPourcent < 10) vArretMoteurs();
  else if (ucPourcent < 50) ucVitesse = 25;
}

//////////////////////////////////////////////////////////////////////////////
// Fonctionnalite : void CLVehicule :: vCapteursEvitement(void)                   
// Concepteur :     Samuel Duclos
// Date :           3 mai 2017
// Description :    Entre en mode evitement (si un objet est detecte, tourne 
//                  dans la direction du capteur le plus proche de l'objet.
// Version :        v0.1
// Compilateur :    IAR
//////////////////////////////////////////////////////////////////////////////
void CLVehicule :: vCapteursEvitement(void) {
  UC ucTimeout = 10;                               // Delai pour lui laisser le
                                                   // temps de tourner
  USI usiObjetGauche = clCaptDistGauche.usiGet();  // Lecture capteur gauche
  USI usiObjetDroite = clCaptDistDroite.usiGet();  // Lecture capteur droit
  
  if (usiObjetGauche < usiObjetDroite) while (ucTimeout--) vTourneDroite();
  else if (usiObjetGauche > usiObjetDroite) while (ucTimeout--) vTourneGauche();
  else vMarcheAvant();
}

//////////////////////////////////////////////////////////////////////////////
// Controleur de la communication avec la telecommande : 
//               void CLVehicule :: vAnalyseTrame(void)                   
// Concepteur :  William Bordeleau
// Date :        3 mai 2017
// Description : Selectionne le mode choisi en fonction de la trame recue.
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
void CLVehicule :: vAnalyseTrame(void) 
{
  // Si trame complete recue, met le pointeur au debut de la trame.
  UC i;
  if (clCom2.ucLireEtatTrame())
  { 
    ucpIndTamp = clCom2.ucpLireTrame();// Mets le pointeur sur la nouvelle trame
    clEcran.vLcdPoscurC0L1(0,4);
    for(i=0; i<14; i++)                // Affiche la trame a l'ecran
    {
      clEcran.vLcdAffCar(*(ucpIndTamp+i));
    }
  }

  switch (*ucpIndTamp) 
  {
    case 'A': choix = AUTOMATIQUE;  break;
    case 'M': choix = CLAVIER;      break;
    case 'E': choix = EVITEMENT;    break;
    case 'I': choix = INCLINOMETRE; break;
    case 'V':
      ucpIndTamp++; // Caractere de vitesse
      switch (*ucpIndTamp) 
      { // ucVitesse est un poucentage.
        case '1': ucVitesse = 25; break;  // Trame: V19C0
        case '3': ucVitesse = 50; break;  // Trame: V32BB
        case '4': ucVitesse = 75; break;  // Trame: V4BCC
        case '6': ucVitesse = 100;        // Trame: V64C0
      }
      vChangeVitesse(ucVitesse);          // Change la vitesse du véhicule
      ucpIndTamp--;                       // Remets le pointeur au premier carac
  }
}

//////////////////////////////////////////////////////////////////////////////
// Fonction :    void CLVehicule :: vAsciiToInt(void)                   
// Concepteur :  William Bordeleau
// Date :        3 mai 2017
// Description : Converti les 12 caractere ASCII de la trame en 4 valeur 10 bits
//               qui sont mis dans un tableau 
// Modification : Samuel Duclos 
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
void CLVehicule :: vAsciiToInt(void) 
{ 
  USI i, usiCompTab;
  usiConvert = usiCompTab = 0;

  for (i = 4; i > 0; i--) //pour les 4 roues
  {
    if (*ucpIndTamp < 0x3A) usiConvert += (*ucpIndTamp - '0') << 8;
    else usiConvert += (*ucpIndTamp - '7') << 8;
    ucpIndTamp++;
    
    if (*ucpIndTamp < 0x3A) usiConvert += (*ucpIndTamp - '0') << 4;
    else usiConvert += (*ucpIndTamp - '7') << 4;
    ucpIndTamp++;
    
    if (*ucpIndTamp < 0x3A) usiConvert += *ucpIndTamp - '0';
    else usiConvert += *ucpIndTamp - '7';
    ucpIndTamp++;

    usiTabRoue[usiCompTab++] = usiConvert;
    usiConvert = 0;
  }
  ucpIndTamp = ucpIndTamp - 12;  // Remise du pointeur au début 
  usiConvert = 0;
}

//////////////////////////////////////////////////////////////////////////////
// Fonctionnalite : void CLVehicule :: vClavier(void)                   
// Concepteur :     William Bordeleau
// Date :           3 mai 2017
// Description :    Repond a la touche recue du clavier.
// Version :        v0.1
// Compilateur :    IAR
//////////////////////////////////////////////////////////////////////////////
void CLVehicule :: vClavier(void) {
  switch (*ucpIndTamp) {
    case 'F': vMarcheAvant();   break;
    case 'S': vArretMoteurs();  break;
    case 'R': vMarcheArriere(); break;
    case 'G': vTourneGauche();  break;
    case 'D': vTourneDroite();
  }
}

//////////////////////////////////////////////////////////////////////////////
// Fonctionnalite : void CLVehicule :: vInclinometre(void)                   
// Concepteur :     Samuel Duclos
// Date :           3 mai 2017
// Description :    Envoi les valeurs de la trames convertis qui sont dans 
//                  usiTabRoue aux roues.
// Version :        v0.1
// Compilateur :    IAR
//////////////////////////////////////////////////////////////////////////////
void CLVehicule :: vInclinometre(void) {
  vAsciiToInt();
  vControleBrut(usiTabRoue[0], usiTabRoue[1], usiTabRoue[2], usiTabRoue[3]);
}


//////////////////////////////////////////////////////////////////////////////
// Fonction :    UC CLVehicule :: ucChecksum5(void)                   
// Concepteur :  William Bordeleau
// Date :        11 mai 2017
// Description : Checksum de la trame du clavier
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
UC CLVehicule :: ucChecksum5(void)
{
  UC ucCheckSum = 0;
  if((*(ucpIndTamp+3)) < 'A')
  {
   ucCheckSum = ucCheckSum + ((*(ucpIndTamp+3) - '0') << 4);
  }
  else 
  {
   ucCheckSum = ucCheckSum + ((*(ucpIndTamp+3) - '7') << 4);
  }
  if((*(ucpIndTamp+4)) < 'A')
  {
   ucCheckSum = ucCheckSum + (*(ucpIndTamp+4) - '0');
  }
  else 
  {
   ucCheckSum = ucCheckSum + (*(ucpIndTamp+4) - '7');
  }
  if(ucCheckSum == ((*ucpIndTamp) + (*(ucpIndTamp+1)) +(*(ucpIndTamp+2))))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

//////////////////////////////////////////////////////////////////////////////
// Fonction :    UC CLVehicule :: ucChecksum12(void)                  
// Concepteur :  William Bordeleau
// Date :        11 mai 2017
// Description : Checksum DE la trame de l'inclino
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
UC CLVehicule :: ucChecksum12(void)
{
  UC i;
  UC ucCheckSum = 0;
  UC ucSomme = 0;
  if((*(ucpIndTamp+12)) < 'A')    
  {
   ucCheckSum = ucCheckSum + ((*(ucpIndTamp+12) - 0x30) << 4); // Conversion des
                     // ASCII 
  }
  else 
  {
   ucCheckSum  = ucCheckSum + ((*(ucpIndTamp+12) - 0x37) << 4);// Conversion des
                     // ASCII
  }
  if((*(ucpIndTamp+13)) < 'A')
  {
   ucCheckSum = ucCheckSum + (*(ucpIndTamp+13) - 0x30);        // Conversion des
                     // ASCII 
  }
  else 
  {
   ucCheckSum = ucCheckSum + (*(ucpIndTamp+13) - 0x37);        // Conversion des
                     // ASCII 
  }
  
  for(i = 0; i < 12;i++ )
  {
   ucSomme += *(ucpIndTamp+i); 
  }
  
  if(ucCheckSum == ucSomme)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



