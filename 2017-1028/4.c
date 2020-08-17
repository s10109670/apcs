#include <stdio.h>
#include <stdlib.h>

typedef struct goods{
	int weight;
	int times;
}Goods;

int cmp(const void* a, const void* b){
	return ((Goods*)b)->weight *  ((Goods*)a)->times - ((Goods*)a)->weight * ((Goods*)b)->times;
}
int main(){
	int N;
	Goods G[100002];
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &G[i].weight);
	}
	for(int i = 0; i < N; i++){
		scanf("%d", &G[i].times);
	}
	qsort(G, N, sizeof(Goods), cmp);
	long long int sum = 0;
	long long int tsum = 0;
	for(int i = 0; i < N; i++){
		sum += G[i].weight * tsum;
		tsum += G[i].times;
	}
	printf("%lld\n", sum);
	return 0;
}
