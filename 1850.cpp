#include <iostream>
using namespace std;

long long greatest(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	else {
		return greatest(b, a%b);
	}
}

int main() {
	long long a, b;
	cin >> a >> b;
	long long g = greatest(a, b);
	for (int i = 0; i<g; i++) {
		cout << '1';
	}
	cout << '\n';
}
