#include <iostream>
#include <vector>
#include "Personnage.h"
#include "Arme.h"
#include "fonctions.h"

using namespace std;

int main()
{
    const int toursMax(3*2), potionDeVie(20);

    static const size_t indiceArmes_EpeeBois(0),
                        indiceArmes_VieilleEpee(1),
                        indiceArmes_EpeeBronze(2),
                        indiceArmes_EpeeFer(3);

    vector<Arme> armes;
    armes.push_back(Arme("Epee en bois", 5, 0));
    armes.push_back(Arme("Vieille epee", 15, 10));
    armes.push_back(Arme("Epee en bronze", 25, 15));
    armes.push_back(Arme("Epee en fer", 30, 20));

    Personnage  joueur_1("Joueur 1", armes[indiceArmes_VieilleEpee]),
                joueur_2("Joueur 2", armes[indiceArmes_VieilleEpee]),
                joueurActuel(joueur_1),
                joueurAdverse(joueur_2);

    int i (0);
    bool abandon(false);

    do
    {
        cout << "\\********************************* Le combat *********************************/" << endl;

        joueur_1.afficher();
        joueur_2.afficher();

        if (i%2==0)
        {
            cout << "<--------------------------------- Joueur 1 --------------------------------->"<< endl;
            joueurActuel = joueur_1;
            joueurAdverse = joueur_2;
        }
        else
        {
            cout << "<--------------------------------- Joueur 2 --------------------------------->"<< endl;
            joueurActuel = joueur_2;
            joueurAdverse = joueur_1;
        }

        int actionChoisie(saisieChoix(joueurActuel,armes));

        switch (actionChoisie)
        {
            case 1: joueurActuel.attaquer(joueurAdverse); //attaquer
                    break;

            case 2: changerDArme(joueurActuel, armes); //changer d'arme
                    break;

            case 3: joueurActuel.boirePotionDeVie(potionDeVie); //boire une potion
                    break;

            case 4: abandon = true; //abandonner
                    break;
        }

        if (i%2==0)
        {
            joueur_1 = joueurActuel;
            joueur_2 = joueurAdverse;
        }
        else
        {
            joueur_2 = joueurActuel;
            joueur_1 = joueurAdverse;
        }

        i++;
        system("cls");

    }while(i<toursMax && joueurAdverse.estVivant() && !abandon);


    cout << "\\********************************* Le combat *********************************/" << endl << endl;

    if (abandon)
    {
        cout << endl << "Bravo " << joueurAdverse.getNom() << " ! Votre adversaire a abandonne !" << endl << endl << endl;
    }
    else if (!joueurAdverse.estVivant())
    {
        cout << endl<< "Bravo " << joueurActuel.getNom() << " ! Vous avez battu votre adversaire !" << endl <<endl;
    }
    else
    {
        cout << "Vous n'avez pas reussi a vous departager..." << endl <<endl;
    }

    cout << "<---------------------------------------------------------------------------->"<< endl;
    cout << "                           Taper sur une touche pour arreter" << endl;
    cout << "<---------------------------------------------------------------------------->"<< endl;

    return 0;
}
