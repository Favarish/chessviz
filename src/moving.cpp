#include <cmath>
#include <iostream>
#include "moving.h"

int friend_or_foe(int position2_1, int position2_2)
{
	//Проверка на своих
	if ((flag == 1 &&
		(chess_field[position2_1][position2_2] == 82 ||
			chess_field[position2_1][position2_2] == 78 ||
			chess_field[position2_1][position2_2] == 66 ||
			chess_field[position2_1][position2_2] == 81 ||
			chess_field[position2_1][position2_2] == 75 ||
			chess_field[position2_1][position2_2] == 80))
		||
		(flag == 0 &&
		(
			chess_field[position2_1][position2_2] == 112 ||
			chess_field[position2_1][position2_2] == 114 ||
			chess_field[position2_1][position2_2] == 110 ||
			chess_field[position2_1][position2_2] == 98 ||
			chess_field[position2_1][position2_2] == 113 ||
			chess_field[position2_1][position2_2] == 107))
		) 
	{
		std::cout << "На своих пошел?!" << std::endl;
		return -1;
	}
	else return 0;
}

void moving_a_shape(int i, int j, int position2_1, int position2_2)
{
	char figure;

	figure = chess_field[i][j];
	chess_field[i][j] = 32;
	chess_field[position2_1][position2_2] = figure;
}

int moving_pawnsB(int i, int j, int position2_1, int position2_2)
{
	if (friend_or_foe(position2_1, position2_2) == -1) return -1;

	char target = chess_field[position2_1][position2_2];

	//Если срубаем
	if (target != 32)
	{
		if ((position2_2 - j == 1 && position2_1 - i == 1) || (j - position2_2 == 1 && position2_1 - i == 1)) 
			return 0;
	}
	else
	{
		if (i == 2 && position2_2 == j && (position2_1 - i == 2 || position2_1 - i == 1)) 
			return 0;
		if (i != 2 && position2_2 == j && position2_1 - i == 1) 
			return 0;
	}
	return -1;
}

int moving_pawnsW(int i, int j, int position2_1, int position2_2)
{
	if (friend_or_foe(position2_1, position2_2) == -1) return -1;

	char target = chess_field[position2_1][position2_2];

	//Если срубаем
	if (target != 32)
	{
		if ((position2_2 - j == -1 && position2_1 - i == -1) || (j - position2_2 == -1 && position2_1 - i == -1)) return 0;
	}
	else
	{
		if (i == 7 && position2_2 == j && (position2_1 - i == -2 || position2_1 - i == -1)) return 0;
		if (i != 7 && position2_2 == j && position2_1 - i == -1) return 0;
	}
	return -1;
}

int moving_rook(int i, int j, int position2_1, int position2_2)
{
	if (friend_or_foe(position2_1, position2_2) == -1) return -1;

	int temp = 0;

	//Перемещение ладьи по вертикали
	if (position2_2 - j == 0 && position2_1 - i != 0)
	{
		if (position2_1 > i)
		{
			for (int k = i + 1; k < position2_1; k++)
				if (chess_field[k][j] != 32 && position2_1 - k > 0) temp++;
			if (temp == 0) return 0;
		}
		else
		{
			for (int k = position2_1; k < i; k++)
				if (chess_field[k][j] != 32 && k - position2_1 > 0) temp++;
			if (temp == 0) return 0;
		}
	}

	//Перемещение ладьи по горизонтали
	if (position2_2 - j != 0 && position2_1 - i == 0)
		if (position2_2 > j)
		{
			for (int k = j + 1; k < position2_2; k++)
				if (chess_field[i][k] != 32 && position2_2 - k > 0) temp++;
			if (temp == 0) return 0;
		}
		else
		{
			for (int k = position2_2; k < j; k++)
				if (chess_field[i][k] != 32 && k - position2_2 > 0) temp++;
			if (temp == 0) return 0;
		}
	return -1;
}

int moving_knight(int i, int j, int position2_1, int position2_2)
{
	if (friend_or_foe(position2_1, position2_2) == -1) return -1;

	int difference1, difference2;
	difference1 = position2_1 - i;
	difference2 = position2_2 - j;

	if ((std::abs(difference1) == 2 && std::abs(difference2) == 1) || (std::abs(difference1) == 1 && std::abs(difference2) == 2)) return 0;
	else return -1;
}

int moving_bishop(int i, int j, int position2_1, int position2_2)
{
	if (friend_or_foe(position2_1, position2_2) == -1) return -1;

	int difference1, difference2, temp = 0;
	difference1 = position2_1 - i;
	difference2 = position2_2 - j;

	if (std::abs(difference1) == std::abs(difference2))
	{
		//вверх влево
		if (i > position2_1 && j > position2_2)
		{
			for (int k = i - 1, z = j - 1; k > position2_1; k--, z--)
				if (chess_field[k][z] != 32) temp++;
			if (temp == 0) return 0;
		}

		//вниз влево
		if (i < position2_1 && j > position2_2)
		{
			for (int k = i + 1, z = j - 1; k < position2_1; k++, z--)
				if (chess_field[k][z] != 32) temp++;
			if (temp == 0) return 0;
		}

		//вверх вправо
		if (i > position2_1 && j < position2_2)
		{
			for (int k = i - 1, z = j + 1; z < position2_2; k--, z++)
				if (chess_field[k][z] != 32) temp++;
			if (temp == 0) return 0;
		}

		//вниз вправо
		if (i < position2_1 && j < position2_2)
		{
			for (int k = i + 1, z = j + 1; k < position2_1; k++, z++)
				if (chess_field[k][z] != 32) temp++;
			if (temp == 0) return 0;
		}
	}
	return -1;
}

int moving_king(int i, int j, int position2_1, int position2_2)
{
	if (friend_or_foe(position2_1, position2_2) == -1) return -1;

	int difference1, difference2;
	difference1 = position2_1 - i;
	difference2 = position2_2 - j;

	if ((std::abs(difference1) == 1 && std::abs(difference2) == 1) || (std::abs(difference1) == 0 && std::abs(difference2) == 1) || (std::abs(difference1) == 1 && std::abs(difference2) == 0)) return 0;
	else return -1;
}

int moving_queen(int i, int j, int position2_1, int position2_2)
{
	if (friend_or_foe(position2_1, position2_2) == -1) return -1;

	int difference1, difference2, temp = 0;
	difference1 = position2_1 - i;
	difference2 = position2_2 - j;

	if (std::abs(difference1) == std::abs(difference2))
	{
		//вверх влево
		if (i > position2_1 && j > position2_2)
		{
			for (int k = i - 1, z = j - 1; k > position2_1; k--, z--)
				if (chess_field[k][z] != 32) temp++;
			if (temp == 0) return 0;
		}

		//вниз влево
		if (i < position2_1 && j > position2_2)
		{
			for (int k = i + 1, z = j - 1; k < position2_1; k++, z--)
				if (chess_field[k][z] != 32) temp++;
			if (temp == 0) return 0;
		}

		//вверх вправо
		if (i > position2_1 && j < position2_2)
		{
			for (int k = i - 1, z = j + 1; z < position2_2; k--, z++)
				if (chess_field[k][z] != 32) temp++;
			if (temp == 0) return 0;
		}

		//вниз вправо
		if (i < position2_1 && j < position2_2)
		{
			for (int k = i + 1, z = j + 1; k < position2_1; k++, z++)
				if (chess_field[k][z] != 32) temp++;
			if (temp == 0) return 0;
		}
	}

	//Перемещение королевы по вертикали
	if (position2_2 - j == 0 && position2_1 - i != 0)
	{
		if (position2_1 > i)
		{
			for (int k = i + 1; k < position2_1; k++)
				if (chess_field[k][j] != 32 && position2_1 - k > 0) temp++;
			if (temp == 0) return 0;
		}
		else
		{
			for (int k = position2_1; k < i; k++)
				if (chess_field[k][j] != 32 && k - position2_1 > 0) temp++;
			if (temp == 0) return 0;
		}
	}

	//Перемещение королевы по горизонтали
	if (position2_2 - j != 0 && position2_1 - i == 0)
		if (position2_2 > j)
		{
			for (int k = j + 1; k < position2_2; k++)
				if (chess_field[i][k] != 32 && position2_2 - k > 0) temp++;
			if (temp == 0) return 0;
		}
		else
		{
			for (int k = position2_2; k < j; k++)
				if (chess_field[i][k] != 32 && k - position2_2 > 0) temp++;
			if (temp == 0) return 0;
		}
	return -1;
}

int correct_input(int i, int j, int position2_1, int position2_2)
{
	if ((i > 0 && i <= 8) && (position2_1 > 0 && position2_1 <= 8) && (j > 0 && j <= 8) && (position2_2 > 0 && position2_2 <= 8))
		return 0;
	else return -1;
}

int win()
{
	int temp = 0;

	for (int i = 1; i < 9; i++)
		for (int j = 1; j < 9; j++)
			if (chess_field[i][j] == 107 || chess_field[i][j] == 75) temp++;
	if (temp < 2) return 1;
}
