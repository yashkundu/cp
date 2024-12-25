/**
*    author:  lazyhash(yashkundu)
*    created: 22 Jun, 2024 | 18:07:34
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


const int MAXN = 1e3+2;
const int MAXK = 10;

mi dp[MAXN][1<<MAXK];


int n, k;
string s;

// 1-a 0-b


bool isPalindrome(int mask, int ind) {
    if(ind<k-1) return false;
    int len = k-1;
    // 0 1 2 3 .. k-1
    for(int i=0;2*i<len;i++) {
        if(((mask>>i)&1)!=((mask>>(len-i))&1)) return false;
    }
    return true;
}

int normalize(int x) {
    x = x&((1<<k)-1);
    return x;
}





 
void solve() {
    cin >> n >> k;
    cin >>s;


    for(int i=0;i<=n;i++) for(int mask=0;mask<(1<<k);mask++) dp[i][mask] = 0;
    dp[0][0] = 1;


    int newMask = 0;
    for(int i=0;i<n;i++) {
        for(int mask=0;mask<(1<<k);mask++) {
            if(dp[i][mask]==0) continue;
            if(s[i]=='A' || s[i]=='?') {
                newMask = normalize((mask<<1) + 1);
                if(!isPalindrome(newMask, i)) {
                    dp[i+1][newMask] += dp[i][mask];
                }
            } 
            if(s[i]=='B' || s[i]=='?') {
                newMask = normalize((mask<<1));
                if(!isPalindrome(newMask, i)) {
                    dp[i+1][newMask] += dp[i][mask];
                }
            }
        }
    }

    mi ans = 0;
    for(int mask=0;mask<(1<<k);mask++) ans += dp[n][mask];

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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/