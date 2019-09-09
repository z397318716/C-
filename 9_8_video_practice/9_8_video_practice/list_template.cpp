//#include <iostream>
#include "Sales_item.h"

using namespace std;

template<class T>
class vector
{
public:
	vector(size_t capacity = 10)
		:_data(new T[capacity])
		, _size(0)
		, _capacity(capacity)
	{}
	~vector();

	void PushBack(const T&data)
	{
		_data = data;
		_size++;
	}
	void PopBack()
	{
		_size--;
	}
	size_t Size()
	{
		return _size;
	}
	T& operator[](size_t pos)
	{
		return _data[pos];
	}
};





int main()
{
	Sales_item* book;
	int i = 0;
	while (i < 10)
	{
		cin >> book[i];
		i++;
	}
	while (i >= 0)
	{
		cout << book[i];
		i--;
	}
	return 0;
}