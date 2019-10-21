#include <stack>
#include <iostream>
#include <queue>


using namespace std;

// OJ 1
// 实现一个最小栈
class MinStack{

	// 创建两个栈,一个栈按正常顺序存储
	// 另外一个栈,始终保持栈顶元素最小
	stack<int> m_data;
	stack<int> m_min;
public:
	// 构造
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

// 两个队列实现一个栈
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

// 两个栈实现一个队列
class StackQueue
{
	// 后进先出 实现 后进后出
	// 创建两个栈, 一个按正常方式存储数据,另一个将数据反向存储
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
		// 此时,栈m_st2 已经 pop了元素,但存储顺序与原数据存储顺序相反
		// 需要将存储顺序反过来
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