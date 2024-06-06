/**
*   author: lazyhash(yashkundu)
*   created: 24 Mar, 2024 | 14:21:18
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
 
const int N = 3e5+10;
int p[N];
int cnt[N];

int n, m;

vector<int> g[N];
bool vis[N];


void dfs(int v) {
    vis[v] = 1;
    for(int u: g[v]) {
        if(vis[u]) continue;
        dfs(u);
    }
}


bool isGoodShift(int k) {
    // 5 6 0 1 2 3 4 (k=2)
    // p[i] = (i-k)modn
    for(int i=0;i<n;i++) g[i].clear();
    fill(vis, vis+n, 0);

    for(int i=0;i<n;i++) {
        int x = (i-k+n)%n;
        g[x].push_back(p[i]);
        g[p[i]].push_back(x);
    }


    int cnt = 0;
    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            cnt++;
            dfs(i);
        }
    }
    return (n-cnt)<=m;
}




void solve() {
    cin >> n >> m;

    for(int i=0;i<n;i++) cnt[i] = 0;

    for(int i=0;i<n;i++) {
        cin >> p[i];
        p[i]--;
    }

   

    for(int i=0;i<n;i++) cnt[(i - p[i] + n)%n]++;

    vector<int> goodShifts;
    for(int i=0;i<n;i++) if(cnt[i]>=(n-2*m) && isGoodShift(i)) goodShifts.push_back(i);

    cout << goodShifts.size() << " ";
    for(int x: goodShifts) cout << x << " ";
    cout << "\n";


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