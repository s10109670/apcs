#include <stdio.h>

int main(){
	int matrix[55][55] = {{0}};
	int n;
	int d;
	scanf("%d%d", &n, &d);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &matrix[i+1][j+1]);
		}
	}
	for(int i = 0; i < n+2; i++){
		matrix[i][0] = -1;
		matrix[0][i] = -1;
		matrix[n+1][i] = -1;
		matrix[i][n+1] = -1;
	}
	/*for(int i = 0; i < n+2; i++){
		for(int j = 0; j < n+2; j++){
			printf("%2d ", matrix[i][j]);
		}
		printf("\n");
	}*/
	int diri[4] = {0, -1, 0, 1};
	int dirj[4] = {-1, 0, 1, 0};
	int nowi = n/2+1, nowj = nowi;
	int cnt = 0;
	while(matrix[nowi][nowj] >= 0){
		for(int i = 0; i < cnt/2+1 && matrix[nowi][nowj] >= 0; i++){
			printf("%d", matrix[nowi][nowj]);
			nowi += diri[d];
			nowj += dirj[d];
		}
		cnt++;
		d = (d+1)%4;
	}
	printf("\n");
}
