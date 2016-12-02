#include <iostream>
using namespace std;
long long hosung[1500000];

int main() {
	hosung[0] = 0;
	hosung[1] = 1;

	for (int i = 2; i <= 1500000; i++) {
		hosung[i] = hosung[i - 1] + hosung[i - 2];
		hosung[i] %= 1000000;
	}

	long long p;
	cin >> p;
	cout << hosung[p % 1500000] << '\n';

	return 0;
}