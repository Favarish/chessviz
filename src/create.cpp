#include <iostream>
#include "create.h"

void create_chess()
{
	chess_field[0][0] = 32;

	//Разметка от 8 до 1
	for (int i = 1; i < 9; i++)
	{
		chess_field[i][0] = 48 + i;
	}

	//Разметка от А до H
	for (int i = 1; i < 9; i++)
	{
		chess_field[0][i] = 64 + i;
	}

	//Расстановка черных пешек
	for (int i = 1; i < 9; i++)
	{
		chess_field[2][i] = 80;
	}

	//Расстановка белых пешек
	for (int i = 1; i < 9; i++)
	{
		chess_field[7][i] = 112;
	}

	//фигурки черных
	chess_field[1][1] = 82;
	chess_field[1][2] = 78;
	chess_field[1][3] = 66;
	chess_field[1][4] = 81;
	chess_field[1][5] = 75;
	chess_field[1][6] = 66;
	chess_field[1][7] = 78;
	chess_field[1][8] = 82;

	//фигурки белых
	chess_field[8][1] = 114;
	chess_field[8][2] = 110;
	chess_field[8][3] = 98;
	chess_field[8][4] = 113;
	chess_field[8][5] = 107;
	chess_field[8][6] = 98;
	chess_field[8][7] = 110;
	chess_field[8][8] = 114;

	//заполнение остатка поля пробелами
	for (int i = 3; i < 7; i++)
	{
		for (int j = 1; j < 9; j++) 
			chess_field[i][j] = 32;
	}
}

void output_chess()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			std::cout << " " << chess_field[i][j] << " |";
		}
		std::cout << std::endl;
	}
}
