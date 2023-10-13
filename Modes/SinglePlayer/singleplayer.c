#include<stdio.h>
#include"../../MemoryManagement/memory_management.h"
#include"../../Logic/logic.h"
#include"../../Output/output.h"
enum BOOL{False,True};
typedef enum BOOL bool;
/*
Player O
System X
*/
void MOSP_vHardMODE()
{
	char *Loc_ptr_pPlayer1;
    MEMN_vAllocatePlayerName(&Loc_ptr_pPlayer1);
    printf("Enter Player1 Name:");
    scanf(" %49[^\n]", Loc_ptr_pPlayer1);
    MEMN_vResizePlayerName(&Loc_ptr_pPlayer1);
	char Loc_cPosition;
	bool flag=True;
    char board[3][3];
    LOGC_vInitBoard(board);
	board[2][2]='X';
	OUT_vPrintBoard(board);
	OUT_vPrintTurn(Loc_ptr_pPlayer1);
    LOGC_vTakeInput(board,'O');
	if(board[1][1]=='O')
	{
		board[0][0]='X';
		for(int i=0;i<6;i++)
		{
			if(flag)
			{
				OUT_vPrintBoard(board);
				OUT_vPrintTurn(Loc_ptr_pPlayer1);
				LOGC_vTakeInput(board,'O');
			}
			else
			{
				Loc_cPosition=LOGC_cAlmostWinX(board);
				if(Loc_cPosition!='N')
				{
					LOGC_vPutInput(board,'X',Loc_cPosition);
				}
				else
				{
					Loc_cPosition=LOGC_cAlmostWinO(board);
					LOGC_vPutInput(board,'X',Loc_cPosition);
				}
			}
			if(LOGC_Win(board))
			{
				OUT_vPrintBoard(board);
				printf("HAHA I WON");
				return;
			}
			flag=!flag;
		}
		printf("DRAW");
	}
	else
	{
		char Loc_cFirst;
		char Loc_cSecond;
		if((board[0][0]=='O')||(board[0][1]=='O')||(board[0][2]=='O'))
		{
			Loc_cSecond='7';
			if(board[0][0]=='O')
			{
				Loc_cFirst='3';
			}
			else
			{
				Loc_cFirst='1';
			}
		}
		else if((board[1][0]=='O')||(board[1][2]=='O'))
		{
			Loc_cFirst='7';
			Loc_cSecond='5';
		}
		else if((board[2][1]=='O')||(board[2][0]=='O'))
		{
			Loc_cFirst='3';
			Loc_cSecond='1';
		}
		LOGC_vPutInput(board,'X',Loc_cFirst);
		OUT_vPrintBoard(board);
		OUT_vPrintTurn(Loc_ptr_pPlayer1);
		LOGC_vTakeInput(board,'O');
		if(LOGC_cAlmostWinX(board)!='N')
		{
			LOGC_vPutInput(board,'X',LOGC_cAlmostWinX(board));
			OUT_vPrintBoard(board);
			printf("HAHA I WON");
			return;
		}
		LOGC_vPutInput(board,'X',Loc_cSecond);
		OUT_vPrintBoard(board);
		OUT_vPrintTurn(Loc_ptr_pPlayer1);
		LOGC_vTakeInput(board,'O');
		LOGC_vPutInput(board,'X',LOGC_cAlmostWinX(board));
		OUT_vPrintBoard(board);
		printf("HAHA I WON");
		return;
	}
}
