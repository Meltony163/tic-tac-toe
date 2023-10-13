#include<stdio.h>
#include"../../MemoryManagement/memory_management.h"
#include"../../Logic/logic.h"
#include"../../UserInterface/input_output.h"
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
    printf("Enter Your Name:");
    scanf(" %49[^\n]", Loc_ptr_pPlayer1);
    MEMN_vResizePlayerName(&Loc_ptr_pPlayer1);
	char Loc_cPosition;
	bool flag=True;
    char board[3][3];
    LOGC_vInitBoard(board);
	board[2][2]='X';
	IOUT_vPrintBoard(board);
	IOUT_vPrintTurn(Loc_ptr_pPlayer1,'O');
    if(IOUT_cTakeInput(board,'O')=='0')
	{
		return;
	}
	if(board[1][1]=='O')
	{
		board[0][0]='X';
		for(int i=0;i<6;i++)
		{
			if(flag)
			{
				IOUT_vPrintBoard(board);
				IOUT_vPrintTurn(Loc_ptr_pPlayer1,'O');
				if(IOUT_cTakeInput(board,'O')=='0')
				{
					return;
				}
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
				IOUT_vPrintBoard(board);
				printf("HAHA I WON\n");
				return;
			}
			flag=!flag;
		}
		printf("DRAW\n");
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
		IOUT_vPrintBoard(board);
		IOUT_vPrintTurn(Loc_ptr_pPlayer1,'O');
		if(IOUT_cTakeInput(board,'O')=='0')
		{
			return;
		}
		if(LOGC_cAlmostWinX(board)!='N')
		{
			LOGC_vPutInput(board,'X',LOGC_cAlmostWinX(board));
			IOUT_vPrintBoard(board);
			printf("HAHA I WON\n");
			return;
		}
		LOGC_vPutInput(board,'X',Loc_cSecond);
		IOUT_vPrintBoard(board);
		IOUT_vPrintTurn(Loc_ptr_pPlayer1,'O');
		if(IOUT_cTakeInput(board,'O')=='0')
		{
			return;
		}
		LOGC_vPutInput(board,'X',LOGC_cAlmostWinX(board));
		IOUT_vPrintBoard(board);
		printf("HAHA I WON\n");
		return;
	}
}

/*
Player X
System O
*/
void MOSP_vEasyMode()
{
	char *Loc_ptr_pPlayer1;
    MEMN_vAllocatePlayerName(&Loc_ptr_pPlayer1);
    printf("Enter Player1 Name:");
    scanf(" %49[^\n]", Loc_ptr_pPlayer1);
    MEMN_vResizePlayerName(&Loc_ptr_pPlayer1);
	bool flag=True;
    char board[3][3];
    LOGC_vInitBoard(board);
	for(int i=0;i<9;i++)
	{
		if(flag)
		{
			IOUT_vPrintBoard(board);
			IOUT_vPrintTurn(Loc_ptr_pPlayer1,'X');
			if(IOUT_cTakeInput(board,'X')=='0')
			{
				return;
			}
		}
		else
		{
			LOGC_vPutInput(board,'O',LOGC_cRandomPosition(board));
		}
		if(LOGC_Win(board))
		{
			if(flag)
			{
				IOUT_vPrintBoard(board);
				printf("%s won\n",Loc_ptr_pPlayer1);
				return;
			}
			else
			{
				IOUT_vPrintBoard(board);
				printf("HAHA I WON\n");
				return;
			}
		}
		flag=!flag;
	}
	IOUT_vPrintBoard(board);
	printf("DRAW\n");
	return;
}
