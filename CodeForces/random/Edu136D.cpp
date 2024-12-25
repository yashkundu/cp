/**
*    author:  lazyhash(yashkundu)
*    created: 24 Jul, 2024 | 17:11:11
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
 
const int MAXN = int(2e5)+10;

vector<int> g[MAXN];

int n, k;
int p;


int cnt = 0;

int dfs(int v, int lim) {
    int mx = 0;
    for(int u: g[v]) {
        int dep = dfs(u, lim);
        if(dep==lim-1 && v!=0) {
            cnt++;
            continue;
        }
        mx = max(mx, 1 + dep);
    }
    return mx;
}


bool check(int x) {
    cnt = 0;
    dfs(0, x);
    return cnt<=k;
}



void solve() {
    cin >> n >> k;

    for(int i=0;i<n;i++) g[i].clear();

    for(int i=1;i<n;i++) {
        cin >> p, p--;
        g[p].push_back(i);
    }

    int L = 0, R = n-1;
    while(R-L>1) {
        int mid = (L+R)/2;
        if(check(mid)) R = mid;
        else L = mid;
    }

    cout << R << "\n";




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