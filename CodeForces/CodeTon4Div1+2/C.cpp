/**
*   author: lazyhash(yashkundu)
*   created: 31 Mar, 2023 | 20:26:04
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

 
void solve() {
    int n;
    ll c, d;

    cin >> n >> c >> d;

    vector<int> v(n);
    bool one_present = false;

    for(int i=0;i<n;i++) {
        cin >> v[i];
        if(v[i]==1) one_present = true;
    }

    ll initAns = 0;

    if(!one_present) {
        v.push_back(1);
        initAns += d;
        n++;
    }

    sort(v.begin(), v.end());
    v.resize(distance(v.begin(), unique(v.begin(), v.end())));
    int m = v.size();

    initAns += (n-m)*c;
    ll ans = 8e18;

    for(int i=m;i>0;i--) {
        ans = min(ans, initAns + (m-i)*c + (v[i-1]-i)*d);
    }

    cout << ans << "\n";





    
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/