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
	int minr = 1, maxr = P[n-1]-P[0]+1;
	while(maxr != minr+1){
		int r = (maxr+minr)/2;
		int cntk = 0, nowk = -r-1;
		for(int i = 0; i < n && cntk <= k; i++){
			if(nowk+r < P[i]){
				cntk++;
				nowk = P[i];
				//printf("nowk:%d\n", nowk);
			}
		}
		if(cntk > k){
			minr = r;
		}

		if(cntk <= k){
			maxr = r;
		}
	}
	printf("%d\n", maxr);
	/*for(int i = 0; i < n; i++){
		printf("%d ", P[i]);
	}
	printf("\n");
	*/
}
