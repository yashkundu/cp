/**
*   author: lazyhash(yashkundu)
*   created: 19 May, 2023 | 08:32:20
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

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

const int N = 2e5+100;
const ll mod = 1e9+7; 

ll totWays = 0;


ll add(ll a, ll b) {
    a += b;
    if(a>=mod) a -= mod;
    return a;
}

ll mul(ll a, ll b) {
    return (a*b)%mod;
}

ll bExp(ll a, ll n) {
    ll res = 1;
    while(n) {
        if(n&1) res = mul(res, a);
        a = mul(a, a);
        n = n>>1;
    }
    return res;
}


vector<ll> fact(N), invFact(N);

vector<int> g[N];
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


void preprocess(){
    fact[0] = 1LL;
    for(int i=1;i<N;i++) fact[i] = mul(fact[i-1], i);
    invFact[N-1] = bExp(fact[N-1], mod-2);
    for(int i=N-2;i>=0;i--) invFact[i] = mul(invFact[i+1], i+1);
}


ll nCr(int n, int r) {
    if(n<r) return 0;
    return mul(fact[n], mul(invFact[n-r], invFact[r]));
}


int n, k;

// returns the number of nodes in the subtree with root v.
// then do the calculation
int dfs(int v, int p=-1) {
    int nodeCnt = 1;
    for(int u: g[v]) {
        if(u==p) continue;
        int curCnt = dfs(u, v);
        totWays = add(totWays, mul(nCr(curCnt, k/2), nCr(n-curCnt, k/2)));
        nodeCnt += curCnt;
    }
    return nodeCnt;
}
 
void solve() {
    preprocess();
    cin >> n >> k;
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }



    if(k&1) {
        cout << "1\n";
        return;
    }

    dfs(0);
    ll ans = mul(add(totWays, nCr(n, k)), bExp(nCr(n, k), mod-2));
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/