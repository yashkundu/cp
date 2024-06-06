/**
*   author: lazyhash(yashkundu)
*   created: 08 May, 2024 | 09:37:08
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


const int N = 2000+5;


mi dp[N][2*N];
int h[N];
 
int n, k;

void solve() {
    cin >> n >> k;
    for(int i=0;i<N;i++) for(int j=0;j<2*N;j++) dp[i][j] = 0;


    for(int i=0;i<n;i++) cin >> h[i];

    dp[0][N] = 1;


    for(int i=0;i<n;i++) {
        for(int bal=0;bal<2*N;bal++) {
            if(dp[i][bal]==0) continue;
            // none of the above 2
            int mul = k;
            if(h[i]==h[(i+1)%n]) mul--;
            else mul -= 2;
            dp[i+1][bal] += dp[i][bal]*mul;

            if(h[i]==h[(i+1)%n]) {
                dp[i+1][bal] += dp[i][bal];
            } else {
                if(bal<2*N) dp[i+1][bal+1] += dp[i][bal];
                if(bal) dp[i+1][bal-1] += dp[i][bal];
            }
        }
    }

    mi ans = 0;
    for(int i=N+1;i<2*N;i++) ans += dp[n][i];

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