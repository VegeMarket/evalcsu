#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include"file.h"
#include"Huffman.h"

using namespace std;
#define N  50
int g_flag = 0;

//�øú�����ȡÿ���ַ���Ӧ��Ȩֵ
void load_weightdata_file(HTNode hnode[])
{
	FILE* fp;
	int i = 0;
	fp = fopen("weightdata.txt", "r");
	if (fp == NULL)
	{
		cout<<"���ļ�ʧ��";
	}
	while (!feof(fp))
	{
		fscanf(fp, "%c", &(hnode[i].data));
		fscanf(fp, "%d", &(hnode[i].weight));
		fseek(fp, 2, SEEK_CUR);
		i++;
		if (i == N - 2)
			break;
	}
	g_flag = 1;
	fclose(fp);
}

char* load_code() {
	ifstream in("code.txt");
	char buffer[256];
	if (!in.is_open()) {
		cout << "�����ļ�����" << endl;
		return NULL;
	}
	cout << "��������ļ�" << endl;
	in.getline(buffer, 200, ' ');
	return buffer;
}

char* load_text()
{
	ifstream in("text.txt");
	char buffer[256]; 
	if (!in.is_open()) {
		cout << "�����ļ�����" << endl;
		return NULL;
	}
	cout << "����������ֶ�" << endl;
	in.getline(buffer, 100);

	return buffer;
}


//�øú�����������ַ��ı��� �ַ� ��Ӧ����
int Print_HuffMan_file()
{
	FILE* fp;
	char data[50], c;
	int d;
	fp = fopen("Huffman.txt", "r");
	if (fp == NULL )
	{
		printf("���ļ��������������\n");
		return -1;
	}
	while (1)
	{
		fscanf(fp, "%c%d%s", &c, &d, data);
		if (feof(fp))
			break;
		printf("%c\t%d\t%s\n", c, d, data);
		fseek(fp, 2, SEEK_CUR);
	}
	fclose(fp);
}
