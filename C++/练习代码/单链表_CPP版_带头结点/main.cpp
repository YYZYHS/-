#include <iostream>
using namespace std;

template <class T>
struct LNode
{
	T data;														// ������
	LNode<T> *next;												// ָ����
	LNode() : next(nullptr) {}									// �޲ι��캯��
	LNode(T d, LNode<T> *n = nullptr) : data(d), next(n) {}		// �вι��캯��
	~LNode() {}													// ��������
};

template <class T>
class LinkList
{
public:
	LinkList();														// �޲ι��캯��
	~LinkList();													// ��������

	// ��Ҫ����
	void initListByHead();											// ͷ�巨��������
	void initListByTail();											// β�巨��������
	bool insertList(int i, T e);									// ��λ���� ----��巨
	bool insertListByForward(int i, T e);							// ��λ���� ----ǰ�巨
	bool deleteElem(int i, T &e);									// ��λɾ��
	bool clearList();												// �������
	LNode<T>* getElem(int i) const;									// ��λ����
	int locateElem(T e) const;										// ��ֵ����

	// ���ú���
	void print() const;												// ��ӡ����
	bool isEmpty() const;											// �п�
	int length() const;												// ���

private:
	LNode<T>* createNewNode(T e) const;								// ����һ���½��
	bool insertNextNode(LNode<T>* p, T e);							// ��ָ�����֮������½��
	bool insertPriorNode(LNode<T>* p, T e);							// ��ָ�����֮ǰ�����½��



private:
	LNode<T> *m_dymmyNode;												// ͷָ��
	int m_length;														// ������
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
	cout << "�����Ƿ����ж�Խ����Ϊ:"<< "L2��" << L2.length() + 1 << "��Ԫ�أ�" << (p4 == nullptr ? "������" : "����") << endl;

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

template<class T>
LinkList<T>::LinkList()
	: m_dymmyNode{ new LNode<T> }, m_length(0)
{
}


template<class T>
LinkList<T>::~LinkList()
{
	clearList();
	m_dymmyNode = nullptr;
	m_length = 0;
}

template<class T>
void LinkList<T>::initListByHead()
{
	clearList();									// �������
	T e;
	while (true)								// ��������
	{
		cout << "����������(��9999����): ";
		cin >> e;
		if (e == 9999)							// ����9999����
		{
			break;
		}
		LNode<T> *newNode = createNewNode(e);		// �����½��
		newNode->next = m_dymmyNode->next;			// �½��ָ��ͷ���ĺ�̽��
		m_dymmyNode->next = newNode;				// ͷ���ָ���½��
		++m_length;									// ���ȼ�1
	}
}

template<class T>
void LinkList<T>::initListByTail()
{
	clearList();									// �������
	T e;
	LNode<T> *tail = m_dymmyNode;					// βָ��
	while (true)								// ��������
	{
		cout << "����������(��9999����): ";
		cin >> e;
		if (e == 9999)								// ����9999����
		{
			break;
		}
		LNode<T> *newNode = createNewNode(e);		// �����½��
		tail->next = newNode;						// β���ָ���½��
		tail = newNode;								// βָ��ָ���½��
		++m_length;									// ���ȼ�1
	}

}

template<class T>
bool LinkList<T>::insertList(int i, T e)
{
	if(i < 1 || i > m_length + 1)						// �ж�λ���Ƿ�Ϸ�
	{
		cerr << "����λ�ò��Ϸ�" << endl;
		return false;
	}
	if(i == 1)
	{
		return insertNextNode(m_dymmyNode, e);			// ��ͷ��������½��
	}
	LNode<T> *p = getElem(i - 1);						// �ҵ���i-1�����
	return insertNextNode(p, e);						// �ڵ�i-1����������½��
}

template<class T>
bool LinkList<T>::insertListByForward(int i, T e)
{
	if(i < 1 || i > m_length + 1)						// �ж�λ���Ƿ�Ϸ�
	{
		cerr << "����λ�ò��Ϸ�" << endl;
		return false;
	}
	LNode<T> *p = getElem(i);							// �ҵ���i�����
	return insertPriorNode(p, e);						// �ڵ�i-1�����ǰ�����½��
}

template<class T>
bool LinkList<T>::deleteElem(int i, T& e)
{
	if(i < 1 || i > m_length)						// �ж�λ���Ƿ�Ϸ�
	{
		cerr << "ɾ��λ�ò��Ϸ�" << endl;
		return false;
	}
	LNode<T> *p = getElem(i - 1);					// �ҵ���i-1�����
	LNode<T> *q = p->next;							// �ҵ���i�����
	e = q->data;									// ��������
	p->next = q->next;								// ɾ�����
	delete q;										// �ͷſռ�
	--m_length;										// ���ȼ�1
	return true;
}

template<class T>
bool LinkList<T>::clearList()
{
	LNode<T> *p = m_dymmyNode->next;
	while (p != nullptr)
	{
		LNode<T> *q = p->next;
		delete p;
		p = q;
	}
	m_dymmyNode->next = nullptr;
	m_length = 0;
	return true;
}

template<class T>
LNode<T>* LinkList<T>::getElem(int i) const
{
	if (i == 0)
	{
		cout << "û�е�0��Ԫ��,�˴�����ͷ���" << endl;
		return m_dymmyNode;							// ����ͷ���
	}
	if(i < 1 || i > m_length)						// �ж�λ���Ƿ�Ϸ�
	{
		cerr << "λ�ò��Ϸ�" << endl;
		return nullptr;
	}
	LNode<T> *p = m_dymmyNode->next;				// ����һ��ָ��pָ��ͷ���
	for (int j = 1; j < i; ++j)						// �ҵ���i�����
	{
		p = p->next;
	}
	return p;										// ���ص�i�����
}

template<class T>
int LinkList<T>::locateElem(T e) const
{
	LNode<T> *p = m_dymmyNode->next;				// ����һ��ָ��pָ��ͷ���
	int i = 1;										// ������
	while (p != nullptr)							// ��������
	{
		if(p->data == e)							// �ҵ�Ԫ��
		{
			return i;								// ����λ��
		}
		p = p->next;
		++i;
	}
	return 0;										// û���ҵ�Ԫ��
}

template<class T>
void LinkList<T>::print() const
{
	LNode<T> *p = m_dymmyNode->next;
	while (p != nullptr)
	{
		cout << p->data << "-->";
		p = p->next;
	}
	cout << "NULL" << endl;
}

template<class T>
bool LinkList<T>::isEmpty() const
{
	return m_length == 0;
}

template<class T>
int LinkList<T>::length() const
{
	return m_length;
}

template<class T>
LNode<T>* LinkList<T>::createNewNode(T e) const
{
	LNode<T> *newNode = new LNode<T>(e);		// �����½��
	if (newNode == nullptr)						// ����ʧ��
	{
		cerr << "�����½��ʧ��" << endl;
		exit(1);
	}
	return newNode;								// �����½��
}

template<class T>
bool LinkList<T>::insertNextNode(LNode<T>* p, T e)
{
	if(p == nullptr)									// �жϽ���Ƿ�Ϊ��
	{
		cerr << "����λ�ò��Ϸ�" << endl;
		return false;
	}

	LNode<T> *newNode = createNewNode(e);					// �����½��
	newNode->next = p->next;								// �½��ָ��p�ĺ�̽��
	p->next = newNode;										// pָ���½��
	++m_length;												// ���ȼ�1
	return true;
}

template<class T>
bool LinkList<T>::insertPriorNode(LNode<T>* p, T e)
{
	if(p == nullptr)									// �жϽ���Ƿ�Ϊ��
	{
		cerr << "����λ�ò��Ϸ�" << endl;
		return false;
	}

	// ����һ: ����������,ʱ�临�Ӷ�O(1)
	LNode<T> *newNode = createNewNode(e);					// �����½��
	if(newNode == nullptr)									// ����ʧ��
	{
		cerr << "�����½��ʧ��" << endl;
		return false;
	}
	newNode->next = p->next;								// �½��ָ��p�ĺ�̽��
	p->next = newNode;										// pָ���½��
	swap(p->data, newNode->data);							// ����������
	++m_length;												// ���ȼ�1

	// ������: ʱ�临�Ӷ�O(n)
	//LNode<T> *q = m_head;									// ����һ��ָ��qָ��ͷ���
	//while (q->next != p)									// �ҵ�p��ǰ�����
	//{
	//	q = q->next;
	//}
	//if(q == nullptr)										// û���ҵ�p��ǰ�����
	//{
	//	cerr << "����λ�ò��Ϸ�" << endl;
	//	return false;
	//}
	//LNode<T> *newNode = createNewNode(e);						// �����½��
	//if(newNode == nullptr)									// ����ʧ��
	//{
	//		cerr << "�����½��ʧ��" << endl;
	// 		return false;
	//}
	//newNode->next = p;										// �½��ָ��p
	//q->next = newNode;										// qָ���½��
	//++m_length;												// ���ȼ�1

	return true;
}
