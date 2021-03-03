#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//菜单
void menu() {
	printf("********************************\n");
	printf("*******  1.play   0.exit  ******\n");
	printf("********************************\n");
}

//游戏实现
void game() {
	char flag = 0;
	//数组存放棋盘信息
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	PrintingBoard(board, ROW, COL);
	//下棋
	while (1)
	{
		//玩家下棋
		PlayerChess(board, ROW, COL);
		PrintingBoard(board, ROW, COL);
		//判断是否赢得胜利
		flag = IsWin(board, ROW, COL);
		if (flag != 'C')
		{
			break;
		}
		//电脑下棋
		ComputerChess(board, ROW, COL);
		PrintingBoard(board, ROW, COL);
		//判断是否赢得胜利
		flag = IsWin(board, ROW, COL);
		if (flag != 'C')
		{
			break;
		}
	}
	if (flag == '*')
	{
		printf("恭喜玩家获得胜利！\n");
	}
	else if (flag == '#')
	{
		printf("很抱歉，电脑取得胜利，你输了！\n");
	}
	else
	{
		printf("平局啦！\n");
	}
}
void test() 
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do 
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选选择！\n");
			break;
		}
	} while (input);
}
int main() {
	test();
	return 0;
}









