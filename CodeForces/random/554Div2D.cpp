/**
*   author: lazyhash(yashkundu)
*   created: 02 Apr, 2024 | 09:20:00
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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif






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

const int N = 2000 + 5;
mi dp[N][N][2];


 
void solve() {
    int n;
    cin >> n;

    n *= 2;

    for(int i=0;i<=n;i++) for(int j=0;j<=n+2;j++) dp[i][j][0] = dp[i][j][1] = -1;
    dp[n][1][0] = dp[n][1][1] = 0;

    for(int i=n-1;i>=0;i--) {
        for(int j=1;j<=n+1;j++) {
            // j = bal + 1
            if(dp[i+1][j-1][0]==-1 && dp[i+1][j+1][0]==-1) continue;
            else if(dp[i+1][j-1][0]==-1) {
                // right side is valid
                dp[i][j][0] = max(dp[i+1][j+1][0], dp[i+1][j+1][1]);
                dp[i][j][1] = 1 + dp[i+1][j+1][0];
            } 
            else if(dp[i+1][j+1][0]==-1) {
                dp[i][j][0] = max(dp[i+1][j-1][0], dp[i+1][j-1][1]);
                dp[i][j][1] = 1 + dp[i+1][j-1][0];
            } else {
                dp[i][j][0] = max(dp[i+1][j-1][0], dp[i+1][j-1][1]) + max(dp[i+1][j+1][0], dp[i+1][j+1][1]);
                dp[i][j][1] = max(1 + dp[i+1][j-1][0] + max(dp[i+1][j+1][0], dp[i+1][j+1][1]), 1 + dp[i+1][j+1][0] + max(dp[i+1][j-1][0], dp[i+1][j-1][1]));
            }
        }
    }


    cout << max(dp[0][1][0], dp[0][1][1]).v << "\n";

    
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