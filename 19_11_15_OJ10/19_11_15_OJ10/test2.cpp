#include<iostream>
#include<string>
#include<vector>

using namespace std;
/*public static Safelevel GetPwdSecurityLevel(string pPasswordStr)
{
}*/
int score = 0;    // 总分
int num_a = 0;    // 小写字母个数
int num_A = 0;    // 大写字母个数
int num_d = 0;
int num_s = 0;    // 字符个数
// 长度判断
void Length(string pstr)
{
	// 长度判分
	if (pstr.size() >= 8)
	{
		score += 25;
	} else if (pstr.size() >= 5 && pstr.size() <= 7)
	{
		score += 10;
	} else
	{
		score += 5;
	}
}
// 2.根据字母判分
void Letter(string pstr)
{
	// 2.根据字母判分

	for (int i = 0; i < pstr.size(); i++)
	{
		if (pstr[i] <= 'z' && pstr[i] >= 'a')
		{
			num_a += 1;
		} else if (pstr[i] <= 'Z' && pstr[i] >= 'A')
		{
			num_A += 1;
		}
	}
	if (num_A != 0 && num_a != 0)
	{
		score += 20;
	} else if ((num_A != 0 && num_a == 0) || (num_A == 0 && num_a != 0))
	{
		score += 10;
	}
}
// 3.数字判分
void Num(string pstr)
{

	for (auto &i : pstr)
	{
		if (i <= '9' && i >= '0')
		{
			num_d++;
		}
	}
	if (num_d == 1)
	{
		score += 10;
	} else if (num_d > 1)
	{
		score += 20;
	}
}
// 4.符号判分
void Symbol(string pstr)
{

	for (auto &i : pstr)
	{
		if (i <= 0x2F && i >= 0x21 ||
			i <= 0x40 && i >= 0x3A ||
			i <= 0x60 && i >= 0x5B ||
			i <= 0x7E && i >= 0x7B)
		{
			num_s++;
		}
	}
	if (num_s > 1)
	{
		score += 25;
	} else if (num_s == 1)
	{
		score += 10;
	}
}
// 5.奖励
void Reward(string pstr)
{
	if (num_d != 0 && num_s != 0 && ((num_a == 0 && num_A != 0) || (num_a != 0 && num_A == 0)))
	{
		score += 3;
	} else if (num_a != 0 && num_A != 0 && num_d != 0 && num_s != 0)
	{
		score += 5;
	} else if (num_d != 0 && num_s == 0 && (num_a != 0 || num_A != 0))
	{
		score += 2;
	}

}
string GetPwdSafeLevel(string pstr)
{
	//int score = 0;
	// 返回输出,l7最高
	string l1("VERY_WEAK"), l2("WEAK"), l3("AVERAGE"), l4("STRONG"), l5("VERY_STRONG"), l6("SECURE"), l7("VERY_SECURE");

	// 1.长度判分
	Length(pstr);
	cout << score << endl;
	// 2.字母判分
	Letter(pstr);
	cout << score << endl;
	// 3.数字判分
	Num(pstr);
	cout << score << endl;
	// 4.符号判分
	Symbol(pstr);
	cout << score << endl;
	// 5.奖励
	Reward(pstr);
	cout << score << endl;
	if (score >= 90)
		return l7;
	else if (score >= 80)
		return l6;
	else if (score >= 70)
		return l5;
	else if (score >= 60)
		return l4;
	else if (score >= 50)
		return l3;
	else if (score >= 25)
		return l2;
	else
		return l1;
}

int main()
{
	string pwd;
	getline(cin, pwd);
	//cout << score << endl;
	cout << GetPwdSafeLevel(pwd) << endl;
	//cout << score << endl;



	return 0;
}