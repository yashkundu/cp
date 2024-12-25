/**
*    author:  lazyhash(yashkundu)
*    created: 13 Jun, 2024 | 18:51:13
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

const int N = 2e5+10;
mi p2[N];

void precompute() {
    p2[0] = 1;
    for(int i=1;i<N;i++) p2[i] = p2[i-1]*2;
}

int n;
ll a[N];
ll sum = 0;
ll mnSum = 0;
int pos = 0;
 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    sum = 0;
    mnSum = 0;
    for(int i=0;i<n;i++) {
        sum += a[i];
        mnSum = min(mnSum, sum);
    }

    if(mnSum==0) {
        cout << p2[n] << "\n";
        return;
    }

    sum = 0;
    pos = 0;

    mi ans = 0;

    for(int i=0;i<n;i++) {
        sum += a[i];
        if(sum==mnSum) {
            ans += p2[n-i-1+pos];
        }   
        if(sum>=0) pos++;
    }

    cout << ans.v << "\n";



}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
    precompute();
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