/**
*    author:  lazyhash(yashkundu)
*    created: 28 Jun, 2024 | 21:06:14
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
 
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
ll a[MAXN] = {0};
ll dp[MAXN];
 
int n;

bool check(ll x) {
    multiset<ll> st;

    int l = 1;
    ll tot = 0;
    for(int i=1;i<=n;i++) {
        // dp[i]
        tot += a[i-1];
        st.insert(dp[i-1]);
        while(l<i && tot>x) {
            st.extract(dp[l-1]);
            tot -= a[l];
            l++;
        }

        dp[i] = *st.begin() + a[i];
        // debug(st, l, i, dp[i]);
    }

    // debug(dp[1], dp[2], dp[3], dp[4], dp[5]);

    tot = 0;
    ll mnVal = 1e18;

    for(int i=n;i>0&&tot<=x;i--) {
        mnVal = min(mnVal, dp[i]);
        tot += a[i];
    }

    return mnVal<=x;
}

void solve() {
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    ll l = 0, r = 1e15;

    while(r-l>1) {
        ll mid = (l+r)/2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r << "\n";

    // cout << check(5) << "\n";
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