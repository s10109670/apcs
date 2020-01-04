#include <iostream>
using namespace std;

int main(){
	int N, M, K;
	cin >> N >> M >> K;
	int alive = 0;
	for(int i = N-K+1; i <= N; i++){
		alive = (alive + M) % i;
		//cout << alive;
	}
	cout << alive+1 << endl;
}
