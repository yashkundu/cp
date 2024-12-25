/**
*    author:  lazyhash(yashkundu)
*    created: 04 Dec, 2024 | 20:56:16
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
 
const ll inf = (ll)1e18;


ll calc(ll x, ll num) {
    ll ans = 0LL;
    for(ll i=0;i<num;i++) {
        ans += x;
        if(ans>inf) return inf+1;
        x /= 2;
    }
    return ans;
}


ll n, x;

void solve() {
    cin >> x >> n;

    ll cnt = n;
    ll num = 1;


    while(cnt>0 && num<=inf) {
        num *= 2;
        cnt--;
    }


    // debug(n, x, num);

    if(num<=inf) {
        ll L = num-1, R = inf;
        while(R-L>1) {
            ll mid = (L+R)/2;
            if(calc(mid, n)>=x) R = mid;
            else L = mid;
        }
        if(calc(R, n)==x) {
            cout << R << "\n";
            return;
        }
    }

    
    ll L = 0, R = num-1;
    while(R-L>1) {
        ll mid = (L+R)/2;
        if(calc(mid, 61)>=x) R = mid;
        else L = mid;
    }

    if(calc(R, 61)==x) {
        cout << R << "\n";
    } else {
        cout << "-1\n";
    }



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