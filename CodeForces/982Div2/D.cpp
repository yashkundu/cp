/**
*    author:  lazyhash(yashkundu)
*    created: 27 Oct, 2024 | 09:35:35
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
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
const int mod = (int)1e9+7;
using mi=mint<mod>;

const ll inf = (ll)1e18+100;


struct SegTree{
    int n;
    vector<pair<ll, mi>> t;
    SegTree(int n) {
        this->n = n;
        t.resize(4*n);
        for(int i=0;i<4*n;i++) t[i] = {inf, 0};
    }
    pair<ll, mi> merge(pair<ll, mi> p1, pair<ll, mi> p2) {
        if(p1.first<p2.first) return p1;
        if(p2.first<p1.first) return p2;
        return {p1.first, p1.second+p2.second};
    }

    pair<ll, mi> query(int v, int tl, int tr, int l, int r) {
        if(l>r) return {inf, 0};
        if(l==tl && r==tr) return t[v];
        int tm = (tl+tr)/2;
        return merge(query(2*v, tl, tm, l, min(r, tm)), query(2*v+1, tm+1, tr, max(tm+1, l), r));
    }

    pair<ll, mi> query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    pair<ll, mi> get(int pos) {
        return query(pos, pos);
    }

    void update(int v, int tl, int tr, int pos, pair<ll,mi> val) {
        if(tl==tr) {
            t[v] = merge(t[v], val);
            return;
        }
        int tm = (tl+tr)/2;
        if(pos<=tm) update(2*v, tl, tm, pos, val);
        else update(2*v+1, tm+1, tr, pos, val);
        t[v] = merge(t[2*v], t[2*v+1]);
    }

    void update(int pos, pair<ll, mi> val) {
        update(1, 0, n-1, pos, val);
    }

};


int n, m;
vector<ll> a, b;

 
void solve() {
    cin >> n >> m;
    a.resize(n+1);
    b.resize(m+1);

    a[0] = 0;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=m;i++) cin >> b[i];

    for(int i=1;i<=n;i++) a[i] += a[i-1];


    vector<SegTree> dp;
    for(int i=0;i<=m;i++) dp.push_back(SegTree(n+1));



    dp[0].update(0, {0, 1});



    for(int i=0;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            // dp[i][j]
            dp[j].update(i, dp[j-1].get(i));
            
            int ind = lower_bound(a.begin(), a.end(), a[i] - b[j]) - a.begin();
            // debug(i, j, ind);
            auto p = dp[j].query(ind, i-1);
            // debug(p.first, p.second.v);
            p.first += (m-j);
            dp[j].update(i, p);
        }
    }

    auto x = dp[1].get(1);

    // debug(x.first, x.second.v);

    auto p = dp[m].get(n);

    if(p.first==inf) {
        cout << "-1\n";
        return;
    }

    cout << p.first << " " << p.second << "\n";


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