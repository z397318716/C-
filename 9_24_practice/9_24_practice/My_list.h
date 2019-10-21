#pragma once
#include <iostream>

namespace xq{
	template<class T>
	class ListNode{
	public:
		T m_val;
		ListNode *m_prev;
		ListNode *m_next;

		// 构造
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
		// list 构造
		// 1.空list构造
		List()
		{
			CreateHead();
		}
		// 2.构造包含n个val值的List(在此函数之前先写插入接口函数)
		List(size_t n, const T &val = T())	// 其中 const T &val = T() 表示只有一个参数参与构造时,调用T()来构造默认参数(0)
		{
			CreateHead();
			m_head->m_val = val;
			for (int i = 0; i < n; i++)
			{

			}
		}
		// 内部类,外部是内部类的友元(内部类可以调用外部类的所有成员,外部类不能调用内部类
		class iterator
		{
		public:
			ListNode <T> *m_pos;
			// 构造
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

			ListNode<T> *ptr = new ListNode<T>;		// 创建新节点
			ListNode<T> *npos = pos.m_pos;

			ptr.m_val = val;					// 为新节点赋值
			ptr.m_prev = npos->m_prev;			// 新节点向前指向pos的前一个节点
			ptr.m_next = npos;					// 新节点向后指向pos

			// 解链
			npos->m_prev->m_next = ptr;			// pos的前一个节点向后指向新节点
			npos->m_prev = ptr;					// pos向前指向新节点

			return ptr;
		}
	}

};