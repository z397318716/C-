//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int minstep(int a, int b) {
//	if (a == b)
//		return 0;
//	int i = 1;
//	while (a != b) {
//		if (a + i <= b)
//			a += i;
//		else
//			b += i;
//		i++;
//	}
//	return i-1;
//}
//
//int main() {
//
//
//	cout << minstep(1, 3) << '\n';
//	cout << minstep(11, 11) << '\n';
//	cout << minstep(27, 20) << '\n';
//	return 0;
//}