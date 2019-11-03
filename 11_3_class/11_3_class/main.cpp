#include<iostream>


template <class T>
class smart_ptr
{
	T *m_ptr;
public:
	smart_ptr(T *ptr = nullptr)
		:m_ptr(ptr)
	{

	}
	~smart_ptr()
	{
		if (m_ptr)
		{
			delete(m_ptr);
		}
	}

	T &operator *()
	{
		return *m_ptr;
	}
	T *operator ->()
	{
		return m_ptr;
	}
	T &operator [](int i)
	{
		return m_ptr[i];
	}

};


int main()
{

	smart_ptr<int> sp1(new int[5]);
	*sp1 = 5;

	for (int i = 0; i < 5; i++)
	{
		sp1[i] = i + 1;
	}
	

	return 0;
}