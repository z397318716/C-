//#include<iostream>
//#include<string>
//#include<map>
//#include<vector>
//using namespace std;
//
//
//void BB() {
//	string s1({ 'l','i','n','k','e' });
//	string s2("ibti lbtlovebte lbtlibtinbtnkbtkebtezbas jebte dosadnbtna ovakbtkebtemibtijaxaszxdbtddbtddbtddbtddbtddbtd");
//	map<char, int> m1;
//	for (int i = 0; i < s1.size(); ++i) {
//		m1[s1[i]] = 100;
//	}
//	string res;
//	// i love linkezbas je dosadnaovakemijaxaszxdbtddbtddbtddbtddbtd
//	for (int i = 0; i < s2.size(); ++i) {
//		if(m1[s2[i]] == 100){
//			i += 3;
//		}
//		res.push_back(s2[i]);
//	}
//	cout << res << endl;
//}
//
//bool isPrime_3(int num)
//{
//	//������С�����⴦��
//	if (num == 2 || num == 3)
//		return 1;
//	//����6�ı��������һ����������
//	if (num % 6 != 1 && num % 6 != 5)
//		return 0;
//	int tmp = sqrt(num);
//	//��6�ı��������Ҳ���ܲ�������
//	for (int i = 5; i <= tmp; i += 6)
//		if (num % i == 0 || num % (i + 2) == 0)
//			return 0;
//	//�ų����У�ʣ���������
//	return 1;
//}
//void CC() {
//	// M ����  N ǰNֻ�粼��  T ��Ҫ֪���ĸ粼�ֱ��
//	// ǰ Nֻ�粼�� �������
//	// T���粼�ֱ��
//
//}
//void DD() {
//	int n = 0;
//	int i = 2;
//	vector<int> temp;
//	while (n < 100) {
//		if (isPrime_3(i)) {
//			temp.push_back(i);
//			n++;
//		}	
//		i++;
//	}
//}
//
//int main() {
//	//BB();
//
//	return 0;
//}