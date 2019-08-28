#include <stdio.h>

typedef struct Player{
	int AB;
	char result[6][3];
}Player;

int move(int base[], int n){
	base[0] = 1;
	for(int i = 7; i >= n; i--){
		base[i] = base[i-n];
	}
	for(int i = n-1; i >= 0; i--){
		base[i] = 0;
	}
	int cnt = 0;
	for(int i = 4; i < 8; i++){
		cnt += base[i];
		base[i] = 0;
	}
	return cnt;
}

int main(){
	Player P[9];
	for(int i = 0; i < 9; i++){
		scanf("%d", &P[i].AB);
		for(int j = 0; j < P[i].AB; j++){
			scanf("%s", P[i].result[j]);
		}
	}
	int b;
	scanf("%d", &b);
	int cnt = 0;
	int base[8] = {0};
	int out = 0;
	for(int i = 0; i < P[0].AB && out < b; i++){
		for(int j = 0; j < 9 && i < P[j].AB && out < b; j++){
			char c = P[j].result[i][0];
			if(c > '0' && c <= '9'){
				cnt += move(base, c-'0');
			}
			else if(c == 'H'){
				cnt += move(base, 4);
			}
			else{ 
				out++;
				if(out % 3 == 0){
					for(int i = 0; i < 4; i++){
						base[i] = 0;
					}
				}
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}
