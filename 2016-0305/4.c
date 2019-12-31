#include <stdio.h>
#include <stdlib.h>

typedef struct list{
	struct list* next;
	int val;
}list;


int traversed[100001] = {0};
void add(list* l[], int a, int b){
	list* node = malloc(sizeof(list));
	node->val = b;
	node->next = l[a];
	l[a] = node;
}

void print_child(list* l[], int i){
	printf("%d: ", i);
	list* p = l[i];
	while(p != NULL){
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
}

int findmaxlen(list* l[], int i, int last){
	printf("%d ", i);
	int maxlen = 0;
	list* p = l[i];
	while(p != NULL){
		if(p->val != last){
			int len = findmaxlen(l, p->val, i) + 1;
			if (len > maxlen)
				maxlen = len;
		}
		p = p->next;
	}
	return maxlen;
}

int main(){
	int N;
	while(scanf("%d", &N) != EOF){
		list* child[100001] = {NULL};
		int leaf[100001] = {0};
		for(int i = 0; i < N-1; i++){
			int p, c;
			scanf("%d %d", &p, &c);
			add(child, p, c);
			leaf[p] = 1;
		}
		for(int i = 0; i < N; i++){
			print_child(child, i);
		}
		int maxlen = 0;
		for(int i = 0; i < N; i++){
			if(!leaf[i]){
				int len = findmaxlen(neighbor, i, i);
				printf("\n%d\n", len);
				if(len > maxlen)
					maxlen = len;
			}
			traversed[i] = 1;	
		}
		printf("%d\n", maxlen);
		
	}
	return 0;
}
