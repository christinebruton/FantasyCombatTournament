//
// Created by christine bruton on 3/4/18.
//

#ifndef TOURNAMENT_MEDUSA_H
#define TOURNAMENT_MEDUSA_H

#include <stdio.h>
#include "Character.h"
#include <cstdlib>

class Medusa : public Character{

public:
    Medusa();
    //see function defintion in Character
    int Attack(Character *enemy) override;
    //see function defintion in Character
    int Defense(Character *enemy, int damage) override;
    int recover()override;
};


#endif //TOURNAMENT_MEDUSA_H
