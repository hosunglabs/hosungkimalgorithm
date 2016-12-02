#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int, int>> a[1001];
bool c[1001];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i<m; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		a[t1].push_back(make_pair(t2, t3));
		a[t2].push_back(make_pair(t1, t3));
	}

	c[1] = true;

	priority_queue<pair<int, int>> q;
	for (auto &p : a[1]) {
		q.push(make_pair(-p.second, p.first));
	}
	int ans = 0;
	while (!q.empty()) {
		auto p = q.top();
		q.pop();
		if (c[p.second]) continue;
		c[p.second] = true;
		ans += -p.first;
		int x = p.second;
		for (auto &p : a[x]) {
			q.push(make_pair(-p.second, p.first));
		}
	}
	printf("%d\n", ans);
	return 0;
}
