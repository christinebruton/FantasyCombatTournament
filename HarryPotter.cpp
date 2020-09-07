/*********************************************************************
* Class: Harry Potter
* Abstraction the class represents: Character with special abilities
* Purpose: Implement character-specific attack and defense
* How to use: Pointer to character accessed in the main
* Summary of functionality: Enter pointer to character's enemy, and/or enemy
* attack points into character-specific function
*********************************************************************/
#include "HarryPotter.h"

HarryPotter::HarryPotter(){
    attack = 0; //roll  dice
    defense = 0; //roll dice
    armor = 0;
    strengthPoints = 10;
}
//see function defintion in Character
int HarryPotter::Attack(Character *enemy){

    int die1= (rand()%6+1);
    int die2= (rand()%6+1);
    //cout<<"Harry Potter: Strength "<<getStrengthPoints()<<endl;
    //cout<<"Harry Potter: Die one rolled: "<<die1<<endl;
    //cout<<"Harry Potter: Die two rolled: "<<die2<<endl;
    this->attack =  die1+die2 ;
    cout<<"Harry Potter: Attack for "<<getAttack()<<" total points"<<endl;
    return attack;
}
//see function defintion in Character
int HarryPotter::Defense(Character *enemy, int enemyAttackPts) {
    //bool resurrect=false;
    int damage;
    checkForDeath();
    if (!isDead) {
        int die1 = (rand() % 6 + 1);
        int die2 = (rand() % 6 + 1);
        //cout<<"Harry Potter: Strength "<<getStrengthPoints()<<endl;
        //cout << "Harry Potter: Die one rolled: " << die1 << endl;
       // cout << "Harry Potter: Die two rolled: " << die2 << endl;
        this->defense = die1 + die2;
        damage = enemyAttackPts - defense - armor;
        damage = zeroOutDamage(damage);
        setStrengthPoints(this->strengthPoints - damage);
        //cout << "Harry Potter: Defended for " << getDefense() << " total points" << endl;
       // cout << "After armor of " << getArmor() << " and defense of " << getDefense() << endl;
        cout << "Harry Potter: Sustain damage of " << damage << endl;
        cout <<  "Harry's remaining strength is " << getStrengthPoints() << endl;
        //check current strengthpoints
        checkForDeath();
        return 0;
    }
    return 0;
}

//friend function used to check for 0 or neg strength and output death message
void HarryPotter::checkForDeath(){
    if (getStrengthPoints()<=0 && resurrected){
        cout << "          " << endl;
        cout<<"Harry Potter already died once before- "<<endl;
        cout<<"he can't be resurrected this time! "<<endl;
        cout<<"                 "<<endl;
        cout<<"               "<<name<< " HAS DIED!"<<endl;
        setStrengthPoints(0);
        isDead = true;
    }else if (getStrengthPoints()<=0 && !resurrected){
        setStrengthPoints(20);
        cout << "Harry Potter used ** Hogwarts! ** "<<endl;
        cout << "20 pts strength added! " << endl;
        resurrected=true;
        isDead = false;
    }
}
/*********************************************************************
* Function: recover(int )
* Purpose: virutal function implemented by each player that is implemented
* and modified based on Character base strength. Character recovers
* percentage of base strength not to exceed orignial strengthpoints.
* Return Type: int
*********************************************************************/

int HarryPotter::recover() {

    int baseStr= 10;
    int rNum = (rand() % 3 + 1);
    //recovers strength of between 1 and 3 points
    strengthPoints= strengthPoints+rNum;
    //if it exceeds base strength, reset to base strength
    if (strengthPoints>baseStr){
        strengthPoints=baseStr;
    }
    return strengthPoints;
}
