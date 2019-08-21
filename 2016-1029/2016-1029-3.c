#include <stdio.h>

int main(){
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	int next[N];
	int alive = N;
	for(int i = 0; i < N; i++){
		next[i] = (i+1) % N;
	}
	int p = (M-2) % alive;
	next[p] = next[next[p]];
	p = next[p]; 
	alive--;
	for(int t = 0; t < K-1; t++){
		for(int i = 0; i < (M-2) % alive; i++){
			p = next[p];
		}
		next[p] = next[next[p]];
		p = next[p]; 
		alive--;
	}
	printf("%d\n", p+1);
	

	return 0;
}
