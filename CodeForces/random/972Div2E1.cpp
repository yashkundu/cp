/**
*    author:  lazyhash(yashkundu)
*    created: 18 Sep, 2024 | 13:24:52
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

int l, n, m;

vector<int> a;
vector<vector<int>> b;

vector<vector<vector<bool>>> dp;
vector<vector<int>> states;
 
void solve() {
    cin >> l >> n >> m;
    a.resize(l);
    b.resize(n);
    for(int i=0;i<n;i++) b[i].resize(m);

    for(int i=0;i<l;i++) cin >> a[i];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> b[i][j];

    dp.resize(2);
    dp[0].resize(n+1), dp[1].resize(n+1);
    for(int k=0;k<2;k++) for(int i=0;i<=n;i++) dp[k][i].resize(m+1);


    for(int k=0;k<2;k++) for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) dp[k][i][j] = 0;
    states.resize(n+1);
    for(int i=0;i<=n;i++) states[i].resize(m+1);
    

    for(int k=l-1;k>=0;k--) {
        for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) states[i][j] = 127;
        int cur = k&1;
        int nxt = cur^1;
        for(int i=n;i>=0;i--) {
            for(int j=m;j>=0;j--) {
                // dp[k][i][j] -> winnig/losing state
                if(i<n && j<m) {
                    int el = b[i][j]-1;
                    if(!dp[nxt][i+1][j+1]) {
                        states[i][j] ^= (1<<el);
                    }
                    states[i][j] &= states[i+1][j];
                    states[i][j] &= states[i][j+1];
                }
                dp[cur][i][j] = !((states[i][j]>>(a[k]-1))&1);
            }
        }
    }

    cout << (dp[0][0][0]?"T":"N") << "\n";

    


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