#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef unsigned long long int ull;

ull to_bit(string s){
	ull bitset = 0;
	int len = s.length();
	for(int i = 0; i < len; i++){
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
		ull complement = Union - cp[i];
		int min = i+1, max = nowj;
		while(min != max){
			int mid = (min + max + 1)/2;
			if(cp[mid] <= complement)
				min = mid;
			else
				max = mid-1;
		}
		nowj = max;
		if(cp[nowj] == complement){
			int cntj = 1;
			while(nowj > i && cp[nowj] == cp[nowj-1]){
				cntj++;
				nowj--;
			}
			cnt += cnti*cntj;
			nowj--;
		}
	}
	cout << cnt << endl;
}
