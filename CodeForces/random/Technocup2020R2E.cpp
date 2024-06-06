/**
*   author: lazyhash(yashkundu)
*   created: 08 May, 2024 | 17:32:23
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

const int N = 2e3+10;

mi d[N][N], r[N][N];
bool a[N][N] = {0};
int downCnt[N][N] = {0}, rightCnt[N][N] = {0};
 

int n, m;

void solve() {
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        for(int j=0;j<m;j++) a[i+1][j+1] = (s[j]=='R');
    }

    if(a[n][m]) {
        cout << "0\n";
        return;
    }

    if(n==1 && m==1) {
        cout << "1\n";
        return;
    }

    for(int i=n;i>0;i--) {
        for(int j=m;j>0;j--) {
            downCnt[i][j] += downCnt[i+1][j];
            if(a[i+1][j]) downCnt[i][j]++;
            rightCnt[i][j] += rightCnt[i][j+1];
            if(a[i][j+1]) rightCnt[i][j]++;
        }
    }


    for(int i=n;i>0;i--) {
        for(int j=m;j>0;j--) {
            if(i==n && j==m) {
                d[i][j] = r[i][j] = 1;
                continue;
            }
            // d
            if(!a[i+1][j]) {
                d[i][j] = d[i+1][j] + r[i+1][j];
                if(i+1==n && j==m) d[i][j] -= 1;
            } else {
                int numMoves = n - (i+1) - downCnt[i+1][j];
                if(numMoves) {
                    d[i][j] = d[i+1][j] + r[i+1][j] - r[i+1+numMoves][j];
                }
            }
            // r
            if(!a[i][j+1]) {
                r[i][j] = r[i][j+1] + d[i][j+1];
                if(i==n && j+1==m) r[i][j] -= 1;
            } else {
                int numMoves = m - (j+1) - rightCnt[i][j+1];
                if(numMoves) {
                    r[i][j] = r[i][j+1] + d[i][j+1] - d[i][j+1+numMoves];
                }
            }
        }
    }

    mi ans = d[1][1] + r[1][1];

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