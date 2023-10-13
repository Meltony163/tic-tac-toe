#include<stdio.h>
/**
 *brief :Use this function to print Initial list.
 */
void IOUT_vPrintList(short int cpy_nFlag)
{
	system("@cls||clear");
	if(cpy_nFlag)
	{
		printf("Wrong Choice\n");
	}
    printf("Choose an option\n");
    printf("1:Multiplayer Mode\n");
    printf("2:Singleplayer Mode\n");
    printf("3:EXIT\n");
    printf("Your Choice:");
}
/**
 *brief :Use this function to print board.
 *@param cpy_aBoard:2d array represinting board.
 */
void IOUT_vPrintBoard(char cpy_aBoard[][3])
{
	system("@cls||clear");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(j!=2)
            {
                printf(" %c |",cpy_aBoard[i][j]);
            }
            else
            {
                printf(" %c ",cpy_aBoard[i][j]);
            }
        }
        printf("\n");
    }
}
/**
 *brief :Use this function to print the name of the player.
 *@param *ptr_aName:char pointer represinting the name of player.
 */
void IOUT_vPrintTurn(char *ptr_aName,char cpy_cSymbol)
{
    printf("%s's(%c) turn\n",ptr_aName,cpy_cSymbol);
    printf("Choose Valid Place or choose 0 to exit:");
}
char IOUT_cTakeInput(char cpy_aBoard[][3],char cpy_cValue)
{
	char Loc_cPlace;
	scanf(" %c",&Loc_cPlace);
	if(Loc_cPlace=='0')
	{
		return '0';
	}
	while(cpy_aBoard[(int)((int)(Loc_cPlace-'1')/3)][(int)(Loc_cPlace-'1')%3]!=Loc_cPlace)
	{
		if(Loc_cPlace=='0')
		{
			return '0';
		}
		printf("Wrong Place\n");
		printf("Enter Valid Place:");
		scanf(" %c",&Loc_cPlace);
	}
	cpy_aBoard[(int)((int)(Loc_cPlace-'1')/3)][(int)(Loc_cPlace-'1')%3]=cpy_cValue;
	return Loc_cPlace;
}
void IOUT_vSinglePlayerMode(short int cpy_nFlag)
{
	system("@cls||clear");
	if(cpy_nFlag)
	{
		printf("Wrong Choice\n");
	}
	printf("Choose an option\n");
    printf("1:Hard Mode (Impossiple to win)\n");
    printf("2:Easy Mode\n");
    printf("3:Main List\n");
	printf("Your Choice:");
}
void IOUT_vPlayAgain(short int cpy_nFlag)
{
	if(cpy_nFlag)
	{
		printf("Wrong Choice\n");
	}
    printf("enter 1 to play again or enter 0 to go to main list:");
}