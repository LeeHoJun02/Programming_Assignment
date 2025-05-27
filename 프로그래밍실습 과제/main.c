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
	printf("****�߿��̿� ����**** \n");
	printf(" /\\_/\\ \n");
	printf(" / o.o \\ \n");
	printf(" ~(* *)~ \n");
	printf(" ^_^ \n");
	printf(" / || \\ \n");
	printf(" ( ()() )\n");
	printf("�߿����� �̸��� ���� �ּ���:");
	scanf_s("%s", name, sizeof(name));
	printf("�߿����� �̸��� %s�Դϴ�.", name);
	Sleep(1000);
	system("cls");

	while (true) {
		turn++;
		printf("==================== ���� ���� ===================\n");
		printf("������� ���� ����: %d��\n", soupCount);
		printf("CP :%d����Ʈ\n", cp);
		printf("%s�� ��а� ģ�е��� ���� CP�� %d ����Ʈ ����Ǿ����ϴ�.\n", name, cpGain);
		if (feel > 0) {
			cpGain = (feel - 1) + realation;
		}
		else
		{
			cpGain = 0 + realation;
		}
		cp += cpGain;

		printf("�˴����� ���(0~3): %d\n", feel);
		switch (feel)
		{
		case 0:
			printf("����̸ſ쳪�޴ϴ�.\n");
			break;
		case 1:
			printf("�ɽ����մϴ�.\n");
			break;
		case 2:
			printf("�Ļ��������ϴ�.\n");
			break;
		case 3:
			printf("�������θ��ϴ�.\n");
			break;
		}
		printf("������� ����(0~4): %d\n", realation);
		switch (realation) {
		case 0:
			printf("�翡���°������Ⱦ��մϴ�\n");
			break;
		case 1:
			printf("���� ���Ǳ� ����Դϴ�.\n");
			break;
		case 2:
			printf("�׷����� ������ �����Դϴ�.\n");
			break;
		case 3:
			printf("�Ǹ��� ����� �����ް� �ֽ��ϴ�.\n");
			break;
		case 4:
			printf("���� �������Դϴ�.\n");
			break;
		}
		printf("==================================================\n");
		if (turn == 3) {
			printf("���� �̺�Ʈ �߻�!");
			int event = rand() % 3;
			switch (event)
			{
			case 1:
			case 2:
			case 3:
				break;
			}
		}
		//��п� ���� ������
		r = rand() % 6 + 1;
		printf("%d-%d: �ֻ��� ���� %d�����̸� �׳� ����� �������ϴ�.\n", r, realation, r-realation);
		printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
		printf("%d��(��) ���Խ��ϴ�.\n", r);
		if (r <= 6 - realation) {
			printf("�ƹ��������̱���̳������ϴ�. ����̴ϱ�?\n");
			printf("%s�� ����� �������ϴ�: %d->%d\n", name, feel, feel - 1);
			if (feel > 0) {
				feel -= 1;
			}
		}

		if (feel == 0) {
			printf("����� �ſ� ���� %s��(��) ������ ���մϴ�.\n", name);
			if (cat > HME_POS) {
				cat--;
			}
		}
		else if (feel == 1) {
			if (hasScratcher) {
				printf("��Ÿ��� ��� ����� �ſ� �������ϴ�.\n");
				if (feel > 0) {
					feel--;
				}
			}
			else {
				printf("%s��(��) �ɽ��ؼ� ��ũ��ó ������ �̵��մϴ�.\n", name);
				if (cat < BWL_PO) {
					cat++;
				}
			}
		}
		else if (feel == 2) {
			printf("%s��(��) ��� ���� �Ļ��� ���� �ֽ��ϴ�.\n", name);
		}

		else if (feel == 3) {
			printf("%s��(��) ������ �θ��� ������ ���鷯 ���ϴ�.\n", name);
			if (cat < ROOM_WIDTH - 1) {
				cat++;
			}
		}
		previousCat = cat;

		//���� �����
		if (cat == ROOM_WIDTH - 1) {
			soup = rand() % 3;
			if (soup == 0) {
				printf("%s��(��) ���ڼ����� ��������ϴ�!\n", name);
				soupCount++;
				printf("���� ���� ���� ����: %d\n", soupCount);
			}
			else if (soup == 1) {
				printf("%s��(��) ����̼����� ��������ϴ�!\n", name);
				soupCount++;
				printf("���� ���� ���� ����: %d\n", soupCount);
			}
			else {
				printf("%s��(��) ����ݸ������� ��������ϴ�!\n", name);
				soupCount++;
				printf("���� ���� ���� ����: %d\n", soupCount);
			}
		}

		//������ ���ȸ��
		if(cat == HME_POS){
		
		}


		Sleep(500);
		printf("\n");
		

		//�� �׸���
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
		//��ȣ�ۿ�
		printf("\n");
		printf("==================================================\n");
		printf("\n");

		printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?\n0. �ƹ��͵� ���� ���� \n1. �ܾ��ֱ�\n2. ����\n");
		if (mouseToy) {
			printf("3. �峭�� ��� ����ֱ�\n");
		}
		if (razerToy) {
			printf("4. ������ �����ͷ� ����ֱ�\n");
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
			printf("�ƹ��͵� ���� �ʽ��ϴ�.\n");
			printf("4/6�� Ȯ���� ģ�е��� �������ϴ�.\n");
			printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
			r = rand() % 7;
			printf("%d��(��) ���Խ��ϴ�!\n", r);

			if (r >= 1 && r <= 4) {
				if (realation > 0) {
					printf("ģ�е��� �������ϴ�.\n");
					realation--;
					printf("���� ģ�е� : %d\n", realation);
				}
			}

			else {
				printf("������ ģ�е��� �������� �ʾҽ��ϴ�.");
				printf("���� ģ�е� : %d\n", realation);
			}
			Sleep(500);
			system("cls");
			break;

		case 1:

			printf("%s�� ���� �ܾ��־����ϴ�.", name);
			printf("2/6�� Ȯ���� ģ�е��� �������ϴ�.\n");
			printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
			int k = rand() % 7;
			printf("%d��(��) ���Խ��ϴ�!\n", k);
			if (k >= 5) {
				if (realation <= 4) {
					printf("ģ�е��� �������ϴ�.\n");
					realation++;
					printf("���� ģ�е� : %d\n", realation);
				}
			}

			else {
				printf("ģ�е��� �״���Դϴ�.");
				printf("���� ģ�е� : %d\n", realation);
			}
			Sleep(500);
			system("cls");
			break;
		
		case 2:
			printf("�������� ������ �� �� �ֽ��ϴ�.\n� ������ �����Ұ���?\n");
			printf("0. �ƹ� �͵� ���� �ʴ´�.\n");
			printf("1. �峭�� ��: 1 CP\n");
			printf("2. ������ ������: 2 CP\n");
			printf("3. ��ũ��ó: 4 CP\n");
			printf("4, Ĺ Ÿ��: 6 CP\n");
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
						printf("�̹� �����߽��ϴ�.\n");
						break;
					}
					printf("�峭�� �㸦 �����߽��ϴ�.\n");
					cp -= 1;
					printf("���� CP %d ����Ʈ", cp);
					mouseToy = true;
				}
				else {
					printf("CP�� �����մϴ�.");
				}
				Sleep(500);
				system("cls");
				break;
			case 2:
				if (cp >= 2) {
					if (razerToy == true) {
						printf("�̹� �����߽��ϴ�.\n");
					}
					printf("������ ����Ʈ�� �����߽��ϴ�.\n");
					cp -= 2;
					printf("���� CP %d ����Ʈ", cp);
					razerToy = true;
				
				}
				else {
					printf("CP�� �����մϴ�.");
				}
				Sleep(500);
				system("cls");
				break;
			case 3:
				if (cp >= 4) {
					if (hasScratcher == true) {
						printf("�̹� �����߽��ϴ�.\n");
					}
					printf("��ũ��ó�� �����߽��ϴ�.\n");
					cp -= 4;
					printf("���� CP %d ����Ʈ", cp);
					hasScratcher = true;
					scratcher = rand() % (ROOM_WIDTH - 2) + 2;
				}
				else {
					printf("CP�� �����մϴ�.");
				}
				Sleep(500);
				system("cls");
				break;
			case 4:
				if (cp >= 6) {
					if (hasTower == true) {
						printf("�̹� �����߽��ϴ�.\n");
					}
					printf("ĹŸ���� �����߽��ϴ�.\n");
					cp -= 6;
					printf("���� CP %d ����Ʈ", cp);
					hasTower = true;
					catTower = rand() % (ROOM_WIDTH - 2) + 2;
				}
				else {
					printf("CP�� �����մϴ�.");
				}
				Sleep(500);
				system("cls");
				break;
			}
			Sleep(500);
			system("cls");
			break;

		case 3:
			printf("�峭�� ��� %s�� ����־����ϴ�.", name);
			printf("%s�� ����� ���� ���������ϴ�.", name);
			feel++;
			if (r >= 4) {
				realation++;
			}
			Sleep(500);
			system("cls");
			break;

		case 4:
			printf("������ �����ͷ� %s�� �ų��� ����־����ϴ�.\n", name);
			printf("%s�� ����� �� ���������ϴ�.", name);
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

