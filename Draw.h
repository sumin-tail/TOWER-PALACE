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
void TitleDraw()//Ÿ��Ʋ ȭ���� �׸��� �Լ� 
{
	gotoxy(6, 5);
	cout << "���� ���� ��    ��    �� ���� ����     ����   ��   ��       ��   ���� ����" << endl;
	gotoxy(6, 6);
	cout << "  ��   ��  ��  ��  ���  ��  ��     ��  ��     ��  �� ��  �� ��     ��  �� ��     ��    " << endl;
	gotoxy(6, 7);
	cout << "  ��   ��  ��   ���  ���   ���� ���       ���   ���� ��     ���� ��     ����" << endl;
	gotoxy(6, 8);
	cout << "  ��   ��  ��    ��    ��    ��     �� ��      ��     ��  �� ��     ��  �� ��     ��    " << endl;
	gotoxy(6, 9);
	cout << "  ��   ����    ��    ��    ���� ��  ��     ��     ��  �� ���� ��  �� ���� ����" << endl;
	gotoxy(42, 15);
	cout << "[  ���� ����  ]";
	gotoxy(42, 17);
	cout << "[   ��   ��   ]";
	gotoxy(42, 19);
	cout << "[  ���� ����  ]";
}

void WDraw()
{
	int loop;
	for (loop = 0; loop < WIDTH - 1; loop++)
	{
		gotoxy(loop, 0);
		if (loop == 0) cout << "��";
		else if (loop == WIDTH - 2) cout << "��";
		else cout << "��";
		gotoxy(loop, HEIGHT - 1);
		if (loop == 0) cout << "��";
		else if (loop == WIDTH - 2) cout << "��";
		else cout << "��";
	}
}
void HDraw()
{
	int loop;
	for (loop = 1; loop < HEIGHT - 1; loop++)
	{
		gotoxy(0, loop);
		cout << "��";
		gotoxy(WIDTH - 2, loop);
		cout << "��";
	}
}

void CursorDraw(int S_X, int E_X, int Y)
{
	gotoxy(S_X, Y);
	cout << "��";
	gotoxy(E_X, Y);
	cout << "��";
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
	cout << "[ ������ ���� �Ͻðڽ��ϱ�? ]";
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
		cout << "������";
		gotoxy(44, 11);
		cout << "��      ��";
		gotoxy(44, 12);
		cout << "��      ��";
		gotoxy(44, 13);
		cout << "������";
		gotoxy(44, 14);
		cout << "        ��";
		gotoxy(44, 15);
		cout << "        ��";
		gotoxy(44, 16);
		cout << "        ��";
		gotoxy(44, 17);
		cout << "        ��";
		break;
	case 8:
		cout << "������";
		gotoxy(44, 11);
		cout << "��      ��";
		gotoxy(44, 12);
		cout << "��      ��";
		gotoxy(44, 13);
		cout << "������";
		gotoxy(44, 14);
		cout << "��      ��";
		gotoxy(44, 15);
		cout << "��      ��";
		gotoxy(44, 16);
		cout << "��      ��";
		gotoxy(44, 17);
		cout << "������";
		break;
	case 7:
		cout << "������";
		gotoxy(44, 11);
		cout << "��      ��";
		gotoxy(44, 12);
		cout << "��      ��";
		gotoxy(44, 13);
		cout << "��      ��";
		gotoxy(44, 14);
		cout << "        ��";
		gotoxy(44, 15);
		cout << "        ��";
		gotoxy(44, 16);
		cout << "        ��";
		gotoxy(44, 17);
		cout << "        ��";
		break;
	case 6:
		cout << "��       ";
		gotoxy(44, 11);
		cout << "��        ";
		gotoxy(44, 12);
		cout << "��        ";
		gotoxy(44, 13);
		cout << "������";
		gotoxy(44, 14);
		cout << "��      ��";
		gotoxy(44, 15);
		cout << "��      ��";
		gotoxy(44, 16);
		cout << "��      ��";
		gotoxy(44, 17);
		cout << "������";
		break;
	case 5:
		cout << "������";
		gotoxy(44, 11);
		cout << "��        ";
		gotoxy(44, 12);
		cout << "��        ";
		gotoxy(44, 13);
		cout << "������";
		gotoxy(44, 14);
		cout << "        ��";
		gotoxy(44, 15);
		cout << "        ��";
		gotoxy(44, 16);
		cout << "        ��";
		gotoxy(44, 17);
		cout << "������";
		break;
	case 4:
		cout << "��      ��";
		gotoxy(44, 11);
		cout << "��      ��";
		gotoxy(44, 12);
		cout << "��      ��";
		gotoxy(44, 13);
		cout << "������";
		gotoxy(44, 14);
		cout << "        ��";
		gotoxy(44, 15);
		cout << "        ��";
		gotoxy(44, 16);
		cout << "        ��";
		gotoxy(44, 17);
		cout << "        ��";
		break;
	case 3:
		cout << "������";
		gotoxy(44, 11);
		cout << "        ��";
		gotoxy(44, 12);
		cout << "        ��";
		gotoxy(44, 13);
		cout << "������";
		gotoxy(44, 14);
		cout << "        ��";
		gotoxy(44, 15);
		cout << "        ��";
		gotoxy(44, 16);
		cout << "        ��";
		gotoxy(44, 17);
		cout << "������";
		break;
	case 2:
		cout << "������";
		gotoxy(44, 11);
		cout << "        ��";
		gotoxy(44, 12);
		cout << "        ��";
		gotoxy(44, 13);
		cout << "������";
		gotoxy(44, 14);
		cout << "��        ";
		gotoxy(44, 15);
		cout << "��        ";
		gotoxy(44, 16);
		cout << "��        ";
		gotoxy(44, 17);
		cout << "������";
		break;
	case 1:
		cout << "  ���    ";
		gotoxy(44, 11);
		cout << "��  ��    ";
		gotoxy(44, 12);
		cout << "    ��    ";
		gotoxy(44, 13);
		cout << "    ��    ";
		gotoxy(44, 14);
		cout << "    ��    ";
		gotoxy(44, 15);
		cout << "    ��    ";
		gotoxy(44, 16);
		cout << "    ��    ";
		gotoxy(44, 17);
		cout << "������";
		break;
	case 0:
		cout << "������";
		gotoxy(44, 11);
		cout << "��      ��";
		gotoxy(44, 12);
		cout << "��      ��";
		gotoxy(44, 13);
		cout << "��      ��";
		gotoxy(44, 14);
		cout << "��      ��";
		gotoxy(44, 15);
		cout << "��      ��";
		gotoxy(44, 16);
		cout << "��      ��";
		gotoxy(44, 17);
		cout << "������";
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
	//1-10���� ������ ����, 11-20���� ������ ����, 21-30���� ������ ����
	Monster List1[8] = {
		Monster("������",20,5,0,45),
		Monster("���",50,7,2,65),
		Monster("���� ��",100,5,0,40),
		Monster("��ũ",60,10,5,50),
		Monster("����",35,7,0,35),
		Monster("���� ����",10,4,2,35),
		Monster("���̷���",20,10,2,60),
		Monster("�̹�",40,10,3,80)
	};
	Monster List2[8] = {
		Monster("���̾� ��",200,20,25,80),
		Monster("�����",140,30,10,100),
		Monster("����",100,35,15,70),
		Monster("����",150,35,15,100),
		Monster("������ �߰���",130,30,20,150),
		Monster("������",80,40,15,80),
		Monster("��Ȧ��",70,20,15,70),
		Monster("�̹�",100,20,20,100)
	};
	Monster List3[8] = {
		Monster("�ٽǸ���ũ",300,65,30,200),
		Monster("��������Ʈ",250,70,30,150),
		Monster("���̹�",330,55,25,190),
		Monster("�����",400,70,25,170),
		Monster("��ġ",270,65,20,200),
		Monster("��",400,70,20,130),
		Monster("�����Ƹ�",220,60,30,150),
		Monster("�̹�",250,75,30,200)
	};
	int currentList = 0;

public:
	void SetList(int index)
	{
		currentList = index;
	}
	// SetList((floor - 1) / 10); �� ��ȯ ����Ʈ ����
	Monster operator[](int i) {
		if (currentList == 0) return List1[i];
		if (currentList == 1) return List2[i];
		if (currentList == 2) return List3[i];
	}
};

class Player {
	int Lv = 1; //����
	int Exp = 0; //����ġ
	int MaxHp = 100; //�ִ�ü�� > Ư���� �̺�Ʈ�� ������ �ö������� ����ġ 100����
	int Hp = 100; //���ӳ����� ���� ü��(����)
	int Atk = 10;//���ݷ�
	//���ݽ� ������ ����  rand() % 10 + Atk - Def
	int Def = 3;//����
	string Name;//�÷��̾� �̸�

	// ���� �� ��. 
	int Play_Time = 0;
	int Name_byte;
	int Record_Floor = 1;
public:
	static int P_Number;  // ��ϵ��۽ÿ� �÷��̾��� �ѹ��� ���� ������ Ű ��
	void PlayerName() {
		//ó�� ĳ���� �����Ҷ� �÷��̾� ������ ����ϴ� ��
		cout << "����� �̸��� �����ΰ���?" << endl;
		cin >> Name;
		Name_byte = Name.length();
		cout << "ž�� ����� ����Ұſ���. " << Name << endl;
		Status();
		system("pause");
	}
	void FullHp() {
		cout << "����� ��� ü���� ȸ���Ǿ���" << endl;
		Hp = MaxHp;
	}
	void LvUp(int ex) {
		//������
		Exp += ex;
		cout << ex << " ����ġ �׵�" << endl;
		while (Exp >= 100)
		{
			Exp -= 100;
			Lv++;
			SetMaxHp(10);
			cout << "������ ����� �� ���� ������ �ö� �� �ִ� ���� �־���." << endl;
			FullHp();
			Atk += rand() % 5 + 5;
			Def += rand() % 5;
			Status();
		}
		system("pause");
	}
	void Death_Check()// ������ �˻��ϴ� �� 
	{
		if (Hp <= 0) // ���� ü���� 0���� �۰ų� ������ 
		{
			GameOver_Draw(); // ���� ������ ȣ�� 
		}
	}
	void GameOver_Draw()
	{
		system("cls");// ȭ���� ���� windows ��� �ʿ� 
		int i;
		char check;
		int check_mid;
		int mid2 = strlen("[[  ��(��) ����Ͽ����ϴ� !! ]]");
		int mid3 = GetNameByte();
		check_mid = (WIDTH - (mid2 + mid3) + 2) / 2;

		for (i = 10; i >= 0; i--)
		{
			WDraw();
			HDraw();
			gotoxy(check_mid, HEIGHT*0.2);
			cout << "[[ " << Name << " ��(��) ����Ͽ����ϴ� !! ]]" << endl;
			gotoxy(WIDTH*0.28 + 5, HEIGHT*0.2 + 2);
			cout << "[[ �絵�� �Ͻðڽ��ϱ�? ( Y / N ) ]]" << endl;
			gotoxy(44, 10);
			Count_Draw(i);
			Sleep(1000); // ���ǽð� 1�� 
			if (kbhit() != 0)  // Ű���尡 �ԷµǸ� ���߰� �ϱ����Ͽ� 
			{
				system("cls"); // ���� �������� ����� 
				break; // for���� Ż�� 
			}
		}
		while (1)
		{
			check = getch();
			if (check == 'Y' || check == 'y')
			{
				//Ÿ��Ʋ�ε��ư�����
				break;
			}
			else if (check == 'N' || check == 'n')
			{
				GameExitDraw();
				break;
			}
			else
			{
				cout << "[[ �߸� �Է��ϼ̽��ϴ�( Y / N �� �Է��Ͻʽÿ�) ]]" << endl;
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
		Monster m = mon[a];//���� ��ȯ
		int damage; //���� �������� ������ �����Ҵ�
		int playerdamage;
		int play;
		int m_Maxhp = m.Hp;
		cout << "���� " << m.Name << "��(��) ��Ÿ����." << endl;
		while (true)
		{
			cout << "-----------------------------------------" << endl;
			damage = rand() % 10 + m.Atk;
			playerdamage = rand() % 10 + Atk - m.Def;
			cout << m.Name << "��(��)" << damage << " �������� ������ �غ��ϰ� �ִ� �� ����." << endl;
			cout << "[1] ����   [2] ���" << endl;
			cin >> play;
			if (play == 1) {
				//����
				cout << P_Number << "��° ��� " << "-" << Name << "�� ����" << endl;
				cout << "[[ " << m.Name << "��(��) " << max(playerdamage, 0)<< "��ŭ �������� �Ծ����ϴ� ]]" << endl;
				m.Hp -= max(playerdamage, 0);
				// ���� ü�� ���̰� ����

				if (m.Hp >= 0)
				{
					cout << "[[ " << m.Name << "�� ���� ü�� : " << m.Hp << "/" << m_Maxhp << " ]]" << endl;
				}

				if (m.Hp <= 0) {
					break;
				}
				cout << endl;
				cout << "-" << m.Name << "�� ����" << endl;
				cout << "[[ " << Name << "��(��) " << max(damage - Def, 0) << "��ŭ �������� �Ծ����ϴ� ]]" << endl;
				Hp -= max(damage - Def, 0); //���� ū���� �����ϴ� �Լ�
				Death_Check();
				if (Hp <= 0) {
					break;
				}
				cout << "[[ " << Name << "�� ���� ü�� : " << Hp << "/" << GetMaxHp() << " ]]" << endl;
			}
			else if (play == 2) {
				//���
				cout << "����� " << m.Name << "�� ������ �Ǹ��ϰ� ���Ƴ´�." << endl;
			}
			cout << endl;
			cout << "-----------------------------------------" << endl;
			system("pause");
			system("cls");
		}
		//���� ��
		if (Hp <= 0) {
			return;
		}
		cout << "-----------------------------------------" << endl;
		cout << "����� " << m.Name << "��(��) �����ƴ�!" << endl;
		LvUp(m.Exp);
		cout << "-----------------------------------------" << endl;
	}

	void Status() {
		cout << "-----------------------------------------" << endl;
		cout << "�̸�: " << Name << endl;
		cout << "����: " << Lv << endl;
		cout << "����ġ: " << Exp << "/" << 100 << endl;
		cout << "ü��: " << Hp << "/" << MaxHp << endl;
		cout << "���ݷ�: " << Atk << endl;
		cout << "����: " << Def << endl;
		cout << "-----------------------------------------" << endl;
	}
	//�ٸ� Ŭ�������� �������ͽ� ���ٿ����� ���
	//����ġ�� LvUp ��� ���
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
	//����
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
		cout<<"[�̺�Ʈ!]"<<endl;
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

	//���ݻ���̺�Ʈ
	void AtkUp(Player p) {
	
		int a= rand() % 5 + 1;
		cout << "����� ���ݷ���" << a << " ��ŭ ����ߴ�." << endl;
		p.SetAtk(a);
		system("pause");
	}
	void DefUp(Player p) {
		int a = rand() % 3 + 1;
		cout << "����� ������" << a << " ��ŭ ����ߴ�." << endl;
		p.SetDef(a);
		system("pause");
	}
	//�����϶��̺�Ʈ
	void AtkDown(Player p) {
		int a = -(rand() % 5 + 1);
		cout << "����� ���ݷ���" << a << " ��ŭ �϶��ߴ�." << endl;
		p.SetAtk(a);
		system("pause");
	}
	void DefDown(Player p) {
		int a = -(rand() % 3 + 1);
		cout << "����� ������" << a << " ��ŭ �϶��ߴ�." << endl;
		p.SetDef(a);
		system("pause");
	}

	//ü��ȸ���̺�Ʈ
	void HpUp(Player p) {
		int num = (rand() % 5 + 1) * 10;//10���� 50������ ü�� ���� ��� ��
		if (p.GetHp() + num >= p.GetMaxHp()) { //ü��ȸ������ �ִ�ü�º��� ũ�ٸ�
			p.FullHp();
		}
		else {
			cout<<"����� ü����"<< num<< " ��ŭ ȸ���Ǿ���." <<endl;
			p.SetHp(num);
		}
		system("pause");
	}
	//�ִ�ü�� ����̺�Ʈ
	void MaxHpUp(Player p) {
		int num = (rand() % 5 + 1) * 10;
		p.SetMaxHp(num);//10���� 50������ �ִ� ü�� ���� ���
		cout << "����� �ִ�ü����" << num << " ��ŭ ����ߴ�." << endl;
		p.SetHp(num);//����� ��ŭ ü�µ� ���� �÷� ��
		system("pause");
	}

	//��Ÿ
	void RandomBox(Player p, MonsterData mon) {
		//¦�� �� ��� ���� �̹Ͱ� ����/Ȧ�� �� ��� �÷��̾�� ����ġ �׵�
		if (0 == rand() % 2) {
			//¦�� 
			p.Attacked(7,mon); //�̹� ���� ��ȣ 7��
		}
		else {
			//Ȧ��
			p.LvUp((rand() % 10 + 1) * 10); //10���� 100������ ����ġ ���� �׵�

		}
	}
	//÷ȣ �з� 
	//�ִ�ü������ ���� �Ƿºз����� ����
	void chage_MaxHp(Player p)
	{
		cout<<"����� ���ֿ� �ɷȴ�. �ִ�ü���� ���� ü������ ����Ǿ���."<<endl;
		p.SetMaxHp(p.GetHp());
		system("pause");
	}
};
