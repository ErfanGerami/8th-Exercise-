#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <ctype.h>
int** Main;
int** Kernel;
int** CreateMatrix(int row) {
	int** Matrix = (int**)malloc(row * sizeof(int*));
	for (int i = 0; i < row; i++) {

		Matrix[i] = (int*)malloc(row * sizeof(int));

	}
	return Matrix;

}

void FillMatrix(int** Matrix, int row) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			scanf("%d", Matrix[i] + j);
		}
	}
}

void PrintMatrix(int** Matrix, int row) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			printf("%d ", Matrix[i][j]);
		}
		printf("\n");
	}
}


int calIndex(int i1, int j1, int space) {
	int Iindex;
	int Jindex;
	int sum = 0;

	for (int i = 0; i < 2 * space + 1; i++) {
		for (int j = 0; j < 2 * space + 1; j++) {
			Iindex = i1 - space + i;
			Jindex = j1 - space + j;
			sum += Main[Iindex][Jindex] * Kernel[i][j];


		}

	}
	if (sum > 255) {
		return 255;
	}
	else if (sum < 0) {
		return 0;
	}
	else {
		return sum;
	}
}

int** cal(int row1, int row2) {

	int space = row2 / 2;
	int** Result = CreateMatrix(row1);
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < row1; j++) {
			Result[i][j] = 0;
		}
	}
	int sum = 0;
	for (int i = space; i < row1 - space; i++) {
		for (int j = space; j < row1 - space; j++) {
			Result[i][j] = calIndex(i, j, space);

		}


	}
	return Result;

}
int main(void) {
	///preparing------------------------
	int row1, row2;
	scanf("%d", &row1);
	Main = CreateMatrix(row1);
	FillMatrix(Main, row1);
	scanf("%d", &row2);
	Kernel = CreateMatrix(row2);
	FillMatrix(Kernel, row2);

	//end of preparation---------------
	PrintMatrix(cal(row1, row2), row1);












}
