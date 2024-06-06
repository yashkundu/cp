/**
*   author: lazyhash(yashkundu)
*   created: 16 May, 2024 | 08:48:36
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <numeric>
#include <map>
#include <assert.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
const int mod = 1e9+7;
using mi=mint<mod>;



struct UnionFind{
    int n;
    vector<int> par, rank;
    UnionFind(int n) {
        this->n = n;
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        rank.assign(n, 0);
    }
    int find(int v) {
        if(par[v]==v) return v;
        return par[v] = find(par[v]);
    }
    bool merge(int a, int b) {
        a = find(a);
        b = find(b);
        if(a==b) return false;
        if(rank[a]>rank[b]) swap(a, b);
        par[a] = b;
        if(rank[a]==rank[b]) rank[b]++;
        return true;
    }
};

 

const int N = 5e5+10;
ll c[N];

int n, m, k;

 
map<int, vector<pair<int, int>>> mp;



void solve() {
    cin >> n >> m >> k;
    for(int i=0;i<n;i++) {
        cin >> c[i];
    }

    UnionFind dsu(n);

    for(int i=0;i<m;i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        ll xVal = c[x]^c[y];
        if(mp.find(xVal)==mp.end()) mp[xVal] = vector<pair<int, int>>();
        mp[xVal].push_back({x, y});
    }

    ll tot =  (1LL<<k);
    mi ans = 0;

    for(auto it=mp.begin(); it!=mp.end(); it++) {
        int cnt = n;
        for(auto p: it->second) {
            if(dsu.merge(p.first, p.second)) cnt--;
        }
        ans += pow(mi(2), cnt);
        for(auto p: it->second) {
            dsu.rank[p.first] = dsu.rank[p.second] = 0;
            dsu.par[p.first] = p.first;
            dsu.par[p.second] = p.second;
        }
    }

    ans += pow(mi(2), n)*(tot-mp.size());

    cout << ans.v << "\n";
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