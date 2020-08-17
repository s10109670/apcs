#include <stdio.h>

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	int num[25];
	int S = 0;
	for(int i = 0; i < N; i++){
		int tmp;
		scanf("%d", &num[i]);
		for(int j = 1; j < M; j++){
			scanf("%d", &tmp);
			if(tmp > num[i])
				num[i] = tmp;
		}
		S += num[i];
	}
	printf("%d\n", S);
	int cnt = 0;
	for(int i = 0; i < N; i++){
		if(S % num[i] == 0){
			num[cnt++] = num[i];
		}
	}
	if(cnt == 0)
		printf("-1\n");
	else{
		for(int i = 0; i < cnt-1; i++){
			printf("%d ", num[i]);
		}
		printf("%d\n", num[cnt-1]);
	}
}
