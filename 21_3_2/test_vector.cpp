#include<iostream>

namespace my_vector {
	template<class T>
	class vector {
	public:
		// construct and destory

	private:
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin();
		iterator end();
		const_iterator cbegin();
		const_iterator cend();
	};


}