/**
*    author:  lazyhash(yashkundu)
*    created: 19 Jul, 2024 | 00:13:02
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

int n;
int a[MAXN];
bool good[MAXN], vis[MAXN];
int num[MAXN];

ll ans = 0;


vector<int> g[MAXN];

void dfs(int ind) {
    vis[ind] = 1;
    int nind = ind + a[ind];
    if(nind>=n || nind<0) {
        good[ind] = true;
        return;
    } else {
        if(!vis[nind]) dfs(nind);
        good[ind] = good[nind];
    }
}


void dfs2(int v) {
    int c = 1;
    for(int u: g[v]) {
        dfs2(u);
        c += num[u];
    }
    num[v] = c;
}


void solve() {
    cin >> n;
    for(int i=0;i<n;i++) g[i].clear();

    for(int i=0;i<n;i++) {
        cin >> a[i];
        if(i+a[i]<n && i+a[i]>=0) g[i+a[i]].push_back(i);
    }


    fill(good, good+n, 0);
    fill(vis, vis+n, 0);

    for(int i=0;i<n;i++) if(!vis[i]) dfs(i);

    int cntgood = 0;
    for(int i=0;i<n;i++) if(good[i]) cntgood++;

    ans = 0;
    if(!good[0]) {
        fill(vis, vis+n, 0);
        int ind = 0;
        while(!vis[ind]) {
            ans += (cntgood+n+1);
            vis[ind] = 1;
            ind += a[ind];
        }
    } else {
        int top = 0;
        while(top+a[top]<n && top+a[top]>=0) {
            top += a[top];
        }
        fill(num, num+n, 0);
        dfs2(top);
        int ind = 0;
        int cnt = 1;
        ans += (cntgood - num[0]+n+1);
        while(ind+a[ind]<n && ind+a[ind]>=0) {
            ind += a[ind];
            cnt++;
            ans += cntgood - num[ind] + n + 1;
        }
        ans += 1LL*(n-cnt)*(2*n+1);
    }

    cout << ans << "\n";
    
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