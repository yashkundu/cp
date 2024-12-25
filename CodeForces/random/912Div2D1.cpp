/**
*    author:  lazyhash(yashkundu)
*    created: 30 Jun, 2024 | 17:49:18
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
 
const int MAXN = 1e5+10;

vector<ll> a;
int n, q;

const ll inf = ll(1e18)+10;

ll calc(vector<ll> a, ll k) {
    ll res = 0;
    vector<ll> ta;
    ll f = (1LL<<60);

    ll cur = 0;
    ll del = 0;

    for(int j=59;j>=0;j--) {
        cur = 0LL;
        for(ll x: a) {
            del = max(0LL, f/2 - (x&(f-1)));
            cur = min(inf, cur+del);
            ta.push_back(x+del);
        }
        if(cur<=k) {
            k -= cur;
            res += f/2;
            swap(a, ta);
        }
        ta.clear();
        f = f>>1;
    }

    return res;

}


void solve() {
    cin >> n >> q;
    a.resize(n);

    for(int i=0;i<n;i++) {
        cin >> a[i];
    }

    while(q--) {
        ll k;
        cin >> k;
        ll ans = calc(a, k);
        cout << ans << "\n";
    }

}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
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