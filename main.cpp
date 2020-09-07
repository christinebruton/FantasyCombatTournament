
/*********************************************************************
* Program name: Tournament
* Author: Christine Bruton
* Student ID: 933010860
* Date: 3/4/2018
* Description: Tournament game allowing two different players to enter
* the number of fighters for both team. After that, the characters at the start of
 * each lineup battle. The one who doesn't die has a percentage of strength restored
 * based on a die roll and has 2 points added to it's score.
 * The Tournament ends when the lineup is empty. User is asked
 * if they want to see a stack of losers.
 * ----->Object lineups are stored in Queue-like circular linked list structures
 * and the losers are stored in stack-like circular linked list structure. (I decided
 * to alter my previous lab to accomplish this as endorsed by the TA on piazza thread @395
 *
* Citations: Function to free node memory based on the one described here
https://stackoverflow.com/questions/43149249/c-circular-link-list-remove-all-nodes
*********************************************************************/


#include <iostream>
#include "Character.h"
#include "Utilities.h"
#include "Barbarian.h"
#include "BlueMen.h"
#include "Queue.h"
#include "Stack.h"
#include "Vampire.h"
#include "Medusa.h"
#include "HarryPotter.h"
int aChoice=0;int bChoice= 0;int repeatChoice; int damageIncurred;
int playerAscore=0;
int playerBscore=0;

int pAMenu();
Utilities menu;

void displayTournResults();

int main() {

    do{  //call menu at the start of the game, the menu should display 2 choices for user

//pointers used in the main program that will be deleted later to reset them
/*************************************************/
        

        Character *charA;
        Character *charB;
        Character *attacker;
        Character *defender;

        Queue *teamAPtr = new Queue;
        Queue *teamBPtr = new Queue;
        Stack *loserList = new Stack;

/*************************************************/

         while (menu.playMenu() == 1) {


        /*************************************************************************
        *                              TEAM A SELECTION
        *************************************************************************/


        menu.playerAMenu();
        string cName=""; //holder for the user entered name

        //iterator
        int i = 0;
        // do while loop gathers all the fighters in the team
        do {
            cout << "Player A: For fighter number -> " << i + 1 << endl;
            aChoice = menu.fighterAMenu();
            cout << "Player A: Name for fighter number " << i + 1 <<"? (no spaces)"<< endl;
            //determine character type
            //choose character and enter it in the list
            if (aChoice == 1) {
                Barbarian *b = new Barbarian;
                //get name from user
                cin >> cName;
                b->setName(cName);
                //add to the back of the list so that the first added will be first to fight
                teamAPtr->enqueue(b);
                //clear the buffer
                cin.ignore();

            }else if(aChoice==2){
                BlueMen *bM =new BlueMen;
                //get name from user
                cin >> cName;
                bM->setName(cName);
                //add to the back of the list so that the first added will be first to fight
                teamAPtr->enqueue(bM);
                //clear the buffer
                cin.ignore();

            }else if(aChoice==3){
                HarryPotter *hp = new HarryPotter;
                cin >> cName;
                hp->setName(cName);
                //add to the back of the list so that the first added will be first to fight
                teamAPtr->enqueue(hp);
                //clear the buffer
                cin.ignore();

            }else if(aChoice == 4){
                Medusa *m = new Medusa;
                cin >> cName;
                m->setName(cName);
                //add to the back of the list so that the first added will be first to fight
                teamAPtr->enqueue(m);
                //clear the buffer
                cin.ignore();

            }else if(aChoice==5){
                Vampire *v = new Vampire;
                cin >> cName;
                v->setName(cName);
                //add to the back of the list so that the first added will be first to fight
                teamAPtr->enqueue(v);
                //clear the buffer
                cin.ignore();
            }
            //increment the iterator up one
            i++;
        } while (i < (menu.getFighterNumA()));

     /*************************************************************************
     *                              TEAM B SELECTION
     * ***********************************************************************/

        menu.playerBMenu();
        string cBName="";//holder for the user entered name
        int j=0;
        do{
            cout << "Player B: For fighter number -> " << i + 1 << endl;
            bChoice = menu.fighterAMenu();
            cout << "Player B: Name for fighter number " << i + 1 <<"? (no spaces)"<< endl;

            //determine character type
            //choose character and enter it in the list
            if (bChoice == 1) {
                Barbarian *b = new Barbarian;
                //get name from user
                cin >> cBName;
                b->setName(cBName);
                //add to the back of the list so that the first added will be first to fight
                teamBPtr->enqueue(b);
                //clear the buffer
                cin.ignore();

            }else if(bChoice==2){
                BlueMen *bM =new BlueMen;
                //get name from user
                cin >> cBName;
                bM->setName(cBName);
                //add to the back of the list so that the first added will be first to fight
                teamBPtr->enqueue(bM);
                //clear the buffer
                cin.ignore();

            }else if(bChoice==3){
                HarryPotter *hp=new HarryPotter;
                cin >> cBName;
                hp->setName(cBName);
                //add to the back of the list so that the first added will be first to fight
                teamBPtr->enqueue(hp);
                //clear the buffer
                cin.ignore();

            }else if(bChoice ==4){
                Medusa *m= new Medusa;
                cin >> cBName;
                m->setName(cBName);
                //add to the back of the list so that the first added will be first to fight
                teamBPtr->enqueue(m);
                //clear the buffer
                cin.ignore();

            }else if(bChoice==5){
                Vampire *v=new Vampire;
                cin >> cBName;
                v->setName(cBName);
                //add to the back of the list so that the first added will be first to fight
                teamBPtr->enqueue(v);
                //clear the buffer
                cin.ignore();
            }

            j++;
        }while (j < (menu.getFighterNumB()));
             while (teamAPtr->isEmpty()==false && teamBPtr->isEmpty()==false) {

     /*************************************************************************
     *                             ROUNDS OF COMBAT
     ************************************************************************/
                 double round=.5;//keeps track of which round
                 /* make a pointer that also points to the first character in the node.
                 * that new pointer (charA will be used in the following gameplay)*/
                 charA=teamAPtr->getFront();
                 charB=teamBPtr->getFront();

                 //use new attacker/defener pointers for inside of the battle
                 attacker=charA;
                 defender=charB;
                 //general combat info display
                 while (attacker->getStrengthPoints()>0 && defender->getStrengthPoints()>0) {

                     //formats output from character for round by round display
                     cout << "           ROUND: "<<round<<" STARTS"<< endl;
                     cout << " ====================================  " << endl;
                     cout << " " << endl;
                     cout << "              " << attacker->getName()<<" ATTACKS!" << endl;
                     cout << " " << endl;
                     int attackPts=0;
                     attackPts=attacker->Attack(defender);
                     cout << "              " << endl;
                     cout << " " << endl;
                     cout << "              " << defender->getName()<<" DEFENDS!" << endl;
                     cout << " " << endl;
                     damageIncurred=defender->Defense(attacker, attackPts);
                     cout << " " << endl;

                     cout << "                  " << endl;
                     cout << " =====================================  " << endl;


                     if (charA->getStrengthPoints()<=0){
                         cout<<"            BATTLE HAS ENDED "<<endl;
                         cout<<"                SUMMARY: "<<endl;
                         cout<<"               "<<charA->getName()<<":"<<" DIED!"<<endl;
                         playerBscore=playerBscore+2;
                         cout<<"    "<<charB->getName()<<":";
                         cout<<" After recovery, strength: "<<charB->recover()<<endl;
                         playerAscore=playerAscore-1;
                         cout<<"   "<<endl;
                         cout<<"           ** TEAM B WINS **"<<endl;
                         cout<<"                 SCORE: "<<endl;
                         cout<<"     TEAM A: "<<playerAscore<<"pts     TEAM B: "<<playerBscore<<"pts "<<endl;
                         cout << " =====================================  " << endl;
                         cout<<"   "<<endl;
                         loserList->push(charA);
                         teamAPtr->dequeue();

                     }else if (charB->getStrengthPoints()<=0){
                         cout<<"            BATTLE HAS ENDED "<<endl;
                         cout<<"                SUMMARY: "<<endl;
                         cout<<"               "<<charB->getName()<<":"<<" DIED!"<<endl;
                         playerAscore=playerAscore+2;
                         cout<<"    "<<charA->getName()<<":";
                         cout<<" After recovery, strength: "<<charA->recover()<<endl;
                         playerBscore=playerBscore-1;
                         cout<<"   "<<endl;
                         cout<<"           ** TEAM A WINS **"<<endl;
                         cout<<"                 SCORE: "<<endl;
                         cout<<"     TEAM A: "<<playerAscore<<"pts    TEAM B: "<<playerBscore<<"pts "<<endl;
                         cout << " =====================================  " << endl;
                         cout<<"   "<<endl;
                         loserList->push(charB);
                         teamBPtr->dequeue();
                     }

                     //if both players survive, make the previous defender into the attacker
                     if (attacker->getStrengthPoints()>0 && defender->getStrengthPoints()>0){
                         //swap characters
                         Character *temp;
                         temp=attacker;
                         attacker= defender;
                         defender= temp;

                         //increment rounds by 1/2
                         round=round + .5;
                     }
                 }
             }
             displayTournResults();
             playerBscore=0;
             playerAscore=0;
             if (menu.showLosers()==1){
                 cout<<"** Losers ** "<<endl;
                 loserList->revPrintStack();
                 break;
             }else {
                 cout<<"Quitting "<<endl;
             }
                    break;
         }

    //find out if the user wants to play again

   repeatChoice = pAMenu();

//attempting to free all memory via deleting pointer and deletion functions
/*************************************************/
        charA= nullptr;
        charB= nullptr;
        attacker = nullptr;
        defender= nullptr;

        teamAPtr->removeNodes();
        teamBPtr->removeNodes();
        loserList->removeSNodes();

        delete teamAPtr ;
        delete teamBPtr;
        delete loserList;

/*************************************************/

} while (repeatChoice == 1);


    return 0;
}

/*********************************************************************
** Function: PAMenu()
** Purpose: Used in a do while loop in the main to see if the user
 * wants to play the game again.
** Arguments|Preconditions: None
** Return Type: None
*********************************************************************/

int pAMenu(){
    Utilities menuTwo;
    //variables used in input validation
    int pAChoice= 1;
    bool temp = 0;
    string inputStr = "";
    //display menu
    cout<<"                                        "<<endl;
    cout<<" ============ PLAY AGAIN? ============  "<<endl;
    cout<<"                                        "<<endl;
    cout<<"  [1] Play again                        "<<endl;
    cout<<"  [2] Quit                              "<<endl;
    cout<<"                                        "<<endl;
    cout<<" ====================================== "<<endl;
    cout<<"  Enter your selection:"<<endl;
    //input validation: takes in choice as a string
    while (!temp || (pAChoice != 1 && pAChoice !=2)){
        getline(cin, inputStr );
        //processes string through validation function and returns bool
        temp = menuTwo.inputValid(inputStr);
        if(temp){
            //converts to int if no letters detected
            pAChoice = stoi(inputStr);
        }
        if(pAChoice != 1 && pAChoice != 2){
            //error msg if int is out of range
            cout << "Enter a 1 or 2. Please try again: " << endl;
        }
    }
    switch (pAChoice) {
        case 1:
        {
            cout<< "You have selected [1]."<<endl;
            pAChoice= 1;
        }
            break;
        case 2:
        {
            cout<< "You have selected [2] QUIT."<<endl;
            pAChoice= 0;
        }
            break;
    }
    return pAChoice;
}//end function



/*********************************************************************
** Function: displayTournResults()
** Purpose: Displays the results of the tournament
** Arguments|Preconditions: None
** Return Type: None
*********************************************************************/

void displayTournResults(){

        cout<< " =====================================  " << endl;

        cout<< " " << endl;

        cout<< "           TOURNAMENT ENDED!" << endl;
        playerBscore=playerBscore+2;
        playerAscore=playerAscore-2;
    /*************************************  PLAYER B WINS  *****************************************/
    if (playerBscore>playerAscore){

        cout<<"   "<<endl;
        cout<<"           ** TEAM B WINS **"<<endl;
        cout<<"   "<<endl;
        cout<<"                 SCORE: "<<endl;
        cout<<"     TEAM A:"<<playerAscore<<"pts     TEAM B: "<<playerBscore<<"pts "<<endl;

        /*************************************  PLAYER B WINS  *****************************************/
    }else if (playerAscore>playerBscore){
        cout<<"   "<<endl;
        cout<<"           ** TEAM A WINS **"<<endl;
        cout<<"                 SCORE: "<<endl;
        cout<<"     TEAM A: "<<playerAscore<<"pts     TEAM B: "<<playerBscore<<"pts "<<endl;
        /*************************************  TIE  *****************************************/
    }else if (playerAscore==playerBscore){
        cout<<"           ** TIE **"<<endl;
        cout<<"                 SCORE: "<<endl;
        cout<<"     TEAM A: "<<playerAscore<<"pts     TEAM B: "<<playerBscore<<"pts "<<endl;

    }


}

