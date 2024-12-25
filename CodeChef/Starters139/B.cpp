/**
*    author:  lazyhash(yashkundu)
*    created: 19 Jun, 2024 | 20:18:13
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1e6+5;
bool prime[MAXN];
int spf[MAXN];
ll pref[MAXN];

void init() {
    for(int i=2;i<MAXN;i++) prime[i] = 1;
    for(int i=2;i<MAXN;i++) spf[i] = i;

    for(int i=2;i*i<MAXN;i++) {
        if(!prime[i]) continue;
        for(int j=i*i;j<MAXN;j+=i) {
            prime[j] = 0;
            if(spf[j]==j) spf[j] = i;
        }
    }

    pref[1] = 0;
    for(int i=2;i<MAXN;i++) {
        pref[i] = pref[i-1];
        if(prime[i]) pref[i] += i;
    }
}

int k;
 
void solve() {
    cin >> k;

    int s = spf[k];
    ll ans = 1LL*pref[s]*k;
    cout << ans << "\n";

}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
    init();
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