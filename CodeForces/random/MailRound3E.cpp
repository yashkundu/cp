/**
*   author: lazyhash(yashkundu)
*   created: 03 Apr, 2024 | 19:46:05
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


mi base = 1000 + (rng()%100000000);


const int N = 1e6+10;


mi hashPref[N];
mi basePow[N];



string s, t;
int m, n;



bool check(int l0, int l1) {
    bool hasCame[2] = {0};
    
    mi hash[2];

    int cnt[2] = {0};

    for(int i=0;i<m;i++) {
        int bit = (s[i]=='0'?0:1);
        int lenUnitillNow = cnt[0]*l0 + cnt[1]*l1;
        int len = (bit==0?l0:l1);
        // [lenUnitllNow, _ + len)
        mi curHash = (hashPref[lenUnitillNow+len] - hashPref[lenUnitillNow])/basePow[lenUnitillNow];
        if(!hasCame[bit]) {
            hasCame[bit] = true;
            hash[bit] = curHash;
        } else {
            if(hash[bit]!=curHash) return false;
        }
        cnt[bit]++;
    }

    if(l0==l1 && hash[0]==hash[1]) return false;

    return true;

}





 
void solve() {
    cin >> s >> t;
    int cnt0=0, cnt1 = 0;

    m = s.size();
    n = t.size();
    for(int i=0;i<m;i++) if(s[i]=='0') cnt0++; else cnt1++;

    
    hashPref[0] = 0;

    mi baseM = 1;
    basePow[0] = baseM;

    for(int i=0;i<n;i++) {
        hashPref[i+1] = hashPref[i] + baseM*(t[i]-'a'+1);
        baseM *= base;
        basePow[i+1] = baseM;
    }



    int ans = 0;

    // cnt0l0 + cnt1l1 = n;
    for(int l0=1;l0<n;l0++) {
        if(cnt0*l0>=n) break;
        int del = (n - cnt0*l0);
        if(del%cnt1!=0) continue;
        int l1 = del/cnt1;

        // check for (l0, l1)
        if(check(l0, l1)) ans++;
    }

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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/