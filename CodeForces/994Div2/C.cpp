/**
*    author:  lazyhash(yashkundu)
*    created: 23 Dec, 2024 | 00:55:05
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, x, y;
vector<int> a;

bool check(int ind) {
    return a[(ind+1)%n]!=2 && a[(ind-1+n)%n]!=2; 
}

 
void solve() {
    cin >> n >> x >> y;
    x--, y--;

    a.resize(n);

    int start = -1;
    if(n%2==0 && x%2!=y%2) {
        for(int i=0;i<n;i++) cout << (i%2) << " ";
        cout << "\n";
        return;
    }


    if(n%2==0) {
        start = x;
    } else {
        if(x%2==y%2) start = y-1;
        else start = n-1;
    }


    a[start] = 2;
    for(int i=0;i<n-1;i++) {
        a[(start+i+1)%n] = (i&1);
    }

    for(int i=0;i<n;i++) cout << a[i] << " ";
    cout << "\n";




}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
/* stuff you should look for
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/