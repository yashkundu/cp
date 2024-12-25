/**
*    author:  lazyhash(yashkundu)
*    created: 24 Nov, 2024 | 10:56:03
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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


int n, k;
ll m;
vector<ll> h, x;
map<ll, int> mp;

bool check(ll num) {
    mp.clear();
    for(int i=0;i<n;i++) {
        ll del = (h[i]+num-1)/num;
        if(del>m) continue;
        del = m - del;
        mp[x[i]-del]++;
        mp[x[i]+del+1]--;
    }
    int cnt = 0;
    for(auto it: mp) {
        cnt += it.second;
        if(cnt>=k) return true;
    }
    return false;
}

 
void solve() {
    cin >> n >> m >> k;
    h.resize(n);
    x.resize(n);

    for(int i=0;i<n;i++) cin >> h[i];
    for(int i=0;i<n;i++) cin >> x[i];

    int L = 0, R = (ll)1e9+1;

    while(R-L>1) {
        ll mid = (L+R)/2;
        if(check(mid)) R = mid;
        else L = mid;
    }

    if(R==(ll)1e9+1) R = -1LL;

    cout << R << "\n";

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