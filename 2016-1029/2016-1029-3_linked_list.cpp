#include <iostream>
using namespace std;

int main(){
	int n, m ,k;
	cin >> n >> m >> k;
	int next[200000];
	
	for(int i = 0; i < n; i++)
		next[i] = (i+1) % n; //record the next person

	int bomb_pos = n-1;
	for(int t = 0; t < k; t++){
		for(int i = 0; i < (m-1)%n; i++){
			bomb_pos = next[bomb_pos];
		}
		cout << next[bomb_pos]+1 << "die" << '\n';
		next[bomb_pos] = next[next[bomb_pos]];	//next[bomb_pos] should die
		n--;
	}
	cout << bomb_pos+1 << endl;

}
