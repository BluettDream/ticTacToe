#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

//ÉùÃ÷
void InitBoard(char board[ROW][COL], int row, int col);
void PrintingBoard(char board[ROW][COL], int row, int col);
void PlayerChess(char board[ROW][COL], int row, int col);
void ComputerChess(char board[ROW][COL], int row, int col);

char IsWin(char board[ROW][COL], int row, int col);