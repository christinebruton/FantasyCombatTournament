//
// Created by christine bruton on 3/2/18.
//

#ifndef TOURNAMENT_BARBARIAN_H
#define TOURNAMENT_BARBARIAN_H
#include <stdio.h>
#include "Character.h"
#include <cstdlib>



class Barbarian : public Character{

    public:
        Barbarian();
        int Attack(Character *enemy) override;
        int Defense(Character *enemy, int damage) override;
        int recover () override;
        void checkForDeath();


};


#endif //TOURNAMENT_BARBARIAN_H
