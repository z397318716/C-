#pragma once
#include <iostream>

namespace xq{
	template<class T>
	class ListNode{
	public:
		T m_val;
		ListNode *m_prev;
		ListNode *m_next;

		// ����
		ListNode(const T&val = T()) :
			m_val(val),
			m_prev(nullptr),
			m_next(nullptr)
		{
		}

	};

	template<class T>
	class List{
		ListNode<T> *m_head;
		void CreateHead()
		{
			m_head = new ListNode<T>;
			m_head->m_next = m_head;
			m_head->m_prev = m_head;
		}
	public:
		// list ����
		// 1.��list����
		List()
		{
			CreateHead();
		}
		// 2.�������n��valֵ��List(�ڴ˺���֮ǰ��д����ӿں���)
		List(size_t n, const T &val = T())	// ���� const T &val = T() ��ʾֻ��һ���������빹��ʱ,����T()������Ĭ�ϲ���(0)
		{
			CreateHead();
			m_head->m_val = val;
			for (int i = 0; i < n; i++)
			{

			}
		}
		// �ڲ���,�ⲿ���ڲ������Ԫ(�ڲ�����Ե����ⲿ������г�Ա,�ⲿ�಻�ܵ����ڲ���
		class iterator
		{
		public:
			ListNode <T> *m_pos;
			// ����
			iterator(ListNode<T>& *val = nullptr) :
				m_pos(val)
			{

			}
			T & operator *() const{
				return m_pos->m_val;
			}
			T * operator ->() const{
				return &m_pos->m_val;
			}
			


		};
		// 
		iterator insert(iterator pos, const T &val) // 
		{

			ListNode<T> *ptr = new ListNode<T>;		// �����½ڵ�
			ListNode<T> *npos = pos.m_pos;

			ptr.m_val = val;					// Ϊ�½ڵ㸳ֵ
			ptr.m_prev = npos->m_prev;			// �½ڵ���ǰָ��pos��ǰһ���ڵ�
			ptr.m_next = npos;					// �½ڵ����ָ��pos

			// ����
			npos->m_prev->m_next = ptr;			// pos��ǰһ���ڵ����ָ���½ڵ�
			npos->m_prev = ptr;					// pos��ǰָ���½ڵ�

			return ptr;
		}
	}

};