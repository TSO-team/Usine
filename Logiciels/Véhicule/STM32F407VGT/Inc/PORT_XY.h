//******************************************************************************
//   Nom du fichier : PORT_XY.h
//   Auteur : Alain Champagne                  
//      Date de cr�ation : 21-12-2015 
//        Fichier de d�claration et de d�finition des fonctions de controle des 
//        �l�ments d'entr�es sorties.
//  
//******************************************************************************
#ifndef PORT_XYH
  #define PORT_XYH


//Predeclaration des fonctions
 void vPort_IN (uint8_t ucPort);
 void vPort_OUT (uint8_t ucPort);
 uint8_t ucReadPort (uint8_t ucPort);
 void vWritePort(uint8_t ucEcrireDataPort, uint8_t ucPort);


#endif
