

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void generate(char* st) {
	int size = strlen(st);


	for (int i = size; i < 2 * size; i++) {
		if (st[i - size] == '0')
			st[i] = '1';
		else
			st[i] = '0';


	}
	st[2 * size] = '\0';

}
int main(void) {


	int L, R;
	scanf("%d %d", &L, &R);
	char* Main = (char*)malloc((2 * R + 5) * sizeof(char));//+5 just to be sure;
	Main[0] = '1';
	Main[1] = '\0';
	while (strlen(Main) < R) {
		generate(Main);
	}
	for (int i = L - 1; i < R; i++) {
		printf("%c", Main[i]);
	}



}
