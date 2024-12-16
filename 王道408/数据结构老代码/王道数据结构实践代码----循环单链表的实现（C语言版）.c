#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//����bool
#define bool char
#define true 1
#define false 0

//����˳��������Elemtype
typedef int Elemtype;

/*���������������ݽṹ*/
//��1��ѭ��������Ľ��ṹ
typedef struct Node
{
    Elemtype data;
    struct Node *next;
}Node,*PNode;

//��2��ѭ�������������ṹ
typedef struct CLinkList
{
    PNode head;//ָ��ͷ�ڵ�
    PNode tail;//ָ��β���
    int length;
}CLinkList;

/*ѭ��������ĳ�ʼ��*/
bool CLinkListInit(CLinkList *L)
{
    //[1]����ͷ���
    PNode HeadNode = (PNode)malloc(sizeof(Node));
    //[2]�д�
    assert(HeadNode);
    //[3]Ȼ������ṹ���ͷ���ṹ������
    L->head = L->tail = HeadNode;
    L->length = 0;
    //[4]��ͷ�ڵ��nextָ��ָ��ͷָ��
    HeadNode->next = L->head;
}

/*�����½ڵ�*/
PNode CreatNode(Elemtype e)
{
    //[1]�����½ڵ�Ŀռ�
    PNode newNode = (PNode)malloc(sizeof(Node));
    //[2]Ϊ�½ڵ㸳ֵ
    newNode->data = e;
    newNode->next = NULL;
}

/*��λ*/
//��1����λ��λ
PNode GetElem(CLinkList *L,int i)
{
    //[1]�ж�Ҫ��λ�Ľ���Ƿ�Ϸ�������
    assert(L);//���L�����Ƿ����
    if(i == 0) return L->head;//����ͷָ�����������ڰ�λɾ�����߲���ʱʹ��
    if(L->length < i || i < 1) return NULL;//�������Ľڵ�λ���Ƿ����
    //[2]���ɶ�λָ��
    PNode p = L->head->next;
    //[3]ѭ����λ
    while (i > 1)
    {
        p = p->next;
        i--;
    }
    //[4]����p
    return p;
}
//��2��������ֵ��λ
PNode LocateElem(CLinkList *L,Elemtype e)
{
    //[1]�д�
    assert(L);//���L�����Ƿ����
    //[2]���ɶ�λָ��
    PNode p = L->head->next;
    //[3]ѭ����λ
    for (int i = 1; i < L->length; i++)
    {
        if(p->data == e) return p;
        p = p->next;
    }
    return NULL;
}

/*�������ϵ��пշ�ʽ*/
//����ͷ����ָ���Ƿ�ָ��ͷָ��Ϊ�п�����
bool IfEmpty(CLinkList *L)
{
    return (L->head->next == L->head);
}

/*�����½ڵ�*/
//��1��ͷ�巨
bool CLinListHeadInsert(CLinkList *L,Elemtype e)
{
    //[1]�����½ڵ�
    PNode newNode = CreatNode(e);
    //[2]�����½ڵ�
    newNode->next = L->head->next;
    L->head->next = newNode;
    //[3]�ж����Ƿ��ǵ�һ�����
    if(L->head == L->tail)
    L->tail = newNode;
    //[4]�����ȼ�1
    L->length++;
    //[5]����ɹ���������Ϣ
    return 1;
}
//��2��β�巨
bool CLinListTailInsert(CLinkList *L,Elemtype e)
{
    //[1]�����½ڵ�
    PNode newNode = CreatNode(e);
    //[2]��λ���һ���ڵ�
    //������forѭ����Ҳ�����ñ���λ
    //�����βָ�룬��ֱ����βָ��
    PNode p = L->tail;//��ʵ������pҲ���ԣ�ֱ����L->tail������
    //[3]�����½ڵ�
    newNode->next = p->next;
    p->next = newNode;
    L->tail = newNode;
    //[4]�����ȼ�1
    L->length++;
    //[5]����ɹ���������Ϣ
    return 1;
}
//��3����λ����
bool CLinListLocalInsert(CLinkList *L,int i,Elemtype e)
{
    //[1]�жϲ����λ���Ƿ�Ϸ�������
    if(i > L->length+1 || i < 1)  return 0;
    if(IfEmpty(L))              return 0;
    //[2]��λ
    PNode p = GetElem(L,i-1);
    //[3]�����½ڵ�
    PNode newNode = CreatNode(e);
    //[4]�����½ڵ�
    newNode->next = p->next;
    p->next = newNode;
    //[5]�����ȼ�1
    L->length++;
    //[6]����ɹ���������Ϣ
    return 1;    
}

/*��������*/
int printList(CLinkList *L)
{
    //[1]�п�
    if(IfEmpty(L))  
    {
        printf("��գ�\n");
        return 0;
    }
    //[2]���ɶ�λָ��
    PNode p = L->head->next;
    //[2]forѭ������
    printf("HEADNODE ==> ");
    for(int i = 1;i <= L->length;i++)
    {
        printf("%d ==> ",p->data);
        p = p->next;
        if(i == L->length)
        printf("HEADNODE\n");
    }
    return 0;
}

/*ɾ���ڵ�*/
//��1����λɾ��
bool DeleteNode(CLinkList *L,int i)
{
    //[1]�жϲ����λ���Ƿ�Ϸ�
    if(i > L->length || i < 1)  return 0;
    if(IfEmpty(L))              return 0;
    //[2]��λ��ɾ���ڵ������ǰһ�ڵ�
    PNode p = GetElem(L,i-1);//��ɾ���ڵ��ǰһ�ڵ�
    PNode q = p->next;//��ɾ���ڵ�
    //[3]ִ��ɾ������
    p->next = p->next->next;
    free(q);
    //[4]������-1
    L->length--;
    //[5]ɾ���ɹ���������Ϣ
    return 1; 
}
//��2��ɾ�����нڵ�
bool DestoryNode(CLinkList *L)
{
    //[1]�жϲ����λ���Ƿ�Ϸ�
    if(IfEmpty(L))              return 0;
    //[2]����ָ���ɾ���ڵ��ָ��
    PNode p = NULL;
    //[3]forѭ��½��ɾ����ǰ�ĵ�һ���ڵ�
    for (int i = 1; i <= L->length; i++)
    {
        p = L->head->next;
        L->head->next = L->head->next->next;
        free(p);
    }
    //[4]��ʾɾ�����нڵ����Ϣ�������ز���
    printf("��ɾ�����нڵ㣡\n");
    return 0;
}

/*�����������Դ���*/
int main()
{
    CLinkList L;
    CLinkListInit(&L);
    CLinListHeadInsert(&L,1);
    CLinListHeadInsert(&L,2);
    CLinListHeadInsert(&L,3);
    CLinListHeadInsert(&L,4);
    CLinListHeadInsert(&L,5);
    CLinListHeadInsert(&L,6);
    printList(&L);
    CLinListTailInsert(&L,7);
    CLinListTailInsert(&L,8);
    CLinListTailInsert(&L,9);
    CLinListTailInsert(&L,10);
    printList(&L);
    CLinListLocalInsert(&L,11,66666);
    printList(&L);
    printf("%d\n",LocateElem(&L,2)->data);
    DeleteNode(&L,1);
    printList(&L);
    DestoryNode(&L);
    printList(&L);
    return 0;
}

