/**
*   author: lazyhash(yashkundu)
*   created: 17 Dec, 2023 | 12:43:41
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
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);


    ll ans = 1e18+100;
    for(ll &x: a) {
        cin >> x;
        ans = min(ans, x);
    }


    if(k>=3) {
        cout << "0\n";
        return;
    }

    vector<ll> diffs;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) diffs.push_back(abs(a[i]-a[j]));
    }

    sort(diffs.begin(), diffs.end());
    diffs.resize(distance(diffs.begin(), unique(diffs.begin(), diffs.end())));


    for(ll &x: diffs) ans = min(ans, x);

    int m = diffs.size();

    if(k==1 || ans==0) {
        cout << ans << "\n";
        return;
    }

    sort(a.begin(), a.end());

    int j = 0;
    for(ll x: a) {
        while(j<m && x>diffs[j]) j++;
        if(j<m) ans = min(ans, abs(x-diffs[j]));
        if(j>0 && j-1<m) ans = min(ans, abs(x-diffs[j-1]));
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