// 1.
#include <iostream>
#include <string>
using namespace std;
int main(){
	int n;
	string order;
	while (cin >> n >> order)
	{
		int num = 1, first = 1; //将n首歌曲编号1：n , num为光标当前所在歌曲的编号,first为当前屏幕显示页的第一首歌曲的编号
		if (n <= 4) //歌曲总数不超过4时，所有歌曲一页即可显示完，不需翻页，first始终不变
		{
			for (int i = 0; i < order.size(); i++)
			{
				if (num == 1 && order[i] == 'U') num = n;
				else if (num == n && order[i] == 'D') num = 1;
				else if (order[i] == 'U') num--;
				else  num++;
			}
			for (int i = 1; i <= n - 1; i++)
				cout << i << ' ';
			cout << n << endl;
			cout << num << endl;
		} else  //歌曲总数大于4时，显示完全所有歌曲需要翻页，屏幕总是显示4首歌曲
		{
			for (int i = 0; i < order.size(); i++)
			{
				if (first == 1 && num == 1 && order[i] == 'U') { first = n - 3; num = n; } //特殊翻页1
				else if (first == n - 3 && num == n && order[i] == 'D') { first = 1; num = 1; } //特殊翻页2
				else if (first != 1 && num == first && order[i] == 'U') { first--; num--; } //一般翻页1
				else if (first != n - 3 && num == first + 3 && order[i] == 'D') { first++; num++; } //一般翻页2
				else if (order[i] == 'U') num--; //其他情况1
				else num++; //其他情况2
			}
			for (int i = first; i < first + 3; i++)
				cout << i << ' ';
			cout << first + 3 << endl;
			cout << num << endl;
		}
	}
	return 0;
}

/*
// 2. 
//将n首歌曲编号放入playlist中，因此playlist={1,2，...n};
//屏幕上呈现的歌曲编号由win_pos 和win_size共同确定。
//cursor则是光标指定的歌曲编号的下标
//核心就是根据输入的数字和字符串确定win_pos 和win_size以及cursor.
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	int n;
	string ins;//instruction：指令
	while (cin >> n >> ins){
		int cursor = 0;//光标定位
		int win_pos = 0;//窗定位
		int win_size = 4;
		vector<int> playlist(n, 0);
		for (int i = 0; i < n; i++){//初始化播放列表
			playlist[i] = i + 1;
		}
		if (n <= 4){
			win_size = n;
			for (int i = 0; i < ins.length(); i++){
				if (ins[i] == 'U'){
					cursor == 0 ? cursor = n - 1 : cursor--;
				} else{
					cursor == n - 1 ? cursor = 0 : cursor++;
				}
			}
		} else{
			for (int i = 0; i < ins.length(); i++){
				if (ins[i] == 'U'){
					if (cursor == 0){
						cursor = n - 1;//光标移到最下
						win_pos = n - 4;//窗定位也要相应的移动
					} else{
						if (cursor == win_pos){
							win_pos--;//光标移动
							cursor--;//窗定位相应的移动
						} else{
							cursor--;//只有光标移动
						}
					}
				} else{//ins[i]=='D'
					if (cursor == n - 1){
						cursor = 0;//光标移到最上
						win_pos = 0;//窗定位也要相应的移动
					} else{
						if (cursor == win_pos + 3){
							cursor++;//光标移动
							win_pos++;//窗定位相应的移动
						} else{
							cursor++;//只有光标移动
						}
					}
				}
			}
		}
		for (int i = win_pos; i < win_pos + win_size; i++){
			cout << playlist[i] << " ";
		}
		cout << endl;
		cout << playlist[cursor] << endl;
	}
	system("pause");
	return 0;
}
*/