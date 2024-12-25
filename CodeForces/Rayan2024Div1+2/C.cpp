/**
*    author:  lazyhash(yashkundu)
*    created: 30 Nov, 2024 | 20:24:01
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

const int MAXN = 1005;

int n, m;
char a[MAXN][MAXN];
bool vis[MAXN][MAXN];
bool good[MAXN][MAXN];

map<char, pair<int, int>> dmp = {
    {'U', {-1, 0}},
    {'D', {1, 0}},
    {'L', {0, -1}},
    {'R', {0, 1}}
};

bool isoutside(int x, int y) {
    return x<0 || x>=n || y<0 || y>=m;
}


void dfs(int x, int y) {
    vis[x][y] = 1;
    if(a[x][y]=='?') return;
    auto p = dmp[a[x][y]];
    int nx = x+p.first, ny = y+p.second;
    if(isoutside(nx, ny)) {
        good[x][y] = 1;
        return;
    }
    if(!vis[nx][ny]) dfs(nx, ny);
    good[x][y] = good[nx][ny];
}



string s;
 
void solve() {
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> s;
        for(int j=0;j<m;j++) a[i][j] = s[j];
    }


    for(int i=0;i<n;i++) for(int j=0;j<m;j++) vis[i][j] = good[i][j] = 0;


    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(!vis[i][j]) dfs(i, j);


    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        if(a[i][j]!='?') continue;
        bool isgood = true;
        for(auto p: dmp) {
            int nx = i + p.second.first, ny = j + p.second.second;
            if(!isoutside(nx, ny) && !good[nx][ny]) isgood = false; 
        }
        good[i][j] = isgood;
    }


    int cnt = 0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(good[i][j]) cnt++;

    int ans = n*m - cnt;

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