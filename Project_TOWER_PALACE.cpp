#include "Draw.h"
#include <time.h>
#define MAX 5 
void MapDraw() // 洹몃━???⑥닔??珥앷큵 
{
	WDraw();
	HDraw();
	TitleDraw();
	CursorDraw(MenuStart, MenuEnd, MenuY);
	Sleep(20);
}
void Record(Player &p, Player* p_list)
{
	p_list[Player::P_Number].SetName(p.GetName());
	p_list[Player::P_Number].SetAtk(p.GetAtk());
	p_list[Player::P_Number].SetLv(p.GetLv());
	p_list[Player::P_Number].SetDef(p.GetDef());
	p_list[Player::P_Number].SetPlayTime(p.GetPlayTime());
	p_list[Player::P_Number].SetRecordFloor(p.GetRecordFloor());
}
void GameStart(Player* p_List)
{
	Player p;
	Event e;
	MonsterData mon;
	time_t begin, end;
	begin = time(NULL);
	system("cls");
	int Floor = 1;
	p.PlayerName();

	while (Floor <= 30)
	{
		mon.SetList((Floor - 1) / 10);
		system("cls");
		WDraw();
		HDraw();
		gotoxy(WIDTH / 2 - 3, HEIGHT / 2);
		cout << Floor << "층";
		Sleep(1000);
		if (2>rand() % 10) {
			e.eventselect(rand() % 9, p,mon);
		}
		else{
			p.Attacked(rand() % 8,mon);
			if (p.GetHp() <= 0) {
				break;
			}
		}
		Floor++;
		p.SetRecordFloor(Floor);
	}
	if (p.GetHp() <= 0) {
		end = time(NULL);
		p.SetPlayTime(end - begin);
		Record(p, p_List);
		return;
	}
	system("cls");
	cout << endl;
	end = time(NULL);
	p.SetPlayTime(end - begin);
	Record(p, p_List);
	cout <<"당신의 도움으로 "<< p.GetName() << "은 탑의 30층까지 등반하는것에 성공했다. " << endl;
	cout << endl;
	cout << "5초뒤에 메인화면으로 돌아갑니다." << endl;
	Sleep(5000);
	system("cls");

}
void Show_Record(Player* p_List, int i)
{
	if (Player::P_Number == 0) { cout << "[[ 기록이 존재하지 않습니다 ]]" << endl; }
	if (i != 0)
	{
		cout << "=============================" << endl;
		cout << i << "번째 용사 : " << p_List[i].GetName() << "   Lv : " << p_List[i].GetLv() << endl;
		cout << "공격력 : " << p_List[i].GetAtk() << "   방어력 : " << p_List[i].GetDef() << endl;
		cout << "도달한 층수 : " << p_List[i].GetRecordFloor() << "   플레이 타임 : " << p_List[i].GetPlayTime() << " 초" << endl;
		cout << "=============================" << endl;
	}
}
void GameRecord(Player* p_List)
{
	system("cls");
	for (int i = 0; i <= Player::P_Number; i++)
	{
		Show_Record(p_List, i);
	}
	system("pause");
	system("cls");
}
void GameExit()
{
	system("cls");
	GameExitDraw();
}
void SelectMenu(Player* p_List) //硫붾돱 ?좏깮???꾪븳 ?⑥닔 
{
	int key = 0;
	while (1)
	{
		if (kbhit()) //kbhit() != 0 ?대옉 媛숈? ?? 利?kbhit媛 1?쇰븣留??묐룞. ?ㅻ낫?쒓? ?낅젰諛쏆븯?꾨븣留??묐룞?쒕떎????
		{
			key = getch(); // ?낅젰?섏뿀?꾨븣??媛믪쓣 ?ㅻ줈 ?ｋ뒗??
			if (key == 224) // 224 ??諛⑺뼢?ㅼ쓽 ?꾩뒪?ㅼ퐫?쒖씠??
			{
				key = getch(); // ?ㅼ떆?쒕쾲 寃??, 諛⑺뼢?ㅻ뒗 4媛쒓? 紐⑤몢 224??媛믪쓣 媛吏湲곗뿉 ?쒕쾲 ??泥댄겕瑜??섎뒗 寃?
			}
			switch (key)
			{
			case 72: // 諛⑺뼢???꾩쓽 ?꾩뒪??媛?
				if (MenuY > 15) // 泥ル쾲吏?硫붾돱??y?꾩튂媛 15?닿린 ?뚮Ц????紐??щ씪媛寃??섍린 ?꾪븿 
				{
					CursorClear(MenuStart, MenuEnd, MenuY);
					MenuY -= 2; // 媛믪씠 以꾩뼱???꾨줈 ?щ씪媛꾨떎. 2以?諛곗뿴怨?媛숈? 援ъ“?닿린 ?뚮Ц??
				}
				break;
			case 80://諛⑺뼢???꾨옒???꾩뒪??媛?
				if (MenuY < 19)
				{
					CursorClear(MenuStart, MenuEnd, MenuY);
					MenuY += 2;
				}
				break;
			case 13: // ?뷀꽣???꾩뒪??媛?
				if (MenuY == 15)
				{
					Player::Number_Count();
					GameStart(p_List);
				}
				if (MenuY == 17) { GameRecord(p_List); }
				if (MenuY == 19) GameExit();
				break;
			}
		}
		else break;
	}
}

int main(void)
{

	InOption();
	srand(time(NULL));
	Player *p_List = new Player[MAX];
	while (1)
	{
		MapDraw();
		SelectMenu(p_List);

	}

}

