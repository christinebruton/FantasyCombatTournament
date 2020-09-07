//
// Created by christine bruton on 3/4/18.
//

#ifndef TOURNAMENT_HARRYPOTTER_H
#define TOURNAMENT_HARRYPOTTER_H

#include <stdio.h>
#include "Character.h"
#include <cstdlib>

class HarryPotter : public Character {
private:

    //used to determine if resurrection occurred already
    bool resurrected=false;

public:
    //constructor
    HarryPotter();
    //see function defintion in Character
    int Attack(Character *enemy) override;
    //see function defintion in Character
    int Defense(Character *enemy, int damage) override;
    //friend function used to check for 0 or neg strength and output death message
    void checkForDeath();

    int recover()override;
};





#endif //TOURNAMENT_HARRYPOTTER_H
