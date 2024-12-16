#include <stdio.h>
#include <stdlib.h>

//C�����Զ���bool����
#define bool char
#define false 0
#define true 1

/*����Ԫ������*/
typedef int ElemType;

/*������ṹ�嶨��*/
typedef struct LNode        //���嵥����������
{
    ElemType data;          //ÿ�������һ������Ԫ��
    struct LNode *next;     //ָ��ָ����һ�ڵ�
}LNode,*LinkList;

/*
    ����Ĵ���ȼ���
    typedef struct Lnode Lnode;
    typedef struct Lnode * Linklist;
*/

//LinkList L; //����һ��ָ�������һ������ָ��,���ַ�������ɶ��Ը�ǿ
/*
    ����Ĵ���Ҳ��д��:
    LNode *L;
    //����һ��ָ�������һ������ָ��,�����ַ����ɶ��Բ�ǿ,
    //�޷���һʱ�俴��L��ָ�����������ͷָ��,���ǽ����Ǹ��µĽ��
*/

//�����ʼ������
LinkList ListInit()
{
    //[1]����һ��LinkList���͵Ĵ洢�ռ��L
    LinkList L = (LinkList)malloc(sizeof(LinkList));
    //[2]����L��ָ����Ϊ��
    L->next = NULL;
    //����Lָ��
    return L;
}

//�����½��
LNode* createNote(int data)
{
    //[1]Ϊ�½ڵ�����ռ�
    LNode* newNode = (LNode*)malloc(sizeof(LNode));
    //[2]����ڴ�����,�����ʧ��,����0
    if(newNode == NULL) 
    {
        printf("������ʧ��,�����ڴ�!");
        return NULL;
    }
    //[3]Ϊ�½ڵ���������ָ����ֱ�ֵ
    newNode->data = data;
    newNode->next = NULL;
    //[4]�����½ڵ��ָ��
    return newNode;
}


//ͷ�巨
bool ListHeadInsert(LinkList L,ElemType data)
{
    //[1]���ô����½ڵ㺯��,Ϊ�丳ֵ
    LNode* newNode = createNote(data);
    //[2]�ȸ��½ڵ��ָ����ֵ(ָ��ԭ������ĵ�һ���ڵ�)
    newNode->next = L->next;
    //[3]����ͷ���ָ���½��
    L->next = newNode;
    //[4]����true,��ʾ����ɹ�
    return true;
}

//β�巨(����βָ���β�巨)
bool ListTailInsert(LinkList L,ElemType data)
{
    //[1]�����½ڵ�
    LNode* newNode = createNote(data);
    //[2]���ɹ���ָ��
    LNode* p = L->next;
    //[3]��������,�ҵ�����Ԫ��,�ù���ָ��ָ����
    while (p->next != NULL)
    {
        p = p->next;
    }
    //[4]β�����½ڵ�
    newNode->next = NULL;
    p->next = newNode;
}

//��λ�����(forѭ����,�������ú�����װ�����ļ��װ�)
bool ListInsert(LinkList L,int i,ElemType data)
{
    int count;
    LNode* newNode = createNote(data);
    LNode* p = L;
    for ( count = 0; count < i-1; count++)
    {
        if(p->next == NULL) return false;
        p = p->next;
    }
    newNode->next = p->next;
    p->next = newNode;
}

//����Ų��ҽڵ�ֵ
LNode *GetElem(LinkList L,int i)
{
    //[1]����һ����������
    int j = 1;
    //[2]���ô����صĽ��p,��ʼָ���һ�����
    LNode *p = L->next;
    //[3]������
    if(i == 0) {p = L; return p;}
    if(i < 1) { return NULL;}
    //[4]��ʼѭ��
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    //[5]���ֵ,�˴����ص�i������ָ�룬��i���ڱ����򷵻�NULL
    return p;
}

//��ֵ���ұ�ڵ�
LNode* LocateElem(LinkList L,ElemType e)
{
    //[1]���ô����صĽ��p,��ʼָ���һ�����
    LNode *p = L->next;
    //[2]��ʼѭ���Ƚ�
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    //[3]/�ҵ��󷵻ظý��ָ�룬���򷵻�ULL
    return p;
}

//������ڵ����
bool LocateTailInsert(LinkList L,int i,ElemType e)
{
    //[1]����ָ��Ŀ��ڵ��ָ��p
    LNode* p = GetElem(L,i-1);
    //[2]�����½ڵ�s
    LNode* s = createNote(e);
    //[3]����
    s->next = p->next;
    p->next = s;
}

//ǰ�����ڵ����
bool LocateHeadInsert(LinkList L,int i,ElemType e)
{
    //[1]����ָ��Ŀ��ڵ��ָ��p
    LNode* p = GetElem(L,i);
    //[2]�����½ڵ�s
    LNode* s = createNote(e);
    //[3]����
    ElemType temp = p->data;
    s->next = p->next;
    p->next = s;
    p->data = s->data;
    s->data = temp;
}

//ɾ��ָ�����(��������)
bool ElemDelete(LinkList L,int i)
{
    //[1]��λ
    LNode *p = GetElem(L,i-1);
    LNode *q = p->next;
    //[2]ɾ��
    p->next = q->next;
    //[3]�ͷű�ɾ���ڵ�
    free(q);
}

//ɾ��ָ���ڵ�(ɾ����̵ķ���)
bool LocateElemDelete(LinkList L,int i)
{
    //[1]��λ
    LNode *p = GetElem(L,i);
    LNode *q = p->next;
    //[2]��������
    p->data = q->data;
    p->next = q->next;
    //[3]�ͷŽ��
    free(q);
}

//���
int ListLength(LinkList L)
{
    int count = 0;
    while (L->next != NULL)
    {
        L = L->next;
        count++;
    }
    return count;    
}

//��ӡ���
void Listprint(LinkList L)
{
    LNode* p = L->next;
    while (p != NULL)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
    printf("\n");
}


int main()
{
    //[1]����һ������
    LinkList L = NULL;
    // printf("%d",L->next);//���Գ���,��ʱL->next�޷����
    //[2]�������ʼ��
    L = ListInit();
    ListHeadInsert(L,1);
    ListHeadInsert(L,2);
    ListHeadInsert(L,3);
    ListHeadInsert(L,4);
    ListHeadInsert(L,5);
    ListTailInsert(L,6);
    ListTailInsert(L,7);
    ListTailInsert(L,8);
    ListTailInsert(L,9);
    ListTailInsert(L,10);
    ListInsert(L,3,666);
    ListInsert(L,1,88888);
    LocateTailInsert(L,8,6969);
    LocateHeadInsert(L,2,3333);
    ElemDelete(L,3);
    LocateElemDelete(L,5);
    Listprint(L);
    printf("������Ϊ:%d\n",ListLength(L));
    return 0;
}