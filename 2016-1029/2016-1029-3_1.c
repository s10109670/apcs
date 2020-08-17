#include <stdio.h>

long long int kth(int n, int m, int k)
{
	if (m == 1) return k;
	long long i = (long long)k * m;
	while(i >= (long long)n)
		i = i-n + (i-n)/(m-1);
	return i;
}

int main(){
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	printf("%lld\n", kth(N, M, K)+1);
	return 0;
}
