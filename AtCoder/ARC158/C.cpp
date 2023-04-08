/**
*   author: lazyhash(yashkundu)
*   created: 15 Mar, 2023 | 21:40:57
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
 
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

const int N = 2e5+10;
vector<ll> a(N, 0);
vector<pair<ll, int>> sufs(N, {0LL, 0});
vector<vector<int>> cnt(N, vector<int>(10, 0));
vector<ll> ans(10, 0);
 
void solve() {
    int n;
    cin >> n;

    for(int i=0;i<n;i++) cin >> a[i];
    
    ll k = 1;
    for(int j=0;j<=15;j++, k*= 10) {
        for(int i=0;i<n;i++) {
            sufs[i] = {a[i]%k, int(a[i]/k%10)};
            for(int d=0;d<10;d++) cnt[i+1][d] = 0;
        }
        sort(sufs.begin(), sufs.begin()+n);
        for(int i=0;i<n;i++) {
            cnt[i+1][sufs[i].second]++;
            for(int d=0;d<10;d++) {
                cnt[i+1][d] += cnt[i][d];
            }
        }
        for(int i=0;i<n;i++) {
            int ind = lower_bound(sufs.begin(), sufs.begin()+n, make_pair<ll, int>(k-sufs[i].first, 0)) - sufs.begin();
            for(int d=0;d<10;d++) {
                ans[(d+sufs[i].second)%10] += cnt[ind][d];
                if(ind<n) ans[(d+sufs[i].second+1)%10] += cnt[n][d] - cnt[ind][d];
            }

        }
    }    


    ll res = 0;
    for(int i=0;i<10;i++) res += i*ans[i];
    cout << res << "\n";
    
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