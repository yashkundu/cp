/**
*    author:  lazyhash(yashkundu)
*    created: 06 Sep, 2024 | 21:11:33
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



ll fb, fc, db, dc, nb, nc;


ll lcm(ll a, ll b) {
    return a/__gcd(a, b)*b;
}


bool check(ll x) {
    ll n = (x-fb)/db + 1;
    if(n>=1 && n<=nb && fb + (n-1)*db==x) return true;
    return false;
}

 
void solve() {
    cin >> fb >> db >> nb;
    cin >> fc >> dc >> nc;


    if(dc%db) {
        cout << "0\n";
        return;
    }

    if(!check(fc) || !check(fc+(nc-1)*dc)) {
        cout << "0\n";
        return;
    }

    if(!check(fc-dc) || !check(fc+nc*dc)) {
        cout << "-1\n";
        return;
    }


    mi ans = 0;

    for(ll i=1;i*i<=dc;i++) {
        if(dc%i) continue;
        if(lcm(i, db)==dc) {
            ll x = i;
            ans += (dc/x)*(dc/x);
        }
        if(i!=dc/i && lcm(dc/i, db)==dc) {
            ll x = dc/i;
            ans += (dc/x)*(dc/x);
        }
        
    }

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