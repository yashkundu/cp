/**
*   author: lazyhash(yashkundu)
*   created: 23 Sep, 2023 | 21:32:18
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <assert.h>
#include <iterator>
 
using namespace std;
 
typedef long long ll;



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

using mi=mint<998244353>;
 
void solve() {

    int n;
    cin >> n;
    vector<int> s(n, 0);
    for(int &x: s) cin >> x;

    sort(s.begin(), s.end());

    mi expVal = 0;
    mi prob = mi(1)/(mi(n)*mi(n));



    for(int i=0;i<n;i++) {
        int x = 0;
        int prevPos = -1;
        int setBitCntr = 0;
        // 10110001
        for(int j=29;j>=0;j--) {
            if((1<<j)&s[i]) {
                setBitCntr++;
                x += (1<<j);
                int ind = distance(s.begin(), lower_bound(s.begin(), s.end(), x));
                expVal += mi(2*setBitCntr+1)*mi(ind-prevPos-1);
                prevPos = ind-1;
            }
        }
        expVal += mi(2*setBitCntr+2)*mi(i-prevPos-1);
        expVal += mi(setBitCntr+1);
    }

    expVal *= prob;
    cout << expVal << "\n";

    
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/