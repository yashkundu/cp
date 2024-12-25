/**
*    author:  lazyhash(yashkundu)
*    created: 27 Oct, 2024 | 22:01:51
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
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

const ll inf = (ll)9e18+10;

ll x, y, z, k;


bool check(int a, int b) {
    int del = a/k;
    if(del>b) return false;
    ll num = 1LL*k*(del)*(del+1)/2;
    num += 1LL*a*(b-del);
    return num>=z;
}


 
void solve() {
    cin >> x >> y >> z >> k;

    ll ans = inf;

    // debug(check(3, 2));

    for(int i=1;i<=20000;i++) {
        int L = 0, R = (int)1e8+10;
        while(R-L>1) {
            int mid = (L+R)/2;
            if(check(i, mid)) R = mid;
            else L = mid;
        }
        ans = min(ans, 1LL*x*i + 1LL*y*R);
    }


    for(int i=1;i<=20000;i++) {
        int L = 0, R = min((ll)1e8+10, 1LL*(i+1)*k);
        while(R-L>1) {
            int mid = (L+R)/2;
            if(check(mid, i)) R = mid;
            else L = mid;
        }
        if(check(R, i)) ans = min(ans, 1LL*x*R + 1LL*y*i);
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