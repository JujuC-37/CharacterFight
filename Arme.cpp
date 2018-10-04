#include "Arme.h"

using namespace std;

/*Arme::Arme()
constructeur par d�faut
*/
Arme::Arme() :  m_nom("Vieille epee"),
                m_degats(15),
                m_forceRequise(10)
{

}

/*Arme::Arme(string nomArme, int degatsArme, int forceRequise)
constructeur avec propri�t�s donn�es en param�tres
*/
Arme::Arme(string nomArme, int degatsArme, int forceRequise) :  m_nom(nomArme),
                                                                m_degats(degatsArme),
                                                                m_forceRequise(forceRequise)
{

}

/*void Arme::changer(string nomNouvelleArme, int degatsNouvelleArme)
change les propri�t�s de l'arme (m_nom et m_degats) en fonction des param�tres donn�s
*/
void Arme::changer(string nomNouvelleArme, int degatsNouvelleArme, int forceRequiseNouvelleArme)
{
    m_nom = nomNouvelleArme;
    m_degats = degatsNouvelleArme;
    m_forceRequise = forceRequiseNouvelleArme;
}

/*string Arme::getNom() const
accesseur retournant l'attribut m_nom de l'arme
*/
string Arme::getNom() const
{
    return m_nom;
}

/*int Arme::getDegats() const
accesseur retournant l'attribut m_degats de l'arme
*/
int Arme::getDegats() const
{
    return m_degats;
}

/*int getForceDegats() const
accesseur retournant l'attribut m_forceRequise de l'arme
*/
int Arme::getForceRequise() const
{
    return m_forceRequise;
}

/*void Arme::afficher() const
affiche les propri�t�s de l'arme
*/
void Arme::afficher() const
{
    cout << m_nom << " (Degats : " << m_degats << " ; Force requise : " << m_forceRequise << ")" << endl;
}
