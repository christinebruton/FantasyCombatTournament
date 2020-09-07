/*********************************************************************
* Class: Blue Men
* Abstraction the class represents: Character with special abilities
* Purpose: Implement character-specific attack and defense
* How to use: Pointer to character accessed in the main
* Summary of functionality: Enter pointer to character's enemy, and/or enemy
* attack points into character-specific function
*********************************************************************/

#ifndef TOURNAMENT_BLUEMEN_H
#define TOURNAMENT_BLUEMEN_H
#include <stdio.h>
#include "Character.h"
#include <cstdlib>

class BlueMen : public Character{

private:
    bool atLeastOnce=false;//have the blue men defended at least once
    int numOfDie = 3;//keep track of number of dice available

public:
    BlueMen();
    int Attack(Character *enemy) override;
    int Defense(Character *enemy, int damage) override;

    //special ability function, reduces number of die based on damage taken
    int mob(int numOfDie, int damage);
    //check strength to make sure it's not <=0. If it is, print death statement
    void checkForDeath();
    //virtual recover function
    int recover () override;

};



#endif //TOURNAMENT_BLUEMEN_H
