/**
*   author: lazyhash(yashkundu)
*   created: 01 Mar, 2024 | 09:28:01
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
const int mod = 1e9+7;
using mi=mint<mod>;
 
const int N = 1e6+10;
mi fact[N], invFact[N], p3[N];


void precompute() {
    fact[0] = 1;
    for(int i=1;i<N;i++) fact[i] = fact[i-1]*i;

    invFact[N-1] = inv(fact[N-1]);
    for(int i=N-2;i>=0;i--) invFact[i] = invFact[i+1]*(i+1);


    p3[0] = 1;
    for(int i=1;i<N;i++) p3[i] = p3[i-1]*3;
}

mi nCr(int n, int r) {
    if(n<0 || r<0 || n<r) return 0;
    return fact[n]*invFact[n-r]*invFact[r];
}


void solve() {
    int n, k;
    cin >> n >> k;

    // check if k==0, return 3^n
    if(!k) {
        mi ans = 1;
        cout << p3[n].v << "\n";
        return;
    }

    mi ans = 0;
    // iterating over the number of carry subsegments
    for(int num=1;num<=k;num++) {
        if(k+num-1>n) break;
        // case-1 first carry segment will start from the beginning
        // c1 * 0c2 * 0c3 * 0c4 * 0c5 * 0c6 *
        ans += (nCr(k-1, num-1))*(nCr(n-k, num-1))*(p3[k-num])*(p3[n-k-num+1]);

        // case-3 first carry segment will not start from the beginning
        // 0c1 * 0c2 * 0c3 * 0c4 * 0c5 * 0c6 *
        if(k+num>n) break;
        ans += (nCr(k-1, num-1))*(nCr(n-k, num))*(p3[k-num])*(p3[n-k-num]);
    }

    cout << ans.v << "\n";


}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
    precompute();
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