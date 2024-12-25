/**
*    author:  lazyhash(yashkundu)
*    created: 01 Sep, 2024 | 18:08:10
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


int n;
vector<int> a, b;
vector<bool> vis;


map<int, int> mp;



 
void solve() {
    cin >> n;
    a.resize(n); b.resize(n);
    vis.resize(n);
    fill(vis.begin(), vis.end(), 0);

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];


    mp.clear();


    for(int i=0;i<n;i++) mp[a[i]] = i;
    for(int i=0;i<n;i++) {
        a[i] = mp[a[i]];
        b[i] = mp[b[i]];
    }


    int cnt = 0;

    for(int i=0;i<n;i++) {
        if(vis[i]) continue;
        vis[i] = 1;
        int num = 1;
        int ind = i;
        while(b[ind]!=i) {
            num++;
            vis[b[ind]] = 1;
            ind = b[ind];
        }
        cnt += num/2;
    }

    // debug(cnt);

    ll ans = 0;
    for(int i=0;i<cnt;i++) ans += 2*(n-1-2*i);

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