#include <iostream>
#include <vector>
using namespace std;
int d[100][100];
int main() {
	int n;
	cin >> n;
	int m;
	cin >> m;
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		x--; y--;
		if (d[x][y] == 0) {
			d[x][y] = z;
		}
		else {
			d[x][y] = min(d[x][y], z);
		}
	}
	for (int k = 0; k<n; k++) {
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				if (i == j)
					continue;
				if (d[i][k] != 0 && d[k][j] != 0) {
					if (d[i][j] == 0) {
						d[i][j] = d[i][k] + d[k][j];
					}
					else {
						d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
					}
				}
			}
		}
	}
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			cout << d[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}