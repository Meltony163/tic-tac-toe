#include<stdio.h>
#include"../../MemoryManagement/memory_management.h"
#include"../../Logic/logic.h"
#include"../../Output/output.h"
enum BOOL{False,True};
typedef enum BOOL bool;
/*
Player1 X
Player2 O
*/
void MOMT_vMultiplayerMode()
{
    short int Loc_nC=0;
    char board[3][3];
    LOGC_vInitBoard(board);
    bool flag=True;
    char *Loc_ptr_pPlayer1;
    char *Loc_ptr_pPlayer2;
    MEMN_vAllocatePlayerName(&Loc_ptr_pPlayer1);
    MEMN_vAllocatePlayerName(&Loc_ptr_pPlayer2);
    printf("Enter Player1 Name:");
    scanf(" %49[^\n]", Loc_ptr_pPlayer1);
    MEMN_vResizePlayerName(&Loc_ptr_pPlayer1);
    printf("Enter Player2 Name:");
    scanf(" %49[^\n]", Loc_ptr_pPlayer2);
    MEMN_vResizePlayerName(&Loc_ptr_pPlayer2);
    for(int i=0;i<9;i++)
    {
		OUT_vPrintBoard(board);
        if(flag)
        {
			OUT_vPrintTurn(Loc_ptr_pPlayer1);
            LOGC_vTakeInput(board,'X');
            flag=!flag;
        }
        else
        {
			OUT_vPrintTurn(Loc_ptr_pPlayer2);
            LOGC_vTakeInput(board,'O');
            flag=!flag;
        }
        if(LOGC_Win(board))
        {
			OUT_vPrintBoard(board);
            if(flag)
            {
                printf("%s won",Loc_ptr_pPlayer2);
                return;
            }
            else
            {
                printf("%s won",Loc_ptr_pPlayer1);
                return;
            }
        }
    }
    printf("DRAW");
}
