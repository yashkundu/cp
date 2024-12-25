/**
*    author:  lazyhash(yashkundu)
*    created: 16 Oct, 2024 | 20:28:12
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
ll x;
vector<ll> b;
vector<pair<ll, ll>> segs;


bool check(int del) {
    segs[0] = {b[0]-del, b[0]+del};
    for(int i=1;i<n;i++) {
        segs[i] = {max(b[i]-del, segs[i-1].first), min(b[i]+del, segs[i-1].second+x)};
        if(segs[i].first>segs[i].second) return false;
    }
    return true;
}

 
void solve() {
    cin >> n >> x;
    b.resize(n);
    segs.resize(n);
    for(int i=0;i<n;i++) {
        cin >> b[i];
    }

    int L = -1, R = (int)1e9+10;

    while(R-L>1) {
        int mid = (L+R)/2;
        if(check(mid)) R = mid;
        else L = mid;
    }

    cout << L+1 << "\n";
    check(L+1);
    for(int i=0;i<n;i++) cout << segs[i].second << " ";
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