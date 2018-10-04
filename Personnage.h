#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include "Arme.h"

class Personnage
{
    public :
        Personnage();
        Personnage(std::string nomPersonnage, Arme arme);
        void changerArme(Arme nouvelleArme);
        void recevoirDegats(int nbDegats);
        void attaquer(Personnage &cible);
        void boirePotionDeVie(int quantitePotion);
        bool estVivant() const;
        void afficher() const;
        std::string getNom() const;
        int getPointdeForce() const;
        Arme getArme() const;

    private :
        std::string m_nom;
        int m_pointsVie;
        int m_pointsForce;
        Arme m_Arme;
};


#endif // PERSONNAGE_H_INCLUDED
