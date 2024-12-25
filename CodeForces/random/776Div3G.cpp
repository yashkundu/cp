/**
*    author:  lazyhash(yashkundu)
*    created: 25 Sep, 2024 | 22:52:21
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
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

const int mod = (int)1e9+7;
using mi=mint<mod>;

const int MAXN = (int)2e5+10;
vector<int> g[MAXN];

int dis[MAXN];
mi num1[MAXN], num2[MAXN];

int n, m;
int s, t;
int u, v;

 
void solve() {
    cin >> n >> m;
    cin >> s >> t;
    s--, t--;

    for(int i=0;i<n;i++) g[i].clear();

    for(int i=0;i<m;i++) {
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v), g[v].push_back(u);
    }

    for(int i=0;i<n;i++) {
        dis[i] = -1;
        num1[i] = num2[i] = 0;
    }

    vector<int> vec;
    vec.push_back(s);

    dis[s] = 0;
    num1[s] = 1;


    while(!vec.empty()) {
        for(int v: vec) {
            for(int u: g[v]) {
                if(dis[u]==dis[v]) {
                    num2[u] += num1[v];
                }
            }
        }

        vector<int> nvec;

        for(int v: vec) {
            for(int u: g[v]) {
                if(dis[u]==-1) {
                    dis[u] = 1 + dis[v];
                    nvec.push_back(u);
                    num1[u] += num1[v];
                    num2[u] += num2[v];
                } else if(dis[u]==1+dis[v]) {
                    num1[u] += num1[v];
                    num2[u] += num2[v];
                }
            }
        }
        swap(vec, nvec);
    }


    cout << num1[t] + num2[t] << "\n";



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