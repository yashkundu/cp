/**
*    author:  lazyhash(yashkundu)
*    created: 08 Sep, 2024 | 16:23:31
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int res;
    cin >> res;
    return res;
}


void output(int x) {
    cout << "! " << x << endl;
}

int cur = 0;
int big = (1<<30);
int delta;
 
void solve() {
    
    cur = 0;
    int f = 1;
    for(int i=0;i<30;i++,f*=2) {
        delta = f - cur;
        int res = query(delta, delta+big);
        if(res%(2*f)==0) cur += f; 
    }

    output(cur);



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