/**
*   author: lazyhash(yashkundu)
*   created: 08 Mar, 2023 | 12:03:15
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

const int N = 1e4+10;
int tree[N][2] = {0};
vector<int> cnt(N, 0);

// dp[v][j][k] - the maximum no. of non-adjacent non-leaf vertices in subtree with root v, if we have selected j leaf vertices, and k tell if v is chosen as x or y
// 0 -> x | 1 -> y
int dp[N][N][2] = {0};


void update(int &x, int y) {
    x = max(x, y);
}


void dfs(int v) {
    if(!tree[v][0] && !tree[v][1]) {
        cnt[v] = 1; dp[v][0][0] = dp[v][1][1] = 0; return;
    }
    dfs(tree[v][0]), dfs(tree[v][1]);
    cnt[v] = cnt[tree[v][0]] + cnt[tree[v][1]];
    for(int l=0;l<=cnt[tree[v][0]];l++) {
        for(int r=0;r<=cnt[tree[v][1]];r++) {
            int yleft = dp[tree[v][0]][l][1], yright = dp[tree[v][1]][r][1];
            int xleft = dp[tree[v][0]][l][0], xright = dp[tree[v][1]][r][0];
            if(xleft!=-1 && xright!=-1) update(dp[v][l+r][1], xleft+xright+1);
            int mleft = max(yleft, xleft), mright = max(yright, xright);
            if(mleft!=-1 && mright!=-1) update(dp[v][l+r][0], mleft+mright);
        }
    }
}

 
void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    for(int i=1;i<=n;i++) tree[i][0] = tree[i][1] = 0;
    fill(cnt.begin(), cnt.begin()+n+1, 0);

    for(int i=0;i<n-1;i++) {
        int p;
        cin >> p;
        if(!tree[p][0]) tree[p][0] = i+2;
        else tree[p][1] = i+2;
    }

    if(c&1) {
        cout << "No\n";
        return;
    }

    for(int i=1;i<=n;i++) for(int j=0;j<=n;j++) dp[i][j][0] = dp[i][j][1] = -1;

    dfs(1);


    // 1 is y
    if(b+1-c/2>=0 && dp[1][b+1-c/2][1]>=c/2) cout << "Yes\n";
    // 1 is x
    else if(b-c/2>=0 && dp[1][b-c/2][0]>=c/2) cout << "Yes\n";
    else cout << "No\n";

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