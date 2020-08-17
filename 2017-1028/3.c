#include <stdio.h>
#include <stdlib.h>

int main(){
	srand(1234);
	int parent[100005] = {0};
	int height[100005] = {0};
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int num = 0;
		scanf("%d", &num);
		int kid;
		for(int j = 0; j < num; j++){
			scanf("%d", &kid);
			parent[kid] = i;
		}
	}
	/* Find root */
	int root = rand()%n + 1;// evil -> n
	while(parent[root] != 0){
		height[parent[root]] = height[root]+1;
		root = parent[root];
	}
	/* Get Height */
	printf("%d\n", root);
	for(int i = 1; i <= n; i++){
		if (height[i])
			continue;
		int now = i;
		while(now != root && height[parent[now]] < height[now] + 1){
			height[parent[now]] = height[now]+1;
			now = parent[now];
		}
	}
	long long int sum = 0;
	for(int i = 1; i <= n; i++){
		sum += height[i];
	}
	printf("%lld\n", sum);
	return 0;
}
