/**
*   author: lazyhash(yashkundu)
*   created: 02 Mar, 2023 | 09:16:16
**/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
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

const int N = 1e7+100;
vector<int> cnt(N, 0), gCnt(N, 0);
 
 
void solve() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int &x: s) {
        cin >> x;
    }
    int m = s[n-1];

    fill(cnt.begin(), cnt.begin()+2*m+5, 0);
    fill(gCnt.begin(), gCnt.begin()+m+1, 0);

    for(int i=0;i<n;i++) cnt[s[i]]++;

    for(int i=1;i<=2*m+1;i++) cnt[i] += cnt[i-1];
    mi ans = 0;

    // x not divisible by sn
    for(int k=1;k<=m;k++) {
        int l = m/(k+1)+1, r = (m-1)/k;
        if(r-l+1==0) continue;
        // k - k+1, 2k - 2k+2, 3k - 3k+3, --- --- -- (k-2)k + k-2, ---- (k-1)k ---
        // 1-k-1, k+2-2k-1, 2k+3-3k-1, ------ (k-2)k + k-2 + 1
        int x1 = 1, x2 = k-1;
        int num = 0;
        for(int i=0;i<=k-2 && x1<=m;i++) {
            if(x1>x2) break;
            num += cnt[x2]-cnt[x1-1];
            x1 += k+1;
            x2 += k;
        }
        mi sum = 1LL*(r-l+1)*(l+r)/2;
        sum *= (n-num);
        ans += sum;
    }
    vector<int> gcds;

    for(int i=0;i<n;i++) {
        int x = gcd(s[i], m);
        gcds.push_back(x);
        gCnt[gcds.back()]++;
    }

    sort(gcds.begin(), gcds.end());
    gcds.resize(distance(gcds.begin(), unique(gcds.begin(), gcds.end())));

    vector<int> factors;
    for(int i=1;i<=m;i++) if(m%i==0) factors.push_back(i);

    for(int fact: factors) {
        for(int gcd: gcds) {
            if(gcd%fact==0) ans += 1LL*gCnt[gcd]*(m/fact);
        }
    }

    cout << ans << "\n";


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