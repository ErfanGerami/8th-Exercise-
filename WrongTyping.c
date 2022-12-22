

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void reverse(char* st) {
	char temp;
	int size = strlen(st);
	for (int i = 0; i < size / 2; i++) {
		temp = st[i];
		st[i] = st[size - i - 1];
		st[size - i - 1] = temp;

	}
}
int main(void) {

	char st[100001];

	scanf("%s", st);
	int size = strlen(st);
	char* stM = (char*)malloc((size + 1) * sizeof(char));
	int cnt = 0;
	int mines = 0;
	char ch;
	for (int i = size - 1; i >= 0; i--) {
		ch = st[i];
		if (st[i] == '=') {
			mines++;
		}
		else {
			if (!mines) {
				stM[cnt] = ch;
				cnt++;
			}
			else {
				mines--;
			}

		}



	}
	stM[cnt] = '\0';
	reverse(stM);
	printf("%s", stM);



}
