#include <stdio.h>

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int flag = 0;
	if((a && b) == c){
		printf("AND\n");
		flag = 1;
	}
	if((a || b) == c){
		printf("OR\n");
		flag = 1;
	}
	if(((a||0) ^ (b||0)) == c){
		printf("XOR\n");
		flag = 1;
	}
	if(!flag){
		printf("IMPOSSIBLE\n");
	}
	return 0;
}
