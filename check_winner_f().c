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

int checkWinner(void) {
  int i;
  //whose final winner
  int max_dollar_player = 0;
  for (i = 1; i < n_user; i++){
     //if another player has more money, reset the max
     if (dollar[max_dollar_player] < dollar[i]){
        max_dollar_player = i;
     }
  }
  // final result
  printf("\n------------------ FINAL RESULT --------------------------\n");
  printUserDollarStatus();
  printf("\n------------------ FINAL WINNER --------------------------\n");
  if (max_dollar_player == 0)
     printf("\n\t\t     is YOU\n");
  else
     printf("\n\t\t     player%d \n", max_dollar_player);

  printf("\n-----------------------------------------------------------\n");
}

