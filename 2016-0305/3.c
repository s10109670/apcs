#include <stdio.h>

int cnt(int arr[], int L, int R){
	int sum = 0;
	for(int i = L; i < R; i++){
		sum += arr[i];
	}
	return sum;
}
void add(int arr[], int L, int R){
	for(int i = L; i < R; i++){
		arr[i] = 1;
	}
}

int arr[10000000]={0};
int main(){
	//unsigned long long arr[10000000/64+1] = {0};
	int n, L, R;
	scanf("%d", &n);
	int maxR = -1, minL = 10000002;
	for(int i = 0; i < n; i++){
		scanf("%d %d", &L, &R);
		add(arr, L, R);
		if(R > maxR)
			maxR = R;
		if(L < minL)
			minL = L;
	}
	printf("%d\n", cnt(arr, minL, maxR));
	return 0;
}
