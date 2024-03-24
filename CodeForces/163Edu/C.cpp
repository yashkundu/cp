/**
*   author: lazyhash(yashkundu)
*   created: 15 Mar, 2024 | 20:27:17
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

const int N = 2e5+10;
bool vis[2*N];


int n;

bool a[2][N];


bool isInside(int r, int c) {
    return (r>=0 && r<=1) && (c>=0 && c<=n-1);
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


void dfs(int v) {
    int r = v/n, c = v%n;
    if(vis[v]) return;
    vis[v] = 1;
    for(int i=0;i<4;i++) {
        int nr = r + dx[i], nc = c + dy[i];
        if(!isInside(nr, nc)) continue;
        if(a[nr][nc]) nc++;
        else nc--;
        dfs(nr*n + nc);
    }
}

 
void solve() {
    cin >> n;

    for(int i=0;i<2*n;i++) vis[i] = false;

    for(int i=0;i<2;i++) {
        string s;
        cin >> s;
        for(int j=0;j<n;j++) {
            a[i][j] = (s[j]=='>');
        }
    }


    dfs(0);

    cout << (vis[2*n-1]?"YES":"NO") << "\n";




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