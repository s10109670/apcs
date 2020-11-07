#include <iostream>
using namespace std;

int alive(int n, int m, int k, int r){
    if(r == k){
        return 0;
    }
    return (alive(n-1, m, k, r+1)+m)%n;
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    int alive = 0;
    cout << alive(n, m, k, 0)+1 << endl;
}
