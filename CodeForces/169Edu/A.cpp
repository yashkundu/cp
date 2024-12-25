/**
*    author:  lazyhash(yashkundu)
*    created: 15 Aug, 2024 | 20:07:20
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<int> x;
 
void solve() {
    cin >> n;
    x.resize(n);
    for(int i=0;i<n;i++) cin >> x[i];


    if(n>2) {
        cout << "NO\n";
        return;
    }

    if(x[1]==x[0]+1) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }

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