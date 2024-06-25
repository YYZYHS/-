#include <stdio.h>		//��׼�������
#include <stdlib.h>		//��׼�⺯��,������һЩ���õĺ���,��malloc(),free(),exit(),system()
#include <stdbool.h>	//C99��׼�����ͷ�ļ�,������bool,true,false

/*
 *  ����C���԰��ͷ���ĵ�����ļ�ʵ�ְ���
 *  ��Ҫʵ��������ĳ�ʼ��,����,ɾ��,����,�����ȹ���
 *
 *  ���մ�ͷ���ĵ������ʵ��˼·,ͷ��㲻�洢����,ֻ����Ϊһ��ͷָ��ʹ�ã�����Ϊ�������У�
 *  ͷ������������int���ͣ�����ͷ�������������������¼����Ҳ���Բ��ã��Ӿ����������
 */

 /*1��ǰ��׼��*/
typedef int ElemType;			//��������洢����������,������intΪ��
typedef struct LNode
{
	ElemType data;				//������
	struct LNode* next;			//ָ����
}LNode, * LinkList;				//LNodeΪ�������,LinkListΪ����ָ������

/*2�����������������*/
bool initList(LinkList* L);		//�����ʼ��
LNode* createNewNode(ElemType e);	//����һ���½��

bool initListByHead(LinkList* L); //ͷ�巨��������
bool initListTail(LinkList* L); //β�巨��������

/*3������ĳ��ú�������ӡ���*/
void printList(LinkList L)
{
	printf("�����е�Ԫ��Ϊ: ");
	LNode* p = L->next;			//pָ���һ�����
	while (p != NULL)			//p��Ϊ��,��pָ��Ľ�����
	{
		printf("%d-->", p->data);	//����������
		p = p->next;			//pָ����һ�����
	}
	printf("NULL");				//���NULL��ʾ�������
	printf("\n");
}

/*4������Ļ�����������ʼ��*/
// ����һ����ͷ���Ŀ�����
bool initList(LinkList* L)
{
	*L = (LinkList)malloc(sizeof(LNode));	//����һ��ͷ���
	if (*L == NULL)							//�ڴ����ʧ��
	{
		return false;
	}
	(*L)->data = 0;							//��ͷ����������������������¼����ĳ���
	(*L)->next = NULL;						//ͷ����ָ�����ÿ�
	return true;
}

// ����һ���½��
LNode* createNewNode(ElemType e)
{
	LNode* node = (LNode*)malloc(sizeof(LNode));	//����һ���½��
	if (node == NULL)								//�ڴ����ʧ��
	{
		return NULL;
	}
	node->data = e;									//�½���������ֵ
	node->next = NULL;								//�½���ָ�����ÿ�
	return node;
}

// ͷ�巨��������
bool initListByHead(LinkList* L)
{
	*L = (LinkList)malloc(sizeof(LNode));	//����һ��ͷ���
	if (*L == NULL)							//�ڴ����ʧ��
	{
		return false;
	}
	(*L)->data = 0;							//��ͷ����������������������¼����ĳ���
	(*L)->next = NULL;						//ͷ����ָ�����ÿ�

	while (true)							//ѭ������Ԫ�ص�ֵ
	{
		ElemType value;						//����һ�������洢�����ֵ
		printf("������һ��Ԫ�ص�ֵ,����9999������������������");
		int len = scanf("%d", &value);		//����һ��ֵ
		if (value == 9999)					//�ж��������������
		{
			break;
		}
		LNode* newNode = createNewNode(value);	//����һ���½��
		if (NULL == newNode)				//�ڴ����ʧ��
		{
			return false;
		}
		newNode->next = (*L)->next;			//�½���ָ����ָ��ͷ������һ�����
		(*L)->next = newNode;				//ͷ����ָ����ָ���½��
		(*L)->data++;						//�����ȼ�1
	}
	return true;
}
// β�巨��������
bool initListTail(LinkList* L)
{
	*L = (LinkList)malloc(sizeof(LNode));	//����һ��ͷ���
	if (*L == NULL)							//�ڴ����ʧ��
	{
		return false;
	}
	(*L)->data = 0;							//��ͷ����������������������¼����ĳ���
	(*L)->next = NULL;						//ͷ����ָ�����ÿ�

	LNode* tail = *L;						//tailָ��ͷ���
	while (true)							//ѭ������Ԫ�ص�ֵ
	{
		ElemType value;						//����һ�������洢�����ֵ
		printf("������һ��Ԫ�ص�ֵ,����9999������������������");
		int len = scanf("%d", &value);		//����һ��ֵ
		if (value == 9999)					//�ж��������������
		{
			break;
		}
		LNode* newNode = createNewNode(value);	//����һ���½��
		if (NULL == newNode)				//�ڴ����ʧ��
		{
			return false;
		}
		tail->next = newNode;				//β����ָ����ָ���½��
		tail = newNode;						//β���ָ���½��
		(*L)->data++;						//�����ȼ�1
	}
	return true;
}
/*5������Ļ�������������*/
// ��λ����
LNode* getElem(LinkList L, int i)
{
	if (i < 0 || i > L->data)	//�ж�i�ĺϷ���
	{
		return NULL;
	}
	LNode* p = L->next;			//pָ���һ�����
	int j = 1;					//jΪ������,����λ���1��ʼ
	while (p != NULL && j < i)	//ѭ�����ҵ�i�����
	{
		p = p->next;			//pָ����һ�����
		j++;					//��������1
	}
	return p;					//���ص�i������ָ��
}

// ��ֵ����
int locateElem(LinkList L, ElemType e)
{
	LNode* p = L->next;			//pָ���һ�����
	int i = 1;					//iΪ������,����λ���1��ʼ
	while (p != NULL && p->data != e)	//ѭ������������Ϊe�Ľ��
	{
		p = p->next;			//pָ����һ�����
		i++;					//��������1
	}
	if (p == NULL)				//����ʧ��
	{
		return 0;
	}
	return i;					//����������Ϊe�Ľ���λ��
}

/*6������Ļ�������������*/
// ��λ���� --- ǰ�巨
bool insertListByForward(LinkList L, int i, ElemType e)
{
	// ˼·��Ҫ���뵽��i��λ�ã����ǲ���ĳ������ǰ�棬����Ҫ�ҵ���i����㣬������i-1������ָ����ָ���½��

	// �ж�i����λ�õĺϷ���
	if (i < 1 || i > L->data + 1)	
	{
		return false;
	}

	// Ѱ�ҵ�i-1�����
	LNode* p = getElem(L, i - 1);
	if(NULL == p)	// ����ʧ��
	{
		return false;
	}

	// ����һ���½��
	LNode* newNode = createNewNode(e);
	if(NULL == newNode)	// �ڴ����ʧ��
	{
		return false;
	}
	
	// ǰ�巨�����½��
	newNode->next = p->next;
	p->next = newNode;

	// �����ȼ�1
	L->data++;
	return true;
}

// ��λ���� --- ��巨
bool insertListByBack(LinkList L, int i, ElemType e)
{
	if (i < 1 || i > L->data + 1)	//�ж�i�ĺϷ���
	{
		return false;
	}
	LNode* p = getElem(L, i);		//���ҵ�i�����
	if (p == NULL)					//����ʧ��
	{
		return false;
	}
	LNode* newNode = createNewNode(e);	//����һ���½��
	if (newNode == NULL)			//�ڴ����ʧ��
	{
		return false;
	}
	newNode->next = p->next;		//�½���ָ����ָ���i+1�����
	p->next = newNode;			//��i������ָ����ָ���½��
	L->data++;					//�����ȼ�1
	return true;
}

/*7������Ļ���������ɾ��*/
// ��λɾ��

// ��ֵɾ��

/*8������Ļ�����������������*/
bool destroyList(LinkList* L)
{

}

/*9������ĳ��ú������п�*/
bool isEmpty(LinkList L)
{
	return NULL == L->next;
}

/*10������ĳ��ú��������*/
// ���ڱ�������������£������ʱ�临�Ӷȿ���ΪO(1)
int length1(LinkList L)
{
	return L->data;		// ͷ����������洢��������ĳ���
}

// ����һ������£������ʱ�临�Ӷ�ΪO(n)
int length2(LinkList L)
{
	int len = 0;		//��ʼ������Ϊ0
	LNode* p = L->next;
	while (p != NULL)	//��������
	{
		len++;
		p = p->next;
	}
	return len;
}

int main()
{
	LinkList L;		//����һ������
	initListTail(&L);

	printList(L);	//��ӡ����
	printf("����ĳ���Ϊ��%d\n", length1(L));	//�������ĳ���
	printf("����ĳ���Ϊ��%d\n", length2(L));	//�������ĳ���

	return 0;
}