/**
*   author: lazyhash(yashkundu)
*   created: 24 Jul, 2023 | 00:46:19
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
 
void solve() {
    ll s, k;
    cin >> s >> k;
    if(s%10==0) {
        cout << s*k << "\n";
        return;
    }
    if(s%10==5) {
        cout << max(s*k, (s+5)*(k-1)) << "\n";
        return;
    }

    auto calc = [](ll s, ll k) {
        ll ans = s*k;
        // (s+20x)(k-4x)
        // sk + 20kx - 4sx - 80x2
        // -160x + 20k - 4s
        // (5k-s)/40
        // point of maxima
        ll x = (5*k-s)/40;
        if(x>0) ans = max(ans, (s+20*(x))*(k-4*(x)));
        if(x-1>0) ans = max(ans, (s+20*(x-1))*(k-4*(x-1)));
        if(x+1>0)ans = max(ans,(s+20*(x+1))*(k-4*(x+1)));
        return ans;
    };


    ll ans = s*k;
    s += s%10;
    k--;
    for(int i=0;i<4;i++) {
        if(i) {
            s += s%10;
            k--;
        }
        ans = max(ans, calc(s, k));
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