#include <stdio.h>

int prime[1000001];

void checkprime()
{
	int i, j;

	for (i = 2; i < 1000001; i++)     prime[i] = 1;
	for (i = 2; i * i < 1000001; i++) {
		for (j = 2; prime[i] && i * j < 1000001; j++)
			prime[i * j] = 0;
	}
}

int main()
{
	int n;
	int i;

	checkprime();

	while (scanf("%d", &n) && n) {
		for (i = 3; i * 2 <= n; i += 2) {
			if (prime[i] && prime[n - i]) {
				printf("%d = %d + %d\n", n, i, n - i);
				break;
			}
		}
	}

	return 0;
}