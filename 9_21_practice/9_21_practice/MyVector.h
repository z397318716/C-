#include <iostream>
#include <vector>
#include<cstddef>
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