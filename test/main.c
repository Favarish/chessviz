#define CTEST_MAIN

#include "moving.h"
#include "create.h"
#include <ctest.h>



CTEST(Moving, moving_pawnsB)
{
	void create_chess();
	int i = 2;
	int j = 2;
	int position2_1 = 4;
	int position2_2 = 2;
	ASSERT_EQUAL(0, moving_pawnsB(i, j, position2_1, position2_2));
}

CTEST(Moving, moving_pawnsW)
{
	void create_chess();
	int i = 7;
	int j = 3;
	int position2_1 = 5;
	int position2_2 = 3;
	ASSERT_EQUAL(0, moving_pawnsW(i, j, position2_1, position2_2));
}

CTEST(Moving, moving_rook)
{
	void create_chess();
	moving_a_shape(8, 1, 5, 2);
	int i = 5;
	int j = 2;
	int position2_1 = 5;
	int position2_2 = 6;
	ASSERT_EQUAL(0, moving_rook(i, j, position2_1, position2_2));
}

CTEST(Moving, moving_knight)
{
	void create_chess();
	int i = 8;
	int j = 2;
	int position2_1 = 6;
	int position2_2 = 3;
	ASSERT_EQUAL(0, moving_knight(i, j, position2_1, position2_2));
}

CTEST(Moving, moving_bishop)
{
	void create_chess();
	moving_a_shape(8, 3, 6, 3);
	int i = 6;
	int j = 3;
	int position2_1 = 3;
	int position2_2 = 6;
	ASSERT_EQUAL(0, moving_bishop(i, j, position2_1, position2_2));
}

CTEST(Moving, moving_king)
{
	void create_chess();
	moving_a_shape(8, 5, 5, 5);
	int i = 5;
	int j = 5;
	int position2_1 = 6;
	int position2_2 = 6;
	ASSERT_EQUAL(0, moving_king(i, j, position2_1, position2_2));
}

CTEST(Moving, moving_queen)
{
	void create_chess();
	moving_a_shape(8, 4, 5, 5);
	int i = 5;
	int j = 5;
	int position2_1 = 5;
	int position2_2 = 1;
	ASSERT_EQUAL(0, moving_queen(i, j, position2_1, position2_2));
}

CTEST(Moving, correct_input)
{
	void create_chess();
	int i = 1;
	int j = 9;
	int position2_1 = 3;
	int position2_2 = 4;
	ASSERT_EQUAL(-1, correct_input(i, j, position2_1, position2_2));
}