#include<stdio.h>
/**
 *brief :Use this function to print Initial list.
 */
void OUT_vPrintList()
{
	system("@cls||clear");
    printf("Tic-Tac-Toe\n");
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
void OUT_vPrintBoard(char cpy_aBoard[][3])
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
void OUT_vPrintTurn(char *ptr_aName)
{
    printf("%s's turn\n",ptr_aName);
    printf("Choose Valid Place:");
}
