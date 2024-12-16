/*
 *                        _oo0oo_
 *                       o8888888o
 *                       88" . "88
 *                       (| -_- |)
 *                       0\  =  /0
 *                     ___/`---'\___
 *                   .' \\|     |// '.
 *                  / \\|||  :  |||// \
 *                 / _||||| -:- |||||- \
 *                |   | \\\  - /// |   |
 *                | \_|  ''\---/''  |_/ |
 *                \  .-\__  '-'  ___/-. /
 *              ___'. .'  /--.--\  `. .'___
 *           ."" '<  `.___\_<|>_/___.' >' "".
 *          | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *          \  \ `_.   \_ __\ /__ _/   .-` /  /
 *      =====`-.____`.___ \_____/___.-`___.-'=====
 *                        `=---='
 * 
 * 
 *      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 
 *            ���汣��       ����崻�     ����BUG
 * 
 * @Author       : YYZYHS
 * @Date         : 2021-11-20 18:03:33
 * @LastEditTime : 2021-11-20 20:54:41
 * @LastEditors  : YYZYHS
 * @Description  : 
 * @FilePath     : \C\SString.c
 * ��ѧ֮��,��ӭ����.
 */

#include <stdio.h>
#include <stdlib.h>

#define bool char
#define true 1
#define false 0

#define MAXLEN 255  //Ԥ������󴮳�Ϊ255
//��0���������ݽṹ�����ʼ������
//[1]˳��洢�ַ��������ݽṹ
typedef struct SString
{
    char ch[MAXLEN + 1];    /*char���͵����飬�����ÿ������洢һ���ַ�*/
    char length;            /*����ʵ�ʳ���*/
}SString;
//[2]˳��洢�ַ����ĳ�ʼ��
/**
 * @brief         ˳��洢�ַ����ĳ�ʼ��
 * @param         str ����:SString*,Ҫ���г�ʼ�����ַ���
 * @return        �ɹ�����ture�����򷵻�false
 */
bool StrInit(SString* Str)
{
    Str->length = 0;
    return true;
}

//��1��˳��洢�ַ������󴮳�����ա��пղ���
/**
 * @brief         ˳��洢�ַ������󴮳�
 * @param         Str ����:SString,Ŀ���ַ���
 * @return        ����һ��int���͵�ֵ����Ŀ���ַ����ĳ��ȣ�
 */
int StrLength(SString Str)
{
    return Str.length;
}
/**
 * @brief         ˳��洢�ַ�������ղ���
 * @param         Str ����:SString*,Ŀ���ַ�����ָ��
 * @return        �ɹ�����ture�����򷵻�false
 */
bool StrClear(SString* Str)
{
    Str->length = 0;
    return true;
}
/**
 * @brief         ˳��洢�ַ������пղ���
 * @param         Str ����:SString,Ŀ���ַ���
 * @return        ���շ���ture�����򷵻�false
 */
bool StrEmpty(SString Str)
{
    return !Str.length;
}
//��2��˳��洢�ַ����ĸ�ֵ�������������
//[1]˳��洢�ַ����ĸ�ֵ����
/**
 * @brief         ˳��洢�ַ����ĸ�ֵ����,�Ѵ�src��ֵΪDest
 * @param         Dest ����:SString*,ָ�����ڴ洢��ֵ���ݵ�Ŀ���ַ������׵�ַ
 * @param         *Src ����:char,�ַ���Dest������Ҫ����ֵ������
 * @return        ��ֵ�ɹ�������true��ͬʱDest��������ȷ��ֵ�����򷵻�false������
 */
bool StrAssign(SString* Dest,char *Src)
{
    if(!Src)
    {
        printf("StrAssign:Src is NULL!\n");
        return false;
    }
    int i = 1;
    for(i = 1;Src[i - 1] != '\0';i++)
    {
        if(i <= MAXLEN)
        {
            Dest->ch[i] = Src[i - 1];
        }
        else
        {
            break;
        }
    }
    Dest->length = i - 1;
    return true;
}
//[2]˳��洢�ַ������������
/**
 * @brief         ˳��洢�ַ������������
 * @param         Str ����:SString,Ŀ���ַ���
 * @return        ����ַ�����ֵ�ʹ���
 */
bool StrPrint(SString Str)
{
    if(StrEmpty(Str))
    {
        printf("StrPrint:The SString is an empty sstring or an error sstring\n");
        return false;
    }
    for(int i = 1;i <= Str.length;i++)
    {
        printf("%c",Str.ch[i]);
    }
    printf("\nLength = %d\n\n",StrLength(Str));
    return true;
}

//��3��˳��洢�ַ����ĸ��Ʋ���
/**
 * @brief         ˳��洢�ַ����ĸ��Ʋ���,�ɴ�Src���Ƶõ���Dest
 * @param         Dest ����:SString*,���ڴ洢Ҫ���Ƶ��ַ���
 * @param         Src ����:SString*,���ڴ洢�����Ƶ��ַ���
 * @return        ���Ƴɹ�����������true��ͬʱDest��ֵ���Src��ֵ������������fales
 */
bool StrCopy(SString* Dest,SString* Src)
{
    if(StrEmpty(*Src))
    {
        printf("StrCopy:The copied sstring is an empty sstring!\n");
        return false;
    }
    for(int i = 1; i <= Src->length;i++)
    {
        Dest->ch[i] = Src->ch[i];
    }
    Dest->length = Src->length;
    return true;
}

//��4��˳��洢�ַ����Ĵ�����
/**
 * @brief         ˳��洢�ַ����Ĵ����ӡ���Dest������Str1��Str2���Ӷ��ɵ�
 * @param         Dest ����:SString*,ָ���´����׵�ַ
 * @param         Str1 ����:SString,Ҫ���ӵĵ�һ���ַ���
 * @param         Str2 ����:SString,Ҫ���ӵĵڶ����ַ���
 * @return        ���Ƴɹ�����������true��ͬʱDest�Ĵ����´��ĵ�ַָ�룬����������fales
 */
bool StrConcat(SString* Dest,SString Str1,SString Str2)
{
    if(StrEmpty(Str1) || StrEmpty(Str2))
    {
        printf("StrConcat:At least one of the two sstrings is an empty sstring!\n");
        return false;
    }
    StrCopy(Dest,&Str1);
    for(int i = Dest->length + 1; 
        i <=(StrLength(Str1) + StrLength(Str2)) && i <= MAXLEN;
        i++)
    {
        Dest->ch[i] = Str2.ch[i - StrLength(*Dest)];
    }
    Dest->length = StrLength(Str1) + StrLength(Str2);
    return true;
}

//��5��˳��洢�ַ��������ִ�����
/**
 * @brief         ˳��洢�ַ��������Ӵ�����Dest���ش�Src�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ���
 * @param         Dest ����:SString*,ָ�����ڱ����Ӵ��Ĵ洢�ռ�
 * @param         Src ����:SString,����
 * @param         pos ����:int,�Ӵ��������е�λ��
 * @param         len ����:int,�Ӵ��ĳ���
 * @return        ���ɹ�����Ӵ�����������true��ͬʱDest�����Ӵ���ָ�룬���򣬺�������false
 */
bool SubString(SString* Dest,SString Src,int pos,int len)
{
    if((pos + len -1) > StrLength(Src))
    {
        printf("SubString:The substring does not exist!\n");
        return false;
    }
    for(int i = pos;i <= pos + len -1;i++)
    {
        Dest->ch[i - pos + 1] = Src.ch[i];
    }
    Dest->length = len;
    return true;
}

//��7��˳��洢�ַ����ĶԱȲ���
/**
 * @brief         ˳��洢�ַ����ĶԱȲ���
 * @param         Str1 ����:SString,
 * @param         Str2 ����:SString,
 * @return        ����һ��int�͵�ֵ����Str1 > Str2������ֵ>0;��Str1 == Str2������ֵ=0����Str1 < Str2������ֵ<0��
 */
int StrCompare(SString Str1,SString Str2)
{
    for(int i = 1;i <= StrLength(Str1) && i <= StrLength(Str2);i++)
    {
        if(Str1.ch[i] != Str2.ch[i])
        return Str1.ch[i] - Str2.ch[i];
    }
    return StrLength(Str1) - StrLength(Str2);
}

//��8��˳��洢�ַ����Ķ�λ����
/**
 * @brief         ˳��洢�ַ����Ķ�λ����
 * @param         MainStr ����:SString,����
 * @param         SubStr ����:SString,�Ӵ�
 * @return        ������MainStr�д����봮SubStrֵ��ͬ���Ӵ����򷵻���������MainStr�е�һ�γ��ֵ�λ�ã�������ֵΪ-1.
 */
int StrIndex(SString MainStr,SString SubStr)
{
    if(StrEmpty(SubStr))
    {
        printf("StrIndex:The substring does not exist!\n");
    }
    int i = 1;
    SString sub;//��ʱ�洢�Ӵ��ı���
    while (i <= StrLength(MainStr) - StrLength(SubStr) + 1)
    {
        SubString(&sub,MainStr,i,StrLength(SubStr));
        if(StrCompare(sub,SubStr) != 0) i++;
        else return i;
    }
    return -1;    
}

int main()
{
    SString str1,str2,str3;
    StrInit(&str1);
    StrInit(&str2);
    StrInit(&str3);
    StrAssign(&str1,"Str1:ABC");
    StrAssign(&str2,"Str2:HUAWEI MatePad pro?!!");
    StrAssign(&str3,"Str3:IPhone 13 Pro Plus 666!");
    // StrClear(&str1);
    StrPrint(str1);
    StrPrint(str2);
    StrPrint(str3);
    // StrCopy(&str1,&str3);
    // StrPrint(str1);
    SString str4,str5;
    StrInit(&str4);
    StrInit(&str5);
    StrConcat(&str4,str2,str3);
    StrPrint(str4);
    SubString(&str5,str1,3,4);
    StrPrint(str5);
    printf("StrCompare(str4,str4) = %d",StrCompare(str4,str4));
    printf("StrIndex(str1,str5) = %d",StrIndex(str1,str5));
    return 0;
}
