//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//// �ж��Ƿ����
//bool Ishuiwen(string str) {
//    if (str.size() == 1)
//        return true;
//    int i = 0, j = str.size() - 1;
//    while (i <= j) {
//        if (str[i] != str[j])
//            return false;
//        i++;
//        j--;
//    }
//    return true;
//}
//// ��ǰ����� �����Ӵ�
//int Find(string str) {
//    int ans = 1; // �����Ӵ�����󳤶�
//    int i;
//    for (i = 1; i < str.size() - 1; ++i) {
//        string tmp(str.begin() + i, str.end());
//        if (Ishuiwen(tmp)) {
//            ans = tmp.size();
//            break;
//        }
//    }
//    return ans;
//}
//
//int main() {
//    string str;
//    while (cin >> str) {
//        if (Ishuiwen(str)) {
//
//        }
//        else {
//            int ret = Find(str);
//            /*if (ret % 2 == 1)
//                ret += 1;*/
//            string tmp(str.begin(), str.end() - ret);
//            reverse(tmp.begin(), tmp.end());
//            str += tmp;
//        }
//        printf("%s\n", str.c_str());
//    }
//
//
//    return 0;
//}