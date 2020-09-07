//
// Created by christine bruton on 3/2/18.
//

#ifndef TOURNAMENT_UTILITIES_H
#define TOURNAMENT_UTILITIES_H


#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <array>

using std::cout; using std::cin; using std::endl;  using std::string;


class Utilities {

private:
    //container for number of rounds
    int fighterNumA=-99;
    int fighterNumB=-99;
    //container for character choice int
    int characterCh=0;



public:
    //displays attacker menu
    int fighterAMenu();
    //displays defineder menu
    int defenderMenu();
    int playMenu();

    //input validaton function



    bool inputValid(string userInputString);

    int playerAMenu();

    int playerBMenu();

    int getFighterNumA() const;

    void setFighterNumA(int fighterNumA);

    int getFighterNumB() const;

    void setFighterNumB(int fighterNumB);

    int fighterBMenu();

    int showLosers();
};


#endif //TOURNAMENT_UTILITIES_H
