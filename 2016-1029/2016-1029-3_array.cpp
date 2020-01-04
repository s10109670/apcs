#include <iostream>

using namespace std;

int main(){
	int n, m ,k;
	cin >> n >> m >> k;
	int people[200000];
	for(int i = 0; i < n; i++)
		people[i] = i;

	int bomb_pos = 0;
	for(int t = 0; t < k; t++){
		bomb_pos = (bomb_pos+m-1) % n;
		//cout << people[bomb_pos]+1 << "die" << '\n';
		//bomb_pos should die
		n--;
		for(int i = bomb_pos; i < n; i++){
			people[i] = people[i+1];
		}
	}
	cout << people[bomb_pos%n]+1 << endl;

}
