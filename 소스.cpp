#include <stdio.h>
#include <Windows.h>

void showScreen(); // 자판기 화면 출력
void selectDrink();// 음료수 선택 함수
void insertCoin(); // 동전 투입/반환 함수

static int money = 0, wallet = 3000;

struct drink
{
	char* name;
	int amount;
	int price; // name : 음료수 이름, amount : 음료수 갯수, price : 가격
};
typedef struct drink drink;

static drink kindOfDrink[7] = { {"Coke",2,900},{"Cider",3,800},{"Fanta",1,700},
{"Milktea",4,700},{"Orangejuice",4,500},{"Applejuice",4,500},{"Cocopalm",2,700} }; // 음료 종류

int main()
{
	int num;
	showScreen();
	while(1)
	{
		printf("숫자 입력:"); // 1:음료선택, 2:동전투입, 3:프로그램 종료
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
			printf("프로그램을 종료합니다.");				
			break;
		}
		else
		{
			system("cls");
			showScreen();
			printf("숫자를 잘못입력하셨습니다. 다시 입력해주세요.\n");
		}
	}
	return 0;
}

void showScreen()
{
	printf("자판기 프로그램\n-----------------------------------\n");
	for (int i = 0; i < 7; i++)
	{
		printf("%d번 음료: %-15s [가격:%d] - 남은 갯수:%d\n", i + 1, kindOfDrink[i].name, kindOfDrink[i].price, kindOfDrink[i].amount);
	}
	printf("현재 투입된 금액 : %d원\n", money);
	printf("현재 남아있는 돈 : %d원\n", wallet);
	printf("-----------------------------------\n");
	printf("명령어 사용 도움말\n");
	printf("1:음료수 선택\n2:동전 투입/회수\n3:프로그램 종료\n");
	return;
}

void selectDrink()
{
	int select, select2; // 입력받은 숫자를 임시 저장할 변수
	while (1)
	{
		while (1)
		{
			printf("-----------------------------------\n");
			printf("선택할 음료수 번호:");
			scanf_s("%d", &select);
			if (select <= 7 && select > 0)
				break;
			else
				printf("범위 밖의 숫자입니다. 다시 입력 해 주세요.\n");
		}
		if (money >= kindOfDrink[select-1].price) // 현재 가지고 있는 돈이 음료수 값보다 많은지 체크
		{
			if (kindOfDrink[select - 1].amount == 0) // 선택한 음료수의 재고가 남아있는지 체크
			{
				printf("해당 음료수는 품절되었습니다. 다른 음료수를 선택해주세요.\n");
			}
			else
			{
				money -= kindOfDrink[select - 1].price;
				kindOfDrink[select - 1].amount -= 1;
				system("cls");
				printf("선택하신 음료수가 나왔습니다.\n");
				printf("선택하신 음료수 : %s / 남은 돈 : %d원\n\n", kindOfDrink[select - 1].name, money);
				break;
			}
		}
		else
		{
			printf("돈이 모자릅니다.다른 음료수를 선택해주세요.\n");
		}
		printf("1:메인으로 돌아가기\n2:다른 음료수 선택\n번호 입력:");
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
			printf("잘못된 숫자를 입력하셨습니다. 메인으로 돌아갑니다.\n\n");
			break;
		}
	}
}


void insertCoin()
{
	int select, select2;
	printf("-----------------------------------\n");
	printf("현재 가지고 있는돈 : %d원\n", wallet);
	printf("투입 된 금액의 량 : %d원\n", money);
	while (1)
	{
		printf("-----------------------------------\n");
		printf("1:100원 투입 / 2:500원 투입 / 3:1000원 투입\n4:투입된 돈 반환\n5:메인으로 돌아가기\n");
		printf("숫자 입력:");
		scanf_s("%d", &select);
		printf("-----------------------------------\n");
		if (select == 1)
		{
			if (wallet >= 100) // 지갑의 돈이 투입하려는 돈 보다 많은지 체크
			{
				money += 100, wallet -= 100;
				printf("★100원 투입됨\n");
				printf("현재 투입된 금액:%d원\n", money);
			}
			else
			{
				printf("돈이 모자릅니다. 다시 시도해주세요\n");
				continue;
			}
		}
		if (select == 2)
		{
			if (wallet >= 500)
			{
				money += 500, wallet -= 500;
				printf("★500원 투입됨\n");
				printf("현재 투입된 금액:%d원\n", money);
			}
			else
			{
				printf("돈이 모자릅니다. 다시 시도해주세요\n");
				continue;
			}
		}
		if (select == 3)
		{
			if (wallet >= 1000)
			{
				money += 1000, wallet -= 1000;
				printf("★1000원 투입됨\n");
				printf("현재 투입된 금액:%d원\n", money);
			}
			else
			{
				printf("돈이 모자릅니다. 다시 시도해주세요\n");
				continue;
			}
		}
		if (select == 4)
		{
			if (money != 0)
			{
				wallet += money, money = 0;
				printf("투입된 돈이 반환되었습니다.\n");
				printf("현재 투입된 금액:%d원\n", money);
			}
			else
			{
				printf("투입된 돈이 없습니다.\n");
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
			printf("더 돈을 넣으시겠습니까?\n");
			printf("1:더 넣는다.\n2:메인으로 돌아간다.\n");
			printf("숫자 입력:");
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
				printf("잘못된 숫자를 입력하셨습니다. 메인으로 돌아갑니다.\n\n");
				break;
			}
		}
	}
}