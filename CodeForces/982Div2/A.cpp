/**
*    author:  lazyhash(yashkundu)
*    created: 26 Oct, 2024 | 20:09:58
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

int n;
vector<pair<int, int>> v;
 
void solve() {
    cin >> n;
    v.resize(n);

    int mxw = 0;

    for(int i=0;i<n;i++) {
        cin >> v[i].first >> v[i].second;
        mxw = max(mxw, v[i].second);
    }
    
    sort(v.begin(), v.end(), [](const pair<int, int> p1, const pair<int, int> p2) {
        if(p1.first!=p2.first) return p1.first>p2.first;
        return p1.second>p2.second;
    });

    // debug(v);


    int ans = mxw + v[0].first;
    int cur = 0;

    // debug(ans);

    for(int i=0;i<n;i++) {
        int del = max(0, v[i].second-cur);
        // debug(i, del);
        ans += del;
        if(i>0) ans += v[i-1].first - v[i].first;
        // debug(ans);
        cur += del;
    }

    ans += v[n-1].first;

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