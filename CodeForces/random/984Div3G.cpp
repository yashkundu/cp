/**
*    author:  lazyhash(yashkundu)
*    created: 24 Nov, 2024 | 18:20:22
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

ll query(ll l, ll r) {
    cout << "xor " << l << " " << r << endl;
    ll x;
    cin >> x;
    if(x==-1) exit(0);
    return x;
}

void output(ll a, ll b, ll c) {
    cout << "ans " << a << " " << b << " " << c << endl;
}

ll n;
 
void solve() {
    cin >> n;

    int x = 63 - __builtin_clzll(n);

    ll l = -1, r = -1;
    ll num = 0;

    for(int j=x;j>=0;j--) {
        num = query((1LL<<j), min((1LL<<(j+1))-1, n));
        if(num) {
            l = (1LL<<j), r = min((1LL<<(j+1))-1, n);
            break;
        }
    }

    ll L = l-1, R = r;
    while(R-L>1) {
        ll mid = (L+R)/2;
        if(query(l, mid)==num) R = mid;
        else L = mid;
    }

    ll c = R;
    num = query(1, c-1);


    L = 0, R = c-1;
    while(R-L>1) {
        ll mid = (L+R)/2;
        if(query(1, mid)==num) R = mid;
        else L = mid;
    }

    ll b = R;

    ll a = b^c^query(1, n);

    output(a, b, c);


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