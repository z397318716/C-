#pragma once
#include <string.h>
#define DEFAULTCAPA 16
#include <malloc.h>
#include <iostream>
using namespace std;
class String
{
	char *m_data;
	size_t m_size;
	size_t m_capacity;
public:
	String(const char *str = "") :
		m_capacity(16),
		m_size(0)
	{
		if (nullptr == str)
		{
			m_size = 0;
		}
		else
		{
			m_size = strlen(str);
		}
		
		m_size = strlen(str);

		m_data = new char[m_capacity];
		strncpy(m_data, str, m_size);
	}
	String(size_t, char ch):
		m_size(0),
		m_capacity(DEFAULTCAPA)
	{
		Reserve(m_size);

		m_data = new char[m_capacity];
		memset(m_data, ch, m_size);
	}
	~String()
	{
		if (m_data)
		{
			delete[]m_data;
			m_data = NULL;
		}
		m_size = m_capacity = 0;
	}
	String(String &s)
	{
		m_size = s.m_size;
		m_capacity = s.m_capacity;

		m_data = new char[m_capacity];
		strcpy(m_data, s.m_data);
	}
	void Reserve(size_t size)
	{
		if (size >= m_capacity)
		{
			m_capacity = (size / DEFAULTCAPA + 1) * DEFAULTCAPA;
			m_data = (char *)realloc(m_data, m_capacity);
		}
	}

	char &operator[](int i)
	{
		return m_data[i];
	}

	typedef char *iterator;
	iterator begin()
	{
		return m_data;
	}
	iterator end()
	{
		return m_data + m_size;
	}
	void push_back(char ch)
	{
		Reserve(m_size);		// 判断容量是否足够
		m_data[m_size] = ch;
		m_size++;
	}
	void pop_back(char ch)
	{
		if (!empty())
		{
			m_size--;
		}
	}
	String &operator = (const char *str)
	{
		m_size = strlen(str);
		Reserve(m_size);
		strcpy(m_data, str);		// 
		return *this;
	}
	String &operator = (string &s)
	{
		m_size = s.m_size;
		Reserve(m_size);
		strcpy(m_data, s.m_data);		// 
		return *this;
	}
	String &operator += (const char *str)
	{
		m_size += strlen(str);
		Reserve(m_size);
		strcat(m_data, str);		// 字符串拼接
		return *this;
	}

	friend ostream & operator << (ostream & os, const String &s);
	friend istream & operator >> (istream & is, String &s);
};



ostream & operator << (ostream & os, const String &s)
{
	//os << s.m_data;			// 这样实现的是 C 风格
	int i;
	for (i = 0; i < s.m_data[i]; i++)
	{
		os << s.m_data[i];
	}

	return os;
}
istream & operator >> (istream & is, String &s)
{
	//is >> s.m_data;			// 越界问题

	char *tmp = new char[1024];
	is.getline(tmp, 1024);
	s.m_size = strlen(tmp);
	s.m_capacity = COUNTCAPA(s.m_size);
	/*delete[]s.m_data;
	s.m_data = tmp;*/
	strcpy(s.m_data, tmp);
	delete[]tmp;
	

	return is;
}