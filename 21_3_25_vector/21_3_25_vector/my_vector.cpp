#include<iostream>


namespace MyVector {

	template<class T>
	class vector {
	public:
		// ----------------------------construct and destroy------------------------------------
		vector():
			_first(nullptr),
			_last(nullptr),
			_capacity(nullptr){}
		vector(int n, const T& value = T()) {
			reserve(n);
			while (n--) {
				push_back(value);
			}
		}
		vector(T* first, T* end) {
			reserve(end - first);
			while (first != end) {
				push_back(*first);
				first++;
			}
		}
		vector(const vector<T>& v)
		{
			// �������������
			_first = new T[v.capacity()];
			_last = _first + v.size();
			_capacity = _first + v.capacity();
			for(int i = 0; i < v.size(); ++i){
				_first[i] = v[i];
			}
		}
		vector<T>& operator=(vector<T> v) {
			delete[] _first;
			_first = new T[v.capacity()];
			_last = _first + v.size();
			_capacity = _first + v.capacity();
			for (int i = 0; i < v.size(); ++i) {
				_first[i] = v[i];
			}
		}

		~vector() {
			delete[]_first;
			_first = _last = _capacity = nullptr;
		}
	public:
		// ------------------------------ iterator---------------------------------------------
		typedef T* iterator; // ��������һ��ԭ��ָ��
		typedef const T* const_iterator;
		iterator begin() {
			return _first;
		}
		iterator end() {
			return _last;
		}
		const_iterator cbegin() {
			const_iterator it = _first;
			return it;
		}
		const_iterator cend() {
			const_iterator it = _last;
			return it;
		}
	public:
		// -----------------------------Capacity:-------------------------------------------
		size_t size()const {
			return (_last - _first);
		}
		size_t capacity()const {
			return (_capacity - _first);
		}
		void reserve(size_t n) {
			// ���ݺ�Ŀռ��С��Ҫ��������ǰ Ԫ�� ��ռ��С, ���򲻲���
			// ���ݲ���:
			//	1. �½����ݴ�С�ռ�
			//	2. ��ԭ�����ݿ������½��ռ�
			//  3. �ͷ�ԭ�ռ䡢������ָ���¿ռ�
			if (n >= capacity()) {
				int old_size = size();
				T* new_capacity = new T[n];
				if (_first) {
					for (int i = 0; i < old_size; ++i) {
						new_capacity[i] = _first[i];
					}
				}
				delete[]_first;
				_first = new_capacity;
				_last = _first + old_size;
				_capacity = _first + n;
			}
		}
		void resize(size_t n, const T& value = T()) {
			if (n <= size()) {
				_last = _first + n;
			}
			if (n > _capacity) {
				reserve(n * 1.5);
			}
			iterator tmp = _last;
			_last = _first + n;
			while (tmp != _last) {
				*tmp = value;
				tmp++;
			}
		}
		bool empty() {
			return (begin() == end());
		}
	public:
		//-------------------------Element Access--------------------------------------------
		T& operator[](size_t pos) {
			return (*(begin() + pos));
		}

	public:
		// ------------------------Modifiers---------------------------------------------------
		void push_back(const T& value) {
			insert(_last, value);
		}
		void pop_back() {
			if (!empty()) {
				_last--;
			}
		}
		// �������� pos λ��ǰ����
		iterator insert(iterator pos, const T& x) {
			// �����������
			if (size() + 1 >= capacity()) {
				size_t tmp = pos - _first;	// ��¼������λ��ƫ��
				reserve(capacity() * 2);    // ����
				pos = _first + tmp;			// ���¸���������λ��, ���ݺ�, ֮ǰ�ĵ�����ʧЧ
			}
			// �� pos ���ֵ �����Ų��һλ
			for (iterator i = _last; i != pos; --i) {
				*i = *(i - 1);
			}
			*pos = x;
			_last++;
			return pos;
		}
		iterator erase(iterator pos) {
			iterator tmp = pos;
			while (tmp != _last - 1) {
				*tmp = *(tmp + 1);
				tmp++;
			}
			_last--;
			return pos;
		}
	private:
		iterator _first;  // ָ�� ���ݿ� �Ŀ�ʼ
		iterator _last; // ָ�� ��Ч���� �Ľ�β
		iterator _capacity; // ָ�� �洢���� �Ľ�β
	};
}// end MyVector
