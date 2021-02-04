//#include<iostream>
//#include<utility>
//const int daytab[2][13] = { {0,31,28,31,30,31,30,31,31,30,31,30,31},
//					{0,31,29,31,30,31,30,31,31,30,31,30,31} };
//class Date
//{
//public:
//	// 全缺省的构造函数
//	Date(int year = 1900, int month = 1, int day = 1)
//		:_year(year), _month(month), _day(day) {
//		// 应当对传入的日期进行合法性判定
//		if (year < 0)
//		{
//			std::cout << "输入年份不合法,使用默认日期1900-1-1" << std::endl;
//			_year = 1900;
//			_month = 1;
//			_day = 1;
//		}else if (month < 1 || month > 12)
//		{
//			std::cout << "输入月份不合法,使用默认日期1900-1-1" << std::endl;
//			_year = 1900;
//			_month = 1;
//			_day = 1;
//		}
//		// 标志位决定是否是闰年 1表示是闰年
//		int flag = 0;
//		if (0 == _year % 400 || (0 != _year % 100 && 0 == _year % 4))
//			flag = 1;
//		// 是否超出当月天数
//		if (((_month == 1 || _month == 3 || _month == 5 || _month == 7 ||
//			_month == 8 || _month == 10 || _month == 12) && _day > 31 || day < 1) ||
//			((_month == 4 || _month == 6 || _month == 9 || _month == 10 ||
//				_month == 11) && _day > 30 || day < 1) || ((_month == 2) && _day > 28 + flag || day < 1)) {
//			std::cout << "输入天数不合法,使用默认日期1900-1-1" << std::endl;
//			_year = 1900;
//			_month = 1;
//			_day = 1;
//		}
//	}
//	// 析构函数
//	~Date() {}
//	// 拷贝构造函数
//	Date(const Date& d) {
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	// 赋值运算符重载
//	// d2 = d3 -> d2.operator=(&d2, d3)
//	class Date& operator=(const Date& d) {
//		this->_year = d._year;
//		this->_month = d._month;
//		this->_day = d._day;
//		return *this;
//	}
//	// 日期+=天数
//	Date& operator+=(int day) {
//		for (int i = 0; i < day; ++i) {
//			(*this)++;
//		}
//		return *this;
//	}
//	// 日期+天数
//	Date operator+(int day) {
//		for (int i = 0; i < day; ++i) {
//			(*this)++;
//		}
//		return *this;
//	}
//	// 日期-天数
//	Date operator-(int day) {
//		for (int i = 0; i < day; ++i) {
//			(*this)--;
//		}
//		return *this;
//	}
//	// 日期-=天数
//	Date& operator-=(int day) {
//		for (int i = 0; i < day; ++i) {
//			(*this)--;
//		}
//		return *this;
//	}
//	// 日期-日期   返回两个日期相差的天数
//	int& operator-(Date d) {
//		int res = abs(Days(*this) - Days(d));
//		return res;
//	}
//	// 前置++
//	Date& operator++() {
//		// 标志位决定是否是闰年 1表示是闰年
//		int flag = 0;
//		if (0 == _year % 400 || (0 != _year % 100 && 0 == _year % 4))
//			flag = 1;
//		// 是否是当月的最后一天判定
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
//	// 后置++
//	Date operator++(int) {
//		Date* tmp = this;
//		++(*this);
//		return *tmp;
//	}
//	// 后置--
//	Date operator--(int) {
//		Date tmp = *this;
//		--(*this);
//		return tmp;
//	}
//	// 前置--
//	Date& operator--() {
//		// 标志位决定是否是闰年 1表示是闰年
//		int flag = 0;
//		if (0 == _year % 400 || (0 != _year % 100 && 0 == _year % 4))
//			flag = 1;
//		// 是否是当月的第一天判定
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
//	// >运算符重载
//	bool operator>(const Date& d) {
//		if (_year < d._year)
//			return false;
//		if (_year == d._year && _month < d._month)
//			return false;
//		if (_year == d._year && _month == d._month && _day < d._day)
//			return false;
//		return true;
//	}
//	// ==运算符重载
//	bool operator==(const Date& d) {
//		if (_year == d._year && _month == d._month && _day == d._day)
//			return true;
//		return false;
//	}
//	// >=运算符重载
//	inline bool operator >= (const Date& d) {
//		if (!((*this) < d))
//			return true;
//		return false;
//	}
//	// <运算符重载
//	bool operator < (const Date& d) {
//		if (_year > d._year)
//			return false;
//		if (_year == d._year && _month > d._month)
//			return false;
//		if (_year == d._year && _month == d._month && _day > d._day)
//			return false;
//		return true;
//	}
//	// <=运算符重载
//	bool operator <= (const Date& d) {
//		if (!((*this) > d))
//			return true;
//		return false;
//	}
//	// !=运算符重载
//	bool operator != (const Date& d) {
//		return !((*this)==d);
//	}
//	// 获取某年某月的天数
//	int GetMonthDay(int year, int month) {
//		int res = 0;
//		// 标志位决定是否是闰年 1表示是闰年
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
//	// 显示当前日期
//	void Show() {
//		std::cout << _year << '-' << _month << '-' << _day << std::endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};