#include<stdio.h>
#include<stdlib.h>
#include"../UserInterface/input_output.h"

/**
 * @file logic.h
 * @author Moamen eltony
 * @brief This file contains functions that deal with logic of the game.
 * @version 0.1
 * @date 2023-11-10
 */
 
 
enum BOOL{False,True};
typedef enum BOOL bool;

/**
 *brief :Use this function to put numbers on the board.
 *@param cpy_aBoard:2d array represinting game board
 */
 
void LOGC_vInitBoard(char cpy_aBoard[][3])
{
	char temb='1';
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cpy_aBoard[i][j]=temb;
			temb++;
		}
	}
}

/**
 *brief :Use this function to check if someone wins.
 *@param cpy_aBoard:2d array represinting game board
 */
 
int LOGC_Win(char cpy_aBoard[][3])
{
	bool flag=True;
	for(int i=0;i<3;i++)
	{
		flag=True;
		for(int j=1;j<3;j++)
		{
			if(cpy_aBoard[i][j]!=cpy_aBoard[i][j-1])
			{
				flag=False;
				break;
			}
		}
		if(flag)
		{
			return 1;
		}
	}
	for(int i=0;i<3;i++)
	{
		flag=True;
		for(int j=1;j<3;j++)
		{
			if(cpy_aBoard[j][i]!=cpy_aBoard[j-1][i])
			{
				flag=False;
				break;
			}
		}
		if(flag)
		{
			return 1;
		}
	}
	if((cpy_aBoard[0][0]==cpy_aBoard[1][1])&&(cpy_aBoard[2][2]==cpy_aBoard[1][1]))
	{
		return 1;
	}
	if((cpy_aBoard[0][2]==cpy_aBoard[1][1])&&(cpy_aBoard[2][0]==cpy_aBoard[1][1]))
	{
		return 1;
	}
	return 0;
}

/**
 *brief :Use this function to put X or Y in position on board
 *@param cpy_aBoard:2d array represinting game board
 *@param cpy_cValue:Value to put in board (X or Y)
 *@param cpy_cPosition:locatioin in board
 */
 
void LOGC_vPutInput(char cpy_aBoard[][3],char cpy_cValue,char cpy_cPosition)
{
	cpy_aBoard[(int)((int)(cpy_cPosition-'1')/3)][(int)(cpy_cPosition-'1')%3]=cpy_cValue;
}

/**
 *brief :Use this function to check if there is a position where I put O and win.
 *@param cpy_aBoard:2d array represinting game board
 *@return :char representing the location or N if there is not
 */
 
char LOGC_cAlmostWinO(char cpy_aBoard[][3])
{
	char Loc_cPosition;
	short int c=0;
	bool flag=False;
	for(int i=0;i<3;i++)
	{
		c=0;
		flag=True;
		for(int j=0;j<3;j++)
		{
			if(cpy_aBoard[i][j]=='O')
			{
				c++;
			}
			else if(cpy_aBoard[i][j]=='X')
			{
				flag=False;
				break;
			}
			else
			{
				Loc_cPosition=cpy_aBoard[i][j];
			}
		}
		if((c==2)&&(flag))
		{
			return Loc_cPosition;
		}
	}
	for(int i=0;i<3;i++)
	{
		c=0;
		flag=True;
		for(int j=0;j<3;j++)
		{
			if(cpy_aBoard[j][i]=='O')
			{
				c++;
			}
			else if(cpy_aBoard[j][i]=='X')
			{
				flag=False;
				break;
			}
			else
			{
				Loc_cPosition=cpy_aBoard[j][i];
			}
		}
		if((c==2)&&(flag))
		{
			return Loc_cPosition;
		}
	}
	for(int i=0;i<3;i++)
	{
		c=0;
		flag=True;
		if(cpy_aBoard[i][i]=='O')
		{
			c++;
		}
		else if(cpy_aBoard[i][i]=='X')
		{
			flag=False;
			break;
		}
		else
		{
			Loc_cPosition=cpy_aBoard[i][i];
		}
	}
	if((c==2)&&(flag))
	{
		return Loc_cPosition;
	}
	c=0;
	flag=True;
	if(cpy_aBoard[0][2]=='O')
	{
		c++;
	}
	else if(cpy_aBoard[0][2]=='X')
	{
		flag=False;
	}
	else
	{
		Loc_cPosition=cpy_aBoard[0][2];
	}
	if(cpy_aBoard[1][1]=='O')
	{
		c++;
	}
	else if(cpy_aBoard[1][1]=='X')
	{
		flag=False;
	}
	else
	{
		Loc_cPosition=cpy_aBoard[1][1];
	}
	if(cpy_aBoard[2][0]=='O')
	{
		c++;
	}
	else if(cpy_aBoard[2][0]=='X')
	{
		flag=False;
	}
	else
	{
		Loc_cPosition=cpy_aBoard[2][0];
	}
	if((c==2)&&(flag))
	{
		return Loc_cPosition;
	}
	return 'N';
}

/**
 *brief :Use this function to check if there is a position where I put X and win.
 *@param cpy_aBoard:2d array represinting game board
 *@return :char representing the location or N if there is not
 */
 
char LOGC_cAlmostWinX(char cpy_aBoard[][3])
{
	char Loc_cPosition;
	short int c=0;
	bool flag=False;
	for(int i=0;i<3;i++)
	{
		c=0;
		flag=True;
		for(int j=0;j<3;j++)
		{
			if(cpy_aBoard[i][j]=='X')
			{
				c++;
			}
			else if(cpy_aBoard[i][j]=='O')
			{
				flag=False;
				break;
			}
			else
			{
				Loc_cPosition=cpy_aBoard[i][j];
			}
		}
		if((c==2)&&(flag))
		{
			return Loc_cPosition;
		}
	}
	for(int i=0;i<3;i++)
	{
		c=0;
		flag=True;
		for(int j=0;j<3;j++)
		{
			if(cpy_aBoard[j][i]=='X')
			{
				c++;
			}
			else if(cpy_aBoard[j][i]=='O')
			{
				flag=False;
				break;
			}
			else
			{
				Loc_cPosition=cpy_aBoard[j][i];
			}
		}
		if((c==2)&&(flag))
		{
			return Loc_cPosition;
		}
	}
	for(int i=0;i<3;i++)
	{
		c=0;
		flag=True;
		if(cpy_aBoard[i][i]=='X')
		{
			c++;
		}
		else if(cpy_aBoard[i][i]=='O')
		{
			flag=False;
			break;
		}
		else
		{
			Loc_cPosition=cpy_aBoard[i][i];
		}
	}
	if((c==2)&&(flag))
	{
		return Loc_cPosition;
	}
	c=0;
	flag=True;
	if(cpy_aBoard[0][2]=='X')
	{
		c++;
	}
	else if(cpy_aBoard[0][2]=='O')
	{
		flag=False;
	}
	else
	{
		Loc_cPosition=cpy_aBoard[0][2];
	}
	if(cpy_aBoard[1][1]=='X')
	{
		c++;
	}
	else if(cpy_aBoard[1][1]=='O')
	{
		flag=False;
	}
	else
	{
		Loc_cPosition=cpy_aBoard[1][1];
	}
	if(cpy_aBoard[2][0]=='X')
	{
		c++;
	}
	else if(cpy_aBoard[2][0]=='O')
	{
		flag=False;
	}
	else
	{
		Loc_cPosition=cpy_aBoard[2][0];
	}
	if((c==2)&&(flag))
	{
		return Loc_cPosition;
	}
	return 'N';
}

/**
 *brief :Use this function to get an unused random position on the board.
 *@param cpy_aBoard:2d array represinting game board
 *@return :char representing the location
 */
 
char LOGC_cRandomPosition(char cpy_aBoard[][3])
{
	short int Loc_nNum=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if((cpy_aBoard[i][j]!='X')&&(cpy_aBoard[i][j]!='O'))
			{
				Loc_nNum++;
			}
		}
	}
	Loc_nNum=rand()%Loc_nNum;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if((cpy_aBoard[i][j]!='X')&&(cpy_aBoard[i][j]!='O'))
			{
				if(Loc_nNum==0)
				{
					return cpy_aBoard[i][j];
				}
				Loc_nNum--;
			}
		}
	}
}

/**
 *brief :Use this function to ask the user if he wants to play again.
 *@return :1 if YES 0 if NO
 */
 
int LOGC_nPlayAgain()
{
	int Loc_nChoice;
	IOUT_vPlayAgain(0);
	scanf("%d",&Loc_nChoice);
    while((Loc_nChoice!=1)&&(Loc_nChoice!=0))
	{
		IOUT_vPlayAgain(1);
		scanf("%d",&Loc_nChoice);
    }
	if(Loc_nChoice==0)
    {
		return 0;
    }
	return 1;
}

/**
 *brief :Use this function to make the user choose between two modes in single-player mode or to exit.
 *@return :user's choice
 */
 
int LOGC_nSinglePlayerMode()
{
	int Loc_nChoice;
	IOUT_vSinglePlayerMode(0);
    scanf("%d",&Loc_nChoice);
    while((Loc_nChoice!=1)&&(Loc_nChoice!=2)&&(Loc_nChoice!=3))
    {
		IOUT_vSinglePlayerMode(1);
        scanf("%d",&Loc_nChoice);
    }
	return Loc_nChoice;
}

/**
 *brief :Use this function to make the user choose between two modes in main list or to exit.
 *@return :user's choice
 */
 
int LOGC_nMainList()
{
	int Loc_nChoice;
	IOUT_vPrintList(0);
    scanf("%d",&Loc_nChoice);
    while((Loc_nChoice!=1)&&(Loc_nChoice!=2)&&(Loc_nChoice!=3))
    {
		IOUT_vPrintList(1);
        scanf("%d",&Loc_nChoice);
    }
	return Loc_nChoice;
}