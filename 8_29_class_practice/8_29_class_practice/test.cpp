#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

// 花色
enum{


};

// 全局变量 加 g_ 区分
// 局部变量 加 s_ 区分
// 成员变量 加 m_ 区分
class Poker{
	char m_type;		 
	int m_point;
public:
	void MakePoker(char type, int point)
	{
		m_type = type - 'a';
		m_point = point;
	}
	void OutPoker()
	{

	}

	bool CmpPoker(Poker tmp)
	{
		return (m_point < tmp.m_point) || (m_point == tmp.m_point && m_type > tmp.m_type)
	}
};

class Player
{
	Poker m_HandCard[18];
	int m_size;
public:

	// 构造函数:
	// 写法1:
	//Player() : m_size(0) {}
	// 写法2:
	Player()
	{
		m_size = 0;
	}
	void GetCard(Poker NewCard)
	{
		//m_HandCard[m_size] = NewCard;

		//Poker tmp = m_HandCard[m_size - 1];
		Poker tmp = NewCard;
		int i;
		for (i = m_size; i > 0 && m_HandCard[i - 1].CmpPoker(NewCard); i--)
		{
			m_HandCard[i] = m_HandCard[i - 1];
		}
		m_HandCard[i] = NewCard;
		m_size++;
	}

	void ShowCard()
	{

	}
};





int main()
{

	srand(time(NULL));




	return 0;
}