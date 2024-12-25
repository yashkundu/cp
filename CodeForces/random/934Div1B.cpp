/**
*    author:  lazyhash(yashkundu)
*    created: 21 Jun, 2024 | 11:09:52
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

int base = uniform_int_distribution<int>(27, mod-1)(rng);


const int MAXN = 2e5+10;
mi pref[MAXN];
mi suf[MAXN];
mi basePow[MAXN];
int cnt[MAXN][26][2] = {0};

int n, q;
int l, r;
string s;
int c1, c2;
bool isPalin = false;
ll ans = 0;


void init() {
    pref[0] = 0;

    basePow[0] = 1;
    for(int i=1;i<n;i++) basePow[i] = basePow[i-1]*base;

    for(int i=0;i<n;i++) {
        pref[i+1] = pref[i] + (s[i]-'a'+1)*basePow[i];
    }

    suf[n] = 0;
    for(int i=n-1;i>=0;i--) {
        suf[i] = suf[i+1] + (s[i]-'a'+1)*basePow[n-1-i];
    }


    for(int i=0;i<n;i++) {
        for(int j=0;j<26;j++) for(int k=0;k<2;k++) cnt[i+1][j][k] = cnt[i][j][k];
        cnt[i+1][s[i]-'a'][i&1]++;
    }

}

mi getHash(int l, int r) {
    return (pref[r]-pref[l])/basePow[l];
}

mi getHashSuf(int l, int r) {
    return (suf[l]-suf[r])/basePow[n-r];
}

int getCntAll(int l, int r) {
    int c = 0;
    for(int j=0;j<26;j++) {
        if(cnt[r][j][0]-cnt[l][j][0] + cnt[r][j][1]-cnt[l][j][1]) c++;
    }
    return c;
}

int getCntSpecific(int l, int r, int k) {
    int c = 0;
    for(int j=0;j<26;j++) if(cnt[r][j][k]-cnt[l][j][k]) c++;
    return c;
}
 
void solve() {
    cin >> n >> q;
    cin >> s;
    init();

    while(q--) {
        cin >> l >> r;
        l--;
        c1 = getCntAll(l, r);
        c2 = getCntSpecific(l, r, 0) + getCntSpecific(l, r, 1);
        isPalin = getHash(l, l + (r-l)/2) == getHashSuf(r - (r-l)/2, r);
        ans = isPalin?0:(r-l);
        // debug(c1, c2, isPalin);
        if(c1>1) {
            int lim = (r-l-1)/2*2;
            int num = (lim-2)/2+1;
            if(r-l>=2) ans += 1LL*num*(2+lim)/2;
        }
        if(c2>2) {
            int lim = (r-l-1);
            if(lim%2==0) lim--;
            int num = (lim-3)/2+1;
            if(r-l>2) ans += 1LL*num*(3+lim)/2;
        }
        cout << ans << "\n";
    }



}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
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