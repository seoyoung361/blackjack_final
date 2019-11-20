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

//playing game functions -----------------------------

//player settiing
int configUser(void) {
  printf("Input the number of players (MAX 5) : ");
  scanf("%d", &n_user); 
  
  int i;
  for (i = 0; i < n_user; i++){
     dollar[i] = N_DOLLAR;
  }
}


//betting
int betDollar(void) {
  int i;
  printf("YOUR BETTING : ");
  int bet_dollar; 
  scanf("%d", &bet_dollar); 

  bet[0] = bet_dollar; //put my betting into arry 
  for (i = 1; i < n_user; i++){
     while (1){
        int bet_dollar = (rand() % N_MAX_BET) + 1; //from 1 to n_max_bet, decide players betting dollar  
        // not to bet over owned dollar
        if (bet_dollar <= dollar[i]){
           bet[i] = bet_dollar;
           break;
        }
     }
  }
}


//offering initial 2 cards
void offerCards(void) {
  int i;
  //1. give two card for each players
  for (i = 0; i<n_user; i++)
  {
     cardhold[i][0] = pullCard();
     cardhold[i][1] = pullCard();
  }
  //2. give two card for the operator
  cardhold[n_user][0] = pullCard();
  cardhold[n_user][1] = pullCard();

  return;
}

//print initial card status
void printCardInitialStatus(void) {
  int i;
  printf("dealer : ?, "); //dealer initial card 
  printCard(cardhold[n_user][1]);
  printf("\n");
  printf("³ª : "); // 'your' initial card 
  printCard(cardhold[0][0]);
  printf(", ");
  printCard(cardhold[0][1]);
  printf("\n");
  //player's initial card 
  for (i = 1; i < n_user; i++){
     printf("player%d : ", i);
     printCard(cardhold[i][0]);
     printf(", ");
     printCard(cardhold[i][1]);
     printf("\n");
  }
}
