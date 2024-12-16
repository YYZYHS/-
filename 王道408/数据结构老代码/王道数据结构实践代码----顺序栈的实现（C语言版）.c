//��1��Ԥ���벿��
#include <stdio.h>
#include <stdlib.h>
//��2���궨�岿��
#define bool char
#define true 1
#define false 0
//��3���Զ����������
#define MaxSize 50      //����ջ��Ԫ�ص�������
//��4��˳��ջ�����ݽṹ
typedef int Elemtype;   //�Զ���˳��ջ������Ԫ������
typedef struct SqStack
{
    Elemtype data[MaxSize];
    int top;            //ջ��ָ��
}SqStack;
//��5��˳��ջ�ĳ�ʼ��
bool Initstack(SqStack *S)
{
    S->top = -1;        //��ʼ��ջ��ָ�루�п�����S->top = -1;��
}
//��6����ջ��
bool StackEmpty(SqStack S)
{
    if(S.top == -1)     return true;        //ջ��
    else                return false;       //ջ����
}
//��7����ջ��ѹջ��
bool Push(SqStack *S,Elemtype e)
{
    if(S->top == MaxSize - 1)     return false;     //ջ��������
    S->data[++S->top] = e;                  //ָ���ȼ�1������ջ
    return  true;
}
//��8����ջ
bool Pop(SqStack *s,Elemtype *e)
{
    if(StackEmpty(*s))      return false;   //ջ�ձ���
    *e = s->data[s->top--];                 //�ȳ�ջ��ָ���ټ�һ
    return true;
}
//��9����ջ��Ԫ��
bool GetTop(SqStack S,Elemtype *e)
{
    if(StackEmpty(S))      return false;   //ջ�ձ���
    *e = S.data[S.top];
    return true;
}
//��10��main������֤
int main()
{
    SqStack S;
    Initstack(&S);
    Push(&S,1);
    Push(&S,2);
    Push(&S,3);
    Push(&S,4);
    Push(&S,5);
    Push(&S,6);

    Elemtype X; //���뱣���ջ�Ͷ�ջ��Ԫ�ط��صı�����ֵ
    int count = S.top;
    for(int i = 0;i <= count;i++)
    {
        printf("i = %d\n",i);
        GetTop(S,&X);
        printf("GetTop X = %d\n",X);
        Pop(&S,&X);
        printf("GetTop X = %d\n",X);
    }

    return 0;
}
