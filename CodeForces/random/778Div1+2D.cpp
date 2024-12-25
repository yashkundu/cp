/**
*    author:  lazyhash(yashkundu)
*    created: 24 Sep, 2024 | 23:17:27
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
#include <assert.h>
 
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

template<int MOD> struct mint {
    static const int mod = MOD;
    int v;
    explicit operator int() const {return v;}
    mint(): v(0) {}
    mint(ll _v) {
        v = int((_v > -MOD && _v < MOD)?_v:_v%MOD);
        if(v<0) v += MOD;
    }
    bool operator==(const mint& o) const{ return (v==o.v);}
    friend bool operator!=(const mint& a, const mint& b) {return !(a==b);}
    friend bool operator<(const mint& a, const mint& b) {return a.v<b.v;}
    friend bool operator>(const mint& a, const mint& b) {return a.v>b.v;}
    friend bool operator<=(const mint& a, const mint& b) {return a.v<=b.v;}
    friend bool operator>=(const mint& a, const mint& b) {return a.v>=b.v;}

    friend mint operator+(mint a, const mint& b) {return a += b;}
    friend mint operator-(mint a, const mint& b) {return a -= b;}
    friend mint operator*(mint a, const mint& b) {return a *= b;}
    friend mint operator/(mint a, const mint& b) {return a /= b;}

    mint& operator+=(const mint& o) {if((v+=o.v)>=MOD) v -= MOD; return *this;}
    mint& operator-=(const mint& o) {if((v-=o.v)<0) v += MOD; return *this;}
    mint& operator*=(const mint& o) {v = int((ll)v*o.v%MOD); return *this;}
    mint& operator/=(const mint& o) {return (*this) *= inv(o);}

    friend mint pow(mint a, ll n) {
        mint res = 1; assert(n>=0);
        for(;n;n/=2, a*=a) if(n&1) res *= a;
        return res;
    }
    friend mint inv(mint a) {return pow(a, MOD-2);}

    mint operator-() {return mint(-v);}
    mint& operator++() {return *this += 1;}
    mint& operator--() {return *this -= 1;}

    friend istream& operator>>(istream& in, const mint& o) {
        ll x; in >> x; o.v = int(mint(x)); return in;
    }
    friend ostream& operator<<(ostream& out, const mint& o) {
        out << o.v; return out;
    }
};
const int mod = 998244353;
using mi=mint<mod>;

const int MAXN = (int)2e5+10;

int spf[MAXN];
vector<int> pfactors[MAXN];

int f[MAXN] = {0}, wf[MAXN] = {0};
vector<pair<int, pair<int, int>>> g[MAXN];



void init() {
    for(int i=1;i<MAXN;i++) spf[i] = i;
    for(int i=2;i*i<MAXN;i++) {
        for(int j=i*i;j<MAXN;j+=i) if(spf[j]==j) spf[j] = i;
    }

    for(int i=2;i<MAXN;i++) {
        for(int x=i;x!=1;x/=spf[x]) {
            pfactors[i].push_back(spf[x]);
        }
    }

}

int n;
int u, v, x, y;

set<int> dprimes;


void dfs(int v, int p = -1) {
    for(auto pr: g[v]) {
        int u = pr.first, x = pr.second.first, y = pr.second.second;
        if(u==p) continue;
        for(int factor: pfactors[y]) f[factor]--;
        for(int factor: pfactors[x]) f[factor]++;
        for(int factor: pfactors[x]) wf[factor] = max(wf[factor], f[factor]);
        dfs(u, v);
        for(int factor: pfactors[y]) f[factor]++;
        for(int factor: pfactors[x]) f[factor]--;

    }
}


mi ans = 0;


void dfs2(int v, int p, mi val) {
    ans += val;
    mi tmp = val;
    for(auto pr: g[v]) {
        int u = pr.first, x = pr.second.first, y = pr.second.second;
        if(u==p) continue;
        val = tmp;
        for(int factor: pfactors[y]) val *= factor;
        for(int factor: pfactors[x]) val /= factor;
        dfs2(u, v, val);
    }
}




 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) g[i].clear();


    dprimes.clear();

    for(int i=0;i<n-1;i++) {
        cin >> u >> v >> x >> y;
        u--, v--;
        g[u].push_back({v, {x, y}});
        g[v].push_back({u, {y, x}});
        for(int factor: pfactors[x]) dprimes.insert(factor);
        for(int factor: pfactors[y]) dprimes.insert(factor);
    }


    dfs(0, -1);

    mi p = 1;
    for(int x: dprimes) for(int i=0;i<wf[x];i++) p *= x;

    ans = 0;
    dfs2(0, -1, p);

    cout << ans << "\n";

    for(int x: dprimes) f[x] = wf[x] = 0;

}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    init();
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