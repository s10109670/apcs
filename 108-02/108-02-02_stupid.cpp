#include <iostream>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	int tape[100005] = {0};
	for(int i = 1; i <= n; i++){
		cin >> tape[i];
	}
	int sum_max = 0, sum_min = 0;
	for(int t = 0; t <= k; t++){
		if(t > 0){
			int c;
			cin >> c;
			tape[c] = 1;
		}
		int cnt = 0, min = 1000001, max = -1;
		for(int i = 1; i <= n+1; i++){
			if (tape[i]){
				cnt++;
			}
			else{
				if(cnt > max)
					max = cnt;
				if (cnt < min && cnt > 0)
					min = cnt;
				cnt = 0;
			}
		}
		//cout << "round " << t<<": ";
		//cout << max << ' ' << min <<endl;
		sum_max += max;
		sum_min += min;
	}
	cout << sum_max << '\n' << sum_min << '\n';
}
