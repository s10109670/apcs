#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b){
	return *(int*)a - *(int*)b;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int P[50001] = {0};
	for(int i = 0; i < n; i++){
		scanf("%d", &P[i]);
	}
	qsort(P, n, sizeof(int), cmp);
	for(int r = 1; r <= P[n-1]-P[0]; r++){
		int cntk = 0, nowk = -r-1;
		for(int i = 0; i < n && cntk <= k; i++){
			if(nowk+r < P[i]){
				cntk++;
				nowk = P[i];
				//printf("nowk:%d\n", nowk);
			}
		}
		if(cntk <= k){
			printf("%d\n", r);
			break;
		}
	}
}
