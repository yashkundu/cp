/**
*   author: lazyhash(yashkundu)
*   created: 31 Dec, 2023 | 10:28:11
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <numeric>
 
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
vector<int> g[N];
bool els[N], nodes[N];
int n;


bool dfs(int v, int start) {
    if(nodes[v]) return true;
    if(v<start) return false;
    for(int x=v;x<=n;x+=v) els[x] ^= 1;
    nodes[v] = true;
    for(int u: g[v]) {
        bool res = dfs(u, start);
        if(!res) return res;
    }
    return true;
}

 
void solve() {
    int m;
    cin >> n >> m;

    for(int i=1;i<=n;i++) g[i].clear();
    fill(els, els+n+1, 0);
    fill(nodes, nodes+n+1, 0);


    for(int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    if(n>=20) {
        cout << n << "\n";
        for(int i=1;i<=n;i++) cout << i << " ";
        cout << "\n";
        return;
    }

    vector<vector<int>> cmbs;
    if(n/5>=1) for(int i=1;i<=n;i++) cmbs.push_back({i});
    if(n/5>=2) for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) cmbs.push_back({i, j});
    if(n/5>=3) for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) cmbs.push_back({i, j, k});


    auto isInCmb = [](vector<int> &cmb, int x) {
        for(int &y: cmb) if(y==x) return true;
        return false;
    };


    for(vector<int> cmb: cmbs) {
        // checking if a particular combination is achievable
        fill(els, els+n+1, 0);
        fill(nodes, nodes+n+1, 0);
        bool isGood = true;
        for(int i=1;i<=n;i++) {
            if(els[i]!=isInCmb(cmb, i)) {
                // mismatch need to select it
                bool res = dfs(i, i);
                if(!res || els[i]!=isInCmb(cmb, i)) {
                    isGood = false;
                    break;
                }
            }
        }
        if(isGood) {
            int cnt = accumulate(nodes+1, nodes+n+1, 0);
            cout << cnt << "\n";
            for(int i=1;i<=n;i++) if(nodes[i]) cout << i << " ";
            cout << "\n";
            return;
        }
    }

    cout << "-1\n";




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