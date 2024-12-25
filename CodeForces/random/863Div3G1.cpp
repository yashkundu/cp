/**
*    author:  lazyhash(yashkundu)
*    created: 16 Jul, 2024 | 17:58:13
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
const int mod = int(1e9)+7;
using mi=mint<mod>;


const int MAXN = 105;

int n, k;
int c[MAXN];


mi dp[MAXN][MAXN];
mi C[MAXN][MAXN];


void init() {
    C[0][0] = 1;
    for(int i=1;i<MAXN;i++) C[0][i] = 0;

    for(int i=1;i<MAXN;i++) {
        C[i][0] = 1;
        for(int j=1;j<MAXN;j++) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
}

int cnt = 0;
mi ans = 0;
 
void solve() {
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> c[i];


    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dp[i][j] = 0;
    dp[0][0] = 1;


    for(int i=1;i<=n;i++) {
        for(int j=0;j<=n;j++) {
            dp[i][j] += dp[i-1][j];
            if(j==0) continue;
            cnt = 0;
            if(k==1) {
                dp[i][j] += dp[i-1][j-1];
                continue;
            }
            for(int ind=i;ind>0;ind--) {
                if(c[ind]==c[i]) {
                    cnt++;
                    if(cnt>=k) {
                        dp[i][j] += dp[ind-1][j-1]*C[cnt-2][k-2];
                    }
                }
            }
        }
    }

    for(int i=n;i>=0;i--) {
        if(dp[n][i]!=0) {
            ans = dp[n][i];
            break;
        }
    }

    cout << ans << "\n";

    
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