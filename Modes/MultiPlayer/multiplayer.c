#include<stdio.h>
#include"../../MemoryManagement/memory_management.h"
#include"../../Logic/logic.h"
#include"../../UserInterface/input_output.h"
enum BOOL{False,True};
typedef enum BOOL bool;
void MOMT_vMultiplayerMode()
{
    char board[3][3];
    LOGC_vInitBoard(board);
    bool flag=True;
    char *Loc_ptr_pPlayer1;
    char *Loc_ptr_pPlayer2;
    MEMN_vAllocatePlayerName(&Loc_ptr_pPlayer1);
    MEMN_vAllocatePlayerName(&Loc_ptr_pPlayer2);
	system("@cls||clear");
    printf("Enter Player1 Name:");
    scanf(" %49[^\n]", Loc_ptr_pPlayer1);
    MEMN_vResizePlayerName(&Loc_ptr_pPlayer1);
    printf("Enter Player2 Name:");
    scanf(" %49[^\n]", Loc_ptr_pPlayer2);
    MEMN_vResizePlayerName(&Loc_ptr_pPlayer2);
    for(int i=0;i<9;i++)
    {
		IOUT_vPrintBoard(board);
        if(flag)
        {
			IOUT_vPrintTurn(Loc_ptr_pPlayer1,'X');
			if(IOUT_cTakeInput(board,'X')=='0')
			{
				return;
			}
            flag=!flag;
        }
        else
        {
			IOUT_vPrintTurn(Loc_ptr_pPlayer2,'O');
			if(IOUT_cTakeInput(board,'O')=='0')
			{
				return;
			}
            flag=!flag;
        }
        if(LOGC_Win(board))
        {
			IOUT_vPrintBoard(board);
            if(flag)
            {
                printf("%s won\n",Loc_ptr_pPlayer2);
                return;
            }
            else
            {
                printf("%s won\n",Loc_ptr_pPlayer1);
                return;
            }
        }
    }
    printf("DRAW\n");
}
