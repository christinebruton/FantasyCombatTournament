/*********************************************************************
* Class: Blue Men
* Abstraction the class represents: Character with special abilities
* Purpose: Implement character-specific attack and defense
* How to use: Pointer to character accessed in the main
* Summary of functionality: Enter pointer to character's enemy, and/or enemy
* attack points into character-specific function
*********************************************************************/

#include "BlueMen.h"

//constructor w data members
BlueMen::BlueMen(){
    attack = 0;
    defense = 0;
    armor = 3;
    strengthPoints = 12;
}
//see function explanation in Character
int BlueMen::Attack(Character *enemy){
    int die1= (rand()%10+1);
    int die2= (rand()%10+1);
    //cout << "Blue Men: Strength " << getStrengthPoints() << endl;
    //cout<<"Blue men: Die one rolled: "<<die1<<endl;
    //cout<<"Blue men: Die two rolled: "<<die2<<endl;
    this->attack = die1+die2 ;
    cout<<"Blue men: Attack for "<<getAttack()<<" total points"<<endl;
    return attack;
}
//see function explanation in Character
int BlueMen::Defense(Character *enemy, int enemyAttackPts) {
    int damage = 0;
    //make sure the character is not dead in before moving on
    checkForDeath();
    //if the number of die have been reduced, enter the reduced number into the mob switch
    if (numOfDie<3 && !isDead){
        cout <<  "Blue Men: Strength " << getStrengthPoints() << endl;
        mob(numOfDie, enemyAttackPts);
        return 0;
    }
        //if it's the first time that the blue men are defending
    else if (!atLeastOnce && !isDead && numOfDie >= 3) {
        int die1 = (rand() % 6 + 1);
        int die2 = (rand() % 6 + 1);
        int die3 = (rand() % 6 + 1);

        //cout <<  "Blue Men: Strength " << getStrengthPoints() << endl;
        //cout << "Blue men: Die one rolled: " << die1 << endl;
        //cout << "Blue men: Die two rolled: " << die2 << endl;
        //cout << "Blue men: Die three rolled: " << die3 << endl;
        this->defense=die1 + die2 + die3;
       // cout << "Blue men: Defend for " << defense << " total points" << endl;
        damage = enemyAttackPts - defense - armor;
        damage =zeroOutDamage(damage);
        setStrengthPoints(this->strengthPoints - damage);
        //cout << "After armor of " << getArmor() << " and defense of " << getDefense() << endl;
        cout << "Blue Men sustain damage of " << damage << endl;
        cout << "Blue men's remaining strength is " << getStrengthPoints() << endl;

        //transfer net value of damage into another variable to run qualifiers
        int analyzeDamage = damage;
        //see if damage is a multiple of 4 and greater than 4
        while (analyzeDamage >= 4) {
            //reduce number by 4
            analyzeDamage = analyzeDamage - 4;
            //reduce number of dice by 1
            numOfDie = numOfDie - 1;
            if (numOfDie<=0){
                numOfDie=0;
            }

            checkForDeath();
            if (!isDead){
                cout << "Blue Men: ** Mob **" << endl;
                cout << "For the next defense, " << endl;
                cout << "Blue Men: number of Dice reduced to: " << numOfDie << endl;
            }else{
                return damage;
            }
        }
        atLeastOnce = true;
        return damage;
        //process defense if the number of dice have not been reduced
    }else if(atLeastOnce && !isDead && numOfDie >= 3){
        int die1 = (rand() % 6 + 1);
        int die2 = (rand() % 6 + 1);
        int die3 = (rand() % 6 + 1);
        //cout <<  "Blue Men: Strength " << getStrengthPoints() << endl;
        //cout << "Blue men: Die one rolled: " << die1 << endl;
        //cout << "Blue men: Die two rolled: " << die2 << endl;
        // << "Blue men: Die three rolled: " << die3 << endl;
        this->defense=die1 + die2 + die3;
       // cout << "Blue men: Defend for " << defense << " total points" << endl;
        damage = enemyAttackPts - defense - armor;
        damage =zeroOutDamage(damage);
        setStrengthPoints(this->strengthPoints - damage);
       // cout << "After armor of " << getArmor() << " and defense of " << getDefense() << endl;
        cout << "Blue Men sustain damage of " << damage << endl;
        cout << "Blue men's remaining strength is " << getStrengthPoints() << endl;
        //if strength is below 0, character dies
        checkForDeath();

        //transfer net value of damage into another variable to run qualifiers
        int analyzeDamage = damage;

        //see if damage is a multiple of 4 and greater than 4
        while (analyzeDamage >= 4) {
            //reduce number by 4
            analyzeDamage = analyzeDamage - 4;

            //reduce number of dice by 1
            numOfDie = numOfDie - 1;
            if (numOfDie <= 0) {
                numOfDie = 0;
            }

            checkForDeath();
            if (!isDead) {
                cout << "Blue Men: ** Mob **" << endl;
                cout << "For the next defense, " << endl;
                cout << "Blue Men: number of Dice reduced to: " << numOfDie << endl;
            } else {
                return damage;
            }
        }

    }
    return 0;
}

/*********************************************************************
* Function: mob(int,  int)
* Purpose: implement special ability of blue men
* Arguments|Preconditions: intput the number of die from main defense
* function as well as the attack points
* Return Type: int
*********************************************************************/

int BlueMen::mob(int numOfDie, int enemyAttackPts) {
    int damage;
    //main switch function
    cout << "Blue Men: Number of defense dice " << numOfDie << endl;
    switch (numOfDie) {
        case 0: {
            int die1 = (rand() % 6 + 1);
            //cout <<  "Blue Men: Strength " << getStrengthPoints() << endl;
            cout << "Blue men have no defense die " << die1 << endl;
            cout << " " << endl;
            this->defense = 0;
            //standard print out of defense info
            damage = enemyAttackPts - defense - armor;
            damage=zeroOutDamage(damage);
            setStrengthPoints(this->strengthPoints - damage);
           // cout << "Blue men: Defend for " << defense << " total points" << endl;
           // cout << "After armor of " << getArmor() << " and defense of " << getDefense() << endl;
            cout << "Blue Men sustain damage of " << damage << endl;
            cout << "Blue men's remaining strength is " << getStrengthPoints() << endl;
            //if strength is below 0, character dies
            checkForDeath();
        }
            break;

        case 1: {
            int die1 = (rand() % 6 + 1);
            //cout <<  "Blue Men: Strength " << getStrengthPoints() << endl;
           // cout << "Blue men: Die one rolled: " << die1 << endl;
            cout << " " << endl;
            this->defense = die1;

            //standard print out of defense info
            damage = enemyAttackPts - defense - armor;
            damage=zeroOutDamage(damage);
            setStrengthPoints(this->strengthPoints - damage);
            //cout << "Blue men: Defend for " << defense << " total points" << endl;
            //cout << "After armor of " << getArmor() << " and defense of " << getDefense() << endl;
            cout << "Blue Men sustain damage of " << damage << endl;
            cout << "Blue men's remaining strength is " << getStrengthPoints() << endl;
            //if strength is below 0, character dies
            checkForDeath();
        }
            break;
        case 2: {
            int die1 = (rand() % 6 + 1);
            int die2 = (rand() % 6 + 1);
            //cout <<  "Blue Men: Strength " << getStrengthPoints() << endl;
            //cout << "Blue men: Die one rolled: " << die1 << endl;
            //cout << "Blue men:: Die two rolled: " << die2 << endl;
            cout << " " << endl;
            this->defense = die1 + die2;
            //standard print out of defense info
            damage = enemyAttackPts - defense - armor;
            damage=zeroOutDamage(damage);
            setStrengthPoints(this->strengthPoints - damage);
            //cout << "Blue men: Defend for " << defense << " total points" << endl;
           // cout << "After armor of " << getArmor() << " and defense of " << getDefense() << endl;
            cout << "Blue Men sustain damage of " << damage << endl;
            cout << "Blue men's remaining strength is " << getStrengthPoints() << endl;
            //if strength is below 0, character dies
            checkForDeath();
        }
            break;
            //I don't think this will happen but just in case...
        case 3: {
            int die1 = (rand() % 6 + 1);
            int die2 = (rand() % 6 + 1);
            int die3 = (rand() % 6 + 1);
            //cout <<  "Blue Men: Strength " << getStrengthPoints() << endl;
           /* cout << "Blue men: Die one rolled: " << die1 << endl;
            cout << "Blue men: Die two rolled: " << die2 << endl;
            cout << "Blue men: Die three rolled: " << die3 << endl;*/
            cout << " " << endl;
            this->defense = die1 + die2 + die3;
            //standard print out of defense info
            damage = enemyAttackPts - defense - armor;
            damage=zeroOutDamage(damage);
            setStrengthPoints(this->strengthPoints - damage);
            //cout <<  "Blue Men: Strength " << getStrengthPoints() << endl;
            //cout << "Blue men: Defend for " << defense << " total points" << endl;
            //cout << "After armor of " << getArmor() << " and defense of " << getDefense() << endl;
            cout << "Blue Men sustain damage of " << damage << endl;
            cout << "Blue men's remaining strength is " << getStrengthPoints() << endl;
            //if strength is below 0, character dies
            checkForDeath();
        }
            break;
    }
    return 0;
}
//function to see if something is dead
void BlueMen::checkForDeath() {
    if (getStrengthPoints() <= 0) {
        cout << "" << endl;
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

int BlueMen::recover() {
    int baseStr= 12;
    int rNum = (rand() % 1 + 2);
    //recovers strength of between 3 and 6 percent
    strengthPoints= strengthPoints+rNum;
    //if it exceeds base strength, reset to base strength
    if (strengthPoints>baseStr){
        strengthPoints=baseStr;
    }
    return strengthPoints;
}