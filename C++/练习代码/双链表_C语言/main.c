/**
 * @brief ˫������ϰ����
 * @file main.c
 * @date 2024��8��7��
 * @version 1.0
 * @author YYZYHS
 * @note
 *		����һ��˫�������ϰ����,�ƻ�ʵ��˫����Ļ�������:
 *		1.��ʼ��˫����
 * 		2.����˫����
 *		3.���˫����
 *      4.�ж�˫�����Ƿ�Ϊ��
 *		5.��ȡ˫����ĳ���
 */

#include <stdlib.h>
#include <stdio.h>
#include <cstdbool>

// ����Ԫ������
typedef int Element;

// ����˫������
typedef struct DNode
{
	Element data;			// ������
	struct DNode* prior;	// ǰ��ָ��
	struct DNode* next;		// ���ָ��
}DNode, * DLinkList;

/**
* @brief ��ʼ��˫����
 * @param L ˫����
 * @return ��ʼ���ɹ�����1,���򷵻�0
 */

int main() {
	printf("Hello, World!\n");
	return 0;
}
