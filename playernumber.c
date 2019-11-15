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

int n_user;

//player settiing
int configUser(void) {
	
	do
	{
	printf("Input the number of players(MAX:5): \n");
	scanf("%d", &n_user);
	
	if (n_user>=6)
		printf("Too many players!"); //
	 
	else if (n_user<=0)
		printf("Too little players!");
	
	else
		return n_user;
    }
	
	while(n_user>=6 || n_user <= 0);
	
		
	
}
