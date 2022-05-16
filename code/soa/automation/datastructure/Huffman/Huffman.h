#ifndef HUFFMAN_H
#define HUFFMAN_H

#include<string>
#define N 50		/*Ҷ�ӽ����*/
#define M 2*N-1		/*���н������*/
using namespace std;

/*ʵ��˼·��
һ.���ɴ����ļ��еĸ��ַ���Ƶ�ʼ�������ַ��Ĺ����������룬�ɴ˵õ����������
��������������������Ϣ��1.�ý���Ӧ�ı��루���뵽HCode�е�cd�У� 2.Ȩ�أ�����Ƶ�ʣ�
						  3.��ĸ��㣬���ӽ�㣬���ӽ��
��.�����ַ����������Ѿ�������ÿ���ַ���Ӧ�ı��룬��ֱ�Ӱ�ÿ���ַ���������ͺ���*/

typedef struct {
	char data;           //������ֵ,�˴�ΪABCD.....
	unsigned int weight; //����ÿ���ڵ��Ȩ��
	unsigned int parent, lchild, rchild;
}HTNode,*HuffmanTree;

typedef struct {
	char cd[N];
	int start;
}HCode; //����
void Print_weightdata(HTNode hnode[],int n=27);     //���Ȩֵ
void CreateHT(HTNode ht[], int n);		           //������������,�����������ת��Ϊ��
void CreateHCode(HTNode ht[], HCode hcd[], int n); //����������������
void DispHCode(HTNode ht[], HCode hcd[], int n);    //��ӡ�ַ�������
void Encode(char* s, HTNode ht[], HCode hcd[], int n);//ʵ�ֱ��벢��ӡ
void DeCode(string s, int n, HTNode h[]);//ʵ�����벢��ӡ


#endif // !HUFFMAN_H

