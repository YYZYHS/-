#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ��������Ԫ������
typedef int ElemType;

// ��������������
typedef struct LNode
{
	ElemType data;			// ���������ڴ������Ԫ��
	struct LNode* next;		// ָ�������ڴ�ź�̽��ĵ�ַ
} LNode, * LinkList;		// LNode Ϊ������ͣ�����ǿ����㣻LinkList Ϊ���ָ�����ͣ�����ǿ������

int main() 
{
	printf("Hello, World!\n");
	return 0;
}