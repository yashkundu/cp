/**
*    author:  lazyhash(yashkundu)
*    created: 23 Jun, 2024 | 16:29:05
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
const int mod = 998244353;
using mi=mint<mod>;

const int MAXN = 2e6+10;

mi fact[MAXN], invFact[MAXN];

void init() {
    fact[0] = 1;
    for(int i=1;i<MAXN;i++) fact[i] = fact[i-1]*i;

    invFact[MAXN-1] = inv(fact[MAXN-1]);
    for(int i=MAXN-2;i>=0;i--) invFact[i] = invFact[i+1]*(i+1);
}

mi C(int n, int r) {
    return fact[n]*invFact[n-r]*invFact[r];
}

mi ways(int n, int r) {
    return C(n+r-1, r-1);
}

int c[5];
 
void solve() {
    cin >> c[1] >> c[2] >> c[3] >> c[4];


    if(abs(c[1]-c[2])>1) {
        cout << "0\n";
        return;
    }

    if(c[1]==0 && c[2]==0) {
        if(c[3] && c[4]) {
            cout << "0\n";
        } else {
            cout << "1\n";
        }
        return;
    }
    

    mi ans = 0;
    if(c[1]==c[2]) {
        int r = c[1];
        ans = ways(c[3], r)*ways(c[4], r+1) + ways(c[3], r+1)*ways(c[4], r);
    } else {
        int r = max(c[1], c[2]);
        ans = ways(c[3], r)*ways(c[4], r);
    }

    cout << ans.v << "\n";
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
    init();
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