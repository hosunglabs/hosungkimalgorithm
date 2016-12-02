#include <cstdio>
int a[1000000];
int b[1000000];
void swap(int &x, int &y) {
	int z = x;
	x = y;
	y = z;
}
void merge_sort(int start, int end) {
	if (start == end) {
		return;
	}
	else if (start + 1 == end) {
		if (a[start] > a[end]) {
			swap(a[start], a[end]);
		}
		return;
	}
	int mid = (start + end) / 2;
	merge_sort(start, mid);
	merge_sort(mid + 1, end);
	int i = start;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= end) {
		if (a[i] <= a[j]) {
			b[k++] = a[i++];
		}
		else {
			b[k++] = a[j++];
		}
	}
	while (i <= mid) {
		b[k++] = a[i++];
	}
	while (j <= end) {
		b[k++] = a[j++];
	}
	for (int i = start; i <= end; i++) {
		a[i] = b[i - start];
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	merge_sort(0, n - 1);
	for (int i = 0; i<n; i++) {
		printf("%d\n", a[i]);
	}
	return 0;
}