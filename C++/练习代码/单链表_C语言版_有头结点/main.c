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
void printList(LinkList L);		//��ӡ����
LNode* getElem(LinkList L, int i);	//��λ����
int locateElem(LinkList L, ElemType e);	//��ֵ����
bool initListByHead(LinkList* L); //ͷ�巨��������
bool initListTail(LinkList* L); //β�巨��������
bool insertNextNode(LNode* p, ElemType e);	//��ָ�����֮������½��
bool insertPriorNode(LinkList L, LNode* p, ElemType e);	//��ָ�����֮ǰ�����½��
bool insertList(LinkList L, int i, ElemType e);	//��λ����----��巨
bool insertListByForward(LinkList L, int i, ElemType e);	//��λ����---ǰ�巨
bool deleteElem(LinkList L, int i, ElemType* e);	//��λɾ��
bool destroyList(LinkList* L);	//��������
bool isEmpty(LinkList L);		//�п�
int length(LinkList L);			//���



/*3������ĳ��ú�������ӡ���*/
void printList(LinkList L)
{
	if (NULL == L)
	{
		printf("��������\n");
		return;
	}
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
	}
	return true;
}
/*5������Ļ�������������*/
// ��λ����
LNode* getElem(LinkList L, int i)
{
	if (i < 0)	//�ж�i�ĺϷ���
	{
		return NULL;
	}
	LNode* p = L->next;				//pָ���һ�����
	int j = 1;					//jΪ������,����ǰ����λ��
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
	LNode* p = L->next;					//pָ���һ�����
	int i = 1;							//iΪ������,����λ���1��ʼ
	// ��Ϊ && ������Ĺ�����, ֻҪ��һ��Ϊ��,�Ͳ���ִ�к�����ж�,���Ե������p != NULL����ʱ,�Ż�ִ�к����p->data != e
	while (p != NULL && p->data != e)	//ѭ������������Ϊe�Ľ��
	{
		p = p->next;					//pָ����һ�����
		i++;							//��������1
	}
	if (p == NULL)						//����ʧ��
	{
		return 0;
	}
	return i;							//����������Ϊe�Ľ���λ��
}

/*6������Ļ�������������*/
// ��ָ�����֮������½��
bool insertNextNode(LNode* p, ElemType e)
{
	// �жϽ���Ƿ�Ϊ��
	if (NULL == p)
	{
		printf("���Ϊ��\n");
		return false;
	}

	// ����һ���½��
	LNode* newNode = createNewNode(e);
	if (NULL == newNode)	//�ڴ����ʧ��
	{
		printf("�ڴ����ʧ��\n");
		return false;
	}

	// ��巨�����½��
	newNode->next = p->next;	//�½���ָ����ָ��p����һ�����
	p->next = newNode;		//p��ָ����ָ���½��
	return true;
}

// ��ָ�����֮ǰ�����½��
bool insertPriorNode(LinkList L, LNode* p, ElemType e)
{
	// �жϽ���Ƿ�Ϊ��
	if (NULL == p)
	{
		printf("���Ϊ��\n");
		return false;
	}

	/*
	// ǰ�巨�����½�㷽��һ��ʱ�临�Ӷ�O(n)
	LNode* q = L;	//qָ��ͷ���
	while (q->next != p)	//����p��ǰһ�����
	{
		q = q->next;
	}
	if(NULL == q)	//����ʧ��
	{
		printf("����ǰ�ý��ʧ��\n");
		return false;
	}
	// ����һ���½��
	LNode *newNode = createNewNode(e);
	if (NULL == newNode)	//�ڴ����ʧ��
	{
		printf("�ڴ����ʧ��\n");
		return false;
	}
	newNode->next = p;	//�½���ָ����ָ��p
	q->next = newNode;	//q��ָ����ָ���½��
	return true;
	*/

	// ǰ�巨�����½�㷽������ʱ�临�Ӷ�O(1)
	// ����һ���½��
	LNode* newNode = createNewNode(e);
	if (NULL == newNode)	//�ڴ����ʧ��
	{
		printf("�ڴ����ʧ��\n");
		return false;
	}
	newNode->next = p->next;	//�½���ָ����ָ��p����һ�����
	p->next = newNode;		//p��ָ����ָ���½��
	ElemType temp = p->data;	//����������
	p->data = newNode->data;
	newNode->data = temp;
	return true;
}

// ��λ���� --- ��巨
bool insertList(LinkList L, int i, ElemType e)
{
	printf("�������ڵ�����ĵ�%d��λ�ò���Ԫ��%d\n", i, e);
	// ��巨˼·:���ҵ���i-1�����,Ȼ���ڵ�i-1����������½��
	// �жϲ���λ��i�ĺϷ���
	if (i < 1)
	{
		printf("����λ�ò��Ϸ�\n");
		return false;
	}

	// ���ҵ�i�����
	LNode* p = getElem(L, i - 1);
	if (p == NULL)					//����ʧ��
	{
		printf("���ҵ�%d�����ʧ��\n", i);
		return false;
	}

	// ���ú�巨�����½�㺯��
	return insertNextNode(p, e);
}

// ��λ���� --- ǰ�巨
bool insertListByForward(LinkList L, int i, ElemType e)
{
	printf("�������ڵ�����ĵ�%d��λ�ò���Ԫ��%d\n", i, e);
	// ǰ�巨˼·:���ҵ���i�����,Ȼ���ڵ�i�����ǰ�����½��
	// �жϲ���λ��i�ĺϷ���
	if (i < 1)
	{
		printf("����λ�ò��Ϸ�\n");
		return false;
	}

	// ���ҵ�i�����
	LNode* p = getElem(L, i);
	if (p == NULL)					//����ʧ��
	{
		printf("���ҵ�%d�����ʧ��\n", i);
		return false;
	}

	// ����ǰ�巨�����½�㺯��
	return insertPriorNode(L, p, e);

	/*
		ǰ�巨��������ԣ��������λ���Ǳ�+1��ǰ�巨�޷�ʵ��
		��Ϊ�ڶ�λʱ����+1��λ�ûᱻ��λ��NULL����ʱ�޷��ҵ�ǰһ�����
		�����ڶ�λʱ���жϲ���λ���Ƿ�Ϊ��+1������ǣ���ֱ�Ӳ��뵽��β�������������Ӵ���ĸ��Ӷ�
	*/
}


/*7������Ļ���������ɾ��*/
// ��λɾ��
bool deleteElem(LinkList L, int i, ElemType* e)
{
	// �ж�ɾ��λ��i�ĺϷ���
	if (i < 1)
	{
		printf("ɾ��λ�ò��Ϸ�\n");
		return false;
	}

	// ���ҵ�i-1�����
	LNode* p = getElem(L, i - 1);
	if (p == NULL || p->next == NULL)	//����ʧ��
	{
		printf("���ҵ�%d�����ʧ��\n", i - 1);
		return false;
	}

	// ɾ����i�����
	LNode* q = p->next;		//qָ���i�����
	if (NULL != e)
	{
		*e = q->data;			//�����i������������
	}
	p->next = q->next;		//ɾ����i�����
	free(q);				//�ͷŵ�i�������ڴ�
	q = NULL;				//qָ��NULL,��ֹ����Ұָ��
	return true;
}

// ��ֵɾ��
bool deleteElemByValue(LinkList L, ElemType e)
{
	// ����ֵΪe�Ľ��
	LNode* p = L;	//pָ��ͷ���
	while (p->next != NULL && p->next->data != e)	//ѭ������������Ϊe�Ľ��
	{
		p = p->next;	//pָ����һ�����
	}
	if (p->next == NULL)	//����ʧ��
	{
		printf("����ֵΪ%d�Ľ��ʧ��\n", e);
		return false;
	}

	// ɾ��ֵΪe�Ľ��
	LNode* q = p->next;		//qָ��ֵΪe�Ľ��
	p->next = q->next;		//ɾ��ֵΪe�Ľ��
	free(q);				//�ͷ�ֵΪe�Ľ����ڴ�
	q = NULL;				//qָ��NULL,��ֹ����Ұָ��
	return true;
}


/*8������Ļ�����������������*/
bool destroyList(LinkList* L)
{
	// �ͷ����н����ڴ�
	while (NULL != (*L)->next)
	{
		deleteElem(*L, 1, NULL);
	}

	// �ͷ�ͷ�����ڴ�
	free(*L);
	*L = NULL;

	return true;
}

/*9������ĳ��ú������п�*/
bool isEmpty(LinkList L)
{
	return NULL == L->next;
}

/*10������ĳ��ú��������*/

int length(LinkList L)
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
	LinkList L;				//����һ������
	initListTail(&L);		//��ʼ������
	printList(L);			//��ӡ����

	insertListByForward(L, 1, 100);		//�ڵ�һ��λ�ò���100
	printList(L);			//��ӡ����

	insertListByForward(L, 2, 200);		//�ڵڶ���λ�ò���200
	printList(L);			//��ӡ����

	insertList(L, length(L) + 1, 300);		//�����һ��λ�ò���300
	printList(L);	//��ӡ����

	// ��ֵ���Ҳ���
	int pos = locateElem(L, 300);	//����300��λ��
	printf("300��λ��Ϊ��%d\n", pos);

	printf("����ĳ���Ϊ��%d\n", length(L));	//�������ĳ���

	// ��λɾ������
	deleteElem(L, 1, NULL);	//ɾ����һ�����
	printList(L);	//��ӡ����

	deleteElem(L, 3, NULL);	//ɾ���м���
	printList(L);	//��ӡ����

	deleteElem(L, length(L), NULL);	//ɾ�����һ�����
	printList(L);	//��ӡ����

	// ��ֵɾ������
	deleteElemByValue(L, 200);	//ɾ��ֵΪ200�Ľ��
	printList(L);	//��ӡ����
	deleteElemByValue(L, 5959);	//ɾ�������ڵĽ��

	destroyList(&L);	//��������
	printList(L);	//��ӡ����

	return 0;
}