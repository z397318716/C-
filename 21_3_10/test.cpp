//#include<iostream>
//#include<stack>
//using namespace std;
//
//int main() {
//    int n, res = 0;
//    stack<char> st;
//    cin >> n;
//    char tmp;
//    string s1;
//    for (int i = 0; i < n; ++i) {
//        cin >> tmp >> s1;
//        if (s1 == "connect") {
//            st.push(tmp);
//            if (res < st.size())
//                res = st.size();
//        }
//        else if (s1 == "disconnect") {
//            st.pop();
//        }
//    }
//    cout << res << endl;
//
//    return 0;
//}