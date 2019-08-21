#include <stdio.h>

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if(c < a){
		int tmp = a;
		a = c;
		c = tmp;
	}
	if(c < b){
		int tmp = b;
		b = c; 
		c = tmp;
	}
	if(b < a){
		int tmp = a;
		a = b;
		b = tmp;
	}
	printf("%d %d %d\n", a, b, c);
	if(a + b <= c){
		printf("No\n");
	}
	else if(a * a + b * b  < c * c){
		printf("Obtuse\n");
	}
	else if(a * a + b * b == c * c){
		printf("Right\n");
	}
	else{
		printf("Acute\n");
	}
}
