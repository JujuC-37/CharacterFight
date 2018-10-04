#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "Personnage.h"

int saisieChoix(Personnage personnageActuel, std::vector<Arme> & tabArmes);
void changerDArme(Personnage &personnageActuel, std::vector<Arme> & tabArmes);

#endif // FONCTIONS_H_INCLUDED
