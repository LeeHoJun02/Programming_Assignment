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
	int relation = 2;
	int cat = HME_POS;
	int previousCat = cat;
	int soupCount = 0;
	int cp = 0;
	int cpGain = 0;
	int feel = 3;
	int width;
	int height;
	int scratcher = 0;
	int catTower = 0;
	int gameTurn = 0;
	int houseTurn = 0;
	bool hasTower = false;
	bool hasScratcher = false;
	bool house = false;
	bool mouseToy = false;
	bool razerToy = false;

	srand(time(NULL));
	//이름 입력
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

	//상태 출력
	while (true) {
		gameTurn++;
		printf("==================== 현재 상태 ===================\n");
		printf("현재까지 만든 수프: %d개\n", soupCount);
		printf("CP :%d포인트\n", cp);		

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
		printf("집사와의 관계(0~4): %d\n", relation);
		switch (relation) {
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

		//기분 나빠짐
		r = rand() % 6 + 1;
		printf("%d-%d: 주사위 눈이 %d이하이면 그냥 기분이 나빠집니다.\n", r, relation, 6 - relation);
		printf("주사위를 굴립니다. 또르르...\n");
		printf("%d이(가) 나왔습니다.\n", r);
		if (r <= 6 - relation) {
			printf("아무이유없이기분이나빠집니다. 고양이니까?\n");
			printf("%s의 기분이 나빠집니다: %d->%d\n", name, feel, feel - 1);
			if (feel > 0) {
				feel -= 1;
			}
		}

		//기분에 따른 움직임

		if (feel == 0) {
			printf("기분이 매우 나쁜 %s은(는) 집으로 향합니다.\n", name);
			if (cat > HME_POS) {
				cat--;
			}
			if (cat == HME_POS) {
				if (houseTurn == 0) {
					printf("%s이(가) 집에 도착했습니다.\n", name);
					houseTurn++;
				}
				if (houseTurn >= 1) {
					printf("%s이(가) 집에서 휴식을 취합니다.\n", name);
					if (feel < 3) {
						feel++;
					}
				}
			}
		}
		else if (feel == 1) {
			if (!hasScratcher) {
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
				if (cat == scratcher && hasScratcher) {
					printf("%s이(가) 스크래처에서 긁고 놀았습니다.\n", name);
					if (feel < 3) {
						feel++;
						if (feel > 3) feel = 3;
					}
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

		if (previousCat == HME_POS && cat != HME_POS) {
			houseTurn = 0;
		}

		if (cat == catTower && hasTower) {
			printf("%s이(가) 캣타워에서 뛰어다닙니다.\n", name);
			if (feel < 3) {
				feel += 2;
				if (feel > 3) feel = 3;
			}

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
			if (input == 1 || input == 0 || input == 2) {
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
				if (relation > 0) {
					printf("친밀도는 떨어집니다.\n");
					relation--;
					printf("현재 친밀도 : %d\n", relation);
				}
			}

			else {
				printf("다행히 친밀도가 떨어지지 않았습니다.");
				printf("현재 친밀도 : %d\n", relation);
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
				if (relation <= 4) {
					printf("친밀도가 높아집니다.\n");
					relation++;
					printf("현재 친밀도 : %d\n", relation);
				}
			}

			else {
				printf("친밀도는 그대로입니다.");
				printf("현재 친밀도 : %d\n", relation);
			}
			Sleep(500);
			system("cls");
			break;

		case 2:
			printf("장난감 쥐로 %s와 놀아주었습니다.", name);
			printf("%s의 기분이 조금 좋아졌습니다.", name);
			feel++;
			if (r >= 4) {
				relation++;
			}
			Sleep(500);
			system("cls");
			break;

		case 3:
			printf("레이저 포인터로 %s와 신나게 놀아주었습니다.\n", name);
			printf("%s의 기분이 꽤 좋아졌습니다.", name);
			feel += 2;
			if (r >= 2) {
				relation++;
			}

			Sleep(500);
			system("cls");
			break;
		}

		//CP생산
		printf("%s의 기분과 친밀도에 따라서 CP가 %d 포인트 생산되었습니다.\n", name, cpGain);
		printf("현재 보유 CP: %d 포인트\n", cp);
		if (feel > 0) {
			cpGain = (feel - 1) + relation;
		}
		else
		{
			cpGain = 0 + relation;
		}
		cp += cpGain;

		//상점
		printf("상점에서 물건을 살 수 있습니다.\n어떤 물건을 구매할가요?\n");
		printf("0. 아무 것도 사지 않는다.\n");
		if (mouseToy == false) {
			printf("1. 장난감 쥐: 1 CP\n");
		}
		else {
			printf("1. 장난감 쥐(품절)\n");
		}
		if (razerToy == false) {
			printf("2. 레이저 포인터: 2 CP\n");
		}
		else {
			printf("2. 레이저 포인터(품절)\n");
		}
		if (hasScratcher == false) {
			printf("3. 스크래처: 4 CP\n");
		}
		else {
			printf("3. 스크래처(품절)\n");
		}
		if (hasTower == false) {
			printf("4. 캣 타워: 6 CP\n");
		}
		else {
			printf("4. 캣 타워(품절)\n");
		}
		printf(">>");

		int shopInput;
		scanf_s("%d", &shopInput);

		switch (shopInput)
		{
		case 0:
			Sleep(500);
			system("cls");
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

		//돌발 퀘스트 
		if (gameTurn % 3 == 0) {
			printf("랜덤 이벤트 발생!\n");
			int choice;
			int event = rand() % 3 + 1;
			printf("%s가 갑자기 사라졌습니다.\n", name);
			printf("어디를 찾아볼까요.\n");
			printf("1. 주방\n2. 거실\n3. 화장실\n>>");
			do {
				printf(">> ");
				scanf_s("%d", &choice);
				if (choice < 1 || choice > 3) {
					printf("잘못된 입력입니다. 1~3 사이의 숫자를 입력하세요.\n");
				}
			} while (choice < 1 || choice > 3);

			printf("1~3 사이의 숫자를 입력하세요.\n>> ");
			if (choice == event) {
				printf("%s를 찾았습니다.\n", name);
				printf("기분이 좋아집니다.\n");
				if (feel < 4) {
					feel++;
				}
				if (relation < 4) {
					relation++;
				}
				Sleep(500);
				system("cls");
			}
			else {
				printf("%s를 찾지 못했습니다.\n", name);
				printf("기분이 매우 나빠집니다.\n");
				if (feel > 0) {
					feel--;
				}
				if (relation > 0) {
					relation--;
				}
				Sleep(500);
				system("cls");
			}
		}

	}
	Sleep(2500);
	system("cls");
}

