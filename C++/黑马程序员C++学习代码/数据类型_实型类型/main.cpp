#include <iostream>

using namespace std;

int main()
{
	/*�������͡���ʵ����ϰ*/

	//1�������ȸ����͡���float
	float f = 3.14f;//f��ʾ�����ȸ����ͣ�����fĬ��Ϊdouble

	//2��˫���ȸ����͡���double
	double d = 3.14;

	//3����˫���ȸ����͡���long double
	long double ld = 3.14;

	//4����ѧ������
	float f1 = 3e2;//����3*10^2
	float f2 = 3e-2;//����3*10^-2
	double d1 = 3e8;//����3*10^8

	//���
	cout<< "�����ȸ�����f��"<< f << endl;
	cout<< "˫���ȸ�����d��"<< d << endl;
	cout<< "��˫���ȸ�����ld��"<< ld << endl;
	cout<< "��ѧ������f1��"<< f1 << endl;//���300
	cout<< "��ѧ������f2��"<< f2 << endl;//���0.03
	cout<< "��ѧ������d1��"<< d1 << endl;//��ΪC++ �����Ĭ��ʹ�ÿ�ѧ����������ʾ�����֣��������3e+08
	cout<< "��ѧ������d1��"<< fixed << d1 << endl;//ʹ��fixed��ȡ����ѧ�����������300000000


	//�鿴��������ռ���ڴ�ռ�
	cout << "floatռ���ڴ�ռ䣺" << sizeof(float) << "�ֽ�" << endl;
	cout << "doubleռ���ڴ�ռ䣺" << sizeof(double) << "�ֽ�" << endl;
	// Notes����˫���ȸ�������˫���ȸ����͵���չ�����ȸ��ߣ�ռ���ڴ����ͨ��ռ�ò�С��8���ֽ�
	cout << "long doubleռ���ڴ�ռ䣺" << sizeof(long double) << "�ֽ�" << endl;

	return 0;
}