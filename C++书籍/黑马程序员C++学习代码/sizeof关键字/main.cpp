#include <iostream>
using namespace std;

int main()
{
	// sizeof�ؼ���ѧϰ

	// ��֪: 
	//  short����ռ2���ֽ�, int����ռ4���ֽ�, 
	// long����ռ4���ֽ�, long long����ռ8���ֽ�

	// sizeof�ؼ������ڻ�ȡ�������ͻ�����Ĵ�С
	cout << "sizeof(short) = " << sizeof(short) << endl;
	cout << "sizeof(int) = " << sizeof(int) << endl;
	cout << "sizeof(long) = " << sizeof(long) << endl;
	cout << "sizeof(long long) = " << sizeof(long long) << endl;

	// ���ͱ�����С�Ƚ�
	// short < int <= long <= long long

	return 0;
}