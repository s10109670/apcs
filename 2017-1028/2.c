#include <stdio.h>
#include <string.h>

int isLower(char c){
	return (c > 'Z');
}

int main(){
	int k;
	char c[100000] = {'\0'};
	int n[100000] = {0};
	scanf("%d", &k);
	scanf("%s", c);
	int max = -1;
	int n_cnt = 0;
	for(int i = 0; i < strlen(c); i++){
		if(isLower(c[i]) == n_cnt % 2){
			n[n_cnt]++;
		}
		else
			n[++n_cnt]++;
	}
	n_cnt++;
	int t = 0;
	for(int i = 0; i <= n_cnt; i++){
		if(n[i] == k){
			t++;
		}
		else{
			if(n[i] > k)
				t++;
			if(t > max)
				max = t;
			t = 0;
			if(n[i] > k)
				t++;
		}
	}
	printf("%d\n", max*k);
	return 0;
}
