#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROOM_WIDTH 4
#define HME_POS 1
#define BWL_PO (ROOM_WIDTH -2)

int main(void) {
	char name[10];
	int r;
	int soup = 0;
	int realation = 2;
	int cat = HME_POS;
	int previousCat = HME_POS;
	int soupCount = 0;

	printf("****야옹이와 스프**** \n");
	printf(" /\\_/\\ \n");
	printf(" / o.o \\ \n");
	printf(" ~(* *)~ \n");
	printf(" ^_^ \n");
	printf(" / || \\ \n");
	printf(" ( ()() )\n");
	printf("야옹이의 이름을 지어 주세요:");
	scanf_s("%s", name, sizeof(name));
	printf("야옹이의 이름은 %s입니다.", name);
	Sleep(1000);
	system("cls");

	while (true) {
		printf("==================== 현재 상태 ===================\n");
		printf("현재까지 만든 수프: %d개\n", soupCount);
		printf("집사와의 관계(0~4): %d\n", realation);
		switch (realation) {
		case 0:
			printf("곁에오는것조차싫어합니다\n");
			break;
		case 1:
			printf("간식 자판기 취급입니다.\n");
			break;
		case 2:
			printf("그럭저럭 쓸만한 집사입니다.\n");
			break;
		case 3:
			printf("훌륭한 집사로 인정받고 있습니다.\n");
			break;
		case 4:
			printf("집사 껌딱지입니다.\n");
			break;
		}
		printf("==================================================\n");

		printf("%s 이동: 집사와 친밀할수록 냄비 쪽으로 갈 확률이 높아집니다.\n", name);
		printf("주사위 눈이 3 이상이면 냄비 쪽으로 이동합니다.\n");
		printf("주사위를 굴립니다. 또르륵...\n");
		r = rand() % 7;
		printf("%d이(가) 나왔습니다!\n", r);

		if (r > 6 - realation) {
			printf("냄비 쪽으로 움직입니다.\n");
			if (cat < ROOM_WIDTH - 1) {
				previousCat = cat;
				cat++;
			}
			else {
				previousCat = -1; 
			}
			if (cat == ROOM_WIDTH - 1) {
				soup = rand() % 3;
				if (soup == 0) {
					printf("%s이(가) 감자수프를 만들었습니다!\n",name);
					soupCount++;
					printf("현재 만든 수프 개수: %d\n",soupCount);
				}
				else if (soup == 1) {
					printf("%s이(가) 양송이수프를 만들었습니다!\n", name);
					soupCount++;
					printf("현재 만든 수프 개수: %d\n", soupCount);
				}
				else {
					printf("%s이(가) 브로콜리수프를 만들었습니다!\n", name);
					soupCount++;
					printf("현재 만든 수프 개수: %d\n", soupCount);
				}
			}
		}

		else {
			printf("집 쪽으로 움직입니다.\n");
			if (cat > HME_POS) {
				previousCat = cat;
				cat--;
				if (cat == 1) {
					printf("%s은(는) 자신의 집에서 편안함을 느낍니다. ", name);
				}
			}
			else {
				previousCat = -1;
			}
		}
		Sleep(500);
		printf("\n");

		for (int i = 0; i < 4; i++) {
			printf("\n");
			for (int j = 0; j <= ROOM_WIDTH; j++) {
				if (i == 0 || i == 3) {
					printf("#");
				}
				else if (j == 0 || j == ROOM_WIDTH) {
					printf("#");
				}
				else if (i == 1 && j == 1) {
					printf("H");
				}
				else if (i == 1 && j == ROOM_WIDTH - 1) {
					printf("B");
				}
				else if (i == 2 && j == cat) {
					printf("C");
				}
				else if (i == 2 && j == previousCat && previousCat != cat) {
					printf(".");
				}
				else {
					printf(" ");
				}
			}

		}

		printf("\n");
		printf("==================================================\n");
		printf("\n");

		printf("어떤 상호작용을 하시겠습니까? 0. 아무것도 하지 않음 1. 긁어주기\n");
		printf(">>");

		int input;
		while (true)
		{
			scanf_s("%d", &input);
			Sleep(500);
			if (input == 1 || input == 0) {
				break;
			}
			else {
				printf(">>");
			}
		}

		switch (input) {
		case 0:
			printf("아무것도 하지 않습니다.\n");
			printf("4/6의 확률로 친밀도가 떨어집니다.\n");
			printf("주사위를 굴립니다. 또르륵...\n");
			r = rand() % 7;
			printf("%d이(가) 나왔습니다!\n", r);

			if (r >= 1 && r <= 4) {
				if (realation > 0) {
					printf("친밀도는 떨어집니다.\n");
					realation--;
					printf("현재 친밀도 : %d\n", realation);
				}
			}

			else {
				printf("다행히 친밀도가 떨어지지 않았습니다.");
				printf("현재 친밀도 : %d\n", realation);
			}
			Sleep(500);
			system("cls");
			break;

		case 1:

			printf("%s의 턱을 긁어주었습니다.", name);
			printf("2/6의 확률로 친밀도가 높아집니다.\n");
			printf("주사위를 굴립니다. 또르륵...\n");
			int k = rand() % 7;
			printf("%d이(가) 나왔습니다!\n", k);
			if (k >= 5) {
				if (realation < 4) {
					printf("친밀도가 높아집니다.\n");
					realation++;
					printf("현재 친밀도 : %d\n", realation);
				}
			}

			else {
				printf("친밀도는 그대로입니다.");
				printf("현재 친밀도 : %d\n", realation);
			}
			Sleep(500);
			system("cls");
			break;
		} 
	}
	Sleep(2500);
	system("cls");
}

