//[1]����˳�����󳤶ȺͶ�̬�����ʼĬ�ϵ��������
#define MaxSize 10      //��̬˳������󳤶�
#define InitSize 10     //��̬˳���ĳ�ʼ��󳤶�
//��Ҫ������ͷ�ļ�
#include <stdio.h>
#include <stdlib.h>
//C�����Զ���bool����
#define bool char
#define true 1
#define false 0
//�Զ�������Ԫ�ص���������
typedef int Elemtype;

//˳�������Ԫ�ؽṹ��(��̬����)
typedef struct SqList
{
    //[1]�þ�̬�ġ����顱�������Ԫ��
    Elemtype data[MaxSize];
    //[2]˳���ĵ�ǰ����
    int length;
}SqList;//˳�������Ͷ��壨��̬���䷽ʽ��

//˳�������Ԫ�ؽṹ��(��̬����)
typedef struct SeqList
{
    //[1]ָʾ��̬���������ָ��
    Elemtype *data;
    //[2]˳���ĵ�ǰ����
    int length;
    //[3]˳�����������
    int maxsize;
}SeqList;//˳�������Ͷ��壨��̬���䷽ʽ��

//��������----��ʼ��һ����̬˳���
bool InitsqList(SqList *L)
{
    //[1]����������Ԫ����ΪĬ�ϳ�ʼֵ
    for(int i = 0; i < MaxSize; i++)
    {
        L->data[i] = 0;
    }
    /*
    1.��������ʵ����ʡ��
    2.֮���Ը���ֵ����Ϊ�ڴ��л���������"������"
    3.���ǳ��������,�û��޷����ʴ���
      ��ǰ��������Ԫ��,���Կ�������Ҫʱ�ٸ�ֵ
    */

    //[2]˳����ʼ������Ϊ0
    L->length = 0;

    return true;
}

//��������----��ʼ��һ����̬˳���
bool InitseqList(SeqList *L)
{
    //[1]��malloc��������һƬ�����Ĵ洢�ռ�
    L->data = (Elemtype *)malloc(sizeof(Elemtype) * InitSize);
    //[2]����Ĭ����󳤶ȳ�ʼ��
    L->length = 0;
    L->maxsize = InitSize;

    return true;
}

//��̬˳���ļӳ�
bool IncreaseSize(SeqList *L,int len)
{
    //[1]����ָ��ԭ��˳���洢λ�õ�ָ��
    int *p = L->data;
    //[2]Ϊ˳�����һƬ��ԭ������Ŀռ�
    L->data = (Elemtype *)malloc((L->maxsize + len) * sizeof(Elemtype));
    //[3]ת������
    for (int i = 0; i < L->length; i++)
    {
        L->data[i] = p[i];
    }
    //[4]�޸�˳������󳤶�,Ϊ������len
    L->maxsize = L->maxsize + len;
    //[5]�ͷ�ԭ���Ĵ洢�ռ�
    free(p);

    return true;
}

//��������----˳���Ĳ���
//[1]��̬˳���Ĳ���
bool SqListInsert(SqList *L,int i,Elemtype e)
{
    //[1]�ж�i�ĺϷ���
    if(i < 1 || i > L->length + 1)
    {
        printf("The position of the element to be inserted is invalid!\n");
        return false;
    }
    if(L->length >= MaxSize)
    {
        printf("This sequence table is full!\n");
        return false;
    }

    //[2]����i��Ԫ�ؼ�֮���Ԫ�ض�����
    for(int j = L->length; j >= i; j--)
    {
        L->data[j] = L->data[j-1];      //��i��Ԫ�ض�Ӧ�����±�Ϊi-1������Ԫ�� 
    }
    //[3]����ȷ��λ�ò�����Ԫ��
    L->data[i-1] = e;
    //[4]˳���+1(ע��:˳������󳤶Ȳ���)
    L->length++;
    //[5]����ɹ�,���سɹ��ź�
    return true;
}
//[2]��̬˳���Ĳ���
bool SeqListInsert(SeqList *L,int i,Elemtype e)
{
    //[1]�ж�i�ĺϷ���
    if(i < 1 || i > L->length + 1)
    {
        printf("The position of the element to be inserted is invalid!\n");
        return false;
    }
    if(L->length >= L->maxsize)
    {
        printf("This sequence table is full!\n");
        return false;
    }

    //[2]����i��Ԫ�ؼ�֮���Ԫ�ض�����
    for(int j = L->length; j >= i; j--)
    {
        L->data[j] = L->data[j+1];      //��i��Ԫ�ض�Ӧ�����±�Ϊi-1������Ԫ�� 
    }
    //[3]����ȷ��λ�ò�����Ԫ��
    L->data[i-1] = e;
    //[4]˳���+1(ע��:˳������󳤶Ȳ���)
    L->length++;
    //[5]����ɹ�,���سɹ��ź�
    return true;
}

//��������----˳����Ԫ��ɾ��
//[1]��̬˳����Ԫ��ɾ��
bool SqListDelete(SqList *L, int i, Elemtype *e)
{
    //[1]�ж�i�ĺϷ���
    if(i < 1 || i > L->length + 1)
    {
        printf("The position of the element to be delected is invalid!\n");
        return false;
    }
    if(L->length <= 0)
    {
        printf("This sequence table is empty!\n");
        return false;
    }
    //[2]����ɾ����Ԫ��ֵ����e
    *e = L->data[i-1];
    //[3]����i��Ԫ�ؼ�֮���Ԫ�ض�ǰ��
    for(int j = i; j <= L->length; j++)
    {
        L->data[j-1] = L->data[j];      //��i��Ԫ�ض�Ӧ�����±�Ϊi-1������Ԫ�� 
    }
    //[4]˳���-1(ע��:˳������󳤶Ȳ���)
    L->length--;
    //[5]����ɹ�,���سɹ��ź�
    return true;
}
//[2]��̬˳����Ԫ��ɾ��
bool SeqListDelete(SeqList *L,int i,Elemtype *e)
{
        //[1]�ж�i�ĺϷ���
    if(i < 1 || i > L->length + 1)
    {
        printf("The position of the element to be delected is invalid!\n");
        return false;
    }
    if(L->length <= 0)
    {
        printf("This sequence table is empty!\n");
        return false;
    }
    //[2]����ɾ����Ԫ��ֵ����e
    *e = L->data[i-1];
    //[3]����i��Ԫ�ؼ�֮���Ԫ�ض�ǰ��
    for(int j = i; j <= L->length; j++)
    {
        L->data[j-1] = L->data[j];      //��i��Ԫ�ض�Ӧ�����±�Ϊi-1������Ԫ�� 
    }
    //[4]˳���-1(ע��:˳������󳤶Ȳ���)
    L->length--;
    //[5]����ɹ�,���سɹ��ź�
    return true;
}

//��������----��ֵ����
//[1]��̬˳���İ�ֵ����
int SqListLocateElem(SqList L, Elemtype e)
{
    int i;
    for(i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i+1;
        }
    }
    return 0;
}
//[2]��̬˳���İ�ֵ����
int SeqListLocateElem(SeqList L, Elemtype e)
{
    int i;
    for(i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i+1;
        }
    }
    return 0;
}

//�������----˳���Ĵ�ӡ
//[1]��̬˳�������
bool SqListPrint(SqList L)
{
    //[1]�п�
    if(L.length == 0)
    {
        printf("This sequence table is empty!\n");
        return false;
    }
    //[2]���
    printf("SqList:\n");
    for(int i = 0;i < L.length;i++)
    {
        printf("%d-->",L.data[i]);
    }
    printf("end\n");
}
//[2]��̬˳�������
bool SeqListPrint(SeqList L)
{
    //[1]�п�
    if(L.length == 0)
    {
        printf("This sequence table is empty!\n");
        return false;
    }
    //[2]���
    printf("SeqList:\n");
    for(int i = 0;i < L.length;i++)
    {
        printf("%d-->",L.data[i]);
    }
    printf("end\n");
}


int main()
{
    /*��1������˳���*/
    //[1]��̬�����˳���L1
    SqList L1;
    //[2]��̬�����˳���L2
    SeqList L2;

    /*��2��˳���ĳ�ʼ��*/
    //[1]��̬˳���L1�ĳ�ʼ��
    InitsqList(&L1);
    //[2]��̬˳���L2�ĳ�ʼ��
    InitseqList(&L2);

    /*��3��˳��������Ԫ��*/
    int e;
    SqListInsert(&L1,1,1);
    SqListInsert(&L1,2,2);
    SqListInsert(&L1,3,3);
    SqListInsert(&L1,4,4);
    SqListInsert(&L1,5,5);
    SqListDelete(&L1,3,&e);
    SqListInsert(&L1,5,6);

    SeqListInsert(&L2,1,1);
    SeqListInsert(&L2,2,2);
    SeqListInsert(&L2,3,3);
    SeqListInsert(&L2,4,4);
    SeqListInsert(&L2,5,5);
    SeqListDelete(&L2,2,&e);
    SeqListInsert(&L2,5,6);
    IncreaseSize(&L2,5);

    SqListPrint(L1);
    SeqListPrint(L2);

    printf("%d\n",L2.maxsize);
    printf("SqListLocateElem(4) = %d\n",SqListLocateElem(L1,4));
    printf("SeqListLocateElem(6) = %d\n",SeqListLocateElem(L2,6));

    return 0;
}
