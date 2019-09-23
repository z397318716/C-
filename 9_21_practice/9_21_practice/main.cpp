/*
���������Լ�����ʵ��vector������alloc������������һ��� malloc/free
	����*/

#include <cstddef>
#include <iostream>

using namespace std;

template <class T>
inline void destroy(T* pointer) {
	pointer->~T();                                //ֻ������һ���װ����ָ����ָ�Ķ�������---ͨ��ֱ�ӵ��������������
}

template <class T1, class T2>
inline void construct(T1* p, const T2& value) {
	new (p)T1(value);                            //��placement new�� p ��ָ�Ķ����ϴ���һ������value�ǳ�ʼ�������ֵ��
}

template <class ForwardIterator>                //destroy�ķ����棬��������������Ϊ����
inline void destroy(ForwardIterator first, ForwardIterator last) {
	for (; first < last; ++first)
		destroy(&*first);
}


inline void destroy(char*, char*) {}        //��� char * ���ػ���
inline void destroy(wchar_t*, wchar_t*) {}    //��� wchar_t*���ػ���


class My_vector
{
public:
	typedef T value_type;
	typedef value_type* pointer;
	typedef value_type* iterator;
	typedef value_type& reference;
	typedef const value_type* const_pointer;
	typedef const value_type* const_iterator;
	typedef const value_type& const_reference;
	typedef size_t size_type;
protected:
	void __allocate_and_fill(size_type n, const T& value)        //����ռ䣬������ʼֵ
	{
		iterator result = (iterator)malloc(n*sizeof(T));
		if (0 != result)
		{
			//�����ڴ�ɹ����ڵõ����ڴ��ϴ�������
			start = result;
			end_of_storage = start + n;
			finish = end_of_storage;
			while (n--)
			{
				construct(result, value);    //���ڴ��ϣ�һ�����Ľ��й������
				++result;
			}
		} else
		{
			cout << "�ڴ治�㣬������ֹ��" << endl;
			exit(0);
		}
	}
	iterator __allocate_and_copy(iterator first, iterator last, size_type n)    //����ռ䣬������ֵ���ռ���
	{
		iterator result = (iterator)malloc(n*sizeof(T));
		iterator _start = result;
		if (0 != result)
		{
			while (n--)
			{
				construct(result, *first);
				++result;
				++first;
			}
			cout << endl;
		} else
		{
			cout << "�ڴ治�㣬������ֹ��" << endl;
			exit(0);
		}
		return _start;
	}
	//��first��last������֮��[first,last)��Ԫ�ؿ�����_start��ʼ���ڴ���
	iterator __copy(iterator first, iterator last, iterator _start)
	{
		while (first < last)
		{
			*_start++ = *first++;
		}
		return _start;
	}
public:
	//������Ԫ��ָ��
	iterator begin() { return start; }
	const iterator begin() const { return start; }
	//����βԪ����һ��λ�õ�ָ��
	iterator end()   { return finish; }
	const iterator end() const { return finish; }
	//�����Ĵ�С
	size_type size() const { return (size_type)(end() - begin()); }
	//������ʵ�ʴ�С
	size_type capacity() const { return (size_type)(end_of_storage - begin()); }
	//�ж������Ƿ�Ϊ��
	bool empty() { return begin() == end(); }
	//typedef ptrdiff_t difference_type;
	//Ĭ�Ϲ��캯��
	My_vector() :start(0), finish(0), end_of_storage(0){ cout << "Ĭ�Ϲ��캯����������ռ�" << endl; }
	//���캯������ C c(n,t):
	My_vector(size_type n, const T& value)  { __allocate_and_fill(n, value); }
	My_vector(int n, const T& value)        { __allocate_and_fill(n, value); }
	My_vector(long n, const T& value)        { __allocate_and_fill(n, value); }
	//���캯������ C c(n): 
	My_vector(size_type n)    { __allocate_and_fill(n, T()); }
	My_vector(int n)        { __allocate_and_fill(n, T()); }
	My_vector(long n)        { __allocate_and_fill(n, T()); }
	//���캯������ C c2(c1)
	My_vector(const My_vector<T>& mv)
	{
		start = __allocate_and_copy(mv.begin(), mv.end(), mv.end() - mv.begin());
		finish = start + (mv.end() - mv.begin());
		end_of_storage = finish;
	}
	//���캯������ C c2(b,e)
	My_vector(const iterator& b, const iterator& e)
	{
		start = __allocate_and_copy(b, e, size_type(e - b + 1));
		finish = start + (e - b + 1);
		end_of_storage = finish;
	}
	//Ԫ�ز���
	//ɾ�����һ��Ԫ��
	void pop_back()
	{
		if (!empty())
		{
			--finish;
			destroy(finish);
		}
	}
	//ɾ��ָ��λ���ϵ�Ԫ��,����ָ��ɾ��Ԫ�صĵ�����
	iterator erase(iterator position)
	{
		if (position > begin() && position < end())
		{
			__copy(position + 1, finish, position);
		}
		--finish;
		destroy(finish);
		return position;
	}
	//����erase,���ݵ�������Χɾ��
	iterator erase(iterator first, iterator last)
	{
		iterator i = __copy(last, finish, first);
		destroy(i, finish);
		finish -= (last - first);
		return first;
	}
	//���ȫ��Ԫ��
	void clear()
	{
		erase(begin(), end());
	}
	//��vector ������������һ��Ԫ��
	void push_back(const T& value)
	{
		if (finish != end_of_storage)    //������б��ÿռ�
		{
			construct(finish, value);
			++finish;
		} else
		{
			//��������ռ�
			const size_type old_size = size();
			const size_type new_size = (old_size == 0) ? 1 : 2 * old_size;
			iterator new_start = (iterator)malloc(new_size * sizeof(T));
			iterator new_finish = new_start;
			//�ڴ�ķ���Ҫ��ԭ���ԣ���:Ҫôȫ���ɹ���Ҫôȫ��ʧ�ܡ�
			try{
				//1.��ԭ���ݿ������µ�vector
				//2.Ϊ�µ�Ԫ���趨��ֵx
				//3.����new_finish
				for (iterator it = begin(); it < end(); ++it)
				{
					//cout << "it:" << *it << " ";
					construct(new_finish++, *it);
				}
				construct(new_finish, value);
				++new_finish;
			} catch (...)
			{
				//���ʧ����
				destroy(new_start, new_finish);
				//ɾ�����뵽���ڴ�
				free(new_start);
				new_start = new_finish = NULL;
				throw;        //�׳��쳣
			}

			//�������ͷ�ԭvector
			destroy(begin(), end());
			//ɾ���ڴ�
			free(start);
			//������������ָ���µ�vector
			start = new_start;
			finish = new_finish;
			end_of_storage = new_start + new_size;
		}
	}
	//insert--����ö���룬����д
	void insert(iterator position, size_type n, const T& value)
	{
	}
	void insert(iterator position, const T& value)
	{
		insert(position, 1, value);
	}
	//���ز�����
	reference operator[](size_type n){ return *(begin() + n); }
	const_reference operator[](size_type n) const{ return *(begin() + n); }
	bool operator==(const My_vector& mv)
	{
		if (mv.size() != size())
			return false;
		for (iterator it = mv.begin(); it < mv.end(); ++it)
		{
			if (*it != *(begin() + (it - mv.begin())))
				break;
		}
		if (it == mv.end())
			return true;
		else
			return false;
	}
	bool operator!=(const My_vector& mv)
	{
		return !(operator==(mv));
	}
private:
	iterator start;
	iterator finish;
	iterator end_of_storage;
};









int main()
{
	My_vector<int>::iterator it;

	//Ĭ�Ϲ��캯��
	My_vector<int> mvec;
	cout << mvec.begin() << " " << mvec.end() << endl;
	cout << "size=" << mvec.size() << endl;
	cout << "capacity=" << mvec.capacity() << endl;
	for (it = mvec.begin(); it < mvec.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	//����Ԫ�ظ�����һ����ʼֵ�Ĺ��캯��
	My_vector<int> mvecnt(2, 9);
	cout << mvecnt.begin() << " " << mvecnt.end() - 1 << endl;
	cout << "size=" << mvecnt.size() << endl;
	cout << "capacity=" << mvecnt.capacity() << endl;
	for (it = mvecnt.begin(); it < mvecnt.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	My_vector<int> mvecnt1(2, 9);
	cout << mvecnt1.begin() << " " << mvecnt1.end() - 1 << endl;
	cout << "size=" << mvecnt1.size() << endl;
	cout << "capacity=" << mvecnt1.capacity() << endl;
	for (it = mvecnt1.begin(); it < mvecnt1.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	mvecnt1.pop_back();
	cout << "size=" << mvecnt1.size() << endl;
	//���� != �� ==
	if (mvecnt != mvecnt1)
		cout << "mvecnt != mvecnt1" << endl;
	else if (mvecnt == mvecnt1)
		cout << "mvecnt == mvecnt1" << endl;
	//����Ԫ�ظ����Ĺ��캯��
	My_vector<int> mvecn(4);
	cout << mvecn.begin() << " " << mvecn.end() - 1 << endl;
	cout << "size=" << mvecn.size() << endl;
	cout << "capacity=" << mvecn.capacity() << endl;
	for (it = mvecn.begin(); it < mvecn.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	//���ƹ��캯��
	My_vector<int> mvecc(mvec);
	cout << mvecc.begin() << " " << mvecc.end() - 1 << endl;
	cout << "size=" << mvecc.size() << endl;
	cout << "capacity=" << mvecc.capacity() << endl;
	for (it = mvecc.begin(); it < mvecc.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	//�����������������캯��
	int arr[6] = { 1, 2, 3, 4, 5, 6 };
	My_vector<int> mvecbe(&arr[0], &arr[5]);
	cout << mvecbe.begin() << " " << mvecbe.end() - 1 << endl;
	cout << "size=" << mvecbe.size() << endl;
	cout << "capacity=" << mvecbe.capacity() << endl;
	for (it = mvecbe.begin(); it < mvecbe.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	//����5�����캯���������
	//���� pop_back()
	mvecbe.pop_back();
	cout << "size=" << mvecbe.size() << endl;
	cout << "capacity=" << mvecbe.capacity() << endl;
	for (it = mvecbe.begin(); it < mvecbe.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	//���� erase();
	mvecbe.erase(mvecbe.begin() + 1, mvecbe.begin() + 3);
	cout << "size=" << mvecbe.size() << endl;
	cout << "capacity=" << mvecbe.capacity() << endl;
	for (it = mvecbe.begin(); it < mvecbe.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	//����clear()
	mvecbe.clear();
	cout << "size=" << mvecbe.size() << endl;
	cout << "capacity=" << mvecbe.capacity() << endl;
	for (it = mvecbe.begin(); it < mvecbe.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << mvecbe[0] << endl;
	//���²���push_back()
	mvec.push_back(7);
	cout << mvec.begin() << " " << mvec.end() << endl;
	cout << "size=" << mvec.size() << endl;
	cout << "capacity=" << mvec.capacity() << endl;
	for (it = mvec.begin(); it < mvec.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	mvec.push_back(3);
	cout << "size=" << mvec.size() << endl;
	cout << "capacity=" << mvec.capacity() << endl;
	for (it = mvec.begin(); it < mvec.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	mvec.push_back(4);
	cout << "size=" << mvec.size() << endl;
	cout << "capacity=" << mvec.capacity() << endl;
	for (it = mvec.begin(); it < mvec.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	mvec.push_back(9);
	cout << "size=" << mvec.size() << endl;
	cout << "capacity=" << mvec.capacity() << endl;
	for (it = mvec.begin(); it < mvec.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	mvec.push_back(0);
	cout << "size=" << mvec.size() << endl;
	cout << "capacity=" << mvec.capacity() << endl;
	for (it = mvec.begin(); it < mvec.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}