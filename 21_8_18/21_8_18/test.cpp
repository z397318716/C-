#include <iostream>
#include <string>
#include <stack>
int main() {
    int num;
    while (std::cin >> num) {
        //std::stack<int> s1;
        //std::string s1;
        int count = 0;
        int cur = num;
        int res = 0;
        while (num) {
            int tmp = num % 10;
            res = res * 10 + tmp;
            //s1.push_back(tmp+'0');
            num /= 10;
            count++;
        }
        printf("%d��һ��%dλ����\n", cur, count);
        printf("����������ǣ�%d\n", res);


    }


    return 0;
}