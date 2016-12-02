#include <iostream>

using namespace std;
void conversion(int num, int base) {
	if (num == 0) return;
	conversion(num / base, base);
	printf("%d ", num%base);
}
int main() {
	int a, b;
	cin >> a >> b;
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i<n; i++) {
		int x;
		cin >> x;
		ans = ans * a + x;
	}
	conversion(ans, b);
	return 0;
}