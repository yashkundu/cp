/**
*   author: lazyhash(yashkundu)
*   created: 23 Jan, 2024 | 10:11:30
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

using mi=mint<998244353>;



const int N = 2e5+10;
int a[N], nxt[N], col[N];
vector<int> pos[N];
int n;



bool isSegmentGood(int l, int r) {
    if((r-l)&1) return false;
    fill(col+l, col+r, 0);
    int maxInd = l;
    for(int i=l;i<r;i++) {
        if(col[i]) continue;
        col[i] = 1;
        int nxtInd = nxt[i];
        if(nxtInd>=r) return false;
        if(nxtInd<=maxInd) return false;
        maxInd = nxtInd;
        col[nxtInd] = 2;
    }
    return true;
}


// return number of complete segments if all of them are good
int completeSegments() {
    int r = 0;
    int l = 0;
    int cnt = 0;
    for(int i=0;i<n;i++) {
        if(i==r+1) {
            // check the previous one
            if(!isSegmentGood(l, r+1)) return 0;
            cnt++;
            l = i;
            r = i;
        }
        int nxtInd = nxt[i];
        if(nxtInd!=n) r = max(r, nxtInd);
    }
    if(!isSegmentGood(l, n)) return 0;
    cnt++;
    return cnt;
}


 
void solve() {
    cin >> n;

    fill(nxt, nxt+n, n);

    int uniqEl = 0;

    for(int i=0;i<n;i++) {
        cin >> a[i];
        if(!pos[a[i]].empty()) nxt[pos[a[i]].back()] = i;
        else uniqEl++;
        pos[a[i]].push_back(i);
    }


    mi totWays = pow(mi(2), uniqEl);
    int goodSegments = completeSegments();
    if(goodSegments) {
        totWays -= pow(mi(2), goodSegments);
    }

    totWays /= 2;

    cout << totWays.v << "\n";








    for(int i=0;i<n;i++) pos[a[i]].clear();

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