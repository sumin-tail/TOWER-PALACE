#include<iostream>
#include<windows.h> // system 사용 
#include<conio.h> // kbhit 사용 
#include<stdlib.h> // sleep 사용 
#include<string> //스트링 출력용
using namespace std;

class Player
{
	int Lv;
	int Exp;
	int MaxHp = 100; // 최대 체력 고정값 생성자에서 콜론초기화 가능 
	int G_Hp = MaxHp; // G_Hp(Game_Hp라는 뜻) 게임에 쓰일 현재 체력 변동에 쓰일 값 
	string Name = "도전자"; // 플레이어의 이름을 저장할 공간 
public:
	Player() : Lv(0), Exp(0) {}
	void LvUp(int ex)
	{
		Exp += ex;
		while (Exp >= 100)
		{
			Exp -= 100;
			Lv++;
		}
		std::cout << "LV : " << Lv << " exp : " << Exp << std::endl;
	}
	void Death_Check()// 죽음을 검사하는 곳 
	{
		if (G_Hp <= 0) // 현재 체력이 0보다 작거나 같으면 
		{
			GameOver(); // 게임 오버를 호출 
		}
	}
	void GameOver()
	{
		char check;
		int i;
		for (i = 10; i >= 0; i--)
		{
			system("cls");// 화면을 정리 windows 헤더 필요 
			cout << "[[ " << Name << " 이(가) 사망하였습니다 !! ]]" << endl;
			cout << "\n[[ 재도전 하시겠습니까? ( Y / N ) ]]" << endl;
			cout << "\t" << i << endl; // 10부터 0까지 떨어지는 초를 나타낼곳 
			Sleep(1000); // 현실시간 1초 
			if (kbhit() != 0)  // 키보드가 입력되면 멈추게 하기위하여 
			{
				system("cls"); // 위의 지문들을 지운다 
				break; // for문을 탈출 
			}
		}
		if (i == -1) // 시간동안 아무런 입력을 하지 않았을 시 
		{
			system("cls");
			cout << "[[ 게임을 종료하겠습니다 ]]" << endl;
			system("pause"); // 게임 종료 출력문을 한번 확인 하기 위하여 
			exit(1);
		}
		while (1)
		{
			cin >> check;
			if (check == 'Y' || check == 'y')
			{
				G_Hp = MaxHp;
				break;
			}
			else if (check == 'N' || check == 'n')
			{
				//위에서 사용한 게임종료 과정 사용	
				system("cls");
				cout << "[[ 게임을 종료하겠습니다 ]]" << endl;
				system("pause");
				exit(1);
			}
			else
			{
				cout << "[[ 잘못 입력하셨습니다( Y / N 를 입력하십시오) ]]" << endl;
			}
		}

	}

	void Attacked(int a)
	{
		system("cls");
		cout << "[[ " << Name << "이(가) " << a << "만큼 데미지를 입었습니다 ]]" << endl;
		G_Hp -= a;
		Death_Check();
		cout << "[[ " << Name << "의 현재 체력 : " << G_Hp << " ]]" << endl;
		system("pause");
	}
};

int main(void)
{
	Player a;
	while (1)
	{
		a.Attacked(rand() % 25 + 10);
	}
}
