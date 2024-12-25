/**
*    author:  lazyhash(yashkundu)
*    created: 11 Aug, 2024 | 13:57:37
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

const int MAXN = 1003;
bool a[MAXN][MAXN];
pair<int, int> range[MAXN][MAXN];

int n, m;
int x;
 
void solve() {
    cin >> n >> m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
        cin >> x;
        a[i][j] = (x==1);
    }

    if(n%2==m%2) {
        cout << "NO\n";
        return;
    }

    range[1][1] = {a[1][1], a[1][1]};

    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
        if(i+j==2) continue;
        auto up = range[i-1][j];
        auto left = range[i][j-1];
        pair<int, int> merged;
        if(i==1) merged = left;
        else if(j==1) merged = up;
        else merged = {min(up.first, left.first), max(up.second, left.second)};
        merged.first += a[i][j];
        merged.second += a[i][j];
        range[i][j] = merged;
    }

    int del = (n+m-1)/2;
    if(del>=range[n][m].first && del<=range[n][m].second) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }



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