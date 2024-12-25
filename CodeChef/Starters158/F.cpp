/**
*    author:  lazyhash(yashkundu)
*    created: 01 Nov, 2024 | 15:00:41
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


const int MAXN = 5005;

mi fact[MAXN], invfact[MAXN];

void init() {
    fact[0] = 1;
    for(int i=1;i<MAXN;i++) fact[i] = fact[i-1]*i;
    invfact[MAXN-1] = inv(fact[MAXN-1]);
    for(int i=MAXN-2;i>=0;i--) invfact[i] = invfact[i+1]*(i+1);
}


mi C(int n, int r) {
    if(r>n) return 0;
    return fact[n]*invfact[n-r]*invfact[r];
}

mi lC(int k, int r) {
    mi ans = 1;
    for(int i=0;i<r;i++) ans *= k--;
    ans *= invfact[r];
    return ans;
}


int n, m, k;

mi f(int n, int d) {
    mi ans = 0;
    for(int i=0;i<d;i++) {
        mi trm = C(d, i)*pow(mi(d-i), n);
        if(i&1) ans -= trm;
        else ans += trm;
    }
    return ans;
}


 
void solve() {
    cin >> n >> m >> k;


    mi ans = 0;
    mi psum = 0;

    for(int d=1;d<=min(n, k);d++) {
        psum += pow(mi(d), m);
        ans += (f(n, d)*psum*lC(k, d)*n)/d;
    }

    cout << ans << "\n";

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