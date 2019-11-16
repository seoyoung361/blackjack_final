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

//betting
int betDollar(void) {
	
	int i;
	int bet_dollar;
	
	printf("---BETTING STEP---\n -> your betting(total:$%d):", )
	scanf("%d",&bet_dollar);// input betting dollar
	
	bet[0]=bet_dollar; // put betting dollar into arry
    for(i=1;i<n_user;i++){
    	bet[i]=(rand()%N_MAX_BET)+1; //from 1 to N_MAX_BET, bet players dollar randomly
	}

}

