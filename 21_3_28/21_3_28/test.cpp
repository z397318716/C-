#include<iostream>

int main() {
	int m, n;
	while (std::cin >> m >> n) {
		int k = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (n > 26) {
					k = (j + i) % 26;
				}else
					k = (j + i)% n;
				printf("%c ", (k+'A'));
			}
			std::cout << std::endl;
		}
	}

	return 0;
}