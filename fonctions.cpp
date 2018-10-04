#include "fonctions.h"

using namespace std;

/*int saisieChoix()
affiche les actions possibles du joueur
retourne : le choix
*/
int saisieChoix(Personnage personnageActuel, vector<Arme> & tabArmes)
{
    int numeroChoix(0);
    string choix("0");
    bool choixCorrect(false);

    do
    {
        cout << "Que voulez-vous faire ?" << endl;

        //1
        cout << "1. Attaquer" << endl;

        //2
        cout << "2. Changer d'arme" << endl;
        for(size_t i(0); i<tabArmes.size(); i++)
        {
            cout << "\t";
            tabArmes[i].afficher();
        }

        //3
        cout << "3. Boire une potion" << endl;

        //4
        cout << "4. Abandonner" << endl;

        //cin
        cin >> choix;

        numeroChoix = atoi(choix.c_str());

        switch (numeroChoix)
        {
            case 1: if (personnageActuel.getPointdeForce() >= personnageActuel.getArme().getForceRequise())
                    {
                        choixCorrect = true;
                    }
                    break;

            case 2: choixCorrect = true;
                    break;

            case 3: choixCorrect = true;
                    break;

            case 4: choixCorrect = true;
                    break;

        }



    }while (numeroChoix<0 && numeroChoix>5 && !choixCorrect);

    return numeroChoix;
}

/*void changerDArme(Personnage personnageActuel, std::vector<Arme> tabArmes)
demande au joueur quelle arme veut-il et contrôle la saisie
change l'arme du joueur en appelant la méthode changerArme de la classe Personnage
*/
void changerDArme(Personnage &personnageActuel, std::vector<Arme> &tabArmes)
{
    size_t armeDemandeeNb(0);
    string armeDemandeeStr("0");

    do
    {
        cout << "Quelle arme voulez-vous ?" << endl;
        for(size_t i(0); i<tabArmes.size(); i++)
        {
            cout << "\t" << i+1 << ". ";
            tabArmes[i].afficher();
        }
        cin >>armeDemandeeStr;

        armeDemandeeNb = atoi(armeDemandeeStr.c_str());

    }while (armeDemandeeNb<1 || armeDemandeeNb>tabArmes.size());


    //cout << "Vous avez choisi : " << tabArmes[armeDemandeeNb-1].getNom() << endl;
    personnageActuel.changerArme(tabArmes[armeDemandeeNb-1]);
}
