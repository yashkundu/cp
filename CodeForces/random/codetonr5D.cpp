/**
*    author:  lazyhash(yashkundu)
*    created: 13 Jul, 2024 | 11:13:11
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
 
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

const int MAXN = 105;
const int inf = int(1e9) + 1000;

vector<pair<int, int>> g[MAXN];
int dis[MAXN];
bool bad[MAXN];

int n, m;
int u, v, y;
 
set<pair<int, int>> st;

vector<pair<vector<int>, int>> ans;
vector<int> badVertices;

ll tot = 0;


void solve() {
    cin >> n >> m;

    fill(bad, bad+n, 0);
    fill(dis, dis+n, inf);

    for(int i=0;i<m;i++) {
        cin >> u >> v >> y;
        u--, v--;
        g[u].push_back({v, y});
        g[v].push_back({u, y});
    }


    st.insert({0, n-1});
    dis[n-1] = 0;


    while(!st.empty()) {
        auto [sm, v] = *st.begin();
        if(sm) {
            ans.push_back({vector<int>(), sm});
            tot += sm;
            for(int i=0;i<n;i++) if(!bad[i]) ans.back().first.push_back(i);
        }
        badVertices.clear();
        for(int u=0;u<n;u++) {
            if(dis[u]!=inf && !bad[u]) {
                st.erase({dis[u], u});
                dis[u] -= dis[v];
                if(dis[u]) st.insert({dis[u], u});
                else {
                    bad[u] = 1;
                    badVertices.push_back(u);
                }
            }
        }
        for(int u: badVertices) {
            for(auto [x, w]: g[u]) {
                if(!bad[x] && w<dis[x]) {
                    st.erase({dis[x], x});
                    dis[x] = w;
                    st.insert({dis[x], x});
                }
            }
        }
        if(bad[0]) break;
    }

    string s = "";
    for(int i=0;i<n;i++) s += "0";


    if(dis[0]==inf) {
        cout << "inf\n";
        return;
    }

    cout << tot << " " << ans.size() << "\n"; 

    for(auto p: ans) {
        string ts = s;
        for(auto x: p.first) ts[x] = '1';
        cout << ts << " " << p.second << "\n";
    }







    




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