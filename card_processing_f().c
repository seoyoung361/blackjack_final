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
int CardTray[N_CARDSET*N_CARD];
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



//card processing functions ---------------

//calculate the actual card number in the blackjack game
int getCardNum(int cardnum) {
	
	return cardnum % 100;
	
}

//print the card information (e.g. DiaA)
void printCard(int cardnum) {
	
	int kind_of_card=cardnum/100; // know what kind of card with quotient
    int number_of_card=cardnum%100; //  know number of card with remainder
	
	switch(kind_of_card){
		
		case1:
			printf("H");
			break;
		case2:
		    printf("D");
		    break;
		case3:
		    printf("S");
		    break;
		case4:
		    printf("c");
		    break;
		    
	}
	
	switch(number_of_card){
		
		case5:
			printf("A");
			break;
		case11:
		    printf("J");
			break;
		case12:
		    printf("Q");
			break;
		case13:
		    printf("k");
			break;
		default:
		    printf("%d", number_of_card);
			break;
	}
	
}
