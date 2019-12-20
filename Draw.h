#pragma once
#include<iostream>
#include<windows.h>
#include<conio.h> 
#include<stdlib.h>
#include<string> 
using namespace std;
#define WIDTH 100
#define HEIGHT 30
#define HIDDEN 0
#define SHOW 1 
int MenuStart = 38;
int MenuEnd = 59;
int MenuX = 22;
int MenuY = 15;

void gotoxy(int x, int y)
{
	COORD XY = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XY);
}

void CursorView(char show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
void InOption()
{
	system("mode con:cols=100 lines=30");
	CursorView(HIDDEN);
}
void TitleDraw()//타이틀 화면을 그리는 함수 
{
	gotoxy(6, 5);
	cout << "■■■ ■■■ ■    ■    ■ ■■■ ■■■     ■■■   ■   ■       ■   ■■■ ■■■" << endl;
	gotoxy(6, 6);
	cout << "  ■   ■  ■  ■  ■■  ■  ■     ■  ■     ■  ■ ■  ■ ■     ■  ■ ■     ■    " << endl;
	gotoxy(6, 7);
	cout << "  ■   ■  ■   ■■  ■■   ■■■ ■■       ■■   ■■■ ■     ■■■ ■     ■■■" << endl;
	gotoxy(6, 8);
	cout << "  ■   ■  ■    ■    ■    ■     ■ ■      ■     ■  ■ ■     ■  ■ ■     ■    " << endl;
	gotoxy(6, 9);
	cout << "  ■   ■■■    ■    ■    ■■■ ■  ■     ■     ■  ■ ■■■ ■  ■ ■■■ ■■■" << endl;
	gotoxy(42, 15);
	cout << "[  게임 시작  ]";
	gotoxy(42, 17);
	cout << "[   기   록   ]";
	gotoxy(42, 19);
	cout << "[  게임 종료  ]";
}

void WDraw()
{
	int loop;
	for (loop = 0; loop < WIDTH - 1; loop++)
	{
		gotoxy(loop, 0);
		if (loop == 0) cout << "┌";
		else if (loop == WIDTH - 2) cout << "┐";
		else cout << "─";
		gotoxy(loop, HEIGHT - 1);
		if (loop == 0) cout << "└";
		else if (loop == WIDTH - 2) cout << "┘";
		else cout << "─";
	}
}
void HDraw()
{
	int loop;
	for (loop = 1; loop < HEIGHT - 1; loop++)
	{
		gotoxy(0, loop);
		cout << "│";
		gotoxy(WIDTH - 2, loop);
		cout << "│";
	}
}

void CursorDraw(int S_X, int E_X, int Y)
{
	gotoxy(S_X, Y);
	cout << "☞";
	gotoxy(E_X, Y);
	cout << "☜";
}
void CursorClear(int S_X, int E_X, int Y)
{
	gotoxy(S_X, Y);
	cout << "  ";
	gotoxy(E_X, Y);
	cout << "  ";
}

void SelectYN(int &flag)
{
	int key = 0;
	while (1)
	{
		if (kbhit())
		{
			key = getch();
			if (key == 224)
			{
				key = getch();
			}
			switch (key)
			{
			case 75:
				if (MenuX > 22)
				{
					CursorClear(MenuX, MenuX + 11, MenuY - 2);
					MenuX -= 43;
				}
				break;
			case 77:
				if (MenuX < 65)
				{
					CursorClear(MenuX, MenuX + 11, MenuY - 2);
					MenuX += 43;
				}
				break;
			case 13:
				if (MenuX == 22)
				{
					system("cls");
					exit(1);
				}
				if (MenuX == 65) flag = 1;
				break;
			}
		}
		else break;
	}
}


void GameExitTitle()
{
	WDraw();
	HDraw();
	gotoxy(36, 10);
	cout << "[ 게임을 종료 하시겠습니까? ]";
	gotoxy(25, MenuY - 2);
	cout << "[ Yes ]";
	gotoxy(68, MenuY - 2);
	cout << "[ N o ]";
	CursorDraw(MenuX, MenuX + 11, MenuY - 2);
}
void GameExitDraw()
{
	system("cls");
	int ExitFlag = 0;
	while (!ExitFlag)
	{
		GameExitTitle();
		SelectYN(ExitFlag);
	}
	system("cls");
}

void Count_Draw(int i)
{
	switch (i)
	{
	case 9:
		cout << "■■■■■";
		gotoxy(44, 11);
		cout << "■      ■";
		gotoxy(44, 12);
		cout << "■      ■";
		gotoxy(44, 13);
		cout << "■■■■■";
		gotoxy(44, 14);
		cout << "        ■";
		gotoxy(44, 15);
		cout << "        ■";
		gotoxy(44, 16);
		cout << "        ■";
		gotoxy(44, 17);
		cout << "        ■";
		break;
	case 8:
		cout << "■■■■■";
		gotoxy(44, 11);
		cout << "■      ■";
		gotoxy(44, 12);
		cout << "■      ■";
		gotoxy(44, 13);
		cout << "■■■■■";
		gotoxy(44, 14);
		cout << "■      ■";
		gotoxy(44, 15);
		cout << "■      ■";
		gotoxy(44, 16);
		cout << "■      ■";
		gotoxy(44, 17);
		cout << "■■■■■";
		break;
	case 7:
		cout << "■■■■■";
		gotoxy(44, 11);
		cout << "■      ■";
		gotoxy(44, 12);
		cout << "■      ■";
		gotoxy(44, 13);
		cout << "■      ■";
		gotoxy(44, 14);
		cout << "        ■";
		gotoxy(44, 15);
		cout << "        ■";
		gotoxy(44, 16);
		cout << "        ■";
		gotoxy(44, 17);
		cout << "        ■";
		break;
	case 6:
		cout << "■       ";
		gotoxy(44, 11);
		cout << "■        ";
		gotoxy(44, 12);
		cout << "■        ";
		gotoxy(44, 13);
		cout << "■■■■■";
		gotoxy(44, 14);
		cout << "■      ■";
		gotoxy(44, 15);
		cout << "■      ■";
		gotoxy(44, 16);
		cout << "■      ■";
		gotoxy(44, 17);
		cout << "■■■■■";
		break;
	case 5:
		cout << "■■■■■";
		gotoxy(44, 11);
		cout << "■        ";
		gotoxy(44, 12);
		cout << "■        ";
		gotoxy(44, 13);
		cout << "■■■■■";
		gotoxy(44, 14);
		cout << "        ■";
		gotoxy(44, 15);
		cout << "        ■";
		gotoxy(44, 16);
		cout << "        ■";
		gotoxy(44, 17);
		cout << "■■■■■";
		break;
	case 4:
		cout << "■      ■";
		gotoxy(44, 11);
		cout << "■      ■";
		gotoxy(44, 12);
		cout << "■      ■";
		gotoxy(44, 13);
		cout << "■■■■■";
		gotoxy(44, 14);
		cout << "        ■";
		gotoxy(44, 15);
		cout << "        ■";
		gotoxy(44, 16);
		cout << "        ■";
		gotoxy(44, 17);
		cout << "        ■";
		break;
	case 3:
		cout << "■■■■■";
		gotoxy(44, 11);
		cout << "        ■";
		gotoxy(44, 12);
		cout << "        ■";
		gotoxy(44, 13);
		cout << "■■■■■";
		gotoxy(44, 14);
		cout << "        ■";
		gotoxy(44, 15);
		cout << "        ■";
		gotoxy(44, 16);
		cout << "        ■";
		gotoxy(44, 17);
		cout << "■■■■■";
		break;
	case 2:
		cout << "■■■■■";
		gotoxy(44, 11);
		cout << "        ■";
		gotoxy(44, 12);
		cout << "        ■";
		gotoxy(44, 13);
		cout << "■■■■■";
		gotoxy(44, 14);
		cout << "■        ";
		gotoxy(44, 15);
		cout << "■        ";
		gotoxy(44, 16);
		cout << "■        ";
		gotoxy(44, 17);
		cout << "■■■■■";
		break;
	case 1:
		cout << "  ■■    ";
		gotoxy(44, 11);
		cout << "■  ■    ";
		gotoxy(44, 12);
		cout << "    ■    ";
		gotoxy(44, 13);
		cout << "    ■    ";
		gotoxy(44, 14);
		cout << "    ■    ";
		gotoxy(44, 15);
		cout << "    ■    ";
		gotoxy(44, 16);
		cout << "    ■    ";
		gotoxy(44, 17);
		cout << "■■■■■";
		break;
	case 0:
		cout << "■■■■■";
		gotoxy(44, 11);
		cout << "■      ■";
		gotoxy(44, 12);
		cout << "■      ■";
		gotoxy(44, 13);
		cout << "■      ■";
		gotoxy(44, 14);
		cout << "■      ■";
		gotoxy(44, 15);
		cout << "■      ■";
		gotoxy(44, 16);
		cout << "■      ■";
		gotoxy(44, 17);
		cout << "■■■■■";
		break;
	}
}

class Monster {
public:
	string Name;
	int Hp;
	int Atk;
	int Def;
	int Exp;

	Monster(string name, int hp, int atk, int def, int exp) {
		Name = name;
		Hp = hp;
		Atk = atk;
		Def = def;
		Exp = exp;
	};
};

class MonsterData {
	//1-10층에 나오는 몬스터, 11-20층에 나오는 몬스터, 21-30층에 나오는 몬스터
	Monster List1[8] = {
		Monster("슬라임",20,5,0,45),
		Monster("고블린",50,7,2,65),
		Monster("진흙 골렘",100,5,0,40),
		Monster("오크",60,10,5,50),
		Monster("좀비",35,7,0,35),
		Monster("흡혈 박쥐",10,4,2,35),
		Monster("스켈레톤",20,10,2,60),
		Monster("미믹",40,10,3,80)
	};
	Monster List2[8] = {
		Monster("아이언 골렘",200,20,25,80),
		Monster("듀라한",140,30,10,100),
		Monster("하피",100,35,15,70),
		Monster("데몬",150,35,15,100),
		Monster("공포의 추격자",130,30,20,150),
		Monster("도살자",80,40,15,80),
		Monster("비홀더",70,20,15,70),
		Monster("미믹",100,20,20,100)
	};
	Monster List3[8] = {
		Monster("바실리스크",300,65,30,200),
		Monster("데스나이트",250,70,30,150),
		Monster("와이번",330,55,25,190),
		Monster("히드라",400,70,25,170),
		Monster("리치",270,65,20,200),
		Monster("웜",400,70,20,130),
		Monster("리빙아머",220,60,30,150),
		Monster("미믹",250,75,30,200)
	};
	int currentList = 0;

public:
	void SetList(int index)
	{
		currentList = index;
	}
	// SetList((floor - 1) / 10); 로 소환 리스트 결정
	Monster operator[](int i) {
		if (currentList == 0) return List1[i];
		if (currentList == 1) return List2[i];
		if (currentList == 2) return List3[i];
	}
};

class Player {
	int Lv = 1; //레벨
	int Exp = 0; //경험치
	int MaxHp = 100; //최대체력 > 특별한 이벤트가 없는한 올라가지않음 시작치 100고정
	int Hp = 100; //게임내에서 사용될 체력(가변)
	int Atk = 10;//공격력
	//공격시 데미지 계산법  rand() % 10 + Atk - Def
	int Def = 3;//방어력
	string Name;//플레이어 이름

	// 수정 한 곳. 
	int Play_Time = 0;
	int Name_byte;
	int Record_Floor = 1;
public:
	static int P_Number;  // 기록동작시에 플레이어의 넘버를 넣을 일종의 키 값
	void PlayerName() {
		//처음 캐릭터 생성할때 플레이어 네임을 기록하는 곳
		cout << "당신의 이름은 무엇인가요?" << endl;
		cin >> Name;
		Name_byte = Name.length();
		cout << "탑은 당신을 기억할거에요. " << Name << endl;
		Status();
		system("pause");
	}
	void FullHp() {
		cout << "당신의 모든 체력이 회복되었다" << endl;
		Hp = MaxHp;
	}
	void LvUp(int ex) {
		//레벨업
		Exp += ex;
		cout << ex << " 경험치 휙득" << endl;
		while (Exp >= 100)
		{
			Exp -= 100;
			Lv++;
			SetMaxHp(10);
			cout << "경험은 당신이 더 높은 곳으로 올라갈 수 있는 힘을 주었다." << endl;
			FullHp();
			Atk += rand() % 5 + 5;
			Def += rand() % 5;
			Status();
		}
		system("pause");
	}
	void Death_Check()// 죽음을 검사하는 곳 
	{
		if (Hp <= 0) // 현재 체력이 0보다 작거나 같으면 
		{
			GameOver_Draw(); // 게임 오버를 호출 
		}
	}
	void GameOver_Draw()
	{
		system("cls");// 화면을 정리 windows 헤더 필요 
		int i;
		char check;
		int check_mid;
		int mid2 = strlen("[[  이(가) 사망하였습니다 !! ]]");
		int mid3 = GetNameByte();
		check_mid = (WIDTH - (mid2 + mid3) + 2) / 2;

		for (i = 10; i >= 0; i--)
		{
			WDraw();
			HDraw();
			gotoxy(check_mid, HEIGHT*0.2);
			cout << "[[ " << Name << " 이(가) 사망하였습니다 !! ]]" << endl;
			gotoxy(WIDTH*0.28 + 5, HEIGHT*0.2 + 2);
			cout << "[[ 재도전 하시겠습니까? ( Y / N ) ]]" << endl;
			gotoxy(44, 10);
			Count_Draw(i);
			Sleep(1000); // 현실시간 1초 
			if (kbhit() != 0)  // 키보드가 입력되면 멈추게 하기위하여 
			{
				system("cls"); // 위의 지문들을 지운다 
				break; // for문을 탈출 
			}
		}
		while (1)
		{
			check = getch();
			if (check == 'Y' || check == 'y')
			{
				//타이틀로돌아가야함
				break;
			}
			else if (check == 'N' || check == 'n')
			{
				GameExitDraw();
				break;
			}
			else
			{
				cout << "[[ 잘못 입력하셨습니다( Y / N 를 입력하십시오) ]]" << endl;
			}
		}
		if (i == -1)
		{
			system("cls");
			GameExitDraw();
		}
	}
	void Attacked(int a, MonsterData mon)
	{
		system("cls");
		Monster m = mon[a];//몬스터 소환
		int damage; //몬스터 데미지를 저장할 변수할당
		int playerdamage;
		int play;
		int m_Maxhp = m.Hp;
		cout << "몬스터 " << m.Name << "이(가) 나타났다." << endl;
		while (true)
		{
			cout << "-----------------------------------------" << endl;
			damage = rand() % 10 + m.Atk;
			playerdamage = rand() % 10 + Atk - m.Def;
			cout << m.Name << "은(는)" << damage << " 데미지의 공격을 준비하고 있는 것 같다." << endl;
			cout << "[1] 공격   [2] 방어" << endl;
			cin >> play;
			if (play == 1) {
				//공격
				cout << P_Number << "번째 용사 " << "-" << Name << "의 공격" << endl;
				cout << "[[ " << m.Name << "이(가) " << max(playerdamage, 0)<< "만큼 데미지를 입었습니다 ]]" << endl;
				m.Hp -= max(playerdamage, 0);
				// 몬스터 체력 보이게 수정

				if (m.Hp >= 0)
				{
					cout << "[[ " << m.Name << "의 현재 체력 : " << m.Hp << "/" << m_Maxhp << " ]]" << endl;
				}

				if (m.Hp <= 0) {
					break;
				}
				cout << endl;
				cout << "-" << m.Name << "의 공격" << endl;
				cout << "[[ " << Name << "이(가) " << max(damage - Def, 0) << "만큼 데미지를 입었습니다 ]]" << endl;
				Hp -= max(damage - Def, 0); //둘중 큰값을 리턴하는 함수
				Death_Check();
				if (Hp <= 0) {
					break;
				}
				cout << "[[ " << Name << "의 현재 체력 : " << Hp << "/" << GetMaxHp() << " ]]" << endl;
			}
			else if (play == 2) {
				//방어
				cout << "당신은 " << m.Name << "의 공격을 훌륭하게 막아냈다." << endl;
			}
			cout << endl;
			cout << "-----------------------------------------" << endl;
			system("pause");
			system("cls");
		}
		//끝난 후
		if (Hp <= 0) {
			return;
		}
		cout << "-----------------------------------------" << endl;
		cout << "당신은 " << m.Name << "을(를) 물리쳤다!" << endl;
		LvUp(m.Exp);
		cout << "-----------------------------------------" << endl;
	}

	void Status() {
		cout << "-----------------------------------------" << endl;
		cout << "이름: " << Name << endl;
		cout << "레벨: " << Lv << endl;
		cout << "경험치: " << Exp << "/" << 100 << endl;
		cout << "체력: " << Hp << "/" << MaxHp << endl;
		cout << "공격력: " << Atk << endl;
		cout << "방어력: " << Def << endl;
		cout << "-----------------------------------------" << endl;
	}
	//다른 클래스에서 스테이터스 접근용으로 사용
	//경험치는 LvUp 기능 사용
	void SetAtk(int a) {
		Atk += a;
	}
	void SetDef(int a) {
		Def += a;
	}
	void SetHp(int a) {
		Hp += a;
	}
	void SetMaxHp(int a) {
		MaxHp += a;
	}
	void SetLv(int a) { Lv += a; }
	void SetName(string a) { Name = a; }
	void SetRecordFloor(int a) { Record_Floor = a; }
	int GetRecordFloor() { return Record_Floor; }
	int GetLv() { return Lv; }
	int GetAtk() {
		return Atk;
	}
	int GetDef() {
		return Def;
	}
	int GetHp() {
		return Hp;
	}
	int GetMaxHp() {
		return MaxHp;
	}
	string GetName() { return Name; }
	//수정
	int GetNameByte() { return Name_byte; }
	static void Number_Count() { P_Number += 1; }
	int SetPlayTime(int a) { return Play_Time += a; }
	int GetPlayTime() { return Play_Time; }
};
int Player::P_Number = 0;

class Event {

public:
	void eventselect(int a,Player p, MonsterData mon) {
		system("cls");
		cout<<"[이벤트!]"<<endl;
		switch (a)
		{
		case 0:
			AtkUp(p);
			break;
		case 1:
			DefUp(p);
			break;
		case 2:
			AtkDown(p);
			break;
		case 3:
			DefDown(p);
			break;
		case 5:
			HpUp(p);
			break;
		case 6:
			MaxHpUp(p);
			break;
		case 7:
			RandomBox(p,mon);
			break;
		case 8:
			chage_MaxHp(p);
			break;
		default:
			break;
		}

	}

	//스텟상승이벤트
	void AtkUp(Player p) {
	
		int a= rand() % 5 + 1;
		cout << "당신의 공격력이" << a << " 만큼 상승했다." << endl;
		p.SetAtk(a);
		system("pause");
	}
	void DefUp(Player p) {
		int a = rand() % 3 + 1;
		cout << "당신의 방어력이" << a << " 만큼 상승했다." << endl;
		p.SetDef(a);
		system("pause");
	}
	//스텟하락이벤트
	void AtkDown(Player p) {
		int a = -(rand() % 5 + 1);
		cout << "당신의 공격력이" << a << " 만큼 하락했다." << endl;
		p.SetAtk(a);
		system("pause");
	}
	void DefDown(Player p) {
		int a = -(rand() % 3 + 1);
		cout << "당신의 방어력이" << a << " 만큼 하락했다." << endl;
		p.SetDef(a);
		system("pause");
	}

	//체력회복이벤트
	void HpUp(Player p) {
		int num = (rand() % 5 + 1) * 10;//10에서 50까지의 체력 랜덤 상승 값
		if (p.GetHp() + num >= p.GetMaxHp()) { //체력회복값이 최대체력보다 크다면
			p.FullHp();
		}
		else {
			cout<<"당신의 체력이"<< num<< " 만큼 회복되었다." <<endl;
			p.SetHp(num);
		}
		system("pause");
	}
	//최대체력 상승이벤트
	void MaxHpUp(Player p) {
		int num = (rand() % 5 + 1) * 10;
		p.SetMaxHp(num);//10에서 50까지의 최대 체력 랜덤 상승
		cout << "당신의 최대체력이" << num << " 만큼 상승했다." << endl;
		p.SetHp(num);//상승한 만큼 체력도 같이 올려 줌
		system("pause");
	}

	//기타
	void RandomBox(Player p, MonsterData mon) {
		//짝수 일 경우 몬스터 미믹과 조우/홀수 일 경우 플레이어는 경험치 휙득
		if (0 == rand() % 2) {
			//짝수 
			p.Attacked(7,mon); //미믹 몬스터 번호 7번
		}
		else {
			//홀수
			p.LvUp((rand() % 10 + 1) * 10); //10에서 100까지의 경험치 랜덤 휙득

		}
	}
	//첨호 분량 
	//최대체력통을 현제 쳬력분량으로 변경
	void chage_MaxHp(Player p)
	{
		cout<<"당신은 저주에 걸렸다. 최대체력이 현제 체력으로 변경되었다."<<endl;
		p.SetMaxHp(p.GetHp());
		system("pause");
	}
};
