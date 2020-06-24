#include <iostream>

using namespace std;

int f(int x){
	return x*2-3;
}

int g(int x, int y){
	return 2*x + y - 7;
}

int h(int x, int y, int z){
	return 3*x - 2*y + z;
}

int calculate(string s[], int i, int &end){
	if(s[i] == "h"){
		int m1 = end, m2 = end;
		int a = calculate(s, i+1, m1);
		int b = calculate(s, m1, m2);
		int c = calculate(s, m2, end);
		return h(a, b, c);
	}
	else if(s[i] == "g"){
		int m = end;
		int a = calculate(s, i+1, m);
		int b = calculate(s, m, end);
		
		return g(a, b);
	}
	else if(s[i] == "f"){
		return f(calculate(s, i+1, end));
	}
	else
		end = i+1;
		return stoi(s[i]);
}

int main(){
	string s[512];
	int cnt = 0;
	while(cin >> s[cnt++]);
	cout << calculate(s, 0, cnt) << endl;
}
