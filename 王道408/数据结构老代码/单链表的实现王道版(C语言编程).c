//��1��Ԥ���벿��
#include <stdio.h>
#include <stdlib.h>

//��2���궨�岿�� ---- bool
#define bool char
#define true 1
#define false 0
//��3���Զ�������Ԫ������
typedef int ElemType;
//��4��������Ľṹ��
typedef struct LNode
{
    ElemType data;
    struct LNode* next;
}LNode,*LinkList;

//��5��������ĳ�ʼ����ͷ���ĳ�ʼ����
bool InitLinkList(LinkList L)
{
    L->data = 0;    //ͷ����data�������洢��
    L->next = NULL; //ͷ����next������ָ������ĵ�һ�����
}

LNode* InitLinkList_1()//�ڶ��ֳ�ʼ������
{
    LNode *L = (LNode*)malloc(sizeof(LNode));
    L->data = 0;    //ͷ����data�������洢��
    L->next = NULL; //ͷ����next������ָ������ĵ�һ�����
    return L;
}

//��6��������Ĵ�ӡ
bool PrintLinkList(LinkList L)
{
    LNode *p;
    p = L;
    while(p->next)
    {
        p = p->next;
        printf("%d-->",p->data);
    }
    printf("NULL\n");
    return true;
}

//��7���������ͷ�巨��������
bool HeadInsertLinkList(LinkList L)
{
    LNode *NewNode;             //�½��
    ElemType NewNode_data;      //�½ڵ��������ֵ
    printf("Please enter a number(9999 means the end):");
    scanf("%d",&NewNode_data);
    while(NewNode_data != 9999)
    {
        //���в������
        NewNode = (LNode*)malloc(sizeof(LNode));
        NewNode->next = L->next;
        L->next = NewNode;
        NewNode->data = NewNode_data;
        L->data++;
        printf("Please enter a number(9999 means the end):");
        scanf("%d",&NewNode_data);
    }
    return true;
}

//��8���������β�巨��������
bool TailInsertLinkList(LinkList L)
{
    LNode *NewNode;//ָ���½���ָ��
    LNode *TailNode = L;//ָ��β����ָ��
    ElemType NewNode_data;//�½���data��
    while(TailNode->next != NULL)
    {
        TailNode = TailNode->next;
    }
    printf("Please enter a number(9999 means the end):");
    scanf("%d",&NewNode_data);
    while(NewNode_data != 9999)
    {
        NewNode = (LNode*)malloc(sizeof(LNode));
        NewNode->data = NewNode_data;
        TailNode->next = NewNode;
        NewNode->next = NULL;
        TailNode = NewNode;
        L->data++;
        printf("Please enter a number(9999 means the end):");
        scanf("%d",&NewNode_data);
    }
    return true;
}

//��9����λ��������Ԫ��
LNode* GetElem(LinkList L,int i)
{
    //[1]�ж�i�ĺϷ���
    if(i == 0)
    {
        printf("The Linklist's element you are looking for does not exist!\nReturn the head pointer of the Linklist!\n");
        return L;
    }
    if(i < 1 || i > L->data)
    {
        printf("The Linklist's element you are looking for does not exist!\nReturn NULL!\n");
        return NULL;
    }
    //[2]��������Ԫ��
    LNode *p = L;
    for(int j = 1; j <= i;j++)
    {
        p = p->next;
    }
    return p;
}

//��10����ֵ��������Ԫ��
LNode* LocateElem(LinkList L,ElemType e)
{
    if(!L->next)
    {
        printf("This Linklist is empty!\n");
        return L;
    }
    LNode *p = L;
    while(p->next)
    {
        p = p->next;
        if(p->data == e)
        return p;
    }
    printf("The Linklist's element you are looking for does not exist!\n");
    return NULL;
}

//��11��������İ�λ����
bool LocalInsertElem(LinkList L,int i,ElemType e)
{
    //[1]�ж�i�ĺϷ���
    if(i < 1 || i > (L->data + 1))
    {
        printf("The position of the element to be inserted is invalid!\n");
        return false;
    }
    //[2]������Ԫ��
    LNode *p = GetElem(L,i-1);
    LNode *NewNode = (LNode*)malloc(sizeof(LNode));
    NewNode->data = e;
    NewNode->next = p->next;
    p->next = NewNode;
    L->data++;
    return true;
}

//��12��������İ�λɾ��
bool LocalDeletElem(LinkList L,int i,ElemType *e)
{
    //[1]���i�ĺϷ���
    if(!L->next)
    {
        printf("This linklist is empty!\n");
        *e = 9999;
        return false;
    }
    if(i < 1 || i > L->data)
    {
        printf("The position of the element to be deloeted is invalid!\n");
        *e = 9999;
        return false;
    }
    //[2]ɾ��ָ��Ԫ��
    LNode *p = GetElem(L,i-1);//��ɾ��Ԫ�ص�ǰ�����
    LNode *q = p->next;//��ɾ��Ԫ��
    p->next = q->next;
    *e = q->data;
    free(q);
    L->data--;
    return true;
}
//��13�����ٵ�����
bool DestoryLinkList(LinkList L)
{
    int e;
    while(L->data)
    {
        LocalDeletElem(L,1,&e);
        PrintLinkList(L);
    }
    free(L);
}


int main()
{
    LinkList L;//L��һ��ָ��
    L = (LNode*)malloc(sizeof(LNode));
    InitLinkList(L);
    // HeadInsertLinkList(L);
    TailInsertLinkList(L);
    PrintLinkList(L);
    DestoryLinkList(L);
    return 0;
}
