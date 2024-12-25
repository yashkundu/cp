/**
*    author:  lazyhash(yashkundu)
*    created: 14 Jul, 2024 | 14:34:00
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

const int inf = int(1e9) + 1000;
const int MAXN = 502;


struct Ftree{
    vector<int> tree;
    int n;

    void init(int n) {
        this->n = n+1;
        tree.resize(n+2);
        fill(tree.begin(), tree.end(), inf);
    }

    void update(int ind, int val) {
        ind++;
        for(;ind<=n;ind+=ind&-ind) tree[ind] = min(tree[ind], val);
    }

    int query(int ind) {
        ind++;
        int res = inf;
        for(;ind>0;ind-=ind&-ind) res = min(res, tree[ind]);
        return res;
    }
};



int n;
int c[MAXN];
int dp[MAXN][MAXN];


vector<Ftree> ft;

void minimize(int &x, int y) {
    x = min(x, y);
}

 
void solve() {
    cin >> n;
    c[0] = 0;
    for(int i=1;i<=n;i++) cin >> c[i];
    c[n+1] = n+1;

    for(int i=0;i<=n+1;i++) for(int j=0;j<=n+1;j++) dp[i][j] = inf;
    dp[0][0] = 0;

    ft.resize(n+2);
    for(int i=0;i<=n+1;i++) ft[i].init(n);
    ft[0].update(0, 0);

    for(int i=1;i<=n+1;i++) {
        for(int j=0;j<=n+1;j++) {
            if(c[i-1]<c[i]) minimize(dp[i][j], dp[i-1][j]);
            if(j>0) minimize(dp[i][j], ft[j-1].query(c[i]-1) + i-1);
            if(dp[i][j]!=inf) ft[j].update(c[i], dp[i][j] - i);
        }
    }

    int ans = inf;


    for(int k=1;k<=n;k++) {
        ans = min(ans, dp[n+1][k]);
        cout << ans << " ";
    }
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/