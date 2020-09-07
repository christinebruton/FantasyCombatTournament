/*********************************************************************
* Class: Medusa
* Abstraction the class represents: Character with special abilities
* Purpose: Implment character-specific attack and defense
* How to use: Pointer to character accessed in the main
* Summary of functionality: Enter pointer to character's enemy, and/or enemy
 * attack points into character-specific funtion
*********************************************************************/

#include "Medusa.h"
#include "HarryPotter.h"

//constructor w data members
Medusa::Medusa(){
    attack = 0; //roll  dice
    defense = 0; //roll dice
    armor = 3;
    strengthPoints = 8;
}
//see function explanation in Character
int Medusa::Attack(Character *enemy){
    int die1= (rand()%6+1);
    int die2= (rand()%6+1);
    //cout<<"Medusa: Strength "<<getStrengthPoints()<<endl;
    //special printout for Harry Potter
    if(dynamic_cast<HarryPotter*>(enemy)){
        cout<<"Harry Potter detected"<<endl;
        attack=12;
    }
    if (attack==12){
        this->attack=100;//medusa always kill opponent
        cout<<"Medusa uses **Glare** "<<endl;
        cout<<"Her enemy will be turned to stone "<<endl;
    }else{
        //cout << "Medusa: Die one rolled: " << die1 << endl;
        //cout << "Medusa: Die two rolled: " << die2 << endl;
        this->attack = die1 + die2;
        if (attack==12) {
            this->attack = 100;//medusa always kill opponent
            cout << "Medusa uses **Glare** " << endl;
            cout << "Her enemy will be turned to stone " << endl;
            cout << "Medusa: Attacks for " << getAttack() << " total points" << endl;
        }else{
            cout << "Medusa: Attack for " << getAttack() << " total points" << endl;
        }
    }
    return attack;
}
//see function explanation in Character
int Medusa::Defense(Character *enemy, int enemyAttackPts) {
    //cout<<"Medusa: Strength "<<getStrengthPoints()<<endl;
    this->defense = (rand()%6+1);
    //cout<<"Medusa: Die rolled: "<<defense<<endl;
    cout<<"Medusa: Defend for "<<defense<<" total points"<<endl;
    //container for damage points
    int damage;
    damage = enemyAttackPts - defense - armor;
    damage=zeroOutDamage(damage);
    setStrengthPoints(this->strengthPoints - damage);
    //cout << "After armor of " << getArmor() << " and defense of " << getDefense()<< endl;
    //cout << "Medusa: sustain damage of " << damage << endl;
    cout << "Medusa's remaining strength is " << getStrengthPoints() << endl;
    //if strength is below 0, character dies
    if (getStrengthPoints()<=0){
        cout<<"                 "<<endl;
        cout<<"               "<<name<< " HAS DIED!"<<endl;
    }
    return damage;
}
/*********************************************************************
* Function: recover(int )
* Purpose: virutal function implemented by each player that is implemented
* and modified based on Character base strength. Character recovers
* percentage of base strength not to exceed orignial strengthpoints.
* Return Type: int
*********************************************************************/

int Medusa::recover() {

    int baseStr= 8;
    int rNum = (rand() % 10 + 8);
    //recovers strength of between 1 and 10 points
    strengthPoints= strengthPoints+rNum;
    //if it exceeds base strength, reset to base strength
    if (strengthPoints>baseStr){
        strengthPoints=baseStr;
    }
    return strengthPoints;
}
