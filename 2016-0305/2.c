#include <stdio.h>

int main(){
	int R, C, M;
	int matrix[10][10];
	int tmpmatrix[10][10];
	while(scanf("%d %d %d", &R, &C, &M) == 3){
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++)
				scanf("%d", &matrix[i][j]);
		}
		int m[10];
		for(int t = 0; t < M; t++){
			scanf("%d", &m[t]);
		}
		for(int t = M-1; t >= 0; t--){
			if(m[t]){		//flip
				for(int i = 0; i < R; i++){
					for(int j = 0; j < C; j++){
						tmpmatrix[i][j] = matrix[R-i-1][j];
					}
				}
				for(int i = 0; i < R; i++){
					for(int j = 0; j < C; j++){
						matrix[i][j] = tmpmatrix[i][j];
					}
				}
			}
			else{		//transpose
				int tmp = R;
				R = C;
				C = tmp;
				for(int i = 0; i < R; i++){
					for(int j = 0; j < C; j++){
						tmpmatrix[i][j] = matrix[j][R-1-i];
					}
				}
				for(int i = 0; i < R; i++){
					for(int j = 0; j < C; j++){
						matrix[i][j] = tmpmatrix[i][j];
					}
				}
			}
		}
		printf("%d %d\n", R, C);
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				printf((j == C-1)?"%d\n":"%d ", matrix[i][j]);
			}
		}
	}
	return 0;
}
