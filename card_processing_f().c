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
extern int CardTray[N_CARDSET*N_CARD];     //extern 선언해야하는가 
extern int cardIndex ;							


//player info
extern int dollar[N_MAX_USER];						//dollars that each player has
extern int n_user;									//number of users


//play yard information
extern int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//cards that currently the players hold
extern int cardSum[N_MAX_USER];					//sum of the cards
extern int bet[N_MAX_USER];						//current betting 
extern int gameEnd ; 							//game end flag
extern int cardholdnum[N_MAX_USER];                //card that user hold at the final
extern int playerwin[N_MAX_USER];                  //express user win or not          


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
  int kind_of_card = cardnum / 100; // know what kind of card with quotient
  switch (kind_of_card){
  case 1 :
     printf("H");
     break;
  case 2:
     printf("D");
     break;
  case 3:
     printf("S");
     break;
  case 4:
     printf("C");
     break;
  }
  int number_of_card = cardnum % 100; //  know number of card with remainder
  switch (number_of_card){
  case 1:
     printf("A");
     break;
  case 11:
     printf("J");
     break;
  case 12:
     printf("Q");
     break;
  case 13:
     printf("K");
     break;
  default:
     printf("%d", number_of_card);
     break;
  }
}



