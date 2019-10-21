#include <stack>
#include <iostream>
#include <queue>


using namespace std;

// OJ 1
// ʵ��һ����Сջ
class MinStack{

	// ��������ջ,һ��ջ������˳��洢
	// ����һ��ջ,ʼ�ձ���ջ��Ԫ����С
	stack<int> m_data;
	stack<int> m_min;
public:
	// ����
	MinStack()
	{

	}

	void push(int x)
	{
		m_data.push(x);

		if (m_min.empty() || m_min.top() > x)
		{
			m_min.push(x);
		}
	}
	void pop()
	{
		if (m_data.top() == m_min.top())
		{
			m_min.pop();
		}
		m_data.pop();
	}
	int top()
	{
		return m_data.top();
	}
	int GetMin()
	{
		return m_min.top();
	}
};

// ��������ʵ��һ��ջ
class QueueStack
{
	queue<int> m_qu1;
	
public:
	QueueStack()
	{

	}
	void push(int x)
	{
		m_qu1.push(x);
	}
	void pop()
	{
		queue<int> m_qu2;
		while (m_qu1.size() > 1)
		{
			m_qu2.push(m_qu1.front());
			m_qu1.pop();
		}
		m_qu1 = m_qu2;
	}
	int top()
	{
		queue<int> m_qu2;
		while (m_qu1.size() > 1)
		{
			m_qu2.push(m_qu1.front());
			m_qu1.pop();
		}
		int tmp = m_qu1.front();
		m_qu2.push(m_qu1.front());
		m_qu1 = m_qu2;
		return tmp;
	}

};

// ����ջʵ��һ������
class StackQueue
{
	// ����ȳ� ʵ�� ������
	// ��������ջ, һ����������ʽ�洢����,��һ�������ݷ���洢
	stack<int> m_st1;
	
public:
	StackQueue()
	{

	}
	void push(int x)
	{
		m_st1.push(x);
	}
	void pop()
	{
		stack<int> m_st2;
		stack<int> tmp;
		while (m_st1.size() > 1)
		{
			m_st2.push(m_st1.top());
			m_st1.pop();
		}
		// ��ʱ,ջm_st2 �Ѿ� pop��Ԫ��,���洢˳����ԭ���ݴ洢˳���෴
		// ��Ҫ���洢˳�򷴹���
		while (!m_st2.empty())  
		{
			tmp.push(m_st2.top());
			m_st2.pop();
		}
		m_st1 = tmp;
	}
	int top()
	{
		stack<int> m_st2;
		stack<int> tmp_st = m_st1; 
		while (!m_st1.empty())
		{
			m_st2.push(m_st1.top());
			m_st1.pop();
		}
		m_st1 = tmp_st;
		int tmp = m_st2.top();
		return tmp;
	}

};

int main()
{
	StackQueue q1;
	q1.push(1);
	q1.push(2);
	q1.push(3);
	cout << q1.top() << endl;
	q1.pop();
	cout << q1.top() << endl;


	return 0;
}