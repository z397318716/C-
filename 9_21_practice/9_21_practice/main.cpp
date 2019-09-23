/*
　　　　自己动手实现vector，不用alloc配置器，就用一般的 malloc/free
	　　*/

#include <cstddef>
#include <iostream>

using namespace std;

template <class T>
inline void destroy(T* pointer) {
	pointer->~T();                                //只是做了一层包装，将指针所指的对象析构---通过直接调用类的析构函数
}

template <class T1, class T2>
inline void construct(T1* p, const T2& value) {
	new (p)T1(value);                            //用placement new在 p 所指的对象上创建一个对象，value是初始化对象的值。
}

template <class ForwardIterator>                //destroy的泛化版，接受两个迭代器为参数
inline void destroy(ForwardIterator first, ForwardIterator last) {
	for (; first < last; ++first)
		destroy(&*first);
}


inline void destroy(char*, char*) {}        //针对 char * 的特化版
inline void destroy(wchar_t*, wchar_t*) {}    //针对 wchar_t*的特化版


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
	void __allocate_and_fill(size_type n, const T& value)        //分配空间，并填充初始值
	{
		iterator result = (iterator)malloc(n*sizeof(T));
		if (0 != result)
		{
			//申请内存成功，在得到的内存上创建对象！
			start = result;
			end_of_storage = start + n;
			finish = end_of_storage;
			while (n--)
			{
				construct(result, value);    //在内存上，一个个的进行构造对象
				++result;
			}
		} else
		{
			cout << "内存不足，程序终止！" << endl;
			exit(0);
		}
	}
	iterator __allocate_and_copy(iterator first, iterator last, size_type n)    //分配空间，并复制值到空间中
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
			cout << "内存不足，程序终止！" << endl;
			exit(0);
		}
		return _start;
	}
	//将first到last迭代器之间[first,last)的元素拷贝到_start开始的内存中
	iterator __copy(iterator first, iterator last, iterator _start)
	{
		while (first < last)
		{
			*_start++ = *first++;
		}
		return _start;
	}
public:
	//返回首元素指针
	iterator begin() { return start; }
	const iterator begin() const { return start; }
	//返回尾元素下一个位置的指针
	iterator end()   { return finish; }
	const iterator end() const { return finish; }
	//容器的大小
	size_type size() const { return (size_type)(end() - begin()); }
	//容器的实际大小
	size_type capacity() const { return (size_type)(end_of_storage - begin()); }
	//判断容器是否为空
	bool empty() { return begin() == end(); }
	//typedef ptrdiff_t difference_type;
	//默认构造函数
	My_vector() :start(0), finish(0), end_of_storage(0){ cout << "默认构造函数，不分配空间" << endl; }
	//构造函数重载 C c(n,t):
	My_vector(size_type n, const T& value)  { __allocate_and_fill(n, value); }
	My_vector(int n, const T& value)        { __allocate_and_fill(n, value); }
	My_vector(long n, const T& value)        { __allocate_and_fill(n, value); }
	//构造函数重载 C c(n): 
	My_vector(size_type n)    { __allocate_and_fill(n, T()); }
	My_vector(int n)        { __allocate_and_fill(n, T()); }
	My_vector(long n)        { __allocate_and_fill(n, T()); }
	//构造函数重载 C c2(c1)
	My_vector(const My_vector<T>& mv)
	{
		start = __allocate_and_copy(mv.begin(), mv.end(), mv.end() - mv.begin());
		finish = start + (mv.end() - mv.begin());
		end_of_storage = finish;
	}
	//构造函数重载 C c2(b,e)
	My_vector(const iterator& b, const iterator& e)
	{
		start = __allocate_and_copy(b, e, size_type(e - b + 1));
		finish = start + (e - b + 1);
		end_of_storage = finish;
	}
	//元素操作
	//删除最后一个元素
	void pop_back()
	{
		if (!empty())
		{
			--finish;
			destroy(finish);
		}
	}
	//删除指定位置上的元素,返回指向删除元素的迭代器
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
	//重载erase,根据迭代器范围删除
	iterator erase(iterator first, iterator last)
	{
		iterator i = __copy(last, finish, first);
		destroy(i, finish);
		finish -= (last - first);
		return first;
	}
	//清除全部元素
	void clear()
	{
		erase(begin(), end());
	}
	//在vector 容器后面增加一个元素
	void push_back(const T& value)
	{
		if (finish != end_of_storage)    //如果还有备用空间
		{
			construct(finish, value);
			++finish;
		} else
		{
			//重新申请空间
			const size_type old_size = size();
			const size_type new_size = (old_size == 0) ? 1 : 2 * old_size;
			iterator new_start = (iterator)malloc(new_size * sizeof(T));
			iterator new_finish = new_start;
			//内存的分配要有原子性，即:要么全部成功，要么全部失败。
			try{
				//1.将原内容拷贝到新的vector
				//2.为新的元素设定初值x
				//3.调整new_finish
				for (iterator it = begin(); it < end(); ++it)
				{
					//cout << "it:" << *it << " ";
					construct(new_finish++, *it);
				}
				construct(new_finish, value);
				++new_finish;
			} catch (...)
			{
				//如果失败了
				destroy(new_start, new_finish);
				//删除申请到的内存
				free(new_start);
				new_start = new_finish = NULL;
				throw;        //抛出异常
			}

			//析构并释放原vector
			destroy(begin(), end());
			//删除内存
			free(start);
			//调整迭代器，指向新的vector
			start = new_start;
			finish = new_finish;
			end_of_storage = new_start + new_size;
		}
	}
	//insert--这个好多代码，不想写
	void insert(iterator position, size_type n, const T& value)
	{
	}
	void insert(iterator position, const T& value)
	{
		insert(position, 1, value);
	}
	//重载操作符
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

	//默认构造函数
	My_vector<int> mvec;
	cout << mvec.begin() << " " << mvec.end() << endl;
	cout << "size=" << mvec.size() << endl;
	cout << "capacity=" << mvec.capacity() << endl;
	for (it = mvec.begin(); it < mvec.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	//根据元素个数和一个初始值的构造函数
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
	//测试 != 和 ==
	if (mvecnt != mvecnt1)
		cout << "mvecnt != mvecnt1" << endl;
	else if (mvecnt == mvecnt1)
		cout << "mvecnt == mvecnt1" << endl;
	//根据元素个数的构造函数
	My_vector<int> mvecn(4);
	cout << mvecn.begin() << " " << mvecn.end() - 1 << endl;
	cout << "size=" << mvecn.size() << endl;
	cout << "capacity=" << mvecn.capacity() << endl;
	for (it = mvecn.begin(); it < mvecn.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	//复制构造函数
	My_vector<int> mvecc(mvec);
	cout << mvecc.begin() << " " << mvecc.end() - 1 << endl;
	cout << "size=" << mvecc.size() << endl;
	cout << "capacity=" << mvecc.capacity() << endl;
	for (it = mvecc.begin(); it < mvecc.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	//根据两个迭代器构造函数
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
	//以上5个构造函数测试完毕
	//测试 pop_back()
	mvecbe.pop_back();
	cout << "size=" << mvecbe.size() << endl;
	cout << "capacity=" << mvecbe.capacity() << endl;
	for (it = mvecbe.begin(); it < mvecbe.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	//测试 erase();
	mvecbe.erase(mvecbe.begin() + 1, mvecbe.begin() + 3);
	cout << "size=" << mvecbe.size() << endl;
	cout << "capacity=" << mvecbe.capacity() << endl;
	for (it = mvecbe.begin(); it < mvecbe.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	//测试clear()
	mvecbe.clear();
	cout << "size=" << mvecbe.size() << endl;
	cout << "capacity=" << mvecbe.capacity() << endl;
	for (it = mvecbe.begin(); it < mvecbe.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << mvecbe[0] << endl;
	//以下测试push_back()
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