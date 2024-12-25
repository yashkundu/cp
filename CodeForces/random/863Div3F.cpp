/**
*    author:  lazyhash(yashkundu)
*    created: 16 Jul, 2024 | 19:10:45
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
vector<int> tg[MAXN];
int deg[MAXN];
int tdeg[MAXN];
bool vis[MAXN];
int u[MAXN], v[MAXN];


int n, m;

int cnt2 = 0, cnt4 = 0;

int dfs(int v) {
    int cnt = 1;
    vis[v] = 1;
    for(int u: g[v]) {
        if(vis[u]) continue;
        cnt += dfs(u);
    }
    return cnt;
}

int dfs2(int v) {
    int cnt = 1;
    vis[v] = 1;
    for(int u: tg[v]) {
        if(vis[u]) continue;
        cnt += dfs2(u);
    }
    return cnt;
}
 
void solve() {
    cin >> n >> m;
    for(int i=0;i<n;i++) g[i].clear();

    fill(deg, deg+n, 0);
    for(int i=0;i<m;i++) {
        cin >> u[i] >> v[i];
        u[i]--, v[i]--;
        deg[u[i]]++;
        deg[v[i]]++;
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }

    cnt2 = cnt4 = 0;
    for(int i=0;i<n;i++) {
        if(deg[i]!=2 && deg[i]!=4) {
            cout << "NO\n";
            return;
        }
        if(deg[i]==2) cnt2++;
        else cnt4++;
    }


    if(cnt4<3) {
        cout << "NO\n";
        return;
    }

    if(n!=cnt4 + 1LL*cnt4*(cnt4-1)) {
        cout << "NO\n";
        return;
    }

    for(int i=0;i<n;i++) tg[i].clear();

    fill(tdeg, tdeg+n, 0);
    for(int i=0;i<m;i++) {
        if(deg[u[i]]==4 && deg[v[i]]==4) {
            tg[u[i]].push_back(v[i]);
            tg[v[i]].push_back(u[i]);
            tdeg[u[i]]++;
            tdeg[v[i]]++;
        }
    }


    int ver = -1;

    for(int i=0;i<n;i++) {
        if(deg[i]==2) continue;
        ver = i;
        if(tdeg[i]!=2) {
            cout << "NO\n";
            return;
        }
    }

    fill(vis, vis+n, 0);
    int num = dfs2(ver);
    if(num!=cnt4) {
        cout << "NO\n";
        return;
    }

 


    for(int i=0;i<n;i++) {
        if(deg[i]==4) {
            if(dfs(i)!=cnt4) {
                cout << "NO\n"; 
                return;
            }
        } 
    }

    cout << "YES\n";


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