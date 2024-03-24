/**
*   author: lazyhash(yashkundu)
*   created: 16 Dec, 2023 | 18:35:11
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
    int n;
    cin >> n;
    vector<ll> a(n);
    for(ll &x: a) cin >> x;
    sort(a.begin(), a.end());

    ll ans = 0;
    int left = 0;
    int right = n-1;

    while(left<right) {
        ll cur = 0;
        int ptr = left;
        while(ptr<right && cur+a[ptr]<=a[right]) cur += a[ptr++];
        left = ptr;
        if(ptr<right) {
            ll del = a[right]-cur;
            cur += min(a[ptr], del);
            a[ptr] -= min(a[ptr], del);
        } else {
            ll del = (a[right]-cur)/2;
            cur += del;
            a[right] -= del;
        }
        ll del = min(cur, a[right]);
        ans += del + 1;
        a[right] -= del;
        if(!a[right]) right--;
    }

    if(a[right] && right>=left) {
        if(a[right]==1) ans++;
        else 
            ans += a[right]/2 + 1 + a[right] - 2*(a[right]/2);
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