#include <iostream>
using namespace std;


template <typename T>
struct LNode
{
	T data;														// ������
	LNode<T>* next;												// ָ����
	LNode() : next(nullptr) {}									// �޲ι��캯��
	LNode(T d, LNode<T>* n = nullptr) : data(d), next(n) {}		// �вι��캯��
	~LNode() {}													// ��������
};


template <typename T>
class LinkList
{
public:
	LinkList();				//���캯��
	~LinkList();			//��������

	// �������
	bool initListByHead();											// ͷ�巨��������
	bool initListByTail();											// β�巨��������
	bool insertList(int i, T e);									// ��λ���� ----��巨
	bool insertListByForward(int i, T e);							// ��λ���� ----ǰ�巨
	bool deleteElem(int i, T& e);									// ��λɾ��
	bool clearList();												// �������
	LNode<T>* getElem(int i) const;									// ��λ����
	int locateElem(T e) const;										// ��ֵ����


	// ���ú���
	int length() const;			//��ȡ������
	bool isEmpty() const;			//�ж������Ƿ�Ϊ��
	void print() const;			//��ӡ����

private:
	LNode<T>* createNewNode(T e) const;								// ����һ���½��
	bool insertNextNode(LNode<T>* p, T e);							// ��ָ�����֮������½��
	bool insertPriorNode(LNode<T>* p, T e);							// ��ָ�����֮ǰ�����½��


private:
	LNode<T> *m_head;		//ͷָ��
	int m_length;			//������
};



int main()
{
	// �����ǲ��Դ���

	// 1����ʼ����������
	cout << "��ʼ���ԣ����ȳ�ʼ��������������" << endl;
	LinkList<int> L1, L2, L3;
	cout << "��ʼ��ʼ����һ������������Ϊ�ձ�" << endl;
	L1.clearList();
	cout << "��ʼ��ʼ���ڶ���������������ǰ�巨��ʼ��" << endl;
	L2.initListByHead();
	cout << "��ʼ��ʼ��������������������β�巨��ʼ��" << endl;
	L3.initListByTail();

	// 2����ӡ����������пպ����
	cout << "��ʼ��ӡ��һ������" << endl;
	L1.print();
	cout << "��ʼ��ӡ�ڶ�������" << endl;
	L2.print();
	cout << "��ʼ��ӡ����������" << endl;
	L3.print();
	cout << "L1�Ƿ�Ϊ�գ�" << (L1.isEmpty() ? "��" : "��") << endl;
	cout << "L2�Ƿ�Ϊ�գ�" << (L2.isEmpty() ? "��" : "��") << endl;
	cout << "L3�Ƿ�Ϊ�գ�" << (L3.isEmpty() ? "��" : "��") << endl;
	cout << "L1�ĳ��ȣ�" << L1.length() << endl;
	cout << "L2�ĳ��ȣ�" << L2.length() << endl;
	cout << "L3�ĳ��ȣ�" << L3.length() << endl;

	// 3��L2��λ���ң��ֱ������βԪ�غ��м��Ԫ��
	cout << "��ʼ����L2��λ����" << endl;
	LNode<int>* p1 = L2.getElem(1);
	LNode<int>* p2 = L2.getElem(3);
	LNode<int>* p3 = L2.getElem(L2.length());
	LNode<int>* p4 = L2.getElem(L2.length() + 1);
	cout << "L2��1��Ԫ�أ�" << p1->data << endl;
	cout << "L2��3��Ԫ�أ�" << p2->data << endl;
	cout << "L2���һ��Ԫ�أ�" << p3->data << endl;
	cout << "�����Ƿ����ж�Խ����Ϊ:" << "L2��" << L2.length() + 1 << "��Ԫ�أ�" << (p4 == nullptr ? "������" : "����") << endl;

	// 4��L2��ֵ���ң��ֱ������βԪ�غ��м��Ԫ��
	cout << "��ʼ����L2��ֵ����" << endl;
	int i1 = L2.locateElem(1);
	int i2 = L2.locateElem(3);
	int i3 = L2.locateElem(L2.getElem(1)->data);
	int i4 = L2.locateElem(9999);//�����ڵ�Ԫ��
	cout << "Ԫ��1��λ�ã�" << i1 << endl;
	cout << "Ԫ��3��λ�ã�" << i2 << endl;
	cout << "��ʼ��ʱ��������Ԫ�ص�λ�ã�" << i3 << endl;
	cout << "�����Ƿ����жϲ����ڵ�Ԫ��:" << "Ԫ��9999��λ�ã�" << i4 << endl;

	// 5��L3��λ���룬�ֱ���ǰ�塢���ķ�ʽ���ڱ�ͷ����β�����в���Ԫ��
	cout << "��ʼ����L3��λ����" << endl;
	cout << "�ڱ�ͷ��ǰ�巽ʽ����Ԫ��100," << (L3.insertListByForward(1, 100) ? "�ɹ�" : "ʧ��") << endl;
	cout << "�ڱ�β��ǰ�巽ʽ����Ԫ��200," << (L3.insertListByForward(L3.length() + 1, 200) ? "�ɹ�" : "ʧ��") << endl;
	cout << "���������ڶ���λ����ǰ�巽ʽ����Ԫ��300," << (L3.insertListByForward(L3.length(), 300) ? "�ɹ�" : "ʧ��") << endl;
	L3.print();
	cout << "�ڱ�ͷ�Ժ�巽ʽ����Ԫ��400," << (L3.insertList(1, 400) ? "�ɹ�" : "ʧ��") << endl;
	cout << "�ڱ�β�Ժ�巽ʽ����Ԫ��500," << (L3.insertList(L3.length() + 1, 500) ? "�ɹ�" : "ʧ��") << endl;
	cout << "���������ڶ���λ���Ժ�巽ʽ����Ԫ��600," << (L3.insertList(L3.length(), 600) ? "�ɹ�" : "ʧ��") << endl;
	L3.print();

	// 6��L3ɾ��Ԫ�أ��ֱ�ɾ����ͷ����β������Ԫ��
	cout << "��ʼ����L3ɾ��Ԫ��" << endl;
	cout << "ɾ����ͷԪ�أ�" << (L3.deleteElem(1, i1) ? "�ɹ�" : "ʧ��") << "��ɾ����Ԫ���ǣ�" << i1 << endl;
	L3.print();
	cout << "ɾ����βԪ�أ�" << (L3.deleteElem(L3.length(), i2) ? "�ɹ�" : "ʧ��") << "��ɾ����Ԫ���ǣ�" << i2 << endl;
	L3.print();
	cout << "ɾ������Ԫ�أ�" << (L3.deleteElem(L3.length() / 2, i3) ? "�ɹ�" : "ʧ��") << "��ɾ����Ԫ���ǣ�" << i3 << endl;
	L3.print();

	// 7�������������
	cout << "��ʼ�����������,Ϊ�˲�����տձ��Ƚ�L1��Ϊ�ձ�" << endl;
	L1.clearList();
	cout << "���L1��" << (L1.clearList() ? "�ɹ�" : "ʧ��") << endl;
	cout << "���L2��" << (L2.clearList() ? "�ɹ�" : "ʧ��") << endl;
	cout << "���L3��" << (L3.clearList() ? "�ɹ�" : "ʧ��") << endl;
	L1.print();
	L2.print();
	L3.print();

	// 8��������
	cout << "���Խ���" << endl;
	return 0;
}


template<typename T>
LinkList<T>::LinkList()
	: m_head(nullptr), m_length(0)
{
}

template<typename T>
LinkList<T>::~LinkList()
{
	clearList();
}

template<typename T>
bool LinkList<T>::initListByHead()
{
	clearList();
	T e;
	while (true)
	{
		cout << "����������(��9999����): ";
		cin >> e;
		if (e == 9999)
		{
			break;
		}
		LNode<T> *newNode = createNewNode(e);		// �����½��
		if (newNode == nullptr)						// ����ʧ��
		{
			cerr << "�����½��ʧ��" << endl;
			clearList();							// �������
			return false;							// �˳�����
		}
		newNode->next = m_head;							// �½��ָ��ͷ���
		m_head = newNode;								// ͷָ��ָ���½��
		m_length++;										// �����ȼ�1
	}
	cout << "ͷ�巨��������ɹ�" << endl;
	return true;
}

template<typename T>
bool LinkList<T>::initListByTail()
{
	clearList();
	T e;
	LNode<T> *tail = m_head;	// βָ��
	while (true)
	{
		cout << "����������(��9999����): ";
		cin >> e;
		if (e == 9999)
		{
			break;
		}
		LNode<T> *newNode = createNewNode(e);		// �����½��
		if (newNode == nullptr)						// ����ʧ��
		{
			cerr << "�����½��ʧ��" << endl;
			clearList();							// �������
			return false;							// �˳�����
		}
		if (m_head == nullptr)						// ����Ϊ��
		{
			m_head = newNode;						// ͷָ��ָ���½��
			tail = newNode;							// βָ��ָ���½��
		}
		else
		{
			tail->next = newNode;					// β���ָ���½��
			tail = newNode;							// βָ��ָ���½��
		}
		m_length++;									// �����ȼ�1
	}
	cout << "β�巨��������ɹ�" << endl;
	return true;
}

template<typename T>
bool LinkList<T>::insertList(int i, T e)
{
	if (i < 1 || i > m_length + 1)
	{
		cout << "����λ�ò��Ϸ�" << endl;
		return false;
	}

	// �������:����λ��Ϊͷ���
	if (i == 1)
	{
		LNode<T> *newNode = createNewNode(e);	// �����½��
		if (newNode == nullptr)					// ����ʧ��
		{
			return false;
		}
		newNode->next = m_head;					// �½��ָ��ͷ���
		m_head = newNode;						// ͷָ��ָ���½��
		m_length++;								// �����ȼ�1
		return true;
	}

	// һ�����:����λ�ò�Ϊͷ���
	LNode<T> *p = getElem(i - 1);				// ��ȡ��i-1�����
	if (p == nullptr)							// δ�ҵ���i-1�����
	{
		cout << "δ�ҵ���" << i - 1 << "�����" << endl;
		return false;
	}
	return insertNextNode(p, e);				// �ڵ�i-1�����֮������½��
}

template<typename T>
bool LinkList<T>::insertListByForward(int i, T e)
{
	if (i < 1 || i > m_length + 1)
	{
		cout << "����λ�ò��Ϸ�" << endl;
		return false;
	}

	// �������:����λ��Ϊͷ���
	if (i == 1)
	{
		LNode<T> *newNode = createNewNode(e);	// �����½��
		if (newNode == nullptr)					// ����ʧ��
		{
			return false;
		}
		newNode->next = m_head;					// �½��ָ��ͷ���
		m_head = newNode;						// ͷָ��ָ���½��
		m_length++;								// �����ȼ�1
		return true;
	}

	// һ�����:����λ�ò�Ϊͷ���
	LNode<T> *p = getElem(i);				// ��ȡ��i-1�����
	if (p == nullptr)							// δ�ҵ���i-1�����
	{
		cout << "δ�ҵ���" << i<< "�����" << endl;
		return false;
	}
	return insertPriorNode(p, e);				// �ڵ�i�����֮ǰ�����½��
}

template<typename T>
bool LinkList<T>::deleteElem(int i, T& e)
{
	if(i < 1 || i > m_length)
	{
		cout << "ɾ��λ�ò��Ϸ�" << endl;
		return false;
	}

	if(isEmpty())
	{
		cout << "����Ϊ��" << endl;
		return false;
	}

	// �������:ɾ��ͷ���
	if(i == 1)
	{
		LNode<T> *p = m_head;		// pָ��ͷ���
		m_head = m_head->next;		// ͷָ��ָ��ڶ������
		e = p->data;				// ����ɾ������������
		delete p;					// ɾ�����
		m_length--;					// �����ȼ�1
		return true;
	}
	else
	{
		LNode<T>* p = getElem(i - 1);	// ��ȡ��i-1�����
		if (p == nullptr)				// δ�ҵ���i-1�����
		{
			cout << "δ�ҵ���" << i - 1 << "�����" << endl;
			return false;
		}
		LNode<T>* q = p->next;			// qָ���i�����
		if (q == nullptr)				// δ�ҵ���i�����
		{
			cout << "δ�ҵ���" << i << "�����" << endl;
			return false;
		}
		p->next = q->next;				// ɾ����i�����
		e = q->data;					// ����ɾ������������
		delete q;						// ɾ�����
		m_length--;						// �����ȼ�1
		return true;
	}
}

template<typename T>
int LinkList<T>::length() const
{
	return m_length;
}

template<typename T>
bool LinkList<T>::isEmpty() const
{
	return m_head == nullptr;
}

template<typename T>
void LinkList<T>::print() const
{
	LNode<T>* p = m_head;
	while (p != nullptr)
	{
		cout << p->data << "-->";
		p = p->next;
	}
	cout << "NULL" << endl;
}

template<typename T>
LNode<T>* LinkList<T>::createNewNode(T e) const
{
	LNode<T> *newNode = new LNode<T>(e);			// �����½��	
	if (newNode == nullptr)						// ����ʧ��
	{
		cout << "�����½��ʧ��" << endl;
		return nullptr;
	}
	return newNode;							// �����½��
}

template<typename T>
bool LinkList<T>::insertNextNode(LNode<T>* p, T e)
{
	if(p == nullptr)
	{
		cout << "����λ�ò��Ϸ�" << endl;
		return false;
	}
	LNode<T>* newNode = createNewNode(e);	// �����½��
	if (newNode == nullptr)					// ����ʧ��
	{
		return false;
	}
	newNode->next = p->next;				// �½��ָ��p�ĺ�̽��
	p->next = newNode;						// pָ���½��
	m_length++;								// �����ȼ�1
	return true;
}

template<typename T>
bool LinkList<T>::insertPriorNode(LNode<T>* p, T e)
{
	if(p == nullptr)
	{
		cout << "����λ�ò��Ϸ�" << endl;
		return false;
	}

	// �������:����λ��Ϊͷ���
	if(p == m_head)
	{
		LNode<T> *newNode = createNewNode(e);	// �����½��
		if(newNode == nullptr)					// ����ʧ��
		{
			return false;
		}
		newNode->next = m_head;					// �½��ָ��ͷ���
		m_head = newNode;						// ͷָ��ָ���½��
		m_length++;								// �����ȼ�1
		return true;
	}

	// һ�����:����λ�ò�Ϊͷ���
	// ����һ:ͨ���ҵ�p��ǰ�����,Ȼ�������Ԫ��,ʱ�临�Ӷ�O(n)
	/*
	LNode<T> *q = m_head;	// qָ��ͷ���,��ͷ��ʼ����,�ҵ�p��ǰ�����
	while (q != p)
	{
		q = q->next;
	}
	if(q == nullptr)
	{
		cout << "δ�ҵ�p��ǰ�����" << endl;
		return false;
	}
	LNode<T> *newNode = createNewNode(e);	// �����½��
	if(newNode == nullptr)					// ����ʧ��
	{
		return false;
	}
	newNode->next = q->next;				// �½��ָ��p
	q->next = newNode;						// qָ���½��
	m_length++;								// �����ȼ�1
	return true;
	*/

	// ������:ͨ������p��p��ǰ������������,ʱ�临�Ӷ�O(1)
	LNode<T> *newNode = createNewNode(e);	// �����½��
	if(newNode == nullptr)					// ����ʧ��
	{
		return false;
	}
	newNode->next = p->next;						// �½��ָ��p
	p->next = newNode;								// pָ���½��
	// ����p��p��ǰ������������
	T temp = p->data;								
	p->data = newNode->data;
	newNode->data = temp;
	m_length++;										// �����ȼ�1
	return true;
}

template<typename T>
bool LinkList<T>::clearList()
{
	LNode<T>* p = m_head;
	while (p != NULL)
	{
		LNode<T>* q = p->next;
		delete p;
		p = q;
	}
	m_head = nullptr;
	m_length = 0;
	return true;
}

template<typename T>
LNode<T>* LinkList<T>::getElem(int i) const
{
	if(isEmpty())
	{
		cout << "����Ϊ��" << endl;
		return nullptr;
	}
	if(i < 1 || i > m_length)
	{
		cout << "����λ�ò��Ϸ�" << endl;
		return nullptr;
	}
	LNode<T>* p = m_head;
	for (int j = 1; j < i; j++)
	{
		p = p->next;
	}
	return p;
}

template<typename T>
int LinkList<T>::locateElem(T e) const
{
	if(isEmpty())
	{
		cout << "����Ϊ��" << endl;
		return -1;
	}
	LNode<T>* p = m_head;
	int i = 1;
	while (p != nullptr)
	{
		if(p->data == e)
		{
			return i;
		}
		p = p->next;
		i++;
	}
	cout << "δ�ҵ�Ԫ��" << endl;
	return -1;
}
