/**
*    author:  lazyhash(yashkundu)
*    created: 27 Jun, 2024 | 11:39:23
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll x;
vector<int> seq;
 
void solve() {
    cin >> x;
    seq.clear();


    int msb = 63 - __builtin_clzll(x);
    for(int i=1;i<=msb;i++) seq.push_back(i);

    x -= (1LL<<msb);

    while(x) {
        msb = 63 - __builtin_clzll(x);
        seq.push_back(msb+1);
        x -= (1LL<<msb);
    }

    cout << seq.size() << "\n";
    for(int a: seq) cout << a << " ";
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