/*********************************************************************
* Class: Vampire
* Abstraction the class represents: Character with special abilities
* Purpose: Implment character-specific attack and defense
* How to use: Pointer to character accessed in the main
* Summary of functionality: Enter pointer to character's enemy, and/or enemy
 * attack points into character-specific funtion
*********************************************************************/

#include "Vampire.h"

//function prototypes
bool charm(int attackpts);
//bool used to determine if charm power was used
bool charmUsed= false;

//constructor
Vampire::Vampire(){
    attack = 0; //roll 1 12-sided dice
    defense = 0; // roll 1 6-sided die and add *charm
    armor = 1;
    strengthPoints = 18;
}

//see function defintion in Character
int Vampire::Attack (Character *enemy){

    if(isDead){
        cout<<"                 "<<endl;
        cout<<"                 "<<name<< " HAS DIED!"<<endl;
    }else {

        int die1 = (rand() % 10 + 1);
        this->attack = die1;
        //cout << "Vampire: Die rolled " << getAttack() << endl;
        cout << "Vampire: Attack for " << getAttack() << " points" << endl;
        return attack;
    }
    return 0;
}

//see function defintion in Character
int Vampire::Defense(Character *enemy, int enemyAttackPts) {
    int damage=0;
    //if strength is below 0, character dies
    if (getStrengthPoints()<=0){
        cout<<"                 "<<endl;
        cout<<"                "<<name<< " HAS DIED!"<<endl;
        isDead=true;

    }
    if (isDead==false) {
        //cout <<  "Vampire: strength " << getStrengthPoints() << endl;
        charmUsed=charm(enemyAttackPts);
        if (charmUsed){
            cout <<  "Vampire: strength remains at " << getStrengthPoints() << endl;
        }
        //if charm is not chosen, initiate standard defense
        while (!charmUsed) {
            this->defense = rand() % 6 + 1;
           // cout << "Vampire: Die rolled " << defense << endl;
            damage = enemyAttackPts - defense - armor;
            cout << "Vampire: Defended for " << getDefense() << " total points" << endl;
            setStrengthPoints(this->strengthPoints - damage);
            //cout << "After armor of " << getArmor() << " and defense of " << getDefense() << endl;
            //cout << "Vampire: Experienced damage of " << damage << endl;
            cout <<  "Vampire's remaining strength is " << getStrengthPoints() << endl;
            //if strength is below 0, character dies
            if (getStrengthPoints()<=0){
                cout<<"                 "<<endl;
                cout<<"               "<<name<< " HAS DIED!"<<endl;
            }
            return damage;
        }
    }
    return damage;

}

/*********************************************************************
* Function:charm (int)
* Purpose: About 50% of the time, cause enemy's attack to be turned to 0
* Arguments|Preconditions: Character attack points
* Return Type: bool
*********************************************************************/

bool charm(int enemyAttackPts) {
    int charmChoice = 0;
    //randomize whether charm is used- 1 or 2
    charmChoice = rand() % 2 + 1;
    switch (charmChoice){
        case 1: {
            cout << "Vampire uses ** Charm ** !" << endl;
            //cout << "Attack from Vampire's enemy prevented! " << endl;
            charmUsed=true;
        }
            break;
        case 2: {
            //do nothing
            charmUsed=false;
        }
            break;
    }
    return charmUsed;
}
/*********************************************************************
* Function: recover(int )
* Purpose: virutal function implemented by each player that is implemented
* and modified based on Character base strength. Character recovers
* percentage of base strength not to exceed orignial strengthpoints.
* Return Type: int
*********************************************************************/

int Vampire::recover() {

    int baseStr= 18;
    int rNum = (rand() % 7 + 5);
    //recovers strength of between 1-2 points
    cout<<"rNum "<<rNum;
    strengthPoints= strengthPoints+rNum;
    //if it exceeds base strength, reset to base strength
    if (strengthPoints>baseStr){
        strengthPoints=baseStr;
    }
    return strengthPoints;
}
