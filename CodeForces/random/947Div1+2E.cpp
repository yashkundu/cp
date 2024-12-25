/**
*    author:  lazyhash(yashkundu)
*    created: 14 Jun, 2024 | 19:02:10
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

const int N = 2e5+10;
vector<int> g[N];
bool col[N];
int par[N];

int num[N];
int cnt[4];

int whiteParCnt = 0;

int n, q;
int x, y;
int u;


int xor2 = 0;
int tot_black = 0;


void dfs(int v, int p) {
    par[v] = p;
    int sum = 0;
    for(int u: g[v]) {
        if(u==p) continue;
        dfs(u, v);
        if(col[u]) sum++;
    }
    num[v] = sum;
}

void decBlackNumVal(int v) {
    if(num[v]>=3) cnt[3]--;
    else cnt[num[v]]--;
}

void incBlackNumVal(int v) {
    if(num[v]>=3) cnt[3]++;
    else cnt[num[v]]++;
}

 
void solve() {
    cin >> n >> q;
    for(int i=0;i<=n;i++) g[i].clear();
    for(int i=0;i<=n;i++) num[i] = 0;
    for(int i=0;i<4;i++) cnt[i] = 0;

    whiteParCnt = 0;

    col[0] = 0;
    for(int i=1;i<=n;i++) {
        int c;
        cin >> c;
        col[i] = (c==1);
    }

    for(int i=0;i<n-1;i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    g[0].push_back(1);
    g[1].push_back(0);

    dfs(0, -1);

    for(int i=1;i<=n;i++) {
        if(!col[i]) continue;
        tot_black++;
        if(!col[par[i]]) whiteParCnt++;
        if(num[i]==2) xor2 ^= i;
        if(num[i]>=3) cnt[3]++;
        else cnt[num[i]]++;
    }

    // debug(tot_black, whiteParCnt, cnt[0], cnt[1], cnt[2], cnt[3]);
    // debug(xor2);



    while(q--) {
        cin >> u;
        if(col[u]) {
            tot_black--;
            if(num[u]==2) xor2 ^= u;
            if(col[par[u]]) decBlackNumVal(par[u]);
            decBlackNumVal(u);
            if(!col[par[u]]) whiteParCnt--;
            whiteParCnt += num[u];
            col[u] = 0;
            if(num[par[u]]==2) xor2 ^= par[u];
            num[par[u]]--;
            if(num[par[u]]==2) xor2 ^= par[u];
            if(col[par[u]]) incBlackNumVal(par[u]);
        } else {
            tot_black++;
            if(num[u]==2) xor2 ^= u;
            if(col[par[u]]) decBlackNumVal(par[u]);
            incBlackNumVal(u);
            if(!col[par[u]]) whiteParCnt++;
            whiteParCnt -= num[u];
            col[u] = 1;
            if(num[par[u]]==2) xor2 ^= par[u];
            num[par[u]]++;
            if(num[par[u]]==2) xor2 ^= par[u];
            if(col[par[u]]) incBlackNumVal(par[u]);
        }

        // debug(tot_black, whiteParCnt, cnt[0], cnt[1], cnt[2], cnt[3]);
        // debug(xor2);

        // check for chain
        if(!tot_black) {
            cout << "NO\n";
        }
        else if(cnt[3]) {
            cout << "NO\n";
        } else if(whiteParCnt!=1) {
            cout << "NO\n";
        } else if(cnt[2]>1){
            cout << "NO\n";
        } else if(cnt[2]==0) {
            cout << "YES\n";
        } else if(col[par[xor2]]) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }

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