/**
*   author: lazyhash(yashkundu)
*   created: 05 Mar, 2023 | 00:06:42
**/
#include <iostream>
#include <vector>
#include <assert.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;


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

const int N = 4400;
const int A = 1e6+1000;
vector<mi> fact(N, 0), invFact(N, 0);
vector<bool> isPrime(A, 1);
vector<int> cnt(A, 0);
vector<vector<mi>> dp(N, vector<mi>(N, 0));

void precalc() {
    fact[0] = 1;
    for(int i=1;i<N;i++) fact[i] = fact[i-1]*i;
    invFact[N-1] = inv(fact[N-1]);
    for(int i=N-2;i>=0;i--) invFact[i] = invFact[i+1]*(i+1);


    isPrime[1] = false;
    for(int i=2;i*i<A;i++) {
        if(!isPrime[i]) continue;
        for(int j=i*i;j<A;j+=i) isPrime[j] = false;
    }

}

 
 
void solve() {
    int n;
    cin >> n;

    for(int i=0;i<2*n;i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    vector<int> primes;
    for(int i=1;i<A;i++) {
        if(isPrime[i] && cnt[i]) primes.push_back(cnt[i]);
    }


    if(primes.size()<n) {
        cout << "0\n";
        return;
    }

    int m = primes.size();


    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            dp[i][j] = dp[i-1][j] + primes[i-1]*(j==1?1:dp[i-1][j-1]);

        }
    }


    mi ans = dp[m][n];
    ans *= fact[n];
    for(int i=1;i<A;i++) if(cnt[i]) ans *= invFact[cnt[i]];


    cout << ans << "\n";


    
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;    
    precalc();
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