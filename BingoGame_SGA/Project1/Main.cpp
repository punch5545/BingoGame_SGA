#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>

bool bingoCheck();
void playGround(int num);
int bingo[3][3]{0,0,0,
				0,0,0,
				0,0,0};
int hide[3][3];
bool bCheck[8];

int main(void) {

	int inputNum = 0;
	int temp;
	srand(time(0));
	int bingoCount = 0;

	for (int i = 0; i < 8; i++) {
		bCheck[i] = false;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
		//jump:
			bingo[i][j] = rand() % 30 + 1;
			
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			hide[i][j] = '*';
			printf(" %c ", hide[i][j]);
		}
		printf("\n\n");
	}
	while (true)
	{
		printf("입력 (1~30)> ");
		scanf("%d", &inputNum);
		playGround(inputNum);
		bool check = bingoCheck();
		if (check) {
			bingoCount++;
			if (bingoCount>2) {
				printf("클리어!\n");
			}
			else {
				printf("현재 %d빙고입니다.\n", bingoCount);
			}
		}
	}	
}

void playGround(int num) {
	system("cls");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (num == bingo[i][j]) {
				hide[i][j] = num;
				if (hide[i][j] < 10)
					printf("% d ", hide[i][j]);
				else
					printf("%d ", hide[i][j]);
			}
			else {
				if (hide[i][j] != '*') {
					if (hide[i][j] < 10)
						printf(" %d ", hide[i][j]);
					else
						printf("%d ", hide[i][j]);
				}
				else {
					printf(" %c ", hide[i][j]);
				}
			}
		}
		printf("\n\n");
	}
}

bool bingoCheck() {
	for (int i = 0; i < 3; i++) {
		if (hide[i][0] != '*' && hide[i][1] != '*' && hide[i][2] != '*' && !bCheck[i]) {
			bCheck[i] = true;
			return true;
		}
			
		if (hide[0][i] != '*' && hide[1][i] != '*' && hide[2][i] != '*' && !bCheck[i+3]) {
			bCheck[i + 3] = true;
			return true;
		}
	}
	if (hide[0][0] != '*' && hide[1][1] != '*' && hide[2][2] != '*' && !bCheck[7]) {
		bCheck[7] = true;
		return true;
	}
	if (hide[2][0] != '*' && hide[1][1] != '*' && hide[0][2] != '*' && !bCheck[6]) {
		bCheck[6] = true;
		return true;
	}
	return false;
}