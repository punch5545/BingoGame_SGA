#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>

int bingoCheck();
void playGround(int num);
int bingo[3][3]{0,0,0,
				0,0,0,
				0,0,0};
int hide[3][3];
bool bCheck[8];

int main(void) {

	int inputNum = 0;
	int list[9];
	int temp;
	int * listptr = list;
	srand(time(0));

	for (int i = 0; i < 8; i++) {
		bCheck[i] = false;
	}

	for (int i = 0; i < 9; i++)	{
	jump:
		int temp = rand() % 30 + 1;
		for (int j = 0; j < i; j++)	{
			if (temp == list[j]){
				goto jump;
			}
		}
		list[i] = temp;
	}
	temp = 0;

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++)	{
			bingo[i][j] = *(listptr + temp++);
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
		
		if (bingoCheck() > 2) {
			printf("클리어!\n");
		}
		else {
			printf("현재 %d빙고입니다.\n", bingoCheck());
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

int bingoCheck() {
	static int bingoCount = 0;
	for (int i = 0; i < 3; i++) {
		if (hide[i][0] != '*' && hide[i][1] != '*' && hide[i][2] != '*' && !bCheck[i]) {
			bCheck[i] = true;
			bingoCount++;
		}
			
		if (hide[0][i] != '*' && hide[1][i] != '*' && hide[2][i] != '*' && !bCheck[i+3]) {
			bCheck[i + 3] = true;
			bingoCount++;
		}
	}
	if (hide[0][0] != '*' && hide[1][1] != '*' && hide[2][2] != '*' && !bCheck[7]) {
		bCheck[7] = true;
		bingoCount++;
	}
	if (hide[2][0] != '*' && hide[1][1] != '*' && hide[0][2] != '*' && !bCheck[6]) {
		bCheck[6] = true;
		bingoCount++;
	}

	return bingoCount;
}