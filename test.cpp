#include<iostream>
#include<windows.h> // system ��� 
#include<string> //��Ʈ�� ��¿�
using namespace std;

//�÷��̾� ����
int Lv; //����
int Exp; //����ġ
int MaxHp; //�ִ�ü�� > Ʋ���� �̺�Ʈ�� ������ �ö������� ����ġ 100����
int Hp; //���ӳ����� ���� ü��(����)
int Atk;//���ݷ�
//���ݽ� ������ ����  rand() % 10 + Atk - Def
int Def;//����
string Name;//�÷��̾� �̸�
int Money;//�����ý����� �ִ´ٸ� ������

//���ͺ���
int M_Atk;//���� ���ݷ�
int M_Def;//���� ����
string M_Name;//���� �̸�

//��Ÿ
int Floor; //���� �÷��̾��� ��


//�Լ� �̸�
void LvUp(int ex); //�������Լ� >����ġ �����Ҷ� ȣ��
void Death_Check(); //���üũ ü���� 0���ϸ� ���ӿ����Լ� ȣ��
void GameOver(); //���ӿ��� �Լ�


void main() {
	system("cls");// ȭ���� �����ϴ� �Լ� windows ��� �ʿ� 
}