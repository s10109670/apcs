#include <iostream>
using namespace std;

int main(){
	int N, M, K;
	cin >> N >> M >> K;
	
	int alive = 0; //ans is peoele[0] at the beginning of ronud-(K+1)
	/* from round-(K+1) think back to round-1 */
	for(int i = K; i > 0; i--){
		left = N-i+1;
		alive = (alive + M) % left; // alive become the pos of round-(i)
		//cout << "goes to pos:" << alive << endl;
	}
	cout << alive+1 << endl;
}
