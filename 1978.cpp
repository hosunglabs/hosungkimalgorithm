#include <iostream> 
using namespace std;
bool sangorithm(int x) {
	if (x == 1) {
		return false;
	}
	for (int i = 2; i*i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	int n;
	cin >> n;
	int hosung = 0;

	for (int i = 0; i<n; i++) {
		int num;
		cin >> num;
		if (sangorithm(num)) {
			hosung += 1;
		}
	}
	cout << hosung << '\n';
	return 0;
}