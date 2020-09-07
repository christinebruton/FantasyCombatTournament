/*********************************************************************
* Class: Barbarian
* Abstraction the class represents: Character with special abilities
* Purpose: Implement character-specific attack and defense
* How to use: Pointer to character accessed in the main
* Summary of functionality: Enter pointer to character's enemy, and/or enemy
* attack points into character-specific function
*********************************************************************/

#include "Barbarian.h"

//constructor

Barbarian::Barbarian(){
    attack = 0; //roll  dice
    defense = 0; //roll dice
    armor = 0;
    strengthPoints = 12;
}

int Barbarian::Attack(Character *enemy){
    int die1= (rand()%6+1);
    int die2= (rand()%6+1);
    //cout << "Strength " << getStrengthPoints() << endl;
    //cout<<"Die one rolled: "<<die1<<endl;
    //cout<<"Die two rolled: "<<die2<<endl;
    this->attack = die1+die2 ;
    cout<<"Blue Men: Attack for "<<getAttack()<<" total points"<<endl;
    return attack;
}

int Barbarian::Defense(Character *enemy, int enemyAttackPts) {
    int damage;
    checkForDeath();
    if (!isDead) {
        int die1 = (rand() % 6 + 1);
        int die2 = (rand() % 6 + 1);
        cout << "Barbarian: Strength " << getStrengthPoints() << endl;
       // cout << "Die one rolled: " << die1 << endl;
       // cout << "Die two rolled: " << die2 << endl;
        this->defense = die1 + die2;

        damage = enemyAttackPts - defense - armor;
        damage = zeroOutDamage(damage);
        setStrengthPoints(this->strengthPoints - damage);
        //standard print out of defense info
        //cout << "Defend for " << defense << " total points" << endl;
       // cout << "After armor of " << getArmor() << " and defense of " << getDefense() << endl;
        cout << "sustain damage of " << damage << endl;
        cout << "remaining strength is " << getStrengthPoints() << endl;

        //if strength is below 0, character dies
        checkForDeath();

    }
    return damage;
}
void Barbarian::checkForDeath(){
    if (getStrengthPoints()<=0){
        cout << "           " << endl;
        cout<<"               "<<name<< " HAS DIED!"<<endl;
        isDead = true;
    }
}

/*********************************************************************
* Function: recover(int )
* Purpose: virutal function implemented by each player that is implemented
* and modified based on Character base strength. Character recovers
* percentage of base strength not to exceed orignial strengthpoints.
* Return Type: int
*********************************************************************/

int Barbarian::recover() {

    int baseStr= 12;
    int rNum = (rand() % 8 + 3);
        //recovers strength of between 3 and 6 percent
        strengthPoints= strengthPoints+rNum;
    //if it exceeds base strength, reset to base strength
    if (strengthPoints>baseStr){
        strengthPoints=baseStr;
    }
    return strengthPoints;
}


