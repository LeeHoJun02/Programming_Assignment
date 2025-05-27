#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROOM_WIDTH 10
#define HME_POS 1
#define BWL_PO (ROOM_WIDTH -1)

int main(void) {
	char name[10];
	int r;
	int soup = 0;
	int realation = 2;
	int cat = HME_POS;
	int previousCat = HME_POS;
	int soupCount = 0;
	int cp = 0;
	int cpGain = 0;
	int feel = 3;
	int width;
	int height;
	int scratcher;
	int catTower;
	int turn = 0;
	boolean hasTower = false;
	boolean hasScratcher = false;
	boolean house = false;
	boolean mouseToy = false;
	boolean razerToy = false;

	srand(time(NULL));
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
		turn++;
		printf("==================== 현재 상태 ===================\n");
		printf("현재까지 만든 수프: %d개\n", soupCount);
		printf("CP :%d포인트\n", cp);
		printf("%s의 기분과 친밀도에 따라서 CP가 %d 포인트 생산되었습니다.\n", name, cpGain);
		if (feel > 0) {
			cpGain = (feel - 1) + realation;
		}
		else
		{
			cpGain = 0 + realation;
		}
		cp += cpGain;

		printf("쫀덕이의 기분(0~3): %d\n", feel);
		switch (feel)
		{
		case 0:
			printf("기분이매우나쁩니다.\n");
			break;
		case 1:
			printf("심심해합니다.\n");
			break;
		case 2:
			printf("식빵을굽습니다.\n");
			break;
		case 3:
			printf("골골송을부릅니다.\n");
			break;
		}
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
		if (turn == 3) {
			printf("랜덤 이벤트 발생!");
			int event = rand() % 3;
			switch (event)
			{
			case 1:
			case 2:
			case 3:
				break;
			}
		}
		//기분에 따른 움직임
		r = rand() % 6 + 1;
		printf("%d-%d: 주사위 눈이 %d이하이면 그냥 기분이 나빠집니다.\n", r, realation, r-realation);
		printf("주사위를 굴립니다. 또르르...\n");
		printf("%d이(가) 나왔습니다.\n", r);
		if (r <= 6 - realation) {
			printf("아무이유없이기분이나빠집니다. 고양이니까?\n");
			printf("%s의 기분이 나빠집니다: %d->%d\n", name, feel, feel - 1);
			if (feel > 0) {
				feel -= 1;
			}
		}

		if (feel == 0) {
			printf("기분이 매우 나쁜 %s은(는) 집으로 향합니다.\n", name);
			if (cat > HME_POS) {
				cat--;
			}
		}
		else if (feel == 1) {
			if (hasScratcher) {
				printf("놀거리가 없어서 기분이 매우 나빠집니다.\n");
				if (feel > 0) {
					feel--;
				}
			}
			else {
				printf("%s은(는) 심심해서 스크래처 쪽으로 이동합니다.\n", name);
				if (cat < BWL_PO) {
					cat++;
				}
			}
		}
		else if (feel == 2) {
			printf("%s은(는) 기분 좋게 식빵을 굽고 있습니다.\n", name);
		}

		else if (feel == 3) {
			printf("%s은(는) 골골송을 부르며 수프를 만들러 갑니다.\n", name);
			if (cat < ROOM_WIDTH - 1) {
				cat++;
			}
		}
		previousCat = cat;

		//스프 만들기
		if (cat == ROOM_WIDTH - 1) {
			soup = rand() % 3;
			if (soup == 0) {
				printf("%s이(가) 감자수프를 만들었습니다!\n", name);
				soupCount++;
				printf("현재 만든 수프 개수: %d\n", soupCount);
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

		//집에서 기분회복
		if(cat == HME_POS){
		
		}


		Sleep(500);
		printf("\n");
		

		//집 그리기
		for (height = 0; height < 4; height++) {
			printf("\n");
			for (width = 0; width <= ROOM_WIDTH; width++) {
				if (height == 0 || height == 3) {
					printf("#");
				}
				else if (width == 0 || width == ROOM_WIDTH) {
					printf("#");
				}
				else if (height == 1 && width == 1) {
					printf("H");
				}
				else if (height == 1 && width == scratcher && hasScratcher) {
					printf("S");  
				}
				else if (height == 1 && width == catTower && hasTower) {
					printf("T");  
				}
				else if (height == 1 && width == BWL_PO) {
					printf("B");
				}
				else if (height == 2 && width == cat) {
					printf("C");
				}
				else if (height == 2 && width == previousCat && previousCat != cat) {
					printf(".");
				}
				else {
					printf(" ");
				}
			}

		}
		//상호작용
		printf("\n");
		printf("==================================================\n");
		printf("\n");

		printf("어떤 상호작용을 하시겠습니까?\n0. 아무것도 하지 않음 \n1. 긁어주기\n2. 상점\n");
		if (mouseToy) {
			printf("3. 장난감 쥐로 놀아주기\n");
		}
		if (razerToy) {
			printf("4. 레이저 포인터로 놀아주기\n");
		}
		printf(">>");

		int input;
		while (true)
		{
			scanf_s("%d", &input);
			Sleep(500);
			if (input == 1 || input == 0|| input == 2) {
				break;
			}
			else if (input == 3 && mouseToy) {
				break;
			}
			else if (input == 4 && razerToy) {
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
				if (realation <= 4) {
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
		
		case 2:
			printf("상점에서 물건을 살 수 있습니다.\n어떤 물건을 구매할가요?\n");
			printf("0. 아무 것도 사지 않는다.\n");
			printf("1. 장난감 쥐: 1 CP\n");
			printf("2. 레이저 포인터: 2 CP\n");
			printf("3. 스크래처: 4 CP\n");
			printf("4, 캣 타워: 6 CP\n");
			printf(">>");

			int shopInput;
			scanf_s("%d", &shopInput);

			switch (shopInput)
			{
			case 0:
				break;
			case 1:
				if (cp >= 1) {
					if (mouseToy == true) {
						printf("이미 구매했습니다.\n");
						break;
					}
					printf("장난감 쥐를 구매했습니다.\n");
					cp -= 1;
					printf("보유 CP %d 포인트", cp);
					mouseToy = true;
				}
				else {
					printf("CP가 부족합니다.");
				}
				Sleep(500);
				system("cls");
				break;
			case 2:
				if (cp >= 2) {
					if (razerToy == true) {
						printf("이미 구매했습니다.\n");
					}
					printf("레이저 포인트를 구매했습니다.\n");
					cp -= 2;
					printf("보유 CP %d 포인트", cp);
					razerToy = true;
				
				}
				else {
					printf("CP가 부족합니다.");
				}
				Sleep(500);
				system("cls");
				break;
			case 3:
				if (cp >= 4) {
					if (hasScratcher == true) {
						printf("이미 구매했습니다.\n");
					}
					printf("스크래처를 구매했습니다.\n");
					cp -= 4;
					printf("보유 CP %d 포인트", cp);
					hasScratcher = true;
					scratcher = rand() % (ROOM_WIDTH - 2) + 2;
				}
				else {
					printf("CP가 부족합니다.");
				}
				Sleep(500);
				system("cls");
				break;
			case 4:
				if (cp >= 6) {
					if (hasTower == true) {
						printf("이미 구매했습니다.\n");
					}
					printf("캣타워를 구매했습니다.\n");
					cp -= 6;
					printf("보유 CP %d 포인트", cp);
					hasTower = true;
					catTower = rand() % (ROOM_WIDTH - 2) + 2;
				}
				else {
					printf("CP가 부족합니다.");
				}
				Sleep(500);
				system("cls");
				break;
			}
			Sleep(500);
			system("cls");
			break;

		case 3:
			printf("장난감 쥐로 %s와 놀아주었습니다.", name);
			printf("%s의 기분이 조금 좋아졌습니다.", name);
			feel++;
			if (r >= 4) {
				realation++;
			}
			Sleep(500);
			system("cls");
			break;

		case 4:
			printf("레이저 포인터로 %s와 신나게 놀아주었습니다.\n", name);
			printf("%s의 기분이 꽤 좋아졌습니다.", name);
			feel += 2;
			if (r >= 2) {
				realation++;
			}

			Sleep(500);
			system("cls");
			break;
		}
	}
	Sleep(2500);
	system("cls");
}

