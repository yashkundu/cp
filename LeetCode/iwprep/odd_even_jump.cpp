/**
*    author:  lazyhash(yashkundu)
*    created: 03 Nov, 2024 | 20:58:23
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
 
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

const int MAXN = (int)2e4+10;

int a[MAXN];
int nxt[MAXN][2];


bool dp[MAXN][2];

int n;
 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    map<int, int> mp;


    for(int i=n-1;i>=0;i--) {
        auto it = mp.lower_bound(a[i]);
        if(it!=mp.end()) nxt[i][1] = it->second;
        else nxt[i][1] = n;
        auto it2 = mp.upper_bound(a[i]);
        if(it2!=mp.begin()) {
            it2--;
            nxt[i][0] = it2->second;
        } else {
            nxt[i][0] = n;
        }
        mp[a[i]] = i;
    }


    dp[n][0] = dp[n][1] = 0;
    dp[n-1][0] = dp[n-1][1] = 1;


    for(int i=n-2;i>=0;i--) {
        dp[i][0] = dp[nxt[i][0]][1];
        dp[i][1] = dp[nxt[i][1]][0];
    }

    int cnt = 0;
    for(int i=0;i<n;i++) if(dp[i][1]) cnt++;

    cout << cnt << "\n";





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