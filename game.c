#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col) 
{
	int i = 0;
	int j = 0;
	for ( i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++) 
		{
			board[i][j] = ' ';
		}
	}
}

//打印三子棋棋盘
void PrintingBoard(char board[ROW][COL], int row, int col)
{
	/*
		   |   |           行
		---|---|---       分割行 
	       |   |           行
		---|---|---       分割行
		   |   |           行
	*/
	int i = 0;
	for ( i = 0; i < row; i++)
	{
		//打印行
		int j = 0;
		for ( j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		//打印分割行
		if (i < row - 1)
		{
			for ( j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

//玩家下棋
void PlayerChess(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家下棋：>\n");
	while (1)
	{
		printf("请输入下棋的坐标:");
		scanf("%d%d", &x, &y);
		//判断玩家下棋位置是否正确
		if (x >= 0 && x <= row - 1  && y >= 0 && y <= col - 1)
		{
			if (board[x][y] == ' ')
			{
				board[x][y] = '*';
				break;
			}
			else
			{
				printf("该位置已经有棋子，请尝试其他位置\n");
			}
		}
		else
		{
			printf("棋子位置不正确，请重新输入！\n");
		}
	}
}

//电脑下棋
void ComputerChess(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑下棋：>\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for ( i = 0; i < row; i++)
	{
		for ( j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
//判断是否取得胜利
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//横三行
	for ( i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][0];
		}
	}
	//竖三列
	for ( i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//两个对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//平局
	if (1 == IsFull(board,ROW,COL))
	{
		return 'Q';
	}
	return 'C';
}