#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

// ��ɫ
enum{


};

// ȫ�ֱ��� �� g_ ����
// �ֲ����� �� s_ ����
// ��Ա���� �� m_ ����
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

	// ���캯��:
	// д��1:
	//Player() : m_size(0) {}
	// д��2:
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