/**
*   author: lazyhash(yashkundu)
*   created: 02 Apr, 2023 | 09:24:08
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
    ll l, r;
    cin >> l >> r;

    auto check = [l, r](int mindig, int maxdig) -> ll {
        ll x = l;
        ll new_l = l;
        ll k = 1;
        while(x>0) {
            int cur_dig = x%10;
            ll cur_extra = 0;
            if(cur_dig<mindig) cur_extra = mindig - cur_dig;
            else if(maxdig<cur_dig) cur_extra = 10 - (cur_dig-mindig);
            x += cur_extra;
            if(new_l>r-cur_extra*k) return -1LL;
            new_l += cur_extra*k;
            x /= 10;
            k *= 10;
        }
        return new_l;
    };

    ll min_luckiness = 10;
    ll ans = -1;

    for(int i=0;i<10;i++) {
        for(int j=i;j<10;j++) {
            if(i==0 && j==0) continue;
            // mindigit - maxdigit
            ll cur = check(i, j);
            if(cur==-1LL) continue;
            if(j-i<min_luckiness) {
                min_luckiness = j-i;
                ans = cur;
            }
        }
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