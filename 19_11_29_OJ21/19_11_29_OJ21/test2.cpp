// 1.
#include <iostream>
#include <string>
using namespace std;
int main(){
	int n;
	string order;
	while (cin >> n >> order)
	{
		int num = 1, first = 1; //��n�׸������1��n , numΪ��굱ǰ���ڸ����ı��,firstΪ��ǰ��Ļ��ʾҳ�ĵ�һ�׸����ı��
		if (n <= 4) //��������������4ʱ�����и���һҳ������ʾ�꣬���跭ҳ��firstʼ�ղ���
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
		} else  //������������4ʱ����ʾ��ȫ���и�����Ҫ��ҳ����Ļ������ʾ4�׸���
		{
			for (int i = 0; i < order.size(); i++)
			{
				if (first == 1 && num == 1 && order[i] == 'U') { first = n - 3; num = n; } //���ⷭҳ1
				else if (first == n - 3 && num == n && order[i] == 'D') { first = 1; num = 1; } //���ⷭҳ2
				else if (first != 1 && num == first && order[i] == 'U') { first--; num--; } //һ�㷭ҳ1
				else if (first != n - 3 && num == first + 3 && order[i] == 'D') { first++; num++; } //һ�㷭ҳ2
				else if (order[i] == 'U') num--; //�������1
				else num++; //�������2
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
//��n�׸�����ŷ���playlist�У����playlist={1,2��...n};
//��Ļ�ϳ��ֵĸ��������win_pos ��win_size��ͬȷ����
//cursor���ǹ��ָ���ĸ�����ŵ��±�
//���ľ��Ǹ�����������ֺ��ַ���ȷ��win_pos ��win_size�Լ�cursor.
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	int n;
	string ins;//instruction��ָ��
	while (cin >> n >> ins){
		int cursor = 0;//��궨λ
		int win_pos = 0;//����λ
		int win_size = 4;
		vector<int> playlist(n, 0);
		for (int i = 0; i < n; i++){//��ʼ�������б�
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
						cursor = n - 1;//����Ƶ�����
						win_pos = n - 4;//����λҲҪ��Ӧ���ƶ�
					} else{
						if (cursor == win_pos){
							win_pos--;//����ƶ�
							cursor--;//����λ��Ӧ���ƶ�
						} else{
							cursor--;//ֻ�й���ƶ�
						}
					}
				} else{//ins[i]=='D'
					if (cursor == n - 1){
						cursor = 0;//����Ƶ�����
						win_pos = 0;//����λҲҪ��Ӧ���ƶ�
					} else{
						if (cursor == win_pos + 3){
							cursor++;//����ƶ�
							win_pos++;//����λ��Ӧ���ƶ�
						} else{
							cursor++;//ֻ�й���ƶ�
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