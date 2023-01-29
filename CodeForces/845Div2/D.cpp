/**
*    author:  lazyhash(yashkundu)
*    created: 22 Jan, 2023 | 22:42:47
**/
#include <iostream>
#include <vector>
#include <assert.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

const int mod = 1e9+7;

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

using mi=mint<mod>;

const int N = 2e5+10;
vector<int> g[N];
vector<int> dep(N, 0);


void dfs(int v, int p) {
    int mx = 0;
    for(int u: g[v]) {
        if(u==p) continue;
        dfs(u, v);
        mx = max(mx, dep[u]);
    }
    dep[v] = mx + 1;
}
 
void solve() {
    int n;
    cin >> n;

    for(int i=0;i<n;i++) g[i].clear();
    fill(dep.begin(), dep.begin()+n, 0);

    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v), g[v].push_back(u);
    }

    dfs(0, -1);
    mi ans = 0;
    for(int i=0;i<n;i++) ans += dep[i];
    ans *= pow(mi(2), n-1);
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