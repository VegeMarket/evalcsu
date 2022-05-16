#include"Huffman.h"
#include<iostream>
#include<stdlib.h>

using namespace std;

void CreateHT(HTNode ht[], int n)
{
	int i, j, k, lnode, rnode;
	double min1, min2;

	for (int i = 0; i < 2 * n - 1; i++)
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1; //������������һ����ʼ��

	for (i = n; i < 2 * n - 1; i++) {
		min1 = min2 = 10000;
		lnode = rnode = -1;
		for (k = 0; k < i; k++) 
		{
			//ѭ�����ҵ���С�Ľ��
			if (ht[k].parent == -1) {
				if (ht[k].weight < min1) {
					min2 = min1; rnode = lnode;
					min1 = ht[k].weight; lnode = k;
				}
				else if (ht[k].weight < min2) {
					min2 = ht[k].weight; rnode = k;
				}
			}
		}
		ht[i].weight = ht[lnode].weight + ht[rnode].weight;
		ht[i].lchild = lnode; ht[i].rchild = rnode;
		ht[lnode].parent = i; ht[rnode].parent = i;
	}  //������Ĵ���
}

void CreateHCode(HTNode ht[], HCode hcd[], int n) {	 /*��������������*/
	int i, f, c;
	HCode hc;
	for (i = 0; i < n; i++) {
		hc.start = n; c = i;
		f = ht[i].parent;
		while (f != -1) {                         //������Ǹ��ڵ�,�ӵ�ǰ���ѭ����ֱ���������
			if (ht[f].lchild == c)               //���Ϊ�ýڵ������
				hc.cd[hc.start--] = '0';
			else
				hc.cd[hc.start--] = '1';
			c = f; f = ht[f].parent;
		}
		hc.start++;
		hcd[i] = hc;
	}
}

void DispHCode(HTNode ht[], HCode hcd[], int n) {	/*��ʾ�����ַ��Ĺ���������*/
	int i, k;
	int sum = 0, m = 0;
	cout << "���ַ����Ĺ�������������: " << endl;
	for (i = 0; i < n; i++) {
		cout << ht[i].data << " ";
		for (k = hcd[i].start; k <= n; k++) {
			cout << hcd[i].cd[k];
		}
		printf("\n");
	}
}


/*���ַ������б���*/
void Encode(char* s, HTNode ht[], HCode hcd[], int n) { /*��ʾ�ַ���s�Ĺ���������*/
	int i, j, k;
	for (i = 0; s[i] != '\0'; i++)
		cout << s[i];
	cout << "�Ĺ�����������: " << endl;
	i = j = 0;
	while (s[j] != '\0') {
		if (s[j] == ht[i].data) {
			for (k = hcd[i].start; k <= n; k++)
				cout << hcd[i].cd[k];
			j++;
			i = 0;
		}
		else
			i++;
	}
	cout << endl;
}

/*��������з��룬����Ϊ�ַ���*/
void  DeCode(string s, int n, HTNode h[])
{
	int i = 0, j = 0, lchild = 2 * n - 2, rchild = 2 * n - 2;
	while (s[i] != '\0') {
		if (s[i] == '0') {
			lchild = h[lchild].lchild;
			rchild = j = lchild;
		}
		if (s[i] == '1') {
			rchild = h[rchild].rchild;
			lchild = j = rchild;
		}
		if (h[lchild].lchild == -1 && h[rchild].rchild == -1) {
			cout << h[j].data;
			lchild = rchild = 2 * n - 2;
			j = 0;
		}
		i++;
	}
}

void Print_weightdata(HTNode hnode[],int n)
{
	int i;
	cout << "���ַ�����Ȩֵ����: " << endl;
	for (i = 0; i < n; i++) {
		cout << hnode[i].data << " ";
		cout << hnode[i].weight << endl;
	}
}