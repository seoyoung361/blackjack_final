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

int getAction() {
  char go_stop[5];
  printf("Action?(if go, input g /if stop, input s) : ");
  scanf("%s", &go_stop);
  //if player input go, return 1
  if (go_stop[0] == 'g'){
     return 1;
  }
  //if player input stop, return 0
  else if (go_stop[0] == 's'){
     return 0;
  }
}

//computer player and dealer 's action function 
int computer_getAction(int user){
 
  if (cardSum[user] < 17)
     return 1;
  else
     return 0;
}


void printUserCardStatus(int user, int cardcnt) {
  int i;
 // get user and separate you, dealer, player
  if (user == 0)
     printf("YOU");
  else if (user == n_user)
     printf("dealer");
  else
     printf("player%d", user);
  printf("\t-> card : ");
  for (i = 0; i < cardcnt; i++){
     printCard(cardhold[user][i]);
     printf(" ");
  }
  printf("\t ::: ");
}

//print dollar
void printUserDollarStatus(){
  int i;

  for (i = 0; i < n_user; i++){
     if (i == 0)
        printf("You : ");   
     else
        printf("player%d : ", i);

     printf("%d\n", dollar[i]);
  }
}



// calculate the card sum and see if : 1. under 21, 2. over 21, 3. blackjack
int calcStepResult(int user, int cardcnt) {
  int i;
  cardSum[user] = 0;
  //calculate player's cards
  for (i = 0; i < cardcnt; i++){
     //return cardnumber
     int real_num = getCardNum(cardhold[user][i]);
     //if A
     if (real_num == 1){
        //( pick 11)'s result is bigger than 21-> lose. so 1 is better
        if (cardSum[user] + 11 > 21)
           cardSum[user] += 1;
        else
           cardSum[user] += 11;
     }
     //J Q Kis all 10
     else if (real_num > 10){
        real_num = 10;
        cardSum[user] += real_num;
     }
     else{
        cardSum[user] += real_num;
     }
  }

  //if smaller than 21 return 1, if bigger than 2 return 2, if 21 return 3.
  if (cardSum[user] < 21){
     printf("(%d)", cardSum[user]);
     return 1;
  }
  else if (cardSum[user] > 21){
     printf("(%d)", cardSum[user]);
     return 2;
  }
  else{
     printf("(%d, blackjack)", cardSum[user]);
     return 3;
  }
  
  
}
