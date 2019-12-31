#include <stdio.h>
#include <stdlib.h>

typedef struct list{
	struct list* next;
	int val;
}list;

int maxlen = 0;

void add(list* l[], int a, int b){
	list* node = malloc(sizeof(list));
	node->val = b;
	node->next = l[a];
	l[a] = node;
}

int findmax(list* l[], int root){
	list *p = l[root];
	int max[2] = {0};
	while(p != NULL){
		int len = findmax(l, p->val)+1;
		if(len > max[0]){
			max[1] = max[0];
			max[0] = len;
		}
		else if(len > max[1])
			max[1] = len;
		p = p->next;
	}
	if(max[0] + max[1] > maxlen)
		maxlen = max[0] + max[1];
	//printf("%d %d %d %d\n", root, max[0], max[1], max[0]+max[1]);
	return max[0];
}

int main(){
	int N;
	while(scanf("%d", &N) != EOF){
		list* child[100001] = {NULL};
		int parent[100001];
		maxlen = 0;
		for(int i = 0; i < N; i++){
			parent[i] = -1;
		}
		for(int i = 0; i < N-1; i++){
			int p, c;
			scanf("%d %d", &p, &c);
			add(child, p, c);
			parent[c] = p;
		}
		int root = 0;
		while(parent[root] != -1){
			root = parent[root];
		}
		findmax(child, root);	//todo	
		printf("%d\n", maxlen);
	}
	return 0;
}
