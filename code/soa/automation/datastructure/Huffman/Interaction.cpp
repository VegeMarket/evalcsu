#include"Interaction.h"
#include<iostream>
#include<stdio.h>
#include<conio.h> 
#include<math.h>
#include<string>
using namespace std;
#define backColor 7
#define textColor 1

enum Color
{
	black, blue, green, lakeBlue, red, purple, yellow, white, gray
};

void Initialize()
{
	system("cls");
	//���ñ�����ɫ
	char command[9] = "color 07";		//Ĭ����ɫ	
	command[6] = '0' + backColor;		//��backColor������Ϊ�ַ���(������ɫ����Ϊ7��Ϊ��ɫ�� 
	command[7] = '0' + textColor;		//��textColor������Ϊ�ַ��� ��������ɫ����Ϊ1��Ϊ��ɫ��
	system(command);				    //����ϵͳ���� 
	//���ò˵�
	printf("                        **************����������������������***********\n");
	printf("                        |    \t0. �˳�                               |\n");
	printf("                        |    \t1. ��ӡ�ַ�����Ȩֵ�Լ��ַ����ı���   |\n");
	printf("                        |    \t2. ���ַ�������Ϊ����                 |\n");
	printf("                        |    \t3. �����뷭��Ϊ�ַ���                 |\n");
	printf("                        ***********************************************\n");
	
}

int Intercommand()
{
	cout << "����������ѡ��:";
	int input;
	while (1)
	{
		int n = Get_int();
		if (n >= 0 && n < 4)
		{
			input = n;
			break;
		}
			
		cout<<"������������䣺";
	}
	
	return input;
}

int Get_choose()
{
	char ch[21] = { 0 };
	int flag;
	int i = 0;
	while (1)
	{
		fflush(stdin);
		scanf_s("%s", ch, 20);
		if (ch[i] == 'y' || ch[i] == 'Y')
		{
			flag = 1;
			break;
		}
		else if (ch[i] == 'n' || ch[i] == 'N')
		{
			flag = 0;
			break;
		}
		else {
			cout << "�����������������" << endl;
		}
	}
	return flag;
}

char* Get_Capital_letter()
{
	char s[100] ;
	int i ;
	cin.get();
label2:
	i = 0;
	fflush(stdin);
	gets_s(s);
	while (s[i])
	{
		if (s[i] >= 65 && s[i] <= 90)
			i++;
		else if (s[i] == 32)
		{
			s[i++] = 32;
		}
		else if(s[i]==13){
			break;
		}
		else {
			cout << "������Ǵ�д��ĸ���ַ����޷����з���,���������룺" << endl;
			goto label2;
		}
		
	}
	s[i] = '\0';
	return s;
}

char* Get_01()
{
	char s[300] = { 0 };
	int i;
label3:
	i = 0;
	fflush(stdin);
	scanf_s("%s", s, 300);
	while (s[i])
	{
		if (s[i] =='0'||s[i]=='1')
			i++;
		else if (s[i] == 13) {
			break;
		}
		else {
			cout << "�������01���ַ����޷����з���,���������룺" << endl;
			goto label3;
		}

	}
	s[i] = '\0';
	return s;
}

void Is_refresh()
{
	printf("\n");
	cout << "----------------------------------------------------"<<endl;
	cout << "���������ַ���ɲ鿴���ص��˵�ҳ��:" << endl;
	_getch();
}

int Get_int()
{
	int num = 0,i=0;     //int
	char ch[11] = { 0 }; 
label1:
	num = 0;
	scanf_s("%s", ch,10);
	i = 0;
	if (ch[0] == 45 || ch[0] == 43)  //"+""-"
	{
		i++;
	}
	while (ch[i])
	{
		if (ch[i] < '0' || ch[i]>'9')
		{
			cout << "�����������������:" << endl;
			goto label1;
		}
		else {
			num = num * 10 + (int)ch[i] - 48;
		}
		i++;

	}
	if (ch[0] == 45)
	{
		return -num;
	}
	else
	{
		return num;
	}
}