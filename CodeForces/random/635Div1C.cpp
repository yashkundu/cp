/**
*   author: lazyhash(yashkundu)
*   created: 22 Feb, 2024 | 16:08:44
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

const int mod = 998244353;
using mi=mint<mod>;
 
const int N = 3e3+5;
// dp[i][j] the number of ways to choose last i characters of s, such that i choose j operations of the first type
mi dp[N][N];

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dp[i][j] = 0;


    // we can leave last few characters of s without any operation if if we make prefix t without it

    dp[0][0] = 1;
    for(int i=0;i<=n-m;i++) {
        // all of the taken i's have been ignored
        dp[i][0] = 1;
    }

    // lets perform all the operations and only count those which are good for us, i.e makes prefix of A to be t
    for(int i=0;i<n;i++) {
        // we have chosen last i characters of s
        for(int j=0;j<=i;j++) {
            if(!dp[i][j].v) continue;
            // for those last i characters we have performed j first operations
            // there are three options to do: 1) perform operation of type 1, 2) perform operation of type 2, 3) don't perform any operation, if no operation is performed
            // s[n-i-1]
            // do operation of type 1
            // debug(i, j);
            if(j >=m || s[n-i-1]==t[j]) {
                // debug("first type");
                // debug(n-i-1, j);
                dp[i+1][j+1] += dp[i][j];
                // debug(dp[i+1][j+1].v, "increased");
            }
            // do operation of type 2
            if(n+j-i-1>=m || s[n-i-1]==t[n+j-i-1]) {
                // debug("second type");
                // debug(n-i-1, n+j-i-1);
                dp[i+1][j] += dp[i][j];
                // debug(dp[i+1][j].v, "increased");
            }

        }
    }

    // debug(dp[0][0].v);
    // debug(dp[1][0].v, dp[1][1].v);
    // debug(dp[2][0].v, dp[2][1].v, dp[2][2].v);
    // debug(dp[3][0].v, dp[3][1].v, dp[3][2].v, dp[3][3].v);
    // debug(dp[4][0].v, dp[4][1].v, dp[4][2].v, dp[4][3].v, dp[4][4].v);



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