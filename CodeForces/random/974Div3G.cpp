/**
*    author:  lazyhash(yashkundu)
*    created: 03 Dec, 2024 | 18:51:38
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <deque>
 
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

const ll inf = (ll)1e12+10;

int n, m, k;
vector<ll> d, a;

deque<pair<ll, ll>> dq;
ll ans = 0;
 
void solve() {
    cin >> n >> m >> k;
    a.resize(n), d.resize(n);
    dq.clear();
    ans = 0;


    for(int i=0;i<n;i++) cin >> d[i] >> a[i];


    for(int i=0;i<n;i++) {
        dq.push_back({d[i], a[i]});
        ll nxt = inf;
        if(i<n-1) nxt = d[i+1];
        ll ind = d[i];
        // debug(i, dq, nxt);
        while(!dq.empty() && ind<nxt) {
            ll nxtind = min(dq.front().first + k, nxt);
            ll sum = (nxtind-ind)*m;
            ll gathered = 0;
            while(!dq.empty() && gathered<sum) {
                // debug(dq, gathered, sum);
                if(dq.back().second+gathered<=sum) {
                    gathered += dq.back().second;
                    dq.pop_back();
                } else {
                    dq.back().second -= sum - gathered;
                    gathered = sum;
                }
            }
            // debug(ind, gathered, sum);
            ind = nxtind;
            if(!dq.empty() && ind>=dq.front().first+k) dq.pop_front();
            ans += gathered/m;
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/