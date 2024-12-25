/**
*    author:  lazyhash(yashkundu)
*    created: 26 Sep, 2024 | 23:17:17
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


struct Ftree{
    int n;
    vector<int> tree;
    Ftree(int n) {
        this->n = n;
        tree.resize(n+1);
        fill(tree.begin(), tree.end(), 0);
    }
    int query(int ind) {
        int sum = 0;
        for(;ind>0;ind-=ind&-ind) sum += tree[ind];
        return sum;
    }
    void update(int ind, int val) {
        for(;ind<=n;ind+=ind&-ind) tree[ind] += val;
    }
};


const int MAXN = (int)2e5+10;
int cnt[MAXN] = {0};


int n, m;
vector<int> t;
int a;

mi ans = 0;
 
void solve() {
    cin >> n >> m;
    t.resize(m);


    for(int i=0;i<n;i++) {
        cin >> a;
        cnt[a]++;
    }


    for(int i=0;i<m;i++) cin >> t[i];

    Ftree ft(MAXN);

    mi f = 1;
    for(int i=1;i<MAXN;i++) {
        mi x = 1;
        if(cnt[i]) ft.update(i, cnt[i]);
        for(int j=1;j<=cnt[i];j++) x *= j;
        f /= x;
    }

    mi tot = 1;
    for(int i=1;i<n;i++) tot *= i;

    bool good = true;

    for(int i=0;i<min(n, m);i++) {
        ans += tot*f*ft.query(t[i]-1);
        if(!cnt[t[i]]) {
            good = false;
            break;
        }
        f *= cnt[t[i]];
        cnt[t[i]]--;
        ft.update(t[i], -1);
        if(n-i-1) tot /= (n-i-1);
    }

    if(good && n<m) ans += 1;

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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/