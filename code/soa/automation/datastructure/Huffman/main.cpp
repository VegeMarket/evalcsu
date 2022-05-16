#include<iostream>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include"Huffman.h"
#include"Interaction.h"
#include"file.h"
using namespace std;

#define N 50		/*Ҷ�ӽ����*/
#define M 2*N-1		/*���н������*/

int n = 27;
int main() {
	int choose ; //ѡ�����
	HTNode ht[M];
	HCode hcd[N];//��������������͹���������

	load_weightdata_file(ht);
	CreateHT(ht, n);
	CreateHCode(ht, hcd, n);

	char s[100] = { 0 };
	char input_code[300] = { 0 };
	int y_or_n = 0;
	while (1)
	{
		Initialize();
		choose = Intercommand();
		switch (choose)
		{
		case 0:
			exit(0);
		case 1:
			/*����Ȩ�����*/
			Print_weightdata(ht);
		    //���б������
			DispHCode(ht, hcd, n);
			//����û��Ƿ�鿴��ϲ�����ҳ���ˢ��
			Is_refresh();
			break;
		case 2:
			/*�ļ���������ֶ������ַ���*/
			cout << "������Ҫ�ֶ������ַ�������ͨ���ļ�������Ҫ������ַ���,�ļ������밴y���ֶ������밴n:";
			fflush(stdin);
			getchar();
			y_or_n = Get_choose();
			if (y_or_n == 0)
			{
				/*
				cout << "�������ַ�����" << endl; //������㣺�����г����˷Ǵ�д��ĸ��ո�
				fflush(stdin);*/
				cout << "�������ַ�����" << endl;
				fflush(stdin); 
				strcpy_s(s, Get_Capital_letter());
				//gets_s(s);
				Encode(s, ht, hcd, n);
			}
			else if (y_or_n == 1)
			{
				strcpy_s(s, load_text());
				Encode(s, ht, hcd, n);
			}
			/*����û��Ƿ�鿴��ϲ�����ҳ���ˢ��*/
			Is_refresh();
			break;

		case 3:
			/*�ļ�������ֶ��������*/
			cout << "������Ҫ�ֶ�������뻹��ͨ���ļ�������Ҫ����ı���,�ļ������밴y���ֶ������밴n:";
			fflush(stdin);
			getchar();
			y_or_n = Get_choose();
			if (y_or_n == 0)
			{
				/*
				cout << "���������:";      //������㣺�����г����˷�0��1
				fflush(stdin);
				getchar();
				gets_s(input_code);
				*/
				cout << "��������룺" << endl;
				fflush(stdin);
				strcpy_s(input_code, Get_01());
				DeCode(input_code, n, ht);
			}
			else if (y_or_n == 1)
			{
				strcpy_s(input_code, load_code());
				DeCode(input_code, n,ht);
			}
			/*����û��Ƿ�鿴��ϲ�����ҳ���ˢ��*/
			Is_refresh();
			break;
		}
	}

	return 0;
}
