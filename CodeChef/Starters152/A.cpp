/**
*    author:  lazyhash(yashkundu)
*    created: 18 Sep, 2024 | 20:05:08
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m;
vector<string> s;

int cnt0, cnt1, cntq;
ll ans = 0;
 
void solve() {
    cin >> n >> m;
    s.resize(m);
    for(int i=0;i<m;i++) cin >> s[i];

    ans = 0;

    for(int j=0;j<n;j++) {
        cnt0 = cnt1 = cntq = 0;
        for(int i=0;i<m;i++) {
            if(s[i][j]=='?') cntq++;
            else if(s[i][j]=='0') cnt0++;
            else cnt1++;
        }
        if(cnt0<cnt1) {
            int del = min(cnt1-cnt0, cntq);
            cnt0 += del;
            cntq -= del;
        }
        if(cnt1<cnt0) {
            int del = min(cnt0-cnt1, cntq);
            cnt1 += del;
            cntq -= del;
        }

        cnt0 += cntq/2;
        cntq -= cntq/2;
        cnt1 += cntq;
        ans += 1LL*cnt0*cnt1;
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/