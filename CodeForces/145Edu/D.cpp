/**
*   author: lazyhash(yashkundu)
*   created: 23 Mar, 2023 | 21:20:28
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll big = 1e12;
 
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<bool> v(n+5, 0);

    for(int i=0;i<n;i++) v[i] = s[i]=='1';
    vector<int> cnt(n+5, 0);
    vector<int> prev(n+5, 0);

    for(int i=0;i<n;i++) {
        cnt[i+1] = cnt[i] + v[i];
    }

    prev[0] = -1;
    for(int i=1;i<n;i++) {
        prev[i] = prev[i-1];
        if(!v[i-1]) prev[i] = i-1;
    }

    prev[n] = prev[n-1];
    if(!v[n-1]) prev[n] = n-1;

    ll ans = 1e18;

    int cnt0 = 0;
    for(int i=n;i>=0;i--) {
        // | i, i+1
        if(i<n && !v[i]) cnt0++;
        int p1 = prev[i];
        if(p1==-1) {
            ans = min(ans, 1LL*cnt0*(big+1));
            continue;
        }
        int p2 = prev[p1];
        if(p2==-1) {
            ans = min(ans, 1LL*cnt0*(big+1) + 1LL*cnt[p1]*big);
            continue;
        }
        ans = min(ans, 1LL*cnt0*(big+1) + 1LL*(cnt[p1]-cnt[p2])*big + 1LL*cnt[p2]*(big+1));
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