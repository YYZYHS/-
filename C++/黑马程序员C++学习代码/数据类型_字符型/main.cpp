#include <iostream>		// C++��׼���������,��C++�г���cin��cout�����������
#include <cstdio>		// C��׼���������,��C�����г���scanf��printf�����������
using namespace std;

// ������뻺�����Ŀ�ƽ̨����
void clearInputBuffer() {
	// ������뻺����,�������뻺�����е��ַ��Ժ����������������Ӱ��
	int c,count=0;
	while ((c = getchar()) != '\n' && c != EOF) // �����뻺�����л����ַ�ʱ
	{
		count++;
	}
	cout << "�����" << count << "���ַ�" << endl;
}

int main()
{
	// ������������ʾ�ַ����������͵�ʹ��

	// 1.�ַ��ͱ����Ĵ�����ʽ
	char ch = 'A';
	cout << ch << endl;

	// 2.�ַ��ͱ�����ռ�ڴ��С
	cout << "sizeof(char) = " << sizeof(char) << endl; 

	// 3.�ַ��ͱ�����������
	// char ch1 = "A"; // ����˫���ű�ʾ�ַ����������ű�ʾ�ַ�,�����ַ��ͱ���ʱֻ���õ�����
	// char ch2 = 'AB'; // ���󣬵�������ֻ����һ���ַ�


	// 4.�����ַ��ͱ�����Ӧ��ASCII��ֵ
	char ch3 = 'A';
	cout << ch3 << "=" << (int)ch3 << endl; // 65
	char ch4 = 'a';
	cout << ch4 << "=" << (int)ch4 << endl; // 97
	char ch5 = '0';
	cout << ch5 << "=" << (int)ch5 << endl; // 48

	// 5.�ַ��ͱ���������:C++�е��ַ��ͱ�������ͨ��cin��������
	char ch6;
	cout << "������һ���ַ���" << endl;
	cin >> ch6;
	cout << "��������ַ��ǣ�" << ch6 << "����ASCII��ֵ�ǣ�" << (int)ch6 << endl;
	
	clearInputBuffer(); // ������뻺����

	// 6.�ַ��ͱ���������:C�����е��ַ��ͱ�������ͨ��scanf��������
	 char ch7;
	 printf("������һ���ַ���\n");
	 fflush(stdin); // ������뻺����
	 //scanf("%c", &ch7); // scanf�����Ѿ�����̭��������ڸ߰汾��VS�п��ܻ��������,����ʹ��scanf_s
	 scanf_s("%c", &ch7,1);
	 printf("��������ַ��ǣ�%c ����ASCII��ֵ�ǣ�%d\n", ch7, ch7);

	return 0;
}