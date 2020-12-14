#include <stdio.h>
#include <Windows.h>

void showScreen(); // ���Ǳ� ȭ�� ���
void selectDrink();// ����� ���� �Լ�
void insertCoin(); // ���� ����/��ȯ �Լ�

static int money = 0, wallet = 3000;

struct drink
{
	char* name;
	int amount;
	int price; // name : ����� �̸�, amount : ����� ����, price : ����
};
typedef struct drink drink;

static drink kindOfDrink[7] = { {"Coke",2,900},{"Cider",3,800},{"Fanta",1,700},
{"Milktea",4,700},{"Orangejuice",4,500},{"Applejuice",4,500},{"Cocopalm",2,700} }; // ���� ����

int main()
{
	int num;
	showScreen();
	while(1)
	{
		printf("���� �Է�:"); // 1:���ἱ��, 2:��������, 3:���α׷� ����
		scanf_s("%d", &num);
		if (num == 1)
		{
			selectDrink();
			showScreen();
		}
		else if (num == 2)
		{
			insertCoin();
			showScreen();
		}
		else if (num == 3)
		{
			printf("���α׷��� �����մϴ�.");				
			break;
		}
		else
		{
			system("cls");
			showScreen();
			printf("���ڸ� �߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n");
		}
	}
	return 0;
}

void showScreen()
{
	printf("���Ǳ� ���α׷�\n-----------------------------------\n");
	for (int i = 0; i < 7; i++)
	{
		printf("%d�� ����: %-15s [����:%d] - ���� ����:%d\n", i + 1, kindOfDrink[i].name, kindOfDrink[i].price, kindOfDrink[i].amount);
	}
	printf("���� ���Ե� �ݾ� : %d��\n", money);
	printf("���� �����ִ� �� : %d��\n", wallet);
	printf("-----------------------------------\n");
	printf("��ɾ� ��� ����\n");
	printf("1:����� ����\n2:���� ����/ȸ��\n3:���α׷� ����\n");
	return;
}

void selectDrink()
{
	int select, select2; // �Է¹��� ���ڸ� �ӽ� ������ ����
	while (1)
	{
		while (1)
		{
			printf("-----------------------------------\n");
			printf("������ ����� ��ȣ:");
			scanf_s("%d", &select);
			if (select <= 7 && select > 0)
				break;
			else
				printf("���� ���� �����Դϴ�. �ٽ� �Է� �� �ּ���.\n");
		}
		if (money >= kindOfDrink[select-1].price) // ���� ������ �ִ� ���� ����� ������ ������ üũ
		{
			if (kindOfDrink[select - 1].amount == 0) // ������ ������� ��� �����ִ��� üũ
			{
				printf("�ش� ������� ǰ���Ǿ����ϴ�. �ٸ� ������� �������ּ���.\n");
			}
			else
			{
				money -= kindOfDrink[select - 1].price;
				kindOfDrink[select - 1].amount -= 1;
				system("cls");
				printf("�����Ͻ� ������� ���Խ��ϴ�.\n");
				printf("�����Ͻ� ����� : %s / ���� �� : %d��\n\n", kindOfDrink[select - 1].name, money);
				break;
			}
		}
		else
		{
			printf("���� ���ڸ��ϴ�.�ٸ� ������� �������ּ���.\n");
		}
		printf("1:�������� ���ư���\n2:�ٸ� ����� ����\n��ȣ �Է�:");
		scanf_s("%d", &select2);
		if (select2 == 1)
		{
			system("cls");
			break;
		}
		else if (select2 == 2)
		{
			continue;
		}
		else
		{
			system("cls");
			printf("�߸��� ���ڸ� �Է��ϼ̽��ϴ�. �������� ���ư��ϴ�.\n\n");
			break;
		}
	}
}


void insertCoin()
{
	int select, select2;
	printf("-----------------------------------\n");
	printf("���� ������ �ִµ� : %d��\n", wallet);
	printf("���� �� �ݾ��� �� : %d��\n", money);
	while (1)
	{
		printf("-----------------------------------\n");
		printf("1:100�� ���� / 2:500�� ���� / 3:1000�� ����\n4:���Ե� �� ��ȯ\n5:�������� ���ư���\n");
		printf("���� �Է�:");
		scanf_s("%d", &select);
		printf("-----------------------------------\n");
		if (select == 1)
		{
			if (wallet >= 100) // ������ ���� �����Ϸ��� �� ���� ������ üũ
			{
				money += 100, wallet -= 100;
				printf("��100�� ���Ե�\n");
				printf("���� ���Ե� �ݾ�:%d��\n", money);
			}
			else
			{
				printf("���� ���ڸ��ϴ�. �ٽ� �õ����ּ���\n");
				continue;
			}
		}
		if (select == 2)
		{
			if (wallet >= 500)
			{
				money += 500, wallet -= 500;
				printf("��500�� ���Ե�\n");
				printf("���� ���Ե� �ݾ�:%d��\n", money);
			}
			else
			{
				printf("���� ���ڸ��ϴ�. �ٽ� �õ����ּ���\n");
				continue;
			}
		}
		if (select == 3)
		{
			if (wallet >= 1000)
			{
				money += 1000, wallet -= 1000;
				printf("��1000�� ���Ե�\n");
				printf("���� ���Ե� �ݾ�:%d��\n", money);
			}
			else
			{
				printf("���� ���ڸ��ϴ�. �ٽ� �õ����ּ���\n");
				continue;
			}
		}
		if (select == 4)
		{
			if (money != 0)
			{
				wallet += money, money = 0;
				printf("���Ե� ���� ��ȯ�Ǿ����ϴ�.\n");
				printf("���� ���Ե� �ݾ�:%d��\n", money);
			}
			else
			{
				printf("���Ե� ���� �����ϴ�.\n");
				continue;
			}
		}
		if (select == 5)
		{
			system("cls");
			break;
		}
		else
		{
			printf("-----------------------------------\n");
			printf("�� ���� �����ðڽ��ϱ�?\n");
			printf("1:�� �ִ´�.\n2:�������� ���ư���.\n");
			printf("���� �Է�:");
			scanf_s("%d",&select2);
			if (select2 == 1)
				continue;
			else if (select2 == 2)
			{
				system("cls");
				break;
			}
			else
			{
				system("cls");
				printf("�߸��� ���ڸ� �Է��ϼ̽��ϴ�. �������� ���ư��ϴ�.\n\n");
				break;
			}
		}
	}
}