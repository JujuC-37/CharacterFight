#ifndef ARME_H_INCLUDED
#define ARME_H_INCLUDED

#include <string>
#include <iostream>

class Arme
{
    public :
        Arme();
        Arme(std::string nomArme, int degatsArme, int forceRequise);
        void changer(std::string nomNouvelleArme, int degatsNouvelleArme, int forceRequiseNouvelleArme);
        std::string getNom() const;
        int getDegats() const;
        int getForceRequise() const;
        void afficher() const;

    private:
        std::string m_nom;
        int m_degats;
        int m_forceRequise;
};

#endif // ARME_H_INCLUDED
