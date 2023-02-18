/**
*    author:  lazyhash(yashkundu)
*    created: 04 Feb, 2023 | 21:34:35
**/
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const int N = 301;
const int A = 180005;
const int mod = 998244353;

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

vector<vector<mi>> dp(N, vector<mi>(A, 0));
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1, 0);
    for(int i=1;i<=n;i++) cin >> a[i];

    for(int i=1;i<=n;i++) a[i] += a[i-1];
    dp[1][a[1]] = 1;

    for(int i=1;i<n-1;i++) {
        for(int j=0;j<A;j++) {
            if(dp[i][j]==0) continue;
            // j at i'th term 
            // j p[i+1]
            if(a[i+1]==j) dp[i+1][j] += dp[i][j];
            else {
                int del = a[i+1] - j;
                assert(a[i+1]+del>=0);
                assert(a[i+1]-del>=0);
                dp[i+1][a[i+1]+del] += dp[i][j];
                dp[i+1][a[i+1]-del] += dp[i][j];
            } 
        }
    }

    mi ans = 0;
    for(int i=0;i<A;i++) ans += dp[n-1][i];
    cout << ans << "\n";

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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/