#include <iostream>
using namespace std;

// ����һ��չʾת���ַ�ʹ�÷���������
int main() {

	// ת���ַ�

	// ���з� \n
	cout << "Hello, World!\n";

	// ��б�� \\ 
	cout << "This is a backslash: \\ " << endl;

	// ˮƽ�Ʊ�� \t
	// ˮƽ�Ʊ�����������ı�������
	// һ��ˮƽ�Ʊ��ͨ�������ĸ��ո�
	cout << "Name\tAge\tGender" << endl;
	cout << "Tom\t20\tMale" << endl;
	cout << "Jerry\t22\tFemale" << endl;

	// \ddd �˽���ת���ַ�
	// \ddd �˽���ת���ַ���ʾһ���˽�����
	// �˽������ķ�Χ�� 0-7
	cout << "This is an octal number: \101" << endl;

	// \xhh ʮ������ת���ַ�
	// \xhh ʮ������ת���ַ���ʾһ��ʮ��������
	// ʮ���������ķ�Χ�� 0-9, A-F, a-f
	cout << "This is a hexadecimal number: \x41" << endl;

	return 0;
}