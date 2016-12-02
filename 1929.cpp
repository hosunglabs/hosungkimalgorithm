#include <iostream> 
using namespace std;
const int MAX = 1000000;
bool check[MAX + 1];
int main() {
	check[0] = check[1] = true; //지워짐
	for (int i = 2; i*i <= MAX; i++) {
		if (check[i] == false) { //지워지지 않음
			for (int j = i + i; j <= MAX; j += i) {
				check[j] = true;
			}
		}
	}

	int m, n;
	cin >> m >> n;
	for (int i = m; i <= n; i++) {
		if (check[i] == false) {
			cout << i << '\n';
		}
	}
	return 0;
}