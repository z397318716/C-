// case 70%
#include<iostream>
#include<string>
#include<map>
using namespace std;

string Joker(string s)
{
	//string s1, s2;
	//string::iterator it;
    int tmp = s.find('-');
    string s1(s.begin(),s.begin() + tmp);
    string s2(s.begin() + tmp + 1, s.end());
    /*
	for (it = s.begin(); it != s.end(); it++)
	{
		if (*it == '-')
		{
			break;
		}
	}
    */
	//string s1(s.begin(), it);
	//string s2(it + 1, s.end());
	// 统计空格个数, 判断是什么类型的比较
	int count1 = 0;
	int count2 = 0;
	for (auto & i : s1)
	{
		if (i == ' ')
			count1++;
	}
	for (auto & i : s2)
	{
		if (i == ' ')
			count2++;
	}
	// 单个比较情况
	map<string, int> m1;
	for (int i = 3; i < 11; i++)
	{
		m1["i"] = i;
	}
    m1["J"] = 11;
    m1["Q"] = 12;
    m1["K"] = 13;
    m1["A"] = 14;
    m1["2"] = 15;
	m1["joker"] = 16;
	m1["JOKER"] = 17;
    if(s1.find("joker JOKER") != -1 || s2.find("joker JOKER") != -1)
    {
        return "joker JOKER";
    }
    else if(count1 == count2)
    {
        // 单个比较
        if(count1 == 0)
        {
            return m1[s1] > m1[s2] ? s1 : s2;
        }
        else
            return m1["s1[0]"] > m1["s2[0]"] ? s1 : s2;
    }
    else
    {
        if(count1 == 3)
            return s1;
        else if(count2 == 3)
            return s2;
        else
            return "error";
    }
    
    /*
	if (count1 == 0)
	{
		/*
		if(m1[s1] > m1[s2])
		{
		return s1;
		}
		else
		{
		return s2;
		}
		
		return m1[s1] > m1[s2] ? s1 : s2;
	}
	// 对子比较
	else if (count1 == 1 && count2 == 1)
	{
		return m1["s1[0]"] > m1["s2[0]"] ? s1 : s2;
	}
	// 三个比较
	else if (count1 == 2 && count2 == 2)
	{
		return m1["s1[0]"] > m1["s2[0]"] ? s1 : s2;
	}
	// 非王炸炸弹比较
	else if (count1 == 3 && count2 == 3)
	{
		return m1["s1[0]"] > m1["s2[0]"] ? s1 : s2;
	}
	// 有王炸的情况
	else if ((count1 == 1 && count2 == 3 && s1 == "joker JOKER") || (count1 == 3 && count2 == 1 && s2 == "joker JOKER"))
	{
		// 王炸判断
		if (count1 == 1)
		{
			return s1;
		} else if (count2 == 1)
		{
			return s2;
		}
	}
	// 顺子比较
	else if ((count1 == count2) && count1 > 3)
	{
		return m1["s1[0]"] > m1["s2[0]"] ? s1 : s2;
	} else
	{
		return "error";
	}
    */
}


int main()
{
	string s1;
	getline(cin, s1);
	cout << Joker(s1) << endl;


	return 0;
}

