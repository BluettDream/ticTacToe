#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//�˵�
void menu() {
	printf("********************************\n");
	printf("*******  1.play   0.exit  ******\n");
	printf("********************************\n");
}

//��Ϸʵ��
void game() {
	char flag = 0;
	//������������Ϣ
	char board[ROW][COL] = { 0 };
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	PrintingBoard(board, ROW, COL);
	//����
	while (1)
	{
		//�������
		PlayerChess(board, ROW, COL);
		PrintingBoard(board, ROW, COL);
		//�ж��Ƿ�Ӯ��ʤ��
		flag = IsWin(board, ROW, COL);
		if (flag != 'C')
		{
			break;
		}
		//��������
		ComputerChess(board, ROW, COL);
		PrintingBoard(board, ROW, COL);
		//�ж��Ƿ�Ӯ��ʤ��
		flag = IsWin(board, ROW, COL);
		if (flag != 'C')
		{
			break;
		}
	}
	if (flag == '*')
	{
		printf("��ϲ��һ��ʤ����\n");
	}
	else if (flag == '#')
	{
		printf("�ܱ�Ǹ������ȡ��ʤ���������ˣ�\n");
	}
	else
	{
		printf("ƽ������\n");
	}
}
void test() 
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do 
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡѡ��\n");
			break;
		}
	} while (input);
}
int main() {
	test();
	return 0;
}









