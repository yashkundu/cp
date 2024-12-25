/**
*    author:  lazyhash(yashkundu)
*    created: 27 Sep, 2024 | 19:13:16
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

map<ll, ll> ans;

int n, q;
vector<int> x;

ll k;
 
void solve() {

    cin >> n >> q;
    x.resize(n);

    ans.clear();

    for(int i=0;i<n;i++) cin >> x[i];


    for(int i=1;i<n;i++) {
        ans[1LL*i*(n-i)] += x[i]-x[i-1]-1;
    }


    for(int i=1;i<=n;i++) {
        ans[1LL*i*(n-i+1) - 1]++;
    }


    for(int i=0;i<q;i++) {
        cin >> k;
        cout << ans[k] << " ";
    }

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