/**
*   author: lazyhash(yashkundu)
*   created: 21 Feb, 2024 | 16:38:05
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
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];

    a = vector<int>(a.rbegin(), a.rend());
    b = vector<int>(b.rbegin(), b.rend());

    a.push_back(0);


    vector<int> fPos(m, -1);
    vector<int> fMin(m, -1);



    int ptr = 0;

    for(int i=0;i<m;i++) {
        while(ptr<a.size()) {
            if(a[ptr]<b[i]) {
                cout << "0\n";
                return;
            }
            if(a[ptr]==b[i]) {
                fPos[i] = ptr;
                ptr++;
                break;
            }
            ptr++;
        }
        if(fPos[i]==-1) {
            cout << "0\n";
            return;
        }
    } 

    ptr = 0;
    for(int i=0;i<m;i++) {
        // b[i]
        while(ptr<=fPos[i]) ptr++;
        while(ptr<n && a[ptr]>=b[i]) ptr++;
        fMin[i] = ptr; 
    }

    if(fMin[m-1]!=n) {
        cout << "0\n";
        return;
    }

    mi ans = 1;
    for(int i=0;i<m-1;i++) ans *= (fMin[i]-fPos[i]);

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