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


//card array controllers -------------------------------

//mix the card sets and put in the array
int mixCardTray(void) {
  int i, j, k;
  int card_type = 101; //101~113 is H, 201~213 is D, 301~313 is  S,  401~413 is C.

  for (i = 0; i < 4; i++){
     int temp = card_type; //temporary space to put card in the tray
     for (k = 0; k < N_CARDSET; k++){ //control number of putting in depend on N_CARDSET
        for (j = 0; j < 13; j++){
           int index = rand() % (N_CARDSET * 52); // decide location with rand()
           while (CardTray[index] != 0){
              index = rand() % (N_CARDSET * 52); // when card is already located in index
           }
           CardTray[index] = temp;
           temp++;
        }
     }
     card_type += 100; 
  }
}

//get one card from the tray
int pullCard(void) {
  return CardTray[cardIndex++]; //get one card from cardtray. do 'cardIndex++' to get next card
}

