/**
*    author:  lazyhash(yashkundu)
*    created: 16 Nov, 2024 | 20:49:02
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
vector<int> p;

void solve() {
    cin >> n;
    p.resize(n+1);

    for(int i=1;i<=n;i++) cin >> p[i];

    for(int i=1;i<=n;i++) {
        if(abs(p[i]-i)>1) {
            cout << "No\n";
            return;
        }
    }


    cout << "Yes\n";

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