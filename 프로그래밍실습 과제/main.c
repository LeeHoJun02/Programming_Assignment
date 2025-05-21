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
		printf("==================== ���� ���� ===================\n");
		printf("������� ���� ����: %d��\n", soupCount);
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

		printf("%s �̵�: ����� ģ���Ҽ��� ���� ������ �� Ȯ���� �������ϴ�.\n", name);
		printf("�ֻ��� ���� 3 �̻��̸� ���� ������ �̵��մϴ�.\n");
		printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
		r = rand() % 7;
		printf("%d��(��) ���Խ��ϴ�!\n", r);

		if (r > 6 - realation) {
			printf("���� ������ �����Դϴ�.\n");
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
					printf("%s��(��) ���ڼ����� ��������ϴ�!\n",name);
					soupCount++;
					printf("���� ���� ���� ����: %d\n",soupCount);
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
		}

		else {
			printf("�� ������ �����Դϴ�.\n");
			if (cat > HME_POS) {
				previousCat = cat;
				cat--;
				if (cat == 1) {
					printf("%s��(��) �ڽ��� ������ ������� �����ϴ�. ", name);
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

		printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�? 0. �ƹ��͵� ���� ���� 1. �ܾ��ֱ�\n");
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
				if (realation < 4) {
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
		} 
	}
	Sleep(2500);
	system("cls");
}

