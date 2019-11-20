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

int checkResult() {
  int i;
  //print dealer, you, player's result
  printUserCardStatus(n_user, cardholdnum[n_user]);
  calcStepResult(n_user, cardholdnum[n_user]);
  printf("\n");
  for (i = 0; i < n_user; i++){
     printUserCardStatus(i, cardholdnum[i]);
     calcStepResult(i, cardholdnum[i]);
     printf("\n");
  }
  
  for (i = 0; i < n_user; i++){
     //case1: blackjack between you or player
     if (cardSum[i] == 21){
        dollar[i] += (bet[i]*2); //if it's blackjack, get (bet*2)
        playerwin[i] = 1;
     }
     //case2: over 21 between you and player
     else if (cardSum[i] > 21){
        dollar[i] -= bet[i]; //lose betting dollar
        playerwin[i] = 2;
     }
  }
  for (i = 0; i < n_user; i++){
     //give a pass if players win or lose is decided
     if (playerwin[i] == 1 || playerwin[i] == 2)
        continue;
     else{
        //case3: if dealer sum is blackjack
        if (cardSum[n_user] == 21){
           dollar[i] -= bet[i];
           playerwin[i] = 2;
        }
        //case4: if dealer sum is bigger than 21
        else if (cardSum[n_user] > 21){
           dollar[i] += (bet[i] * 2);
           playerwin[i] = 1;
        }
        //case5: if usersum >=dealersum
        else if(cardSum[n_user] <= cardSum[i]){
           dollar[i] += (bet[i] * 2);
           playerwin[i] = 1;
        }
        //case6: if user sum < dealer sum
        else{
           dollar[i] -= bet[i];
           playerwin[i] = 2;
        }
     }
  }
  //return win or not
  printf("=> YOU - ");
  if (playerwin[0] == 1)
     printf("win,");
  else
     printf("lose,");
  for (i = 1; i < n_user; i++){
     printf("player %d - ", i);
     if (playerwin[i] == 1)
        printf("win");
     else
        printf("lose");
     
     if (i != (n_user - 1)){
        printf(",");
     }
  }
  printf("\n");

  //reset win or not
  for (i = 0; i < n_user; i++){
     playerwin[i] = 0;
  }
  
  //check the game is end
	//1. card if end 
  if (cardIndex == N_MIN_ENDCARD){
     gameEnd = 1;
  }
  //2. player's bankrupt
  else{
     for (i = 0; i < n_user; i++){
        if (dollar[i] <= 0){
           gameEnd = 1;
           break;
        }
     }
  }

}

