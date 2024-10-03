/**
* @brief ��̬˳����ʵ��
* @file main.c
* @auther YYZYHS
* @date 2024��8��21��
* @version 1.0
* @note �������Ƕ�̬˳����C++ʵ�֣�������ʼ�������롢ɾ�������ҡ���������ݵȲ���
*/

#include <iostream>
using namespace std;

// ====================��̬˳����ඨ��====================
// ����ʹ��ģ����ʵ�֣�֧��������������
template <class T>
class DSeqList		// D - Dynamic Se-Sequence
{
public:
// ��������
	DSeqList(int capacity = 10);	/// �вι��캯����Ĭ������Ϊ10
	~DSeqList();	/// ��������
	bool init();	/// ��ʼ��
	bool destroy();	/// ����
	bool clear();	/// ���
	bool isEmpty() const;	/// �п�
	int length() const;	/// �󳤶�
	int capacity() const;	/// ������
	bool increase(int len);	/// ����
	bool insert(int i, T e);	/// ����
	bool remove(int i, T& e);	/// ɾ��
	bool locate(T e, int& i) const;	/// ��ֵ����
	bool get(int i, T& e) const;	/// ��λ����
	bool set(int i, T e);	/// ��ֵ
	bool print() const;	/// ���
// ��չ����
	bool push_front(T e);	/// ͷ��
	bool pop_front(T& e);	/// ͷɾ
	bool push_back(T e);	/// β��
	bool pop_back(T& e);	/// βɾ
// �߽ײ���
	bool removeDuplicate();	/// ȥ��
	bool reverse();	/// ����
	bool merge(const DSeqList<T>& list);	/// �ϲ�
	bool sortByInsert();	/// ��������
	bool swap(int i, int j);	/// ����
	bool sortByQuick(int left = 1, int right = -1);	/// ��������

private:
	T* m_data;		/// ������
	int m_size;		/// ��ǰԪ�ظ���,������
	int m_capacity;	/// ��ǰ����,�����Ԫ�ظ���
};

void test1();
void test2();
void test3();
void test4();
void test5();

int main()
{
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ���Կ�ʼ��" << endl;
	test1();
	cout << endl << endl << endl;
	test2();
	cout << endl << endl << endl;
	test3();
	cout << endl << endl << endl;
	test4();
	cout << endl << endl << endl;
	test5();
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ���Խ�����" << endl;
	return 0;
}


/*
* @brief �вι��캯��
* @param capacity ��̬˳��������
* @return �ޣ���Ϊ�ǹ��캯��������Ҫ����ֵ
* @note 
*		�������ܣ�
*			�������ڶ�̬˳�����󴴽�ʱ���Զ����ã����ڳ�ʼ����̬˳������
*		����˼·��
*			1. ��ʼ����̬˳����������
* 			2. ����init()������ʼ����̬˳�������ʼ���ɹ���ʲô�������������ͷ��ڴ档
*		ע�⣺
*			1. �ú����ǹ��캯��������Ҫ����ֵ��
*			2. �ú����ڶ�̬˳�����󴴽�ʱ���Զ����ã������û��ֶ����á�
*			3. �ú����Ĳ�������ָ����̬˳����ʼ����������ָ����Ĭ��Ϊ10���ں�������ʱ�Ѿ�ָ����Ĭ��ֵ����
*			4. ���û��Զ������вι��캯��ʱ��ϵͳ�������ṩ�޲ι��캯������������Ҫ���޲ι��캯�����ɶ�����Ҫ��ʽ�����޲ι��캯����
*/
template<class T>
DSeqList<T>::DSeqList(int capacity)
{
	cout << endl << "[INFO] ���캯��DSeqList(int capacity)������" << endl;
	m_capacity = capacity;
	if (!init())
	{
		m_data = NULL;
		m_size = 0;
		m_capacity = 0;
	}
}

/*
* @brief ��������
* @param ��
* @return �ޣ���Ϊ����������������Ҫ����ֵ
* @note
* 		�������ܣ�
* 			�������ڶ�̬˳����������ʱ���Զ����ã��������ٶ�̬˳������
* 		����˼·��
* 			1. ����destroy()�������ٶ�̬˳������
*       ע�⣺
* 			1. �ú�������������������Ҫ����ֵ��
* 			2. �ú����ڶ�̬˳����������ʱ���Զ����ã������û��ֶ����á�
*/
template<class T>
DSeqList<T>::~DSeqList()
{
	cout << endl << "[INFO] ��������~DSeqList()������" << endl;
	destroy();
}

/*
* @brief ��ʼ��
* @param ��
* @return ��ʼ���ɹ�����true�����򷵻�false
* @note
* 		�������ܣ�
* 			���������ڳ�ʼ����̬˳���
* 		����˼·��
* 			1. ���붯̬˳������������������ɹ����ʼ���ɹ��������ʼ��ʧ�ܡ�
* 			2. �����ʼ���ɹ����򽫵�ǰԪ�ظ�����Ϊ0��������Ϊ0��
* 			3. ���س�ʼ�������
* 		ע�⣺
* 			1. ��ʼ��������ı䶯̬˳����״̬����˲�����Ϊ����Ա������
* 			2. ��ʼ������ʱ�临�Ӷ�ΪO(1)���ռ临�Ӷ�ΪO(1)��
* 			3. ��ʼ�������Ὣ�����򴴽����ѣ��ò������ܻ�ʧ�ܣ�����������ڴ��һ��Ҫ�ж��Ƿ�����ɹ���
*/
template<class T>
bool DSeqList<T>::init()
{
	cout << endl << "[INFO] init()������" << endl;
	m_data = new T[m_capacity];
	if (NULL == m_data)
	{
		cout << "[ERROR] �ڴ����ʧ�ܣ���̬˳����ʼ��ʧ�ܣ�" << endl;
		return false;
	}
	m_size = 0;
	cout << "[INFO] ��̬˳����ʼ���ɹ���" << endl;
	return true;
}

/*
* @brief ����
* @param ��
* @return ���ٳɹ�����true�����򷵻�false
* @note
* 		�������ܣ�
* 			�������������ٶ�̬˳���
* 		����˼·��
* 			1. �ͷŶ�̬˳���������������ͷųɹ������ٳɹ�����������ʧ�ܡ�
* 			2. ������ٳɹ����򽫵�ǰԪ�ظ�����Ϊ0��������Ϊ0��
* 			3. �������ٽ����
* 		ע�⣺
* 			1. ���ٲ�����ı䶯̬˳����״̬����˲�����Ϊ����Ա������
* 			2. ���ٲ���ʱ�临�Ӷ�ΪO(1)���ռ临�Ӷ�ΪO(1)��
* 			3. ���ٲ������ͷŶ�̬˳���������������������ǰ��Ҫ�ж�������ָ���Ƿ�Ϸ������ָ��ΪNULL����Ҫ�ͷš�
*/
template<class T>
bool DSeqList<T>::destroy()
{
	cout << endl << "[INFO] destroy()������" << endl;
	if (NULL != m_data)
	{
		delete[] m_data;
		m_data = NULL;
		m_size = 0;
		m_capacity = 0;
	}
	cout << "[INFO] ��̬˳������ٳɹ���" << endl;
	return true;
}

/*
* @brief ���
* @param ��
* @return ��ճɹ�����true�����򷵻�false
* @note
* 		�������ܣ�
* 			������������ն�̬˳���
* 		����˼·��
* 			1. ����ǰԪ�ظ�����Ϊ0��������Ϊ0��
* 			2. ��ճɹ�����true��
* 		ע�⣺
* 			1. ��ղ�����ı䶯̬˳����״̬����˲�����Ϊ����Ա������
* 			2. ��ղ���ʱ�临�Ӷ�ΪO(1)���ռ临�Ӷ�ΪO(1)��
* 			3. ����ղ���Ϊ�߼��ϵ���գ�������������ڴ�ռ䣨��m_data�����ᱻ�ͷš�
*/
template<class T>
bool DSeqList<T>::clear()
{
	cout << endl << "[INFO] clear()������" << endl;
	m_size = 0;
	return true;
}

/*
* @brief �п�
* @param ��
* @return ����̬˳���Ϊ���򷵻�true�����򷵻�false
* @note
* 		�������ܣ�
* 			�����������ж϶�̬˳����Ƿ�Ϊ�ա�
* 		����˼·��
* 			1. ˳����г�Ա����m_size��¼��ǰԪ�ظ�������m_sizeΪ0���ʾ˳���Ϊ�գ����ֱ�ӷ���m_size�Ƿ�Ϊ0���ɡ�
* 	    ע�⣺
* 			1. ��Ϊ�пղ�������ı䶯̬˳����״̬���������Ϊ����Ա������
* 			2. �пղ���ʱ�临�Ӷ�ΪO(1)���ռ临�Ӷ�ΪO(1)��
*/
template<class T>
bool DSeqList<T>::isEmpty() const
{
	cout << endl << "[INFO] isEmpty()������" << endl;
	return m_size == 0;
}

/*
* @brief �󳤶�
* @param ��
* @return ���ض�̬˳���ĳ���
* @note
* 		�������ܣ�
* 			������������̬˳���ĳ��ȡ�
* 		����˼·��
* 			1. ˳����г�Ա����m_size��¼��ǰԪ�ظ�����ֱ�ӷ���m_size���ɡ�
* 		ע�⣺
* 			1. ��Ϊ�󳤶Ȳ�������ı䶯̬˳����״̬���������Ϊ����Ա������
* 			2. �󳤶Ȳ���ʱ�临�Ӷ�ΪO(1)���ռ临�Ӷ�ΪO(1)��
*/
template<class T>
int DSeqList<T>::length() const
{
	cout << endl << "[INFO] length()������" << endl;
	return m_size;
}


/*
 * @brief ������
 * @param ��
 * @return ���ض�̬˳��������
 * @note
 *		�������ܣ�
 *			������������̬˳�����������������󳤶ȣ���
 *      ����˼·��
 *			1. ˳����г�Ա����m_capacity��¼��ǰ������ֱ�ӷ���m_capacity���ɡ�
 *		ע�⣺
 *			1. ��Ϊ��������������ı䶯̬˳����״̬���������Ϊ����Ա������
 *			2. ����������ʱ�临�Ӷ�ΪO(1)���ռ临�Ӷ�ΪO(1)��
 */
template<class T>
int DSeqList<T>::capacity() const
{
	cout << endl << "[INFO] capacity()������" << endl;
	return m_capacity;
}

/*
* @brief ����
* @param len ���ݵĳ���
* @return ���ݳɹ�����true�����򷵻�false
* @note
* 		�������ܣ�
* 			�������������ݶ�̬˳���
* 		����˼·��
* 			1. �����µ�������������Ϊԭ���������ȼ������ݳ��ȡ�
* 			2. ��ԭ��������Ԫ�ظ��Ƶ�����������
*			3. �ͷ�ԭ��������
* 			4. �����������ĵ�ַ����ԭ��������
* 			5. ���ݳɹ�����true��
* 		ע�⣺
* 			1. ���ݲ�����ı䶯̬˳����״̬����˲�����Ϊ����Ա������
* 			2. ���ݲ���ʱ�临�Ӷ�ΪO(m_size)���ռ临�Ӷ�ΪO(len),����m_sizeΪ��ǰԪ�ظ���, lenΪ���ݳ��ȡ�
* 			3. ���ݲ����Ὣ�����򴴽����ѣ��ò������ܻ�ʧ�ܣ�����������ڴ��һ��Ҫ�ж��Ƿ�����ɹ���
*/
template<class T>
bool DSeqList<T>::increase(int len)
{
	cout << endl << "[INFO] increase(int len)�����ã����ݳ���Ϊ" << len << endl;
	T* new_data = new T[m_capacity + len];
	if (NULL == new_data)
	{
		cout << "[ERROR] �ڴ����ʧ�ܣ���̬˳�������ʧ�ܣ�" << endl;
		return false;
	}
	// ��ԭ��������Ԫ�ظ��Ƶ���������
	// ����һ��ʹ���ڴ濽������memcpy
	// memcpy(new_data, m_data, m_size * sizeof(T));

	// ��������ͨ��forѭ���������
	for (int i = 0; i < m_size; i++)
	{
		new_data[i] = m_data[i];
	}
	delete[] m_data;
	m_data = new_data;
	m_capacity += len;
	cout << "[INFO] ��̬˳������ݳɹ���" << endl;
	return true;
}

/*
* @brief ��λ����
* @param i ����λ��
* @param e ����Ԫ��
* @return ����ɹ�����true�����򷵻�false
* @note
* 		�������ܣ�
* 			�����������ڶ�̬˳���ĵ�i��λ�ò���Ԫ��e��
* 		����˼·��
* 			1. ���Ƚ��кϷ��Լ�飬�ж϶�̬˳����Ƿ��ѳ�ʼ��������λ���Ƿ�Ϸ���ֻҪ��һ�����Ϸ������ʧ�ܡ�
* 			2. �ж϶�̬˳����Ƿ�����������������Ҫ�������ٲ��룬�������ʧ�������ʧ�ܡ�
* 			3. �Ӻ���ǰ����������i��λ�ü�����Ԫ�����κ���һλ��
* 			4. ��Ԫ��e���뵽��i��λ�á�
* 			5. Ԫ�ظ�����1��
* 			6. ����ɹ�����true��
* 		ע�⣺
* 			1. ˳����λ���1��ʼ����������±��0��ʼ����Ҫ������
* 			2. �ں����У�����i��ָ����λ�ã��䱾��Ϊ˳����λ�򣬴�1��ʼ��
*			   ��forѭ���е�j�����ı�����������±꣬��0��ʼ����˵���j����ʾ˳����λ��ʱ����Ҫ��1��
*			   ��ˣ��ɡ�����i��λ�ü�����Ԫ�����κ���һλ����仰��֪j+1�ķ�ΧΪ[i,m_size],
* 			   ����j�������±꣬����j�ķ�ΧΪ[i-1,m_size-1]������forѭ���ķ�ΧΪ[j=m_size-1;j>=i-1;j--]��
* 			3. ��Ϊ���������ı䶯̬˳����״̬�����Բ�����Ϊ����Ա������
* 			4. �������ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)��
*/
template<class T>
bool DSeqList<T>::insert(int i, T e)
{
	cout << endl << "[INFO] insert(int i, T e)�����ã�����λ��Ϊ" << i << "������Ԫ��Ϊ" << e << endl;
	if (NULL == m_data)
	{
		cout << "[ERROR] ��̬˳���δ��ʼ����" << endl;
		return false;
	}
	if (i < 1 || i > m_size + 1)
	{
		cout << "[ERROR] ����λ�ò��Ϸ���" << endl;
		return false;
	}
	if (m_size >= m_capacity)
	{
		cout << "[INFO] ��̬˳�����������ʼĬ������10��Ԫ��" << endl;
		if (!increase(10))
		{
			cout << "[ERROR] ����ʧ�ܣ�����ʧ�ܣ�" << endl;
			return false;
		}
	}
	for (int j = m_size - 1; j >= i - 1; j--)
	{
		m_data[j + 1] = m_data[j];
	}
	m_data[i - 1] = e;
	m_size++;
	return true;
}

/*
* @brief ��λɾ��
* @param i ɾ��λ��
* @param e ��ɾ��Ԫ��
* @return ɾ���ɹ�����true�����򷵻�false
* @note
* 		�������ܣ�
* 			����������ɾ����̬˳���ĵ�i��λ�õ�Ԫ�ء�
*		����˼·��
* 			1. ���Ƚ��кϷ��Լ�飬�ж϶�̬˳����Ƿ��ѳ�ʼ����ɾ��λ���Ƿ�Ϸ���ֻҪ��һ�����Ϸ���ɾ��ʧ�ܡ�
* 			2. ��ͨ���Ϸ��Լ�飬�򽫱�ɾ����Ԫ�ظ�ֵ��e��
* 			3. ��ǰ�������������i+1��λ�ü�����Ԫ������ǰ��һλ��
* 			4. Ԫ�ظ�����1��
* 			5. ɾ���ɹ�����true��
* 		ע�⣺
* 			1. ˳����λ���1��ʼ����������±��0��ʼ����Ҫ������
* 			2. �ں����У�����i��ָɾ��λ�ã��䱾��Ϊ˳����λ�򣬴�1��ʼ��
* 			   ��forѭ���е�j�����ı�����������±꣬��0��ʼ����˵���j����ʾ˳����λ��ʱ����Ҫ��1��
* 			   ��ˣ��ɡ�����i+1��λ�ü�����Ԫ������ǰ��һλ����仰��֪j+1�ķ�ΧΪ[i+1,m_size],
* 			   ����j�������±꣬����j�ķ�ΧΪ[i,m_size-1]������forѭ���ķ�ΧΪ[j=i;j<=m_size-1;j++]��
*			3. ��Ϊɾ��������ı䶯̬˳����״̬�����Բ�����Ϊ����Ա������
* 			4. ɾ������ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)��
*/
template<class T>
bool DSeqList<T>::remove(int i, T& e)
{
	cout << endl << "[INFO] remove(int i, T& e)�����ã�ɾ��λ��Ϊ" << i << endl;
	if (NULL == m_data)
	{
		cout << "[ERROR] ��̬˳���δ��ʼ����" << endl;
		return false;
	}
	if (i < 1 || i > m_size)
	{
		cout << "[ERROR] ɾ��λ�ò��Ϸ���" << endl;
		return false;
	}
	e = m_data[i - 1];
	for (int j = i; j < m_size; j++)
	{
		m_data[j - 1] = m_data[j];
	}
	m_size--;
	return true;
}

/*
* @brief ��ֵ����
* @param e Ҫ���ҵ�Ԫ��
* @param i ���ڷ���Ԫ�ص�λ��
* @return ���ҳɹ�����true�����򷵻�false
* @note
*		�������ܣ�
* 			�����������ڶ�̬˳����в���Ԫ��e��λ��
*		����˼·��
*			1. ���Ƚ��кϷ��Լ�飬�ж϶�̬˳����Ƿ��ѳ�ʼ�������δ��ʼ�������ʧ�ܡ�
*			2. �ӵ�һ��Ԫ�ؿ�ʼ���������ҵ�Ԫ��e�򷵻�true�����򷵻�false��
*		ע�⣺
*			1. ˳����λ���1��ʼ����������±��0��ʼ����Ҫ������
*			2. �����������пղ�������Ϊforѭ�����Ѿ�������˳���Ϊ�յ������
*			3. ��ֵ���Ҳ���ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)��
*			4. ����������Ҫ�ı�˳����е��κ�ֵ���������Ϊ����Ա������
*/
template<class T>
bool DSeqList<T>::locate(T e, int& i) const
{
	cout << endl << "[INFO] locate(T e, int& i)�����ã�����Ԫ��Ϊ" << e << endl;
	if (NULL == m_data)
	{
		cout << "[ERROR] ��̬˳���δ��ʼ����" << endl;
		return false;
	}for (i = 0; i < m_size; i++)
	{
		if (m_data[i] == e)
		{
			cout << "[INFO] Ԫ��" << e << "��λ��Ϊ" << ++i << endl; // i+1ΪԪ�ص�λ��
			return true;
		}
	}
	cout << "[INFO] Ԫ��" << e << "�����ڣ�" << endl;
	return false;
}

/*
* @brief ��λ����
* @param i Ҫ���ҵ�λ��
* @param e ���ڷ���Ԫ��
* @return ���ҳɹ�����true�����򷵻�false
* @note
* 		�������ܣ�
* 			�����������ڶ�̬˳����в���λ��Ϊi��Ԫ�ء�
* 		����˼·��
* 			1. ���Ƚ��кϷ��Լ�飬�ж϶�̬˳����Ƿ��ѳ�ʼ��������λ���Ƿ�Ϸ���ֻҪ��һ�����Ϸ������ʧ�ܡ�
* 			2. ��ͨ���Ϸ��Լ�飬�򽫵�i��λ�õ�Ԫ�ظ�ֵ��e��
* 			3. ���ҳɹ�����true��
* 		ע�⣺
* 			1. ˳����λ���1��ʼ����������±��0��ʼ����Ҫ������
* 			2. �����������пղ�������Ϊ�ںϷ��Լ�����Ѿ�������˳���Ϊ�յ����������i < 1 || i > m_size���е�m_sizeΪ0ʱ��
* 			3. ��λ���Ҳ���ʱ�临�Ӷ�ΪO(1)���ռ临�Ӷ�ΪO(1)��
* 			4. ����������Ҫ�ı�˳����е��κ�ֵ���������Ϊ����Ա������
*/
template<class T>
bool DSeqList<T>::get(int i, T& e) const
{
	cout << endl << "[INFO] get(int i, T& e)�����ã�����λ��Ϊ" << i << endl;
	if (NULL == m_data)
	{
		cout << "[ERROR] ��̬˳���δ��ʼ����" << endl;
		return false;
	}
	if (i < 1 || i > m_size)
	{
		cout << "[ERROR] ����λ�ò��Ϸ���" << endl;
		return false;
	}
	e = m_data[i - 1];
	cout << "[INFO] λ��Ϊ" << i << "��Ԫ��Ϊ" << e << endl;
	return true;
}

/*
* @brief ��ֵ
* @param i Ҫ��ֵ��λ��
* @param e ��ֵ��Ԫ��
* @return ��ֵ�ɹ�����true�����򷵻�false
* @note
* 		�������ܣ�
* 			���������ڽ���̬˳����е�i��λ�õ�Ԫ�ظ�ֵΪe��
* 		����˼·��
* 			1. ���Ƚ��кϷ��Լ�飬�ж϶�̬˳����Ƿ��ѳ�ʼ������ֵλ���Ƿ�Ϸ���ֻҪ��һ�����Ϸ���ֵʧ�ܡ�
* 			2. ��ͨ���Ϸ��Լ�飬�򽫵�i��λ�õ�Ԫ�ظ�ֵΪe��
* 			3. ��ֵ�ɹ�����true��
* 		ע�⣺
* 			1. ˳����λ���1��ʼ����������±��0��ʼ����Ҫ������
* 			2. �����������пղ�������Ϊ�ںϷ��Լ�����Ѿ�������˳���Ϊ�յ����������i < 1 || i > m_size���е�m_sizeΪ0ʱ��
* 			3. ��ֵ����ʱ�临�Ӷ�ΪO(1)���ռ临�Ӷ�ΪO(1)��
* 			4. ��������ı�˳����е�ֵ����˲�����Ϊ����Ա������
*/
template<class T>
bool DSeqList<T>::set(int i, T e)
{
	cout << endl << "[INFO] set(int i, T e)�����ã���ֵλ��Ϊ" << i << "����ֵԪ��Ϊ" << e << endl;
	if (NULL == m_data)
	{
		cout << "[ERROR] ��̬˳���δ��ʼ����" << endl;
		return false;
	}
	if (i < 1 || i > m_size)
	{
		cout << "[ERROR] ��ֵλ�ò��Ϸ���" << endl;
		return false;
	}
	m_data[i - 1] = e;
	cout << "[INFO] λ��Ϊ" << i << "��Ԫ�ظ�ֵΪ" << e << endl;
	return true;
}

void test1()
{
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ����1����̬˳���ĳ�ʼ��������" << endl;
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ����һ������Ϊ5�Ķ�̬˳���" << endl;
	DSeqList<int> list(5);
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] �������ɵĶ�̬˳���" << endl; 
	list.destroy();
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ����1������" << endl;

}

void test2()
{
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ����2�����Ծ�̬˳���Ĳ��롢�������ա��пա������������ݺͲ�ѯ�����Ȳ���" << endl;
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ����һ������Ϊ5�Ķ�̬˳���" << endl;
	DSeqList<int> list(5);
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ���Բ������" << endl;
	list.insert(1, 1);
	list.insert(2, 2);
	list.insert(3, 3);
	list.insert(4, 4);
	list.insert(3, 8);
	list.insert(4, 6);
	list.insert(8, 7);
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] �����������" << endl;
	list.print();
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] �����пղ���" << endl;
	cout << "[INFO] ��̬˳����Ƿ�Ϊ�գ�" << list.isEmpty() << endl;
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ���Ա�����" << endl;
	cout << "[INFO] ��̬˳���ĳ���Ϊ��" << list.length() << endl;
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ������ղ���" << endl;
	list.clear();
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] �����пղ���" << endl;
	cout << "[INFO] ��̬˳����Ƿ�Ϊ�գ�" << list.isEmpty() << endl;
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ���Ա�����" << endl;
	cout << "[INFO] ��̬˳���ĳ���Ϊ��" << list.length() << endl;
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] �����������ݲ���" << endl;
	cout << "[INFO] ��ǰ��̬˳��������Ϊ��" << list.capacity() << endl;
	list.increase(5);
	cout << "[INFO] ���ݺ�̬˳��������Ϊ��" << list.capacity() << endl;
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ����2������" << endl;
}

void test3()
{
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ����3�����Ծ�̬˳����ɾ������λ���ҡ���ֵ���ҡ��޸ĵȲ���" << endl;
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ����һ������Ϊ10�Ķ�̬˳���" << endl;
	DSeqList<int> list(10);
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ����10��Ԫ��" << endl;
	for (int i = 1; i <= 10; i++)
	{
		list.insert(i, i);
	}
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] �����ǰ��̬˳��������" << endl;
	list.print();
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ���԰�λɾ������" << endl;
	int e;
	if (list.remove(5, e))
	{
		cout << "[INFO] ɾ���ɹ�����ɾ����Ԫ��Ϊ��" << e << endl;
	}
	else
	{
		cout << "[ERROR] ɾ��ʧ�ܣ�" << endl;
	}
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] �����ǰ��̬˳��������" << endl;
	list.print();
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ���԰�λɾ����ͷ�ͱ�β" << endl;
	if (list.remove(1, e))
	{
		cout << "[INFO] ɾ����ͷԪ�سɹ�����ɾ����Ԫ��Ϊ��" << e << endl;
	}
	else
	{
		cout << "[ERROR] ɾ����ͷԪ��ʧ�ܣ�" << endl;
	}
	cout << endl << endl << "[INFO] �����ǰ��̬˳��������" << endl;
	list.print();
	if (list.remove(list.length(), e))
	{
		cout << "[INFO] ɾ����βԪ�سɹ�����ɾ����Ԫ��Ϊ��" << e << endl;
	}
	else
	{
		cout << "[ERROR] ɾ����βԪ��ʧ�ܣ�" << endl;
	}
	cout << endl << endl << "[INFO] �����ǰ��̬˳��������" << endl;
	list.print();
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ���԰�ֵ���Ҳ���" << endl;
	int i;
	if (list.locate(3, i))
	{
		cout << "[INFO] ��ֵ����Ԫ��3�ɹ�����λ��Ϊ��" << i << endl;
	}
	else
	{
		cout << "[ERROR] ��ֵ����Ԫ��3ʧ�ܣ�" << endl;
	}
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ���԰�ֵ���ұ�ͷ�ͱ�βԪ��" << endl;
	if (list.locate(2, i))
	{
		cout << "[INFO] ��ֵ���ұ�ͷԪ��2�ɹ�����λ��Ϊ��" << i << endl;
	}
	else
	{
		cout << "[ERROR] ��ֵ���ұ�ͷԪ��2ʧ�ܣ�" << endl;
	}
	if (list.locate(9, i))
	{
		cout << "[INFO] ��ֵ���ұ�βԪ��9�ɹ�����λ��Ϊ��" << i << endl;
	}
	else
	{
		cout << "[ERROR] ��ֵ���ұ�βԪ��9ʧ�ܣ�" << endl;
	}

	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ���԰�λ���Ҳ���" << endl;
	if (list.get(3, e))
	{
		cout << "[INFO] ��λ����λ��Ϊ3��Ԫ�سɹ�����ֵΪ��" << e << endl;
	}
	else
	{
		cout << "[ERROR] ��λ����λ��Ϊ3��Ԫ��ʧ�ܣ�" << endl;
	}
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ���԰�λ���ұ�ͷ�ͱ�βԪ��" << endl;
	if (list.get(1, e))
	{
		cout << "[INFO] ��λ���ұ�ͷԪ�سɹ�����ֵΪ��" << e << endl;
	}
	else
	{
		cout << "[ERROR] ��λ���ұ�ͷԪ��ʧ�ܣ�" << endl;
	}
	if (list.get(list.length(), e))
	{
		cout << "[INFO] ��λ���ұ�βԪ�سɹ�����ֵΪ��" << e << endl;
	}
	else
	{
		cout << "[ERROR] ��λ���ұ�βԪ��ʧ�ܣ�" << endl;
	}

	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] �����޸Ĳ���" << endl;
	if (list.set(3, 5))
	{
		cout << "[INFO] �޸�λ��Ϊ3��Ԫ�سɹ����޸ĺ��Ԫ��Ϊ��" << 5 << endl;
	}
	else
	{
		cout << "[ERROR] �޸�λ��Ϊ3��Ԫ��ʧ�ܣ�" << endl;
	}
	cout << endl << endl << "[INFO] �����ǰ��̬˳��������" << endl;
	list.print();

	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ���ԶԱ�ͷ�ͱ�βԪ�ؽ����޸�" << endl;
	if (list.set(1, 10))
	{
		cout << "[INFO] �޸ı�ͷԪ�سɹ����޸ĺ��Ԫ��Ϊ��" << 10 << endl;
	}
	else
	{
		cout << "[ERROR] �޸ı�ͷԪ��ʧ�ܣ�" << endl;
	}
	if (list.set(list.length(), 20))
	{
		cout << "[INFO] �޸ı�βԪ�سɹ����޸ĺ��Ԫ��Ϊ��" << 20 << endl;
	}
	else
	{
		cout << "[ERROR] �޸ı�βԪ��ʧ�ܣ�" << endl;
	}
	cout << endl << endl << "[INFO] �����ǰ��̬˳��������" << endl;
	list.print();

	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ���ԶԿձ���а�ֵ���ҺͰ�λ���Ҳ���" << endl;
	cout << "[INFO] ���Ƚ���̬˳������" << endl;
	list.clear();
	cout << "[INFO] ��ʼ��ֵ����Ԫ��ֵΪ3��Ԫ��" << endl;
	if (list.locate(3, i))
	{
		cout << "[INFO] ��ֵ����Ԫ��3�ɹ�����λ��Ϊ��" << i << endl;
	}
	else
	{
		cout << "[ERROR] ��ֵ����Ԫ��3ʧ�ܣ�" << endl;
	}

	cout << endl << "[INFO] ��ʼ��λ����λ��Ϊ3��Ԫ��" << endl;
	if (list.get(3, e))
	{
		cout << "[INFO] ��λ����λ��Ϊ3��Ԫ�سɹ�����ֵΪ��" << e << endl;
	}
	else
	{
		cout << "[ERROR] ��λ����λ��Ϊ3��Ԫ��ʧ�ܣ�" << endl;
	}

}

void test4()
{
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ����4�����Ծ�̬˳������չ����" << endl;
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ����һ������Ϊ10�Ķ�̬˳���" << endl;
	DSeqList<int> list(10);
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ����5��Ԫ��" << endl;
	for (int i = 1; i <= 5; i++)
	{
		list.insert(i, i);
	}
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] �����ǰ��̬˳��������" << endl;
	list.print();
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ����ͷ�����" << endl;
	if(list.push_front(0))
	{
		cout << "[INFO] ͷ��Ԫ��0�ɹ���" << endl;
	}
	else
	{
		cout << "[ERROR] ͷ��Ԫ��0ʧ�ܣ�" << endl;
	}
	cout << endl << endl << "[INFO] �����ǰ��̬˳��������" << endl;
	list.print();
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ����β�����" << endl;
	if (list.push_back(6))
	{
		cout << "[INFO] β��Ԫ��6�ɹ���" << endl;
	}
	else
	{
		cout << "[ERROR] β��Ԫ��6ʧ�ܣ�" << endl;
	}
	cout << endl << endl << "[INFO] �����ǰ��̬˳��������" << endl;
	list.print();
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ����βɾ����" << endl;
	int e;
	if (list.pop_back(e))
	{
		cout << "[INFO] βɾ�ɹ�����ɾ����Ԫ��Ϊ��" << e << endl;
	}
	else
	{
		cout << "[ERROR] βɾʧ�ܣ�" << endl;
	}
	cout << endl << endl << "[INFO] �����ǰ��̬˳��������" << endl;
	list.print();
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ����ͷɾ����" << endl;
	if (list.pop_front(e))
	{
		cout << "[INFO] ͷɾ�ɹ�����ɾ����Ԫ��Ϊ��" << e << endl;
	}
	else
	{
		cout << "[ERROR] ͷɾʧ�ܣ�" << endl;
	}
	cout << endl << endl << "[INFO] �����ǰ��̬˳��������" << endl;
	list.print();
	cout << endl << endl << "[INFO] ���ԶԿձ������չ���ܲ���" << endl;
	cout << "[INFO] ���Ƚ���̬˳������" << endl;
	list.clear();
	cout << endl << endl << "[INFO] �����ǰ��̬˳��������" << endl;
	list.print();
	cout << endl << endl << "[INFO] ��ʼͷ��Ԫ��0" << endl;
	if (list.push_front(0))
	{
		cout << "[INFO] ͷ��Ԫ��0�ɹ���" << endl;
	}
	else
	{
		cout << "[ERROR] ͷ��Ԫ��0ʧ�ܣ�" << endl;
	}
	cout << endl << endl << "[INFO] �����ǰ��̬˳��������" << endl;
	list.print();
	cout << "[INFO] �ٴ���ն�̬˳���" << endl;
	list.clear();
	cout << endl << endl << "[INFO] �����ǰ��̬˳��������" << endl;
	list.print();
	cout << endl << endl << "[INFO] ��ʼβ��Ԫ��1" << endl;
	if (list.push_back(1))
	{
		cout << "[INFO] β��Ԫ��1�ɹ���" << endl;
	}
	else
	{
		cout << "[ERROR] β��Ԫ��1ʧ�ܣ�" << endl;
	}
	cout << endl << endl << "[INFO] �����ǰ��̬˳��������" << endl;
	list.print();
	cout << "[INFO] �ٴ���ն�̬˳���" << endl;
	list.clear();
	cout << endl << endl << "[INFO] �����ǰ��̬˳��������" << endl;
	list.print();
	cout << endl << endl << "[INFO] ��ʼͷɾ����" << endl;
	if (list.pop_front(e))
	{
		cout << "[INFO] ͷɾ�ɹ�����ɾ����Ԫ��Ϊ��" << e << endl;
	}
	else
	{
		cout << "[ERROR] ͷɾʧ�ܣ�" << endl;
	}
	cout << endl << endl << "[INFO] ��ʼβɾ����" << endl;
	if (list.pop_back(e))
	{
		cout << "[INFO] βɾ�ɹ�����ɾ����Ԫ��Ϊ��" << e << endl;
	}
	else
	{
		cout << "[ERROR] βɾʧ�ܣ�" << endl;
	}
	cout << endl << endl << "[INFO] �����ǰ��̬˳��������" << endl;
	list.print();
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ����4������" << endl;

}

void test5()
{
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ����5�����Ծ�̬˳���ĸ߽ײ���" << endl;
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ����һ������Ϊ10�Ķ�̬˳���" << endl;
	DSeqList<int> list(10);
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ����10��Ԫ��" << endl;
	list.insert(1, 5);
	list.insert(2, 3);
	list.insert(3, 7);
	list.insert(4, 2);
	list.insert(5, 8);
	list.insert(6, 4);
	list.insert(7, 9);
	list.insert(8, 1);
	list.insert(9, 6);
	list.insert(10, 10);
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] �����ǰ��̬˳��������" << endl;
	list.print();
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] �����������" << endl;
	//list.sortByQuick();
	list.sortByInsert();
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ��������Ķ�̬˳��������" << endl;
	list.print();
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] �������ò���" << endl;
	list.reverse();
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ������ú�Ķ�̬˳��������" << endl;
	list.print();
	cout << endl << endl << "[INFO] ��========================��" << endl << "[INFO] ����5������" << endl;
}

/*
* @brief ���
* @param ��
* @return ����ɹ�����true�����򷵻�false
* @note
* 		�������ܣ�
* 			���������������̬˳��������Ԫ�ء�
* 		����˼·��
* 			1. ���Ƚ��кϷ��Լ�飬�ж϶�̬˳����Ƿ��ѳ�ʼ�������δ��ʼ�������ʧ�ܡ�
* 			2. �ж϶�̬˳����Ƿ�Ϊ�գ����Ϊ�������ʧ�ܡ�
* 			3. �����Ϊ�գ���ӵ�һ��Ԫ�ؿ�ʼ�����������Ԫ�ء�
* 			4. ����ɹ�����true��
* 		ע�⣺
* 			1. �����������ı䶯̬˳����״̬���������Ϊ����Ա������
* 			2. �������ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)��
* 			3. ˳����λ���1��ʼ����������±��0��ʼ����Ҫ������
*/
template<class T>
bool DSeqList<T>::print() const
{
	cout << endl << "[INFO] print()������" << endl;
	if (NULL == m_data)
	{
		cout << "[ERROR] ��̬˳���δ��ʼ����" << endl;
		return false;
	}
	if (isEmpty())
	{
		cout << "[INFO] ��̬˳���Ϊ�գ�" << endl;
		return false;
	}
	cout << "[INFO] ��̬˳����Ԫ��Ϊ��";
	for (int i = 0; i < m_size; i++)
	{
		cout << m_data[i] << " ";
	}
	cout << endl;
	return true;
}


/*
* @brief ͷ��Ԫ��
* @param e Ҫ�����Ԫ��
* @return ����ɹ�����true�����򷵻�false
* @note
* 		�������ܣ�
* 			�����������ڶ�̬˳����ͷ������Ԫ��e��
* 		����˼·��
* 			1. ���Ƚ��кϷ��Լ�飬�ж϶�̬˳����Ƿ��ѳ�ʼ�����Ƿ���������δ��ʼ�����ʧ��,����������Ҫ�������ݡ�
* 			2. �Ӻ���ǰ������������Ԫ�����κ���һλ���ճ���һ��λ�á�
* 			3. ��Ԫ��e���뵽˳���ĵ�һ��λ�ã��������±�Ϊ0��λ�á�
* 			4. Ԫ�ظ�����1��
* 			5. ����ɹ�����true��
* 		ע�⣺
* 			1. ˳����λ���1��ʼ����������±��0��ʼ����Ҫ������
* 			2. ��forѭ���У�j�ı����������±꣬����Ҫ��j��ʾԪ��λ��ʱ��Ӧ��+1��
* 			   ���Ը��ݲ�������С�����i��Ԫ�ؼ�֮���Ԫ�غ��ơ���仰��λ��j+1�ķ�ΧΪ[i,m_size]��
* 			   ����Ϊ�ú�����ͷ�����������i=1��j+1�ķ�ΧΪ[1,m_size]������j�ķ�ΧΪ[0,m_size-1]������forѭ���ķ�ΧΪ[j=m_size-1;j>=0;j--]��
* 			3. ��Ϊ���������ı䶯̬˳����״̬�����Բ�����Ϊ����Ա������
* 			4. ��ͷ�������ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)��
* 			5. ��ʵ�ʵĿ����У�ͷ�巨��ʵ����ֱ�ӵ���insert(1,e)��ʵ�֣�����ֻ��Ϊ����ʾͷ�巨��ʵ��ԭ�������д�����ġ�
*/
template<class T>
bool DSeqList<T>::push_front(T e)
{
	cout << endl << "[INFO] push_front(T e)�����ã�����Ԫ��Ϊ" << e << endl;
	if (NULL == m_data)
	{
		cout << "[ERROR] ��̬˳���δ��ʼ����" << endl;
		return false;
	}
	if (m_size >= m_capacity)
	{
		cout << "[INFO] ��̬˳�����������ʼĬ������10��Ԫ��" << endl;
		if (!increase(10))
		{
			cout << "[ERROR] ����ʧ�ܣ�����ʧ�ܣ�" << endl;
			return false;
		}
	}
	for (int j = m_size - 1; j >= 0; j--)
	{
		m_data[j + 1] = m_data[j];
	}
	m_data[0] = e;
	m_size++;
	return true;
}


/*
* @brief ͷɾԪ��
* @param e ���ڷ��ر�ɾ����Ԫ��
* @return ɾ���ɹ�����true�����򷵻�false
* @note
* 		�������ܣ�
* 			����������ɾ����̬˳���ı�ͷԪ�ء�
* 		����˼·��
* 			1. ���Ƚ��кϷ��Լ�飬�ж϶�̬˳����Ƿ��ѳ�ʼ�����Ƿ�Ϊ�գ���δ��ʼ����Ϊ����ɾ��ʧ�ܡ�
* 			2. ����ͷԪ�ظ�ֵ��e��
* 			3. ��ǰ�������������2��λ�ü�����Ԫ������ǰ��һλ�����ǵ���1��λ�õ�Ԫ�ء�
* 			4. Ԫ�ظ�����1��
* 			5. ɾ���ɹ�����true��
* 		ע�⣺
* 			1. ˳����λ���1��ʼ����������±��0��ʼ����Ҫ������
* 			2. ��Ϊɾ��������ı䶯̬˳����״̬�����Բ�����Ϊ����Ա������
* 			3. ��ͷɾ������ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)��
*			4. ��forѭ���У�j�ı����������±꣬����Ҫ��j��ʾԪ��λ��ʱ��Ӧ��+1��
* 			   ���Ը���ɾ�������С�����i+1��Ԫ�ؼ�֮���Ԫ��ǰ�ơ���仰��λ��j+1�ķ�ΧΪ[i+1,m_size]��
* 			   ����Ϊ�ú�����ͷɾ����������i=1��j+1�ķ�ΧΪ[2,m_size]������j�ķ�ΧΪ[1,m_size-1]������forѭ���ķ�ΧΪ[j=1;j<=m_size-1;j++]��
* 			5. ˳����ͷɾ������ʵ����ֱ�ӵ���remove(1,e)��ʵ�֣�����ֻ��Ϊ����ʾͷɾ������ʵ��ԭ�������д�����ġ�
*/
template<class T>
bool DSeqList<T>::pop_front(T& e)
{
	cout << endl << "[INFO] pop_front(T& e)������" << endl;
	if (NULL == m_data)
	{
		cout << "[ERROR] ��̬˳���δ��ʼ����" << endl;
		return false;
	}
	if (isEmpty())
	{
		cout << "[ERROR] ��̬˳���Ϊ�գ�ɾ��ʧ�ܣ�" << endl;
		return false;
	}
	e = m_data[0];
	for (int j = 1; j < m_size; j++)
	{
		m_data[j - 1] = m_data[j];
	}
	m_size--;
	return true;
}

/*
* @brief β��Ԫ��
* @param e Ҫ�����Ԫ��
* @return ����ɹ�����true�����򷵻�false
* @note
* 		�������ܣ�
* 			�����������ڶ�̬˳����β������Ԫ��e��
* 		����˼·��
* 			1. ���Ƚ��кϷ��Լ�飬�ж϶�̬˳����Ƿ��ѳ�ʼ�����Ƿ���������δ��ʼ�����ʧ��,����������Ҫ�������ݡ�
* 			2. ��Ԫ��e���뵽˳���ĵ�m_size+1��λ�ã�������ĵ�m_size��λ�á�
* 			3. Ԫ�ظ�����1��
* 			4. ����ɹ�����true��
* 		ע�⣺
* 			1. ˳����λ���1��ʼ����������±��0��ʼ����Ҫ������
* 			2. �ڲ��������ݲ���������£�β�������ʱ�临�Ӷ�ΪO(1)���ռ临�Ӷ�ΪO(1)��
*			   �����Ҫ���ݣ���ʱ�临�Ӷ�ΪO(m_size)���ռ临�Ӷ�ΪO(len)������m_sizeΪ��ǰԪ�ظ�����lenΪ���ݳ��ȡ�
* 			3. ˳����β�������ʵ����ֱ�ӵ���insert(m_size+1,e)��ʵ�֣�����ֻ��Ϊ����ʾβ�������ʵ��ԭ�������д�����ġ�
*/
template<class T>
bool DSeqList<T>::push_back(T e)
{
	cout << endl << "[INFO] push_back(T e)�����ã�����Ԫ��Ϊ" << e << endl;
	if (NULL == m_data)
	{
		cout << "[ERROR] ��̬˳���δ��ʼ����" << endl;
		return false;
	}
	if (m_size >= m_capacity)
	{
		cout << "[INFO] ��̬˳�����������ʼĬ������10��Ԫ��" << endl;
		if (!increase(10))
		{
			cout << "[ERROR] ����ʧ�ܣ�����ʧ�ܣ�" << endl;
			return false;
		}
	}
	m_data[m_size] = e;
	m_size++;
	return true;
}

/*
* @brief βɾԪ��
* @param e ���ڷ��ر�ɾ����Ԫ��
* @return ɾ���ɹ�����true�����򷵻�false
* @note
* 		�������ܣ�
* 			����������ɾ����̬˳���ı�βԪ�ء�
* 		����˼·��
* 			1. ���Ƚ��кϷ��Լ�飬�ж϶�̬˳����Ƿ��ѳ�ʼ�����Ƿ�Ϊ�գ���δ��ʼ����Ϊ����ɾ��ʧ�ܡ�
* 			2. ����βԪ�ظ�ֵ��e����˳���ĵ�m_size��Ԫ�أ������±�Ϊm_size-1��Ԫ�ء�
* 			3. Ԫ�ظ�����1��
* 			4. ɾ���ɹ�����true��
* 		ע�⣺
* 			1. ˳����λ���1��ʼ����������±��0��ʼ����Ҫ������
* 			2. ��Ϊɾ��������ı䶯̬˳����״̬�����Բ�����Ϊ����Ա������
* 			3. ��βɾ������ʱ�临�Ӷ�ΪO(1)���ռ临�Ӷ�ΪO(1)��
* 			4. ˳����βɾ������ʵ����ֱ�ӵ���remove(m_size,e)��ʵ�֣�����ֻ��Ϊ����ʾβɾ������ʵ��ԭ�������д�����ġ�
*/
template<class T>
bool DSeqList<T>::pop_back(T& e)
{
	cout << endl << "[INFO] pop_back(T& e)������" << endl;
	if (NULL == m_data)
	{
		cout << "[ERROR] ��̬˳���δ��ʼ����" << endl;
		return false;
	}
	if (isEmpty())
	{
		cout << "[ERROR] ��̬˳���Ϊ�գ�ɾ��ʧ�ܣ�" << endl;
		return false;
	}
	e = m_data[m_size - 1];
	m_size--;
	return true;
}

/*
* @brief ɾ���ظ�Ԫ��
* @param ��
* @return ɾ���ɹ�����true�����򷵻�false
* @note
* 		�������ܣ�
* 			����������ɾ����̬˳����е��ظ�Ԫ�ء�
* 		����˼·��
* 			1. ���Ƚ��кϷ��Լ�飬�ж϶�̬˳����Ƿ��ѳ�ʼ�����Ƿ�Ϊ�գ���δ��ʼ����Ϊ����ɾ��ʧ�ܡ�
* 			2. �ӵ�һ��Ԫ�ؿ�ʼ���������ҵ��ظ�Ԫ����ɾ�����������������
* 			3. ɾ���ɹ�����true��
* 		ע�⣺
* 			1. ˳����λ���1��ʼ����������±��0��ʼ����Ҫ������
* 			2. ��Ϊɾ��������ı䶯̬˳����״̬�����Բ�����Ϊ����Ա������
*			3. ����ɾ��һ��Ԫ�غ󣬺����Ԫ�ػ�ǰ�ƣ�������Ҫ��j--�������©��һ��Ԫ�ء�
* 			4. ��ɾ���ظ�Ԫ�ز�����ʱ�临�Ӷ�ΪO(n^2)���ռ临�Ӷ�ΪO(1)��
*/
template<class T>
bool DSeqList<T>::removeDuplicate()
{
	cout << endl << "[INFO] removeDuplicate()������" << endl;
	if (NULL == m_data)
	{
		cout << "[ERROR] ��̬˳���δ��ʼ����" << endl;
		return false;
	}
	if (isEmpty())
	{
		cout << "[ERROR] ��̬˳���Ϊ�գ�ɾ��ʧ�ܣ�" << endl;
		return false;
	}
	for (int i = 0; i < m_size; i++)
	{
		for (int j = i + 1; j < m_size; j++)
		{
			if (m_data[i] == m_data[j])
			{
				T e;
				remove(j + 1, e);// remove�������Ѿ��Ὣm_size--���������ﲻ��Ҫ��m_size--��
				j--;
			}
		}
	}
	return true;
}

/*
* @brief ����
* @param ��
* @return ���óɹ�����true�����򷵻�false
* @note
* 		�������ܣ�
* 			�������������ö�̬˳����е�����Ԫ�ء�
* 		����˼·��
* 			1. ���Ƚ��кϷ��Լ�飬�ж϶�̬˳����Ƿ��ѳ�ʼ�����Ƿ�Ϊ�գ���δ��ʼ����Ϊ��������ʧ�ܡ�
* 			2. �ӵ�һ��Ԫ�ؿ�ʼ����������i��Ԫ�����m_size-i��Ԫ�ؽ�����
* 			3. ���óɹ�����true��
* 		ע�⣺
* 			1. ˳����λ���1��ʼ����������±��0��ʼ����Ҫ������
* 			2. ���ò�����ı䶯̬˳����״̬�����Բ�����Ϊ����Ա������
*			3. ���˳���ı�Ϊż��������������һ���Ԫ�أ������Ϊ���������м��Ԫ�ز���Ҫ�ƶ�����Ϊ���ǶԳƵ㡣
*			4. ��c++�У������ĳ���������ȡ�������Դ����е�m_size/2��ȡ��������m_size=5ʱ��5/2=2������i�ķ�ΧΪ[0,2)��
*			5. ����Ԫ��λ��ʱ����Ҫһ����ʱ����temp���洢�������м�ֵ�����ñ���д��forѭ�����棬���Լ����ڴ�ķ�����ͷŴ��������Ч�ʡ�
* 			6. �����ò�����ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)��
*/
template<class T>
bool DSeqList<T>::reverse()
{
	cout << endl << "[INFO] reverse()������" << endl;
	if (NULL == m_data)
	{
		cout << "[ERROR] ��̬˳���δ��ʼ����" << endl;
		return false;
	}
	if (isEmpty())
	{
		cout << "[ERROR] ��̬˳���Ϊ�գ�����ʧ�ܣ�" << endl;
		return false;
	}
	// ��ʼ����
	T temp; // ��tempд��forѭ�����棬���Լ����ڴ�ķ�����ͷŴ���
	for (int i = 0; i < m_size / 2; i++)
	{
		temp = m_data[i];
		m_data[i] = m_data[m_size - i - 1];
		m_data[m_size - i - 1] = temp;
	}
	return true;
}


/*
* @brief �ϲ�
* @param list Ҫ�ϲ���˳���
* @return �ϲ��ɹ�����true�����򷵻�false
* @note
* 		�������ܣ�
* 			���������ڽ���������Ķ�̬˳���ϲ���һ������Ķ�̬˳���
* 		����˼·��
*			1. ���Ƚ��кϷ��Լ�飬�ж�������̬˳�����������Ƿ���Ч������һ����Ч����m_data == NULL����ϲ�ʧ�ܡ�
* 			2. �ж�������̬˳����Ƿ�Ϊ��
			   ����˳���Ϊ�գ���list�ϲ�����˳����У���listΪ�գ�����Ҫ�ϲ���
			   ������˳���Ϊ�գ���ϲ�ʧ�ܡ�
* 			3. ����һƬ�µ�����ռ䣬���鳤��Ϊ������̬˳���ĳ���֮�͡�
*			4. �ӵ�һ��Ԫ�ؿ�ʼ��������������̬˳����е�Ԫ�����αȽϣ�����С��Ԫ�ط����µ������С�
* 			5. ����һ����̬˳����Ԫ���Ѿ�ȫ�������������У�����һ����̬˳����ʣ��Ԫ�����η����������С�
* 			6. �ͷ�ԭ��������ռ䣬��������ĵ�ַ��ֵ��������ָ��m_data��
* 			7. �޸Ķ�̬˳���ı���
* 			8. �ϲ��ɹ�����true��
* 		ע�⣺
*			1. ˳����λ���1��ʼ����������±��0��ʼ����Ҫ������
* 			2. �ϲ�������ı䶯̬˳����״̬�����Բ�����Ϊ����Ա������
* 			3. �úϲ�������ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(n)������nΪ������̬˳���ĳ���֮�͡�
*			4. �뾲̬˳���ĺϲ���ȣ���̬˳���ĺϲ�������������ͨ�ã�
			   ��Ϊ��̬˳���������ǿ��Զ�̬�����ģ�����̬˳���������ǹ̶��ģ����Ծ�̬˳���ĺϲ�������Ҫ�������������⡣
*			5. �ںϲ��㷨�У���Ҫά������ָ�룬�ֱ�ָ��������̬˳���������飬�Ա��ڱȽϺͲ��������
*			6. �ϲ��㷨�ľ��������ڣ�ֻ�ܺϲ���������Ķ�̬˳������������̬˳���������ģ�����Ҫ�������ٺϲ���
*/
template<class T>
bool DSeqList<T>::merge(const DSeqList<T>& list)
{
	cout << endl << "[INFO] merge(const DSeqList<T>& list)������" << endl;
	if (NULL == m_data || NULL == list.m_data)
	{
		cout << "[ERROR] ������̬˳�����������һ��δ��ʼ�����ϲ�ʧ�ܣ�" << endl;
		return false;
	}
	if (isEmpty())
	{
		if (list.isEmpty())
		{
			cout << "[ERROR] ������̬˳���Ϊ�գ��ϲ�ʧ�ܣ�" << endl;
			return false;
		}
		cout << "[INFO] ����̬˳���Ϊ�գ���list�ϲ�������̬˳�����" << endl;
		m_data = new T[list.m_capacity];
		for (int i = 0; i < list.m_size; i++)
		{
			m_data[i] = list.m_data[i];
		}
		m_size = list.m_size;
		m_capacity = list.m_capacity;
		return true;
	}
	if (list.isEmpty())
	{
		cout << "[INFO] listΪ�գ�����Ҫ�ϲ�" << endl;
		return true;
	}
	T* temp = new T[m_size + list.m_size];
	// ���������������ֱ��¼��˳����Ԫ��λ�á�list˳����Ԫ��λ�á��������Ԫ��λ��
	int indexThis = 0, indexOther = 0, indexMerged = 0;
	while (indexThis < m_size && indexOther < list.m_size)
	{
		if (m_data[indexThis] < list.m_data[indexOther])
		{
			temp[indexMerged++] = m_data[indexThis++];
		}
		else
		{
			temp[indexMerged++] = list.m_data[indexOther++];
		}
	}
	while (indexThis < m_size)
	{
		temp[indexMerged++] = m_data[indexThis++];
	}
	while (indexOther < list.m_size)
	{
		temp[indexMerged++] = list.m_data[indexOther++];
	}
	delete[] m_data;
	m_data = temp;
	m_size = m_size + list.m_size;
	m_capacity = m_size;
	return true;
}

/*
* @brief ��������
* @param ��
* @return ����ɹ�����true�����򷵻�false
* @note
* 		�������ܣ�
* 			���������ڶԶ�̬˳����е�Ԫ�ؽ��в�������
* 		����˼·��
* 			1. ���Ƚ��кϷ��Լ�飬�ж϶�̬˳����Ƿ��ѳ�ʼ�����Ƿ�Ϊ�գ���δ��ʼ��������ʧ�ܡ�
*			2. �ж϶�̬˳����Ƿ�Ϊ�գ���Ϊ��������ɹ���
* 			3. �ӵ�һ��Ԫ�ؿ�ʼ����Ԫ�ؿ�����Ϊ�Ѿ�������
			4. ȡ����һ��Ԫ�أ���Ϊtemp�����Ѿ������Ԫ�������дӺ���ǰɨ�衣
			5. �����ɨ�赽��Ԫ�ش���temp���򽫸�Ԫ�غ���һλ���ճ�һ��λ�á�
			6. �ظ�����5��ֱ���ҵ��������Ԫ��С�ڻ��ߵ�����Ԫ�ص�λ�á�
			7. ����Ԫ�ز��뵽��λ�ú�
			8. �ظ�����3-7��ֱ������Ԫ�ؾ�������ɡ�
* 		ע�⣺
* 			1. ˳����λ���1��ʼ����������±��0��ʼ����Ҫ������
* 			2. �������������ı䶯̬˳����״̬�����Բ�����Ϊ����Ա������
* 			3. ��������ĺ���˼���ǽ�һ��Ԫ�ز��뵽�Ѿ��ź����Ԫ���У�ʹ�ò�����Ԫ����Ȼ����
*			4. �ò������������ʱ�临�Ӷ�ΪO(n^2)���ռ临�Ӷ�ΪO(1)��
* 			4. ����������һ���ȶ��������㷨������ͬԪ�ص����λ�ò��ᷢ���仯��
* 			5. ����������һ��ԭ�������㷨��������Ҫ����Ĵ洢�ռ䡣
* 			6. ����������һ�ּ򵥵������㷨��������С��ģ����������
* 			7. ���ڲ�����������ݣ����������Ч�ʽϸߣ���֮�����������Ч�ʽϵ͡�
*			8. ������չʾ��������������Ҫ������������Ҫ��temp < m_data[j]��Ϊtemp > m_data[j]���ɡ�
*/
template<class T>
bool DSeqList<T>::sortByInsert()
{
	cout << endl << "[INFO] sortByInsert()������" << endl;
	if (NULL == m_data)
	{
		cout << "[ERROR] ��̬˳���δ��ʼ����" << endl;
		return false;
	}
	if (isEmpty())
	{
		cout << "[INFO] ��̬˳���Ϊ�գ�����ɹ���" << endl;
		return true;
	}
	T temp;
	for (int i = 1; i < m_size; i++)
	{
		temp = m_data[i]; // ȡ����ǰҪ�����Ԫ��
		int j = i - 1;

		// ���Ѿ������Ԫ�������дӺ���ǰɨ��
		while (j >= 0 && temp < m_data[j])
		{
			m_data[j + 1] = m_data[j]; // ����ǰԪ�ش���tempʱ������ǰԪ�غ���һλ
			j--;
		}
		m_data[j + 1] = temp; // ��temp���뵽���ʵ�λ��
	}
	return true;
}

/*
* @brief Ԫ�ؽ���
* @param i ��һ��Ԫ�ص�λ��
* @param j �ڶ���Ԫ�ص�λ��
* @return �����ɹ�����true�����򷵻�false
* @note
* 		�������ܣ�
* 			���������ڽ�����̬˳����е�����Ԫ�أ���Ҫ�����ڿ����㷨�з��㽻��Ԫ�ء�
* 		����˼·��
* 			1. ���Ƚ��кϷ��Լ�飬�ж϶�̬˳����Ƿ��ѳ�ʼ������δ��ʼ���򽻻�ʧ�ܡ�
* 			2. �ж϶�̬˳����Ƿ�Ϊ�գ���Ϊ���򽻻�ʧ�ܡ�
* 			3. �ж�i��j�Ƿ�Ϸ�����i��j�ķ�ΧΪ[1,m_size]��
* 			4. ��������Ԫ�ص�λ�á�
* 			5. �����ɹ�����true��
* 		ע�⣺
* 			1. ˳����λ���1��ʼ����������±��0��ʼ�������������е�i��j��Ԫ�ص�λ�򣬶�����������±꣬ע�ⲻҪ������
* 			2. ����������ı䶯̬˳����״̬�����Բ�����Ϊ����Ա������
* 			3. �ý���������ʱ�临�Ӷ�ΪO(1)���ռ临�Ӷ�ΪO(1)��
*/
template<class T>
bool DSeqList<T>::swap(int i, int j)
{
	cout << endl << "[INFO] swap(int " << i << ", int " << j << ")������" << endl;
	// ���Ƚ��кϷ��Լ��
	if (NULL == m_data)
	{
		cout << "[ERROR] ��̬˳���δ��ʼ����" << endl;
		return false;
	}
	// �ж϶�̬˳����Ƿ�Ϊ��
	if (isEmpty())
	{
		cout << "[ERROR] ��̬˳���Ϊ�գ�����ʧ�ܣ�" << endl;
		return false;
	}
	// �ж�i��j�Ƿ�Ϸ�
	 if (i < 1 || i > m_size || j < 1 || j > m_size)
	 {
		 cout << "[ERROR] ������Ԫ��λ�򲻺Ϸ���" << endl;
		 return false;
	 }
	// test start
	cout << "[INFO] ����ǰ��˳���Ϊ��";
	for (int i = 0; i < m_size; i++)
	{
		cout << m_data[i] << " ";
	}
	cout << endl;
	// test end
	T temp = m_data[i - 1];
	m_data[i - 1] = m_data[j - 1];
	m_data[j - 1] = temp;
	// test start
	cout << "[INFO] �������˳���Ϊ��";
	for (int i = 0; i < m_size; i++)
	{
		cout << m_data[i] << " ";
	}
	cout << endl;
	// test end
	return true;
}


/*
* @brief ��������
* @param left ���������е���߽�
* @param right ���������е��ұ߽磬��rightΪ-1�����ʾ������˳����������
* @return ����ɹ�����true�����򷵻�false
* @note
* 		�������ܣ�
* 			���������ڶԶ�̬˳����е�Ԫ�ؽ��п�������
* 		����˼·��
* 			1. ���Ƚ��кϷ��Լ�飬�ж϶�̬˳����Ƿ��ѳ�ʼ������δ��ʼ��������ʧ�ܡ�
* 			2. �ж϶�̬˳����Ƿ�Ϊ�գ���Ϊ��������ɹ���
* 			3. ѡ��һ����׼Ԫ�أ�ͨ��ѡ���һ��Ԫ�أ��ñ���T pivot��¼����
* 			4. ���������ҵ���һ��С�ڻ�׼Ԫ�ص�Ԫ�أ�����ŵ���׼Ԫ�ص�λ�á�
* 			5. ���������ҵ���һ�����ڻ�׼Ԫ�ص�Ԫ�أ�����ŵ�����4�пճ���λ�á�
* 			6. �ظ�����4��5��ֱ������ָ��������
* 			7. ����׼Ԫ�طŵ����յ�λ�ã���ʱ��׼Ԫ����ߵ�Ԫ�ض�С�������ұߵ�Ԫ�ض���������
* 			8. �ݹ鴦���������������У�ֱ�������еĳ���Ϊ1��
* 			9. ����ɹ�����true��
* 		ע�⣺
* 			1. ˳����λ���1��ʼ����������±��0��ʼ�������������е�left��right��Ԫ�ص�λ�򣬶�����������±꣬ע�ⲻҪ������
* 			2. �������������ı䶯̬˳����״̬�����Բ�����Ϊ����Ա������
* 			3. �ÿ������������ʱ�临�Ӷ�ΪO(nlogn)���ռ临�Ӷ�ΪO(logn)��
* 			4. ����������һ�ֲ��ȶ��������㷨������ͬԪ�ص����λ�ÿ��ܷ����仯��
* 			5. ����������һ�ֵݹ�������㷨���ݹ��������Ϊlogn�����Կռ临�Ӷ�ΪO(logn)��
* 			6. ׼ȷ��˵������������һ�ַ��ε������㷨����һ��������ֽ�Ϊ����С���⣬Ȼ��ݹ�����
* 			7. ����������һ��ԭ�������㷨��������Ҫ����Ĵ洢�ռ䡣
* 			8. ����������һ�ָ�Ч�������㷨�������ڴ��ģ���ݵ�����
* 			9. ���������Ч��ȡ���ڻ�׼Ԫ�ص�ѡ��ͨ��ѡ���һ��Ԫ�أ��������˳���������ģ���ѡ���һ��Ԫ����Ϊ��׼Ԫ�ػᵼ�������ķ�����
* 			10. Ϊ�˱��������ķ������������ѡ���׼Ԫ�أ�����ѡ���м�λ�õ�Ԫ����Ϊ��׼Ԫ�ء�
* 			11. �ÿ��������㷨������������Ҫ������������Ҫ������whileѭ���е�>=��<=�Ի�λ�ü��ɡ�
*/
template<class T>
bool DSeqList<T>::sortByQuick(int left, int right)
{
	cout << endl << "[INFO] sortByQuick(int " << left << ", int " << right << ")������" << endl;
	if (NULL == m_data)
	{
		cout << "[ERROR] ��̬˳���δ��ʼ����" << endl;
		return false;
	}
	if (isEmpty())
	{
		cout << "[INFO] ��̬˳���Ϊ�գ�����ɹ���" << endl;
		return true;
	}
	// test start
	cout << "[INFO] ��ǰ˳��������Ϊ��";
	for (int i = 0; i < m_size; i++)
	{
		cout << m_data[i] << " ";
	}
	cout << endl;
	// test end
	// ��rightΪ-1�����ʾ������˳����������
	if(right == -1)
	{
		right = m_size;
	}
	// �����еĳ���Ϊ1ʱ���ݹ����
	if (left >= right)
	{
		// test start
		cout << "[INFO] ��ǰleft=" << left << ", right=" << right << "�������г���Ϊ1���ݹ����" << endl;
		// test end
		return true; // �ݹ��������
	}
	T pivot = m_data[left-1]; // ѡ���׼Ԫ��
	int low = left, high = right;
	while (low < high)
	{
		while (low < high && m_data[high-1] >= pivot)
		{
			high--; // ���������ҵ�һ��С��pivot��Ԫ��
		}
		while (low < high && m_data[low - 1] <= pivot)
		{
			low++; // ���������ҵ�һ������pivot��Ԫ��
		}
		if (low < high)
		{
			swap(low, high); // ��������Ԫ��
		}
	}
	swap(left, low); // ��pivotԪ�طŵ����յ�λ��
	sortByQuick(left, low - 1); // �ݹ鴦����ߵ�������
	sortByQuick(low + 1, right); // �ݹ鴦���ұߵ�������
	return true;
}

