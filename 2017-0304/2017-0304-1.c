#include <stdio.h>
#include <string.h>

int main(){
	char s[1024];
	scanf("%s", s);
	int ans = 0;
	for(int i = 0; i < strlen(s); i++){
		ans += (s[i]-'0');
		ans *= -1;
	}
	printf("%d\n", (ans<0)? -ans: ans);
}
