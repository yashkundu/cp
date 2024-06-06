/**
*   author: lazyhash(yashkundu)
*   created: 11 May, 2024 | 21:31:31
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

const int N = 2e5+10;
int a[N];

int n, k;

vector<int> oddSeq, evenSeq;


mi solveSeq(vector<int> &v) {
    int diffEl = -1;
    mi diffAns = 0, sameAns = 0;

    int sz = v.size();

    for(int i=0;i<sz;i++) {
        int x = v[i];
        if(i==0) {
            if(x==-1) {
                diffEl = 1;
                sameAns = 1;
                diffAns = 1;
            } else {
                diffEl = x;
                diffAns = 1;
                sameAns = 0;
            }
            continue;
        }
        // process
        if(x==-1) {
            mi sum = diffAns + sameAns*(k-1);
            diffAns = sum - diffAns;
            sameAns = sum - sameAns;
        } else {
            mi sum = diffAns + sameAns*(k-1);
            if(diffEl==x) sum -= diffAns;
            else sum -= sameAns;
            diffEl = x;
            diffAns = sum;
            sameAns = 0;
        }
    }
    return diffAns + sameAns*(-1);
}

 
void solve() {
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        if(i&1) oddSeq.push_back(a[i]);
        else evenSeq.push_back(a[i]);
    }

    mi ans1 = solveSeq(oddSeq);
    mi ans2 = solveSeq(evenSeq);

    mi ans = ans1*ans2;

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