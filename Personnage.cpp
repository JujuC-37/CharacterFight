#include "Personnage.h"

using namespace std;

/*Personnage::Personnage()
constructeur par défaut
*/
Personnage::Personnage() :  m_pointsVie(100),
                            m_pointsForce(100)
{

}

/*Personnage::Personnage(std::string nomArme, int degatsArme)
constructeur (nom et arme donnés)
*/
Personnage::Personnage(std::string nomPersonnage, Arme arme) :    m_nom(nomPersonnage),
                                                                  m_pointsVie(100),
                                                                  m_pointsForce(100),
                                                                  m_Arme(arme.getNom(), arme.getDegats(), arme.getForceRequise())
{

}

/*void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
donne comme nouvelle arme celle donnée en paramètre
*/
void Personnage::changerArme(Arme nouvelleArme)
{
    m_Arme.changer(nouvelleArme.getNom(), nouvelleArme.getDegats(), nouvelleArme.getForceRequise());
}

/*void Personnage::recevoirDegats(int nbDegats)
enlève aux points de vie les dégâts affligés
contrôle le nombre de points de vie (qui doit rester (oujours positif ou nul)
*/
void Personnage::recevoirDegats(int nbDegats)
{
    m_pointsVie -= nbDegats;

    if (m_pointsVie<0)
    {
        m_pointsVie = 0;
    }
}

/*void Personnage::attaquer(Personnage& cible)
applique à la cible donnée en paramètre la méthode recevoirDegats
*/
void Personnage::attaquer(Personnage& cible)
{
    cible.recevoirDegats(m_Arme.getDegats());
    m_pointsForce -= m_Arme.getForceRequise();
}

/*void Personnage::boirePotionDeVie(int quantitePotion)
augmente le nombre de points de vie du personnage en fonction de la quantite mise en paramètre
contrôle le nombre de points de vie (qui ne doit pas depasser 100)
*/
void Personnage::boirePotionDeVie(int quantitePotion)
{
    m_pointsVie += quantitePotion;

    if (m_pointsVie>100)
    {
        m_pointsVie = 100;
    }
}

/*bool Personnage::estVivant() const
indique si le personnage est vivant
retourne : false (m_pointsVie=0) ou true (m_pointsVie>0)
*/
bool Personnage::estVivant() const
{
    if(m_pointsVie==0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/*string Personnage::getNom() const
accesseur retournant l'attribuut m_nom du personnage
*/
string Personnage::getNom() const
{
    return m_nom;
}

/*void Personnage::afficher() const
affiche le nom, les points de vie et force
*/
void Personnage::afficher() const
{
    cout << m_nom << endl;
    cout << "Vie : " << m_pointsVie << endl;
    cout << "Force : " << m_pointsForce << endl;
    cout << "Arme : " << m_Arme.getNom() << " (Degats : " << m_Arme.getDegats() << " ; Force : " << m_Arme.getForceRequise() << ")" << endl << endl;
}

/*int Personnage::getPointdeForce() const
retourne le nombre de point de force du personnage
*/
int Personnage::getPointdeForce() const
{
    return m_pointsForce;
}

/*Arme Personnage::getArme() const
retourne l'arme du personnage
*/
Arme Personnage::getArme() const
{
    return m_Arme;
}
