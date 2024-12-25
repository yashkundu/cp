/**
*    author:  lazyhash(yashkundu)
*    created: 14 Oct, 2024 | 20:42:02
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

const int MAXN = 5005;

int dp[MAXN][MAXN]={0};

int n, m;
vector<int> r;

vector<int> p1[MAXN], p2[MAXN];


int calcnum(int x, vector<int> &p) {
    return upper_bound(p.begin(), p.end(), x) - p.begin();
}

void maximize(int &x, int y) {
    x = max(x, y);
}

 
void solve() {
    cin >> n >> m;
    r.resize(n);

    for(int i=0;i<n;i++) {
        cin >> r[i];
    }


    int cnt = 0;

    for(int i=0;i<n;i++) {
        if(!r[i]) {
            cnt++;
            int j = i+1;
            while(j<n && r[j]) {
                if(r[j]>0) p1[cnt].push_back(r[j]);
                else p2[cnt].push_back(-r[j]);
                j++;
            }
        }
    }


    for(int i=0;i<MAXN;i++) {
        sort(p1[i].begin(), p1[i].end());
        sort(p2[i].begin(), p2[i].end());
    }

    // debug(p1[1], p1[2], p1[3], p1[4], p1[5]);
    // debug(p2[1], p2[2], p2[3], p2[4], p2[5]);

    // debug(calcnum(1, p1[1]));


    for(int i=1;i<=m;i++) {
        for(int j=0;j<=i;j++) {
            int x1 = calcnum(j, p1[i]), x2 = calcnum(i-j, p2[i]);
            if(j) maximize(dp[i][j], dp[i-1][j-1] + x1+x2);
            if(i-j) maximize(dp[i][j], dp[i-1][j]+x1+x2);
        }
    }

    // debug(dp[1][1], dp[2][2]);

    int ans = 0;

    for(int i=0;i<=m;i++) maximize(ans, dp[m][i]);

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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/