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

