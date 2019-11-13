#include<iostream>
#include<windows.h>
using namespace std;

#define WIDTH 100
#define HEIGHT 30
#define HIDDEN 0
#define SHOW 1

void gotoxy(int x,int y) //Ŀ���� �����̱� ���� �Լ� 
{
	COORD XY = {x,y}; // COORD ����ü ������ �ڷ���
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),XY); 
	// �����ϸ� 0�� ����. ù��° ���ڴ� Ŀ���� ��ġ, �ι�° ���ڴ� Ŀ���� �� ��
	// ù��° ���� GetStdHandle(STD_OUTPUT_HANDLE)�� ����͸� ���ϰ� STD_INPUT_HANDLE�� Ű���带 ���� 
}

void CursorView(char show) // Ŀ���� ���̰� ���� �ƴ��� ����� �Լ� 
{
	HANDLE hConsole; 
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show; // true�� ���̰� false�� ������ �ʰ� 
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole , &ConsoleCursor);
}

void Wdraw() //�������� �׸��� �Լ� 
{
	int loop;
	for(loop = 0 ; loop < WIDTH-1 ; loop++ )
	{
		gotoxy(loop,0);
		if(loop == 0) cout<<"��";
		else if(loop == WIDTH-2) cout<<"��";
		else cout<<"��";
		gotoxy(loop,HEIGHT-1);
		if(loop == 0) cout<<"��";
		else if(loop == WIDTH-2) cout<<"��";
		else cout<<"��";
	}
}
void Hdraw() //�������� �׸��� �Լ� 
{ 
	int loop;
	for(loop = 1 ; loop <HEIGHT-1 ; loop++ )
	{
		gotoxy(0,loop);
		cout<<"��";
		gotoxy(WIDTH-2,loop);
		cout<<"��";
	}
}

void TitleDraw() // Ÿ��Ʋȭ���� �׸��� �Լ� 
{
	gotoxy(6,5);
	cout<<"���� ���� ��    ��    �� ���� ����     ����   ��   ��       ��   ���� ����"<<endl;
	gotoxy(6,6);
	cout<<"  ��   ��  ��  ��  ���  ��  ��     ��  ��     ��  �� ��  �� ��     ��  �� ��     ��    "<<endl;
	gotoxy(6,7);
	cout<<"  ��   ��  ��   ���  ���   ���� ���       ���   ���� ��     ���� ��     ����"<<endl;
	gotoxy(6,8);
	cout<<"  ��   ��  ��    ��    ��    ��     �� ��      ��     ��  �� ��     ��  �� ��     ��    "<<endl;
	gotoxy(6,9);
	cout<<"  ��   ����    ��    ��    ���� ��  ��     ��     ��  �� ���� ��  �� ���� ����"<<endl;
	gotoxy(42,15);
	cout<<"[  ���� ����  ]";
	gotoxy(42,17);
	cout<<"[   ��   ��   ]";
	gotoxy(42,19);
	cout<<"[  ���� ����  ]";
}

void SelectMenu() // �޴� ���� Ŀ���� �׸��� �Լ�
//���� �̰����� ���� �޴��� �����ϰ� ����� �ɰ� ���� 
{
	gotoxy(39,15);
	cout<<"��";		
	gotoxy(58,15);
	cout<<"��"; 
}
void MapDraw() // ���� ����Լ����� �Ѱ����� ��Ƽ� ���� 
{
	Wdraw();
	Hdraw();
	TitleDraw();
	SelectMenu();
	Sleep(20);
}
int main(void)
{
	system("mode con:cols=100 lines=30"); // �����Ϸ� â�� ũ�⸦ ����  cols�� ���� lines�� ���� 
	CursorView(HIDDEN); // Ŀ���� ����� 
	while(1)
	{
		MapDraw();
	}
}
