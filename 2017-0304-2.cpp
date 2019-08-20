#include <stdio.h>


int main(){
	int friends[50001];
	int check[50001] = {0};
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", friends+i);
	}
	int cnt = 0;
	for(int i = 0; i < N; i++){
		if(!check[i]){
			cnt++;
			int t = i;
			while(!check[friends[t]]){
				t = friends[t];
				check[t] = 1;
			}
		}
	}
	printf("%d\n", cnt);

	return 0;
}
