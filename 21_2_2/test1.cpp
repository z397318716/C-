//#include<iostream>
//#include<utility>
//const int daytab[2][13] = { {0,31,28,31,30,31,30,31,31,30,31,30,31},
//					{0,31,29,31,30,31,30,31,31,30,31,30,31} };
//class Date
//{
//public:
//	// ȫȱʡ�Ĺ��캯��
//	Date(int year = 1900, int month = 1, int day = 1)
//		:_year(year), _month(month), _day(day) {
//		// Ӧ���Դ�������ڽ��кϷ����ж�
//		if (year < 0)
//		{
//			std::cout << "������ݲ��Ϸ�,ʹ��Ĭ������1900-1-1" << std::endl;
//			_year = 1900;
//			_month = 1;
//			_day = 1;
//		}else if (month < 1 || month > 12)
//		{
//			std::cout << "�����·ݲ��Ϸ�,ʹ��Ĭ������1900-1-1" << std::endl;
//			_year = 1900;
//			_month = 1;
//			_day = 1;
//		}
//		// ��־λ�����Ƿ������� 1��ʾ������
//		int flag = 0;
//		if (0 == _year % 400 || (0 != _year % 100 && 0 == _year % 4))
//			flag = 1;
//		// �Ƿ񳬳���������
//		if (((_month == 1 || _month == 3 || _month == 5 || _month == 7 ||
//			_month == 8 || _month == 10 || _month == 12) && _day > 31 || day < 1) ||
//			((_month == 4 || _month == 6 || _month == 9 || _month == 10 ||
//				_month == 11) && _day > 30 || day < 1) || ((_month == 2) && _day > 28 + flag || day < 1)) {
//			std::cout << "�����������Ϸ�,ʹ��Ĭ������1900-1-1" << std::endl;
//			_year = 1900;
//			_month = 1;
//			_day = 1;
//		}
//	}
//	// ��������
//	~Date() {}
//	// �������캯��
//	Date(const Date& d) {
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	// ��ֵ���������
//	// d2 = d3 -> d2.operator=(&d2, d3)
//	class Date& operator=(const Date& d) {
//		this->_year = d._year;
//		this->_month = d._month;
//		this->_day = d._day;
//		return *this;
//	}
//	// ����+=����
//	Date& operator+=(int day) {
//		for (int i = 0; i < day; ++i) {
//			(*this)++;
//		}
//		return *this;
//	}
//	// ����+����
//	Date operator+(int day) {
//		for (int i = 0; i < day; ++i) {
//			(*this)++;
//		}
//		return *this;
//	}
//	// ����-����
//	Date operator-(int day) {
//		for (int i = 0; i < day; ++i) {
//			(*this)--;
//		}
//		return *this;
//	}
//	// ����-=����
//	Date& operator-=(int day) {
//		for (int i = 0; i < day; ++i) {
//			(*this)--;
//		}
//		return *this;
//	}
//	// ����-����   ��������������������
//	int& operator-(Date d) {
//		int res = abs(Days(*this) - Days(d));
//		return res;
//	}
//	// ǰ��++
//	Date& operator++() {
//		// ��־λ�����Ƿ������� 1��ʾ������
//		int flag = 0;
//		if (0 == _year % 400 || (0 != _year % 100 && 0 == _year % 4))
//			flag = 1;
//		// �Ƿ��ǵ��µ����һ���ж�
//		if (((_month == 1 || _month == 3 || _month == 5 || _month == 7 ||
//			_month == 8 || _month == 10 || _month == 12) && _day == 31) ||
//			((_month == 4 || _month == 6 || _month == 9 || _month == 10 ||
//				_month == 11) && _day == 30) || ((_month == 2) && _day == 28 + flag)) {
//			if (_month == 12) {
//				_year++;
//				_month = 1;
//			}
//			else {
//				_month++;
//			}
//			_day = 1;
//		}
//		else {
//			_day++;
//		}
//		return *this;
//	}
//	// ����++
//	Date operator++(int) {
//		Date* tmp = this;
//		++(*this);
//		return *tmp;
//	}
//	// ����--
//	Date operator--(int) {
//		Date tmp = *this;
//		--(*this);
//		return tmp;
//	}
//	// ǰ��--
//	Date& operator--() {
//		// ��־λ�����Ƿ������� 1��ʾ������
//		int flag = 0;
//		if (0 == _year % 400 || (0 != _year % 100 && 0 == _year % 4))
//			flag = 1;
//		// �Ƿ��ǵ��µĵ�һ���ж�
//		if (_day == 1) {
//			if (_month == 1) {
//				_year--;
//				_month = 12;
//				_day = 31;
//			}
//			else {
//				_month--;
//				if (_month == 1 || _month == 3 || _month == 5 || _month == 7 ||
//					_month == 8 || _month == 10 || _month == 12) {
//					_day = 31;
//				}
//				else if (_month == 4 || _month == 6 || _month == 9 || _month == 10 ||
//					_month == 11) {
//					_day = 30;
//				}
//				else if (_month == 2) {
//					_day = 28 + flag;
//				}
//			}
//		}
//		else {
//			_day--;
//		}
//		return *this;
//	}
//	// >���������
//	bool operator>(const Date& d) {
//		if (_year < d._year)
//			return false;
//		if (_year == d._year && _month < d._month)
//			return false;
//		if (_year == d._year && _month == d._month && _day < d._day)
//			return false;
//		return true;
//	}
//	// ==���������
//	bool operator==(const Date& d) {
//		if (_year == d._year && _month == d._month && _day == d._day)
//			return true;
//		return false;
//	}
//	// >=���������
//	inline bool operator >= (const Date& d) {
//		if (!((*this) < d))
//			return true;
//		return false;
//	}
//	// <���������
//	bool operator < (const Date& d) {
//		if (_year > d._year)
//			return false;
//		if (_year == d._year && _month > d._month)
//			return false;
//		if (_year == d._year && _month == d._month && _day > d._day)
//			return false;
//		return true;
//	}
//	// <=���������
//	bool operator <= (const Date& d) {
//		if (!((*this) > d))
//			return true;
//		return false;
//	}
//	// !=���������
//	bool operator != (const Date& d) {
//		return !((*this)==d);
//	}
//	// ��ȡĳ��ĳ�µ�����
//	int GetMonthDay(int year, int month) {
//		int res = 0;
//		// ��־λ�����Ƿ������� 1��ʾ������
//		int flag = 0;
//		if (0 == _year % 400 || (0 != _year % 100 && 0 == _year % 4))
//			flag = 1;
//		if (_month == 1 || _month == 3 || _month == 5 || _month == 7 ||
//			_month == 8 || _month == 10 || _month == 12)
//			res = 31;
//		else if (_month == 4 || _month == 6 || _month == 9 || _month == 11)
//			res = 30;
//		else if (_month == 2)
//			res = 28 + flag;
//		return res;
//	}
//	bool IsYear(int year) {
//		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//			return true;
//		return false;
//	}
//	int DayYear(int year) {
//		if (IsYear(year))
//			return 366;
//		return 365;
//	}
//	int Days(Date d) {
//		int year, month, day;
//		int res = 0;
//		year = d._year;
//		month = d._month;
//		day = d._day;
//		for (int i = 0; i < year; ++i) {
//			res += DayYear(i);
//		}
//		for (int i = 0; i < month; ++i) {
//			res += daytab[IsYear(year)][i];
//		}
//		res += day;
//		return res;
//	}
//	// ��ʾ��ǰ����
//	void Show() {
//		std::cout << _year << '-' << _month << '-' << _day << std::endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};