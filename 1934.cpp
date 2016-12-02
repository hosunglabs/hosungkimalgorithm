#include <iostream>
using namespace std;
int lowerest(int x, int y) {
	if (y == 0) return x;
	else return lowerest(y, x%y);
}
int main() {
	int i;
	cin >> i;
	while (i--) {
		int a, b;
		cin >> a >> b;
		int l = lowerest(a, b);
		cout << a*b / l << '\n';
	}
	return 0;
}