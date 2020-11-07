//////////////////////////////////////////////////////////////////////////////
// Fichier :                 CLIOPCF8574.cpp
// Concepteur :              Samuel Duclos
// Date :                    2017/04/18
// Description :             Interface du PCF8574.
// Herite de :               CLI2CPort
// Version :                 v0.1
// Compilateur :             IAR
//////////////////////////////////////////////////////////////////////////////
#include "CLIOPCF8574.h"

//////////////////////////////////////////////////////////////////////////////
// Constructeur :       CLIOPCF8574 :: CLIOPCF8574(void)                   
// Concepteur :         Samuel Duclos
// Date :               3 mai 2017
// Description :        Initialise a aucune adresse interne (I2C).
// Contructeur appele : CLI2CPort(PASADR)
// Version :            v0.1
// Compilateur :        IAR
//////////////////////////////////////////////////////////////////////////////
CLIOPCF8574 :: CLIOPCF8574(void) : CLI2CPort(PASADR) {}

//////////////////////////////////////////////////////////////////////////////
// Destructeur :  CLIOPCF8574 :: ~CLIOPCF8574(void)                   
// Concepteur :   Samuel Duclos
// Date :         3 mai 2017
// Description :  NEANT.
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
CLIOPCF8574 :: ~CLIOPCF8574(void) {}

//////////////////////////////////////////////////////////////////////////////
// Modificateur : void CLIOPCF8574 :: vSet(UC ucDonnee)                   
// Concepteur :   Samuel Duclos
// Date :         3 mai 2017
// Description :  Sortie (ecriture) d'un byte a travers le PCF8574.
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
void CLIOPCF8574 :: vSet(UC ucDonnee) {I2CEcrireDonnee(0x44, ucDonnee);}

//////////////////////////////////////////////////////////////////////////////
// Accesseur :   UC CLIOPCF8574 :: ucGet(void)                   
// Concepteur :  Samuel Duclos
// Date :        3 mai 2017
// Description : Entree (lecture) d'un byte a travers le PCF8574.
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
UC CLIOPCF8574 :: ucGet(void) {return I2CLireDonneeSeulement(0x44);}


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


