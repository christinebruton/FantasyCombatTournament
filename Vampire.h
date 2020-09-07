//
// Created by christine bruton on 3/4/18.
//

#ifndef TOURNAMENT_VAMPIRE_H
#define TOURNAMENT_VAMPIRE_H

#include <stdio.h>
#include "Character.h"

class Vampire : public Character{

public:

    //constructor
    Vampire();
    //see function defintion in Character
    int Attack(Character *enemy) override;
    //see function defintion in Character
    int Defense(Character *enemy, int enemyAttackPts) override;

    int recover() override;
};




#endif //TOURNAMENT_VAMPIRE_H
