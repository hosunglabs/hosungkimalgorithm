#include <cstdio>
int a[1001][1001];
int dist[1001];
bool check[1001];
int inf = 1000000000;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = inf;
		}
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i<m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		if (a[x][y] > z) {
			a[x][y] = z;
		}
	}
	int start, end;
	scanf("%d %d", &start, &end);
	for (int i = 1; i <= n; i++) {
		dist[i] = inf;
	}
	dist[start] = 0;
	for (int k = 0; k<n - 1; k++) {
		int m = inf + 1;
		int x = 1;
		for (int i = 1; i <= n; i++) {
			if (check[i] == false && m > dist[i]) {
				m = dist[i];
				x = i;
			}
		}
		check[x] = true;
		for (int i = 1; i <= n; i++) {
			if (dist[i] > dist[x] + a[x][i]) {
				dist[i] = dist[x] + a[x][i];
			}
		}
	}
	printf("%d\n", dist[end]);
	return 0;
}