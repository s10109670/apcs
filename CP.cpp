#include <iostream>
#include <algorithm>

using namespace std;
typedef unsigned long long int ull;

ull to_bit(string s){
	ull bitset = 0;
	for(int i = 0; i < s.length(); i++){
		int pos;
		if(s[i] <= 'Z')
			pos = s[i]-'A';
		else
			pos = s[i]-'a'+26;
		bitset |= (1 << pos);
	}
	return bitset;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int m,n;
	cin >> m >> n;
	const ull Union = ((ull)1<<m)-1;
	string s;
	ull cp[500000] = {0};
	for(int i = 0; i < n; i++){
		cin >> s;
		cp[i] = to_bit(s);
	}
	int cnt = 0;
	sort(cp, cp+n);
	for(int i = 0, nowj = n-1; i < nowj; i++){
		int cnti = 1;
		while(i < nowj && cp[i] == cp[i+1]){
			cnti++;
			i++;
		}
		min = i+1; max = nowj;
		while(min != max){
			int mid = (min + max)/2;
			
		}
		for(int j = nowj; j > i; j--){
			if((cp[i]^cp[j]) == Union){
				int cntj = 1;
				while(i < j && cp[j] == cp[j-1]){
					cntj++;
					j--;
				}
				cnt += cnti*cntj;
				nowj = j-1;
			}
		}
	}
	cout << cnt << endl;
}
