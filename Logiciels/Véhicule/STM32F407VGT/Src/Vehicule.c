

#include "Vehicule.h"


//*****************************vChecksum***********************************
// DESCRIPTION: checksum d'un tableau. La case contenant le MSB doit etre egal
//              a 0.
// INCLUDE:     #include "Vehicule.h"     
// PROTOTYPE:   void vChecksum(unsigned char *ucpTab);
// PARAMETRE D'ENTREE:   *ucpTab           pointeur sur le tableau a cumule
// PARAMETRE DE SORTIE:  AUCUN        
// EXEMPLE:    vChecksum(ucpTrans);
// PROCEDURE   APPELEE:  AUCUNE                    
// DATE DE CREATION: 24-04-2017
// AUTEUR: WILLIAM BORDELEAU
// DATE DE MODIFICATION: JAMAIS
//****************************************************************************
void vChecksum(unsigned char *ucpTab)
{
  unsigned char ucSomme = 0;
  
  while(*ucpTab)
  {
    ucSomme = ucSomme + *ucpTab;
    ucpTab++;
  }
  
  *ucpTab = (ucSomme >> 4) + 0x30;	
  if(*ucpTab >= 0x3A)               //pour 0xAX,0xBX,0xCX,0xDX,0xEX,0xFX
  {
    *ucpTab = *ucpTab + 0x07;         
  }
  
  ucpTab++;
  *ucpTab = (ucSomme & 0x0F) + 0x30;
  if(*ucpTab >= 0x3A)               //pour 0xXA,0xXB,0xXC,0xXD,0xXE,0xXF
  {
    *ucpTab = *ucpTab + 0x07;
  }
}

//*****************************iConVit***********************************
// DESCRIPTION: covnertion de la valeur de l'inclino en une valeur allant de
//              0x0000 a 0x03FF.
// INCLUDE:     #include "Vehicule.h"      
// PROTOTYPE:   int iConVit(float fData);
// PARAMETRE D'ENTREE:   fData         Donnee de l'inclinometre
// PARAMETRE DE SORTIE:  iResultat     Vitesse 10 bit a transmettre aux roues
// EXEMPLE:    iRoue[0] = iConVit(fYData);
// PROCEDURE   APPELEE:  AUCUNE                    
// DATE DE CREATION: 24-04-2017
// AUTEUR: WILLIAM BORDELEAU
// DATE DE MODIFICATION: JAMAIS
//****************************************************************************
int iConVit(float fData)
{
  int iResultat = 0;
  if(fData > 0)       // 0 @ 1
  {
    iResultat = (1024 * fData) + 255;
  }
  if(fData < 0)      // -1 @ 0
  {
    iResultat = (1024 * fData) + 768;
  }
  return iResultat;
}

//*****************************iConX***********************************
// DESCRIPTION: differentiel pour les diagonale 
// INCLUDE:     #include "Vehicule.h"       
// PROTOTYPE:   int iConX(float fData);
// PARAMETRE D'ENTREE:   fData         Donnee de l'inclinometre
// PARAMETRE DE SORTIE:  iResultat     difference pour diagonale       
// EXEMPLE:    iRoue[0] = iConVit(fYData) - iConX(fXData);
// PROCEDURE   APPELEE:  AUCUNE                    
// DATE DE CREATION: 24-04-2017
// AUTEUR: WILLIAM BORDELEAU
// DATE DE MODIFICATION: JAMAIS
//****************************************************************************
int iConX(float fData)
{
  int iResultat = 0;
  if(fData > 0)   // 0 @ 1
  {
    iResultat = (768 * fData) - 192;
  }
  if(fData < 0)  // -1 @ 0
  {
    iResultat = (-768 * fData) - 192;
  }
  return iResultat;
}

//*****************************vIntToASCII***********************************
// DESCRIPTION: converti 4 ints dans un tableau en leur equivalent en ASCII
// INCLUDE:    #include "Vehicule.h"       
// PROTOTYPE:   void vIntToASCII(int *ipTab1,unsigned char *ucpTab2);
// PARAMETRE D'ENTREE:   *ipTab1           pointeur sur le tableau a convertir
//                       *ucpTab2          pointeur sur le tableau avec ASCII
// PARAMETRE DE SORTIE:  AUCUN        
// EXEMPLE:    vIntToASCII(ipRoue,ucpTrameRoue)
// PROCEDURE   APPELEE:  AUCUNE                    
// DATE DE CREATION: 24-04-2017
// AUTEUR: WILLIAM BORDELEAU
// DATE DE MODIFICATION: JAMAIS
//****************************************************************************
void vIntToASCII(int *ipTab1,unsigned char *ucpTab2)
{
  int i = 4;
  for(i; i>0 ; i--)                     // Pour les 4 roues
  {
    *ucpTab2 = (*ipTab1 >> 8) + 0x30;	
    if(*ucpTab2 >= 0x3A)               // Pour 0xAX,0xBX,0xCX,0xDX,0xEX,0xFX
    {
      *ucpTab2 = *ucpTab2 + 0x07;         
    }
    
    ucpTab2++;
    
    *ucpTab2 = ((*ipTab1 >> 4) & 0x0F) + 0x30;	
    if(*ucpTab2 >= 0x3A)               // Pour 0xAX,0xBX,0xCX,0xDX,0xEX,0xFX
    {
      *ucpTab2 = *ucpTab2 + 0x07;         
    }
    ucpTab2++;
    
    *ucpTab2 = (*ipTab1 & 0x0F) + 0x30;
    if(*ucpTab2 >= 0x3A)               // Pour 0xXA,0xXB,0xXC,0xXD,0xXE,0xXF
    {
      *ucpTab2 = *ucpTab2 + 0x07;
    }
    
    ucpTab2++;
    ipTab1++;
  }
}

  




