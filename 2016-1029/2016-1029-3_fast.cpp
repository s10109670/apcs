#include <iostream>
using namespace std;

int main(){
	int N, M, K;
	cin >> N >> M >> K;
	int alive = 0; //ans is peoele[0] at the beginning of ronun-(K+1)
	/* from round-K+1 think back to round-0 */
	for(int i = K+1; i > 0; i--){
		alive = (alive + M) % (N-i+1);
		//cout << "goes to pos:" << alive << endl;
	}
	cout << alive+1 << endl;
}
