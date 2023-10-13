#include<stdio.h>
enum BOOL{False,True};
typedef enum BOOL bool;
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
void LOGC_vTakeInput(char cpy_aBoard[][3],char cpy_cValue)
{
	char Loc_cPlace;
	scanf(" %c",&Loc_cPlace);
	while(cpy_aBoard[(int)((int)(Loc_cPlace-'1')/3)][(int)(Loc_cPlace-'1')%3]!=Loc_cPlace)
	{
		printf("Wrong Place\n");
		printf("Enter Valid Place:");
		scanf(" %c",&Loc_cPlace);
	}
	cpy_aBoard[(int)((int)(Loc_cPlace-'1')/3)][(int)(Loc_cPlace-'1')%3]=cpy_cValue;
}
void LOGC_vPutInput(char cpy_aBoard[][3],char cpy_cValue,char cpy_cPosition)
{
	cpy_aBoard[(int)((int)(cpy_cPosition-'1')/3)][(int)(cpy_cPosition-'1')%3]=cpy_cValue;
}
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