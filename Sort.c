#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int Max(int a, int b) {
	if (a > b) {
		return -1;
	}
	else if (b > a) {
		return 1;
	}
	else {
		return 0;
	}
}
int CompareChar(char a, char b) {
	if (tolower(a) == tolower(b)) {
		if (a > b) {
			return 1;
		}
		else if (b > a) {
			return -1;
		}
		else {
			return 0;
		}
	}
	a = tolower(a);
	b = tolower(b);
	return -Max(a, b);
}

int compare(char* first, char* second) {
	int CompareResult;
	int SizeOfFirst = strlen(first);
	int SizeOfSecond = strlen(second);
	//////////////at least On Of Them Is Smaller than 2;
	if (SizeOfFirst <= 2 || SizeOfSecond <= 2) {

		if (SizeOfFirst < SizeOfSecond) {

			for (int i = 0; i < SizeOfFirst; i++) {
				CompareResult = CompareChar(first[i], second[i]);
				if (!CompareResult) {
					continue;
				}
				return CompareResult;
			}
			return -1;
		}
		else {
			for (int i = 0; i < SizeOfSecond; i++) {
				CompareResult = CompareChar(first[i], second[i]);
				if (!CompareResult) {
					continue;
				}
				return CompareResult;
			}
			if (SizeOfFirst == SizeOfSecond) {
				return -1;
			}
			else if (SizeOfFirst <= 2 && SizeOfSecond <= 2) {
				return 1;

			}
			else {
				return -1;
			}
		}
	}
	/////////////////////else
	int Result = CompareChar(first[0], second[0]);
	if (Result)
		return Result;

	Result = CompareChar(first[1], second[1]);
	if (Result)
		return Result;
	return -1;


}




void sort(char** main, int* series, int size) {
	int temp;
	for (int j = 0; j < size; j++) {
		for (int i = size - 1; i > j; i--) {
			if (compare(main[series[i - 1]], main[series[i]]) == 1) {
				temp = series[i - 1];
				series[i - 1] = series[i];
				series[i] = temp;
			}

		}
	}

}
int main(void) {
	//char first[1002];
	//char second[1002];
	//scanf("%s%s", first, second);
	//printf("%d", compare(first, second));
	//return 0;
	char** strings = (char**)malloc(1004 * sizeof(char*));

	int* series = (int*)malloc(1004 * sizeof(int));

	int size = -1;
	while (++size, 1) {

		strings[size] = (char*)malloc(1004 * sizeof(char));
		scanf("%s", strings[size]);
		strings[size] = (char*)realloc(strings[size], (strlen(strings[size]) + 1) * sizeof(char));
		//strings[size] = (char*)realloc((strlen(strings[i]+2) * sizeof(char));

		series[size] = size;
		if (strings[size][0] == '0') {
			break;
		}
	}

	//the pointer in the strings pointer do not have space in them because they have benn malloced in side the loop to the size we need
	//so we do not need to free them and the realloc of the strings will do the trick of and for the strings realloc will freejust the (pointer value)adrres stored in the rest of it in  ; 
	strings = (char**)realloc(strings, (size + 2) * sizeof(char**));
	sort(strings, series, size);
	for (int j = 0; j < size; j++) {
		printf("%s ", strings[series[j]]);
	}



}