/**
*   author: lazyhash(yashkundu)
*   created: 14 Apr, 2024 | 22:36:58
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
 

const int K = 20;
const int N = 1e6+10;
bool vis[N] = {0};
bool cnt[N*K];
int uniq[K+1];

void solve() {
    int n, m;
    cin >> n >> m;

    ll ans = 0;

    ll curCnt = 0;
    for(int i=1;i<=K;i++) {
        for(int j=1;j<=m;j++) {
            if(!cnt[i*j]) {
                curCnt++;
                cnt[i*j] = 1;
            }
        }
        uniq[i] = curCnt;
    }


    for(int i=1;i<=n;i++) {
        if(i==1) {
            ans += 1;
            continue;
        }
        if(vis[i]) continue;
        int x = 1;
        int pow = 0;
        while(x<=n/i) {
            pow++;
            x = x*i;
            vis[x] = 1;
        }
        ans += uniq[pow];
    }

    cout << ans << "\n";


    
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/