#include <stdio.h>
#include <stdlib.h>

#define N_CARDSET			1
#define N_CARD				52
#define N_DOLLAR			50


#define N_MAX_CARDNUM		13
#define N_MAX_USER			5
#define N_MAX_CARDHOLD		10
#define N_MAX_GO			17
#define N_MAX_BET			5

#define N_MIN_ENDCARD		30


//card tray object
int CardTray[N_CARDSET*N_CARD];     //extern 선언해야하는가 
int cardIndex = 0;							


//player info
int dollar[N_MAX_USER];						//dollars that each player has
extern int n_user;									//number of users


//play yard information
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//cards that currently the players hold
int cardSum[N_MAX_USER];					//sum of the cards
int bet[N_MAX_USER];						//current betting 
int gameEnd = 0; 							//game end flag
int cardholdnum[N_MAX_USER];                //card that user hold at the final
int playerwin[N_MAX_USER];                  //express user win or not          

//some utility functions

//get an integer input from standard input (keyboard)
//return : input integer value
//         (-1 is returned if keyboard input was not integer)
int getIntegerInput(void) {
    int input, num;
    
    num = scanf("%d", &input);
    fflush(stdin);
    if (num != 1) //if it fails to get integer
        input = -1;
    
    return input;
}

int main(int argc, char *argv[]) {
	int roundIndex = 0;
	int max_user;
	int i;
	
	srand((unsigned)time(NULL));
	
	//set the number of players
	configUser();


	//Game initialization --------
	//1. players' dollar
	
	//2. card tray
	mixCardTray();



	//Game start --------
	do {
		
		roundIndex++;
		printf("\n----------ROUND:%d---------------------\n", roundIndex);
		printf("\n----------BETTING STEP----------------\n");
		
		betDollar();
		offerCards(); //1. give cards to all the players
		
		printCardInitialStatus();
		printf("\n------------------ GAME start --------------------------\n");
		
		//each player's turn
		for (i=0;i<=n_user;i++) //each player
		{   cardholdnum[i]=2;//player's initial cardholdnum
		    int keep_going; //
			while (keep_going) //do until the player dies or player says stop
			{
				//print current card status printUserCardStatus();
				 printUserCardStatus(i, cardholdnum[i]);
				//check the card status ::: calcStepResult()
				int check_cardsum=calcStepResult(i,cardholdnum[i]);
				//if sum is over 21, player is over
				if(check_cardsum==2){
					printf("\n over 21, game over");
					keep_going=0;
					break;
				}
				//if blackjack, win
				else if(check_cardsum==3){
					printf("\nBLACKJACK\n");
					keep_going=0;
					break;
				}
				printf("\n");
				//GO? STOP? ::: getAction()
				int check_gostop; 
				//devide 'you' case and computer case
				if(i==0){
					check_gostop=getAction();
				}
				else{
					check_gostop=computer_getAction(i);
				}
				//if go, get one more card 
				if (check_gostop==1){
					cardhold[i][cardholdnum[i]++]==pullCard();
				}
				//check if the turn ends or not
				//if go, game continues; if stop, get out form while
				keep_going=check_gostop;
			}
		}
		printf("\n---------------Round %d result-----------------\n",roundIndex);
		//result
		checkResult();
	} while (gameEnd == 0);
	
	checkWinner();
	
	
	return 0;
}
