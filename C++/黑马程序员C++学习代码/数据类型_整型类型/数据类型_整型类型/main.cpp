#include <iostream>
#include <string>

using namespace std;

int main()
{
	// ����(-32768~32767)
	// 1��������
	short a = 10;
	//short int a = 32768; // 32768������short int�ķ�Χ,�ᱨ��
	// 2������(-2^31~2^31-1)
	int b = 10;
	// 3��������(-2^63~2^63-1)
	 long c = 10;
	// 4����������(-2^63~2^63-1)
	 long long d = 10;


	 cout << "a = " << a << endl;
	 cout << "b = " << b << endl;
	 cout << "c = " << c << endl;
	 cout << "d = " << d << endl;

	 return 0;
}