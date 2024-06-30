#include <stdlib.h>				// ��׼�⺯��,������һЩ���õĺ���,��malloc(),free(),exit()��
#include <stdio.h>				// ��׼��������⺯��,������һЩ���õ������������,��printf(),scanf()��
#include <stdbool.h>			// C99b��׼�����ͷ�ļ�,������bool��true��false�Ⱥ�

/*
 *		����C���԰治��ͷ���ĵ�����ļ�ʵ�ְ���
 *		��Ҫ�����˵�����Ĵ��������롢ɾ�������ҡ������Ȳ���
 *
 *		���ڲ���ͷ���,�����ڲ��롢ɾ���Ȳ���ʱ��Ҫ�ر�ע�⴦��ͷ�������
 */

 /*1��ǰ��׼��*/
typedef int ElemType;		// ��������洢����������,����Ϊ����
typedef struct LNode
{
	ElemType data;			// ������
	struct LNode* next;		// ָ����
}LNode, * LinkList;			// LNodeΪ�������,LinkListΪ���ָ������

/*2�����������������*/
void printList(LinkList L);								// ��ӡ�������
LNode* createNewNode(ElemType e);						// �����½��
bool initList(LinkList* L);								// ��ʼ��һ���ձ�
bool initListByHeadInsert(LinkList* L);					// ��ǰ�巨��ʼ��һ������
bool initListByTailInsert(LinkList* L);					// ��β�巨��ʼ��һ������
LNode* getElem(LinkList L, int i);						// ��λ����
int locateElem(LinkList L, ElemType e);					// ��ֵ����
bool insertPreNode(LinkList* L, LNode* p, ElemType e);	// ��ָ������ǰ������½��
bool insertNextNode(LNode* p, ElemType e);				// ��ָ�����ĺ�������½��
bool insertElem(LinkList* L, int i, ElemType e);			// ��λ����---��巨
bool insertElemByHead(LinkList* L, int i, ElemType e);	// ��λ����---ǰ�巨
bool deleteElem(LinkList* L, int i);						// ɾ��
bool destroyList(LinkList *L);							// ����
bool isEmpty(LinkList L);								// �п�
int length(LinkList L);									// ��ȡ����


/*3������ĳ��ú�������ӡ���*/
void printList(LinkList L)
{
	if(NULL == L)											// �������Ϊ��
	{
		printf("����Ϊ��\n");
		return;
	}
	LNode* p = L;											// ��ͷ��㿪ʼ����
	while (p != NULL)										// ��������
	{
		printf("%d-->", p->data);							// ����������
		p = p->next;										// �ƶ�����һ�����
	}
	printf("NULL\n");										// ������������־
}

/*4������Ļ�����������ʼ��*/
// �����½��
LNode* createNewNode(ElemType e)
{
	LNode* newNode = (LNode*)malloc(sizeof(LNode));			// Ϊ�½������ڴ�
	if (newNode == NULL)									// �ڴ����ʧ��
	{
		printf("�ڴ����ʧ��\n");
		exit(0);
	}
	newNode->data = e;										// �����ݴ����½��
	newNode->next = NULL;									// ���½���ָ�����ÿ�
	return newNode;											// �����½��
}

// ��ʼ��һ���ձ�
bool  initList(LinkList* L)
{
	// ��Ϊ����ͷ��㣬���Գ�ʼ��ʱ����Ҫ����ͷ��㣬ֱ�ӽ�ͷָ���ÿռ���
	*L = NULL;
	return true;
}

// ��ǰ�巨��ʼ��һ������
bool initListByHeadInsert(LinkList* L)
{
	if(*L != NULL)														// �������Ϊ�գ����ÿ�
	{
		*L = NULL;
	}

	ElemType data = 9999;												// ���ڴ�����������
	while (true)														// ѭ����������
	{
		printf("������һ��Ԫ�ص�ֵ,����9999������������������");
		int len = scanf("%d", &data);									// ��������
		if (data == 9999)
		{
			break;
		}
		LNode* newNode = createNewNode(data);							// �����½��
		if(NULL == newNode)												// ����ʧ��
		{
			printf("�ڴ����ʧ��!��������ʧ�ܣ�\n");
			destroyList(*L);											// �����Ѵ���������
			return false;
		}
		newNode->next = *L;												// ���½����뵽��ͷ
		*L = newNode;													// ����ͷָ��
	}
	printf("�������ɹ�\n");
	return true;
}

// ��β�巨��ʼ��һ������
bool initListByTailInsert(LinkList* L)
{
	if(NULL != *L)														// �������Ϊ�գ����ÿ�
	{
		*L = NULL;
	}
	ElemType data = 9999;												// ���ڴ�����������
	LNode *tail = NULL;													// βָ��
	while (true)														// ѭ����������
	{
		printf("������һ��Ԫ�ص�ֵ,����9999������������������");
		int len = scanf("%d", &data);									// ��������
		if (data == 9999)
		{
			break;
		}
		LNode* newNode = createNewNode(data);							// �����½��
		if(NULL == newNode)												// ����ʧ��
		{
			printf("�ڴ����ʧ��!��������ʧ�ܣ�\n");
			destroyList(*L);											// �����Ѵ���������
			return false;
		}
		if(NULL == *L)													// ����ǵ�һ�����
		{
			*L = newNode;												// ����ͷָ��
			tail = newNode;												// ����βָ��
		}
		else
		{
			tail->next = newNode;										// ���½����뵽��β
			tail = newNode;												// ����βָ��
		}
	}
	printf("�������ɹ�\n");
	return true;
}

/*5������Ļ�������������*/
// ��λ����
LNode* getElem(LinkList L, int i)
{
	if(isEmpty(L))													// �������Ϊ��
	{
		printf("����Ϊ��\n");
		return NULL;
	}
	if(i < 1)														// λ�ò��Ϸ�
	{
		printf("λ�ò��Ϸ�\n");
		return NULL;
	}
	LNode* p = L;													// ��ͷ��㿪ʼ����
	int j = 1;														// ������
	while (p != NULL && j < i)										// ��������
	{
		p = p->next;												// �ƶ�����һ�����
		j++;														// ��������1
	}
	if(j == i && NULL != p)											// �ҵ��˵�i�����
	{
		return p;													// ���ظý��
	}
	else															// û�ҵ�
	{
		printf("��%d��Ԫ�ز�����\n", i);
		return NULL;
	}
}

// ��ֵ����
int locateElem(LinkList L, ElemType e)
{
	if(isEmpty(L))													// �������Ϊ��
	{
		printf("����Ϊ��\n");
		return -1;
	}
	LNode* p = L;													// ��ͷ��㿪ʼ����
	int i = 1;														// ������
	while (p != NULL && p->data != e)								// ��������
	{
		p = p->next;												// �ƶ�����һ�����
		i++;														// ��������1
	}
	if(p != NULL)													// �ҵ���Ԫ��
	{
		return i;													// ����Ԫ��λ��
	}
	else															// û�ҵ�
	{
		printf("Ԫ��%d������\n", e);
		return -1;
	}
}

/*6������Ļ�������������*/
// ��ָ������ǰ������½��
bool insertPreNode(LinkList* L, LNode* p, ElemType e)
{
	if(NULL == p)													// ���ָ�����Ϊ��
	{
		printf("ָ�����Ϊ��\n");
		return false;
	}
	/*
	// ǰ�巨�����½�㷽��һ��ʱ�临�Ӷ�O(n)
	// ���ָ�������ͷ���
	LNode* q = L;													// ����һ��ָ��q����ͷ��㿪ʼ����,Ѱ��p��ǰ�����
	while (q != p)
	{
		q = q->next;
	}
	if (q == NULL)
	{
		printf("ָ����㲻��������\n");
		return false;
	}
	if(p == L)
	{
		LNode* newNode = createNewNode(e);							// �����½��
		if(NULL == newNode)											// ����ʧ��
		{
			printf("�ڴ����ʧ��!����ʧ�ܣ�\n");
			return false;
		}
		newNode->next = L;											// ���½����뵽��ͷ
		L = newNode;												// ����ͷָ��
		return true;
	}
	else
	{
		LNode* newNode = createNewNode(e);							// �����½��
		if(NULL == newNode)											// ����ʧ��
		{
			printf("�ڴ����ʧ��!����ʧ�ܣ�\n");
			return false;
		}
		newNode->next = p;											// ���½����뵽ָ������ǰ��
		q->next = newNode;											// ����ָ������ǰ������ָ����
		return true;
	}
	*/

	// ǰ�巨�����½�㷽������ʱ�临�Ӷ�O(1)
	LNode* newNode = createNewNode(e);								// �����½��
	if(NULL == newNode)												// ����ʧ��
	{
		printf("�ڴ����ʧ��!����ʧ�ܣ�\n");
		return false;
	}
	if(p == *L)														// ���ָ�������ͷ���
	{
		newNode->next = *L;											// ���½����뵽��ͷ
		*L = newNode;												// ����ͷָ��
		return true;
	}
	else
	{
		// ���Ժ�巨�����½�㣬Ȼ�󽻻�������
		newNode->next = p->next;									// ��巨�����½��
		p->next = newNode;
		ElemType temp = p->data;									// ����������
		p->data = newNode->data;
		newNode->data = temp;
	}
}

// ��ָ�����ĺ�������½��
bool insertNextNode(LNode* p, ElemType e)
{
	if(NULL == p)													// ���ָ�����Ϊ��
	{
		printf("ָ�����Ϊ��\n");
		return false;
	}
	LNode* newNode = createNewNode(e);								// �����½��
	if(NULL == newNode)												// ����ʧ��
	{
		printf("�ڴ����ʧ��!����ʧ�ܣ�\n");
		return false;
	}
	newNode->next = p->next;										// ���½����뵽ָ�����ĺ���
	p->next = newNode;												// ����ָ������ָ����
	return true;
}

// ��λ���� --- ��巨
bool insertElem(LinkList* L, int i, ElemType e)
{
	if (i < 1)														// λ�ò��Ϸ�
	{
		printf("����λ�ò��Ϸ�\n");
		return false;
	}
	
	if (i == 1)
	{
		LNode* newNode = createNewNode(e);							// �����½��
		if (NULL == newNode)											// ����ʧ��
		{
			printf("�ڴ����ʧ��!����ʧ�ܣ�\n");
			return false;
		}
		newNode->next = *L;											// ���½����뵽��ͷ
		*L = newNode;												// ����ͷָ��
		return true;

	}
	LNode* p = getElem(*L, i - 1);									// ��ȡ��i-1�����
	return insertNextNode(p, e);									// �ڵ�i-1����������½��
}

// ��λ���� --- ǰ�巨
bool insertElemByHead(LinkList* L, int i, ElemType e)
{
	if(i < 1)														// λ�ò��Ϸ�
	{
		printf("����λ�ò��Ϸ�\n");
		return false;
	}

	LNode* p = getElem(*L, i);										// ��ȡ��i�����
	return insertPreNode(L, p, e);									// �ڵ�i�����ǰ�����½��
}


/*7������Ļ���������ɾ��*/
bool deleteElem(LinkList* L, int i)
{
	if(i < 1)	// λ�ò��Ϸ�
	{
		printf("ɾ��λ�ò��Ϸ�\n");
		return false;
	}

	if(isEmpty(*L))	// �������Ϊ��
	{
		printf("����Ϊ��\n");
		return false;
	}

	if(i == 1)	// ɾ��ͷ���
	{
		LNode* p = *L;	// ����ͷ���
		*L = (*L)->next;	// ����ͷָ��
		free(p);	// �ͷ�ͷ���
		return true;
	}
	else
	{
		LNode* p = getElem(*L, i - 1);	// ��ȡ��i-1�����
		if(p == NULL || p->next == NULL)	// �����i-1����㲻���ڻ��ߵ�i����㲻����
		{
			printf("ɾ��λ�ò��Ϸ�\n");
			return false;
		}
		LNode* q = p->next;	// �����i�����
		p->next = q->next;	// ɾ����i�����
		free(q);	// �ͷŵ�i�����
		return true;
	}
}


/*8������Ļ�������������*/
bool destroyList(LinkList *L)
{
	if(NULL == L)	// �������ָ��Ϊ��
	{
		printf("����ָ��Ϊ��\n");
		return false;
	}
	LNode* p = *L;	// ��ͷ��㿪ʼ����
	while (p != NULL)
	{
		LNode* q = p->next;	// ������һ�����
		free(p);	// �ͷŵ�ǰ���
		p = q;	// �ƶ�����һ�����
	}
	*L = NULL;	// ͷָ���ÿ�
	return true;
}

/*9������ĳ��ú������п�*/
bool isEmpty(LinkList L)
{
	return L == NULL;
}

/*10������ĳ��ú�������ȡ����*/
int length(LinkList L)
{
	int len = 0;
	LNode* p = L;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

/*11��������*/
int main()
{
	// �����ǲ��Դ���

	// 1����ʼ����������
	printf("��ʼ���ԣ����ȳ�ʼ��������������\n");
	LinkList L1 = NULL, L2 = NULL, L3 = NULL;
	printf("��ʼ��ʼ����һ������������Ϊ�ձ�\n");
	initList(&L1);
	printf("��ʼ��ʼ���ڶ���������������ǰ�巨��ʼ��\n");
	initListByHeadInsert(&L2);
	printf("��ʼ��ʼ��������������������β�巨��ʼ��\n");
	initListByTailInsert(&L3);

	// 2����һ�δ�ӡ����������пպ����
	printf("��ʼ��ӡ��һ������\n");
	printList(L1);
	printf("��ʼ��ӡ�ڶ�������\n");
	printList(L2);
	printf("��ʼ��ӡ����������\n");
	printList(L3);
	printf("L1�Ƿ�Ϊ�գ�%s\n", isEmpty(L1) ? "��" : "��");
	printf("L2�Ƿ�Ϊ�գ�%s\n", isEmpty(L2) ? "��" : "��");
	printf("L3�Ƿ�Ϊ�գ�%s\n", isEmpty(L3) ? "��" : "��");
	printf("L1�ĳ��ȣ�%d\n", length(L1));
	printf("L2�ĳ��ȣ�%d\n", length(L2));
	printf("L3�ĳ��ȣ�%d\n", length(L3));

	// 3��L2��λ���ң��ֱ������βԪ�غ��м��Ԫ��
	printf("��ʼ����L2��λ����\n");
	LNode* p1 = getElem(L2, 1);
	LNode* p2 = getElem(L2, 3);
	LNode* p3 = getElem(L2, length(L2));
	LNode* p4 = getElem(L2, length(L2) + 1);
	printf("L2��1��Ԫ�أ�%d\n", p1->data);
	printf("L2��3��Ԫ�أ�%d\n", p2->data);
	printf("L2���һ��Ԫ�أ�%d\n", p3->data);
	printf("L2��%d��Ԫ�أ�%s\n", length(L2) + 1, p4 == NULL ? "������" : "����");

	// 4��L2��ֵ���ң��ֱ������βԪ�غ��м��Ԫ��
	printf("��ʼ����L2��ֵ����\n");
	int i1 = locateElem(L2, 1);
	int i2 = locateElem(L2, 3);
	int i3 = locateElem(L2, length(L2));
	printf("Ԫ��1��λ�ã�%d\n", i1);
	printf("Ԫ��3��λ�ã�%d\n", i2);
	printf("���һ��Ԫ�ص�λ�ã�%d\n", i3);

	// 5��L3��λ���룬�ֱ���ǰ�塢���ķ�ʽ���ڱ�ͷ����β�����в���Ԫ��
	printf("��ʼ����L3��λ����\n");
	printf("�ڱ�ͷ��ǰ�巽ʽ����Ԫ��100,%s\n", insertElemByHead(&L3, 1, 100) ? "�ɹ�" : "ʧ��");
	printf("�ڱ�β��ǰ�巽ʽ����Ԫ��200,%s\n", insertElemByHead(&L3, length(L3) + 1, 200) ? "�ɹ�" : "ʧ��");
	printf("���������ڶ���λ����ǰ�巽ʽ����Ԫ��300,%s\n", insertElemByHead(&L3, length(L3), 300) ? "�ɹ�" : "ʧ��");
	printList(L3);
	printf("�ڱ�ͷ�Ժ�巽ʽ����Ԫ��400,%s\n", insertElem(&L3, 1, 400) ? "�ɹ�" : "ʧ��");
	printf("�ڱ�β�Ժ�巽ʽ����Ԫ��500,%s\n", insertElem(&L3, length(L3) + 1, 500) ? "�ɹ�" : "ʧ��");
	printf("���������ڶ���λ���Ժ�巽ʽ����Ԫ��600,%s\n", insertElem(&L3, length(L3), 600) ? "�ɹ�" : "ʧ��");
	printList(L3);

	// 6��L3ɾ��Ԫ�أ��ֱ�ɾ����ͷ����β������Ԫ��
	printf("��ʼ����L3ɾ��Ԫ��\n");
	printf("ɾ����ͷԪ�أ�%s\n", deleteElem(&L3, 1) ? "�ɹ�" : "ʧ��");
	printList(L3);
	printf("ɾ����βԪ�أ�%s\n", deleteElem(&L3, length(L3)) ? "�ɹ�" : "ʧ��");
	printList(L3);
	printf("ɾ������Ԫ�أ�%s\n", deleteElem(&L3, length(L3) / 2) ? "�ɹ�" : "ʧ��");
	printList(L3);

	// 7��������������
	printf("��ʼ������������,Ϊ�˲������ٿձ��Ƚ�L1��Ϊ�ձ�\n");
	while (!isEmpty(L1))
	{
		deleteElem(&L1, 1);
	}
	printf("����L1��%s\n", destroyList(&L1) ? "�ɹ�" : "ʧ��");
	printf("����L2��%s\n", destroyList(&L2) ? "�ɹ�" : "ʧ��");
	printf("����L3��%s\n", destroyList(&L3) ? "�ɹ�" : "ʧ��");
	printList(L1);
	printList(L2);
	printList(L3);

	// 8��������
	printf("���Խ���\n");
	return 0;

}