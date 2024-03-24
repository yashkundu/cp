/**
*   author: lazyhash(yashkundu)
*   created: 11 Nov, 2023 | 21:01:00
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

const int N = 1e6+10;
int cnt[N] = {0};
ll ans[N] = {0};
bool vis[N];
 
void solve() {
    int n;
    cin >> n;
    fill(ans, ans+n+1, 0);
    fill(vis, vis+n+1, 0);
    vector<int> a(n);
    for(int &x: a) {
        cin >> x;
        cnt[x]++;
    }

    for(int i=n;i>0;i--) {
        int freq = 0;
        for(int j=i;j<=n;j+=i) {
            ans[i] -= ans[j];
            freq += cnt[j];
        }
        ans[i] += 1LL*freq*(freq-1)/2;
    }


    // number of pairs whose gcd is exactly i
    for(int i=1;i<=n;i++) {
        if(!cnt[i]) continue;
        for(int j=2*i;j<=n;j+=i) {
            if(!cnt[j] && !vis[j]) {
                ans[i] += ans[j];
                vis[j] = 1;
            }
        }
    }

    ll res = 0;
    for(int i=1;i<=n;i++) if(cnt[i]) res += ans[i];

    res = 1LL*n*(n-1)/2 - res;



    cout << res << "\n";


    for(int &x: a) cnt[x]--;
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