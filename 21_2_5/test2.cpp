#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Mystring
{
public:
	Mystring(const char* str = nullptr);
	~Mystring();
	Mystring(const Mystring& s);
	bool operator==(const Mystring& s);
	Mystring& operator=(const Mystring& s);
	Mystring operator+(const Mystring& s)const;
	Mystring& operator+=(const Mystring& s);
	inline size_t size()const;
	const char* c_str() const;//��stringתΪchar
private:
	char* _str;
	size_t _size;
};
Mystring::Mystring(const char* str) {
	if (str == nullptr) {
		_size = 0;
		_str = new char[1];
		*_str = '\0';
	}
	else {
		int len = strlen(str);
		_str = new char[len+1];
		strcpy(_str, str); // �´�� Դ�ַ������� \0
	}
}
Mystring::~Mystring() {
	_size = 0;
	delete[] _str;
}
Mystring::Mystring(const Mystring& s) {
	_size = s.size();
	_str = new char[_size + 1];
	strcpy(_str, s.c_str());
}

bool Mystring::operator==(const Mystring& s) {
	if (_size == s.size() && strcmp(_str, s.c_str()) == 0)
		return true;
	return false;
}
Mystring& Mystring::operator=(const Mystring& s) {
	if (*this == s)
		return *this;
	delete[]_str;
	_size = s.size();
	_str = new char[s.size() + 1];
	strcpy(_str, s.c_str());
}
Mystring Mystring::operator+(const Mystring& str) const//+������3��
{//�½���������¿ռ䣬�����������ݣ������¿ռ�
	Mystring newstring;
	newstring._size = _size + str.size();
	newstring._str = new char[newstring._size + 1];
	strcpy(newstring._str, _str);
	strcat(newstring._str, str.c_str());
	return newstring;
}

Mystring& Mystring::operator+=(const Mystring& str)//+=������5��
{//�ط����¿ռ䣬�����������ݣ�ɾ���Լ�ԭ�ռ䣬��ֵΪ�¿ռ䣬��������
	_size += str.size();//��Ա_size��ʵ�ʳ���
	char* newstring = new char[_size + 1];
	strcpy(newstring, _str);
	strcat(newstring, str.c_str());
	delete[] _str;
	_str = newstring;
	return *this;
}
inline size_t Mystring::size()const {
	return _size;
}
inline const char* Mystring::c_str()const {
	return _str;
}
