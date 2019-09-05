#include <stdio.h>
#include <stdlib.h>

int* kid[100005];
int parent[100005] = {0};
int height[100005] = {0};
int num[100005] = {0};

int getheight(int root){
	if (root == 0) return -1;
	if (height[root]) return height[root];
	int max = 0, tmp;
	for(int i = 0; i < num[root]; i++){
		tmp = getheight(kid[root][i])+1;
		if (tmp > max)
			max = tmp;
	}
	height[root] = max;
	return max;
	
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &num[i]);
		kid[i] = malloc(sizeof(int) * num[i]);
		int k;
		for(int j = 0; j < num[i]; j++){
			scanf("%d", &kid[i][j]);
			parent[kid[i][j]] = i;
		}
	}
	/* Find root */
	int root = 1;
	while(parent[root] != 0){
		//height[parent[root]] = height[root]+1;
		root = parent[root];
	}
	/* Get Height */
	printf("%d\n", root);
	height[0] = -1;
	getheight(root);
	long long int sum = 0;
	for(int i = 1; i <= n; i++){
		sum += height[i];
	}
	printf("%lld\n", sum);
	return 0;
}
