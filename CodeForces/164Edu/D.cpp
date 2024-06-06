/**
*   author: lazyhash(yashkundu)
*   created: 12 Apr, 2024 | 20:46:59
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
const int mod = 998244353;
using mi=mint<mod>;

const int N = 5000+10;
mi dp[N][N];
int a[N];
 
int n;

void solve() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a, a+n);

    for(int i=0;i<N;i++) for(int j=0;j<N;j++) dp[i][j] = 0;


    dp[0][0] = 1;

    mi ans = 0;

    for(int i=0;i<n;i++) {
        // a[i] is the max
        for(int sum=0;sum<a[i];sum++) {
            ans += dp[i][sum]*a[i];
        } 
        for(int sum=a[i];sum<N;sum++) {
            ans += dp[i][sum]*((sum+a[i]+1)/2);
        }
        for(int j=0;j<N;j++) {
            // don't take a[i]
            dp[i+1][j] += dp[i][j];
            // take a[i]
            if(j+a[i]<N) 
                dp[i+1][j+a[i]] += dp[i][j];

        }
    }

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