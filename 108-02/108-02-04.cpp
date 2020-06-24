#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int b[200005] = {0};
	int p[200005] = {0};
	int num[200005] = {0};
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	for(int i = 0; i < n; i++){
		cin >> p[i];
	}
	long long sum = 0;
	for(int i = 1; i < n; i++){
		for(int j = 1; j <= i; j++){
			if (b[i]+p[i] >= b[i-j]+p[i-j]){
				num[i] = num[i-j] + j;
				sum += num[i];
			}
		}
		/*for(int j = i-1; j >= 0 && p[i]+b[i]>=b[j]; j--){
			sum++
		}*/
	}
	cout <<sum << endl;
}
