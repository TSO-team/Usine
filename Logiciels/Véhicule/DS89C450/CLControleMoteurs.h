//////////////////////////////////////////////////////////////////////////////
// Fichier :                 CLControleMoteurs.h
// Concepteur :              Samuel Duclos
// Date :                    2017/02/05
// Description :             Controleur de quatre moteurs pour chaque roue.
// Version :                 v0.1
// Compilateur :             IAR
//////////////////////////////////////////////////////////////////////////////
#ifndef CLCONTROLEMOTEURS_H
  #define CLCONTROLEMOTEURS_H
  #include "CLRoue.h"

  #define ARRET 0x0200

  class CLControleMoteurs {
    public: CLControleMoteurs(void), CLControleMoteurs(UC);
      ~CLControleMoteurs(void);
    protected:
      void vMarcheAvant(void), vMarcheArriere(void), vTourneGauche(void);
      void vTourneGauche(UC), vTourneDroite(void), vTourneDroite(UC);
      void vControleBrut(USI, USI, USI, USI), vArretMoteurs(void);
      void vChangeVitesse(UC), vTourne(UC, SC);
    private:
      UC ucVitesse;
      class CLRoue clRoueHighLeft, clRoueLowLeft;
      class CLRoue clRoueLowRight, clRoueHighRight;
  };
#endif


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


