#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	bool is_leaf[100002] = {0};
	int parent[100002] = {0};
	for(int i = 1; i <= n; i++){
		int kid_num;
		cin >> kid_num;
		if(kid_num == 0){
			is_leaf[i] = 1;
		}
		for(int j = 0; j < kid_num; j++){
			int kid;
			cin >> kid;
			parent[kid] = i;
		}
	}
	//find root
	int root = 1;
	while(parent[root] != 0){
		root = parent[root];
	}	
	//calculate height
	int height[100002] = {0};
	for(int i = 1; i <= n; i++){
		if(is_leaf[i]){  
			height[i] = 0;
			int pos = i;
			while(pos != root && height[parent[pos]] < height[pos]+1){
				height[parent[pos]] = height[pos]+1;
				pos = parent[pos];
			}
		}
	}
	//height sum
	unsigned long long int sum = 0;
	for(int i = 1; i <= n; i++){
		sum += height[i];
	}
	cout << root << '\n' << sum << '\n';
}
