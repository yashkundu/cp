/**
*   author: lazyhash(yashkundu)
*   created: 29 Feb, 2024 | 23:35:41
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

const int N = 105;
mi dp[N][N];
int a[N][N];
 
void solve() {
    int n;
    cin >> n;

    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j++) {
            cin >> a[i][j];
        }
    }

    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dp[i][j] = 0;
    dp[0][0] = 1;

    for(int i=0;i<n;i++) {
        for(int j=0;j<=i;j++) {
            // dp[i][j] - i len bString with a[j] != a[i]
            // i+1
            // put a[i+1] same as a[i]
            bool canBeSame = true;
            for(int k=1;k<=j;k++) if(a[k][i+1]==1) canBeSame = false;
            for(int k=j+1;k<=i+1;k++) if(a[k][i+1]==2) canBeSame = false;
            if(canBeSame) {
                dp[i+1][j] += dp[i][j];
            }

            // put a[i+1] same as a[j]
            bool canBeDifferent = true;
            for(int k=1;k<=j;k++) if(a[k][i+1]==1) canBeDifferent = false;
            for(int k=j+1;k<=i;k++) if(a[k][i+1]==1) canBeDifferent = false;
            if(a[i+1][i+1]==2) canBeDifferent = false;
            if(canBeDifferent) {
                dp[i+1][i] += dp[i][j];
            }
        }
    }

    mi ans = 0;
    for(int i=0;i<=n;i++) ans += dp[n][i];

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