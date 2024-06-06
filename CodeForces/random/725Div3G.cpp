/**
*   author: lazyhash(yashkundu)
*   created: 24 Mar, 2024 | 20:02:53
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

ll x, y, a, b;

void updateAns(ll n1, ll n2, ll &ans) {
    // (a, b) -> n1
    // (b, a) -> n2
    if((a*n1 + b*n2 <=x) && (b*n1 + a*n2 <= y)) {
        ans = max(ans, n1+n2);
    }
}

 
void solve() {
    cin >> x >> y >> a >> b;
    if(a==b) {
        ll ans = min(x/a, y/a);
        cout << ans << "\n";
        return;
    }

    ll n1 = max((a*x - b*y)/(a*a - b*b), 0LL);
    ll n2 = max((a*y-b*x)/(a*a-b*b), 0LL);


    ll ans = 0;
    updateAns(n1, n2, ans);
    updateAns(n1+1, n2, ans);
    updateAns(n1, n2+1, ans);

    // edges of first line
    updateAns(0, x/b, ans);
    updateAns(x/a, 0, ans);

    // edges of second line
    updateAns(0, y/a, ans);
    updateAns(y/b, 0, ans);

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