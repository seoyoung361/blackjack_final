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

//card array controllers -------------------------------

//mix the card sets and put in the array
int mixCardTray(void) {
	
	int i, j, k;
	int card_type=101; // 101~113 is H, 201~213 is D, 301~313 is S, 401~413 is C
	int temp=card_type; //temporary space to put card in the tray
	int index=rand()%(N_CARDSET*52); // 
	
	for(i=0;i<4;i++){
		temp=card_type; //temporary space to put card in the tray
		
		for(k=0;k<N_CARDSET;k++){ //
			
			for(j=0;j<13;j++){
				index=rand()%(N_CARDSET*52); // 
				
				while(CardTray[index]!=0){
					index=rand()%(N_CARDSET*52); //
				}
				CardTray[index]=temp;
				temp++;
			}
		}
		card_type+= 100; //+100 to put next card type
	}
	

}

//get one card from the tray
int pullCard(void) {
	
	return CardTray[cardIndex++]; //get one card from cardtray. do 'cardIndex++' to get next card
	
}

