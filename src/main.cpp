#include <iostream>
#include <locale>
#include <iomanip>
#include <stdlib.h>

#include "create.h"
#include "moving.h"

char chess_field[9][9];
int flag;

using namespace std;

int main()
{
	flag = 0;
	setlocale(LC_ALL, "Russian");

	char position1, position_i, position2, position_i2, target;
	int game = 1, i, j, position2_1, position2_2, figure, temp;

	cout << "Вас приветствуют интересные шахматы" << endl;
	create_chess();
	output_chess();

	while (game)
	{
		if (flag == 0) cout << "Ходят Белые" << endl;
		else cout << "Ход за Черными" << endl;

		cout << "Введите координаты фигуры, которой хотите походить" << endl << "(можно сразу в формате \"a1b2\")" << endl;
		cin >> position1 >> position_i;
		if (position1 > 95)
		{
			i = position_i - 48;
			j = position1 - 96;
		}
		else
		{
			i = position_i - 48;
			j = position1 - 64;
		}

		cout << "Введите координаты, куда должна сходить фигура" << endl;
		cin >> position2 >> position_i2;
		if (position2 > 95)
		{
			position2_1 = position_i2 - 48;
			position2_2 = position2 - 96;
		}
		else
		{
			position2_1 = position_i2 - 48;
			position2_2 = position2 - 64;
		}

		if (correct_input(i, j, position2_1, position2_2) == -1) figure = -1;
		else figure = chess_field[i][j];

		system("clear");

		switch (figure)
		{
		case 80: if (flag == 0) {cout << "Ходят белые!" << endl; break;}
				 if (moving_pawnsB(i, j, position2_1, position2_2) == 0) { moving_a_shape(i, j, position2_1, position2_2); flag = 0; break; }
				 else break;
		case 112: if (flag == 1) { cout << "Ходят черные!" << endl; break; }
				  if (moving_pawnsW(i, j, position2_1, position2_2) == 0) { moving_a_shape(i, j, position2_1, position2_2); flag = 1; break; }
				  else break;
		case 82: if (flag == 0) { cout << "Ходят белые!" << endl; break; }
				 if (moving_rook(i, j, position2_1, position2_2) == 0) { moving_a_shape(i, j, position2_1, position2_2); flag = 0; break; }
				 else break;
		case 114: if (flag == 1) { cout << "Ходят черные!" << endl; break; }
				 if (moving_rook(i, j, position2_1, position2_2) == 0) { moving_a_shape(i, j, position2_1, position2_2); flag = 1; break; }
				 else break;
		case 78: if (flag == 0) { cout << "Ходят белые!" << endl; break; }
				 if (moving_knight(i, j, position2_1, position2_2) == 0) { moving_a_shape(i, j, position2_1, position2_2); flag = 0; break; }
				 else break;
		case 110: if (flag == 1) { cout << "Ходят черные!" << endl; break; }
				 if (moving_knight(i, j, position2_1, position2_2) == 0) { moving_a_shape(i, j, position2_1, position2_2); flag = 1; break; }
				 else break;
		case 66: if (flag == 0) { cout << "Ходят белые!" << endl; break; }
				 if (moving_bishop(i, j, position2_1, position2_2) == 0) { moving_a_shape(i, j, position2_1, position2_2); flag = 0; break; }
				 else break;
		case 98: if (flag == 1) { cout << "Ходят черные!" << endl; break; }
				 if (moving_bishop(i, j, position2_1, position2_2) == 0) { moving_a_shape(i, j, position2_1, position2_2); flag = 1; break; }
				 else break;
		case 75: if (flag == 0) { cout << "Ходят белые!" << endl; break; }
				 if (moving_king(i, j, position2_1, position2_2) == 0) { moving_a_shape(i, j, position2_1, position2_2); flag = 0; break; }
				 else break;
		case 107: if (flag == 1) { cout << "Ходят черные!" << endl; break; }
				  if (moving_king(i, j, position2_1, position2_2) == 0) { moving_a_shape(i, j, position2_1, position2_2); flag = 1; break; }
				  else break;
		case 81: if (flag == 0) { cout << "Ходят белые!" << endl; break; }
				 if (moving_queen(i, j, position2_1, position2_2) == 0) { moving_a_shape(i, j, position2_1, position2_2); flag = 0; break; }
				 else break;
		case 113: if (flag == 1) { cout << "Ходят черные!" << endl; break; }
				  if (moving_queen(i, j, position2_1, position2_2) == 0) { moving_a_shape(i, j, position2_1, position2_2); flag = 1; break; }
				  else break;
		case -1: cout << "Incorrect input!" << endl; break;
		default:
			break;
		}

		if (win() == 1) game = 0;

		output_chess();
	}

	if (flag == 1) cout << "Победили БЕЛЫЕ!" << endl;
	else cout << "Победили ЧЕРНЫЕ!" << endl;

	system("pause");
    return 0;
}
