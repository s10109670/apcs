#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b){
	return *(int*)a - *(int*)b;
}

int main(){
	int N;
	int m[20];
	while(scanf("%d", &N) != EOF){
		int max = -1, min = 200;
		for(int i = 0; i < N; i++){
			scanf("%d", &m[i]);
			if(m[i] >= 60 && m[i] < min){
				min = m[i];
			}
			else if(m[i] < 60 && m[i] > max){
				max = m[i];
			}
		}
		qsort(m, N, sizeof(int), cmp);
		for(int i = 0; i < N; i++){
			printf((i==N-1)?"%d\n":"%d ", m[i]);
		}
		printf((max < 0)?"best case\n":"%d\n", max);
		printf((min > 100)?"worst case\n":"%d\n", min);
	}
}
