/**
*    author:  lazyhash(yashkundu)
*    created: 27 Oct, 2024 | 21:13:26
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
const int mod = (int)1e9+7;
using mi=mint<mod>;

const int MAXN = (int)2e5+10;

mi p2[30*MAXN];

int n;
vector<ll> a;
vector<int> cnt;

vector<int> v;

void init() {
    p2[0] = 1;
    for(int i=1;i<30*MAXN;i++) p2[i] = p2[i-1]*2;
}

bool check(ll x, ll y, int num) {
    if(num>=30) return true;
    ll z = p2[num].v;
    if(z*y>=x) return true;
    return false;
}
 
void solve() {
    cin >> n;
    a.resize(n+1);
    cnt.resize(n+1);

    cnt[0] = 0;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        cnt[i] = 0;
        while(a[i]%2==0) {
            cnt[i]++;
            a[i] /= 2;
        }
    }

    for(int i=1;i<=n;i++) cnt[i] += cnt[i-1];

    mi cursum = 0;
    mi ans = 0;


    v.clear();
    v.push_back(0);

    for(int i=1;i<=n;i++) {
        cursum += a[i];
        while(v.size()>1 && check(a[v.back()], a[i], cnt[i]-cnt[v.back()])) v.pop_back();
        if(cnt[i]-cnt[v.back()]) v.push_back(i);

        ans = cursum;
        for(int i=1;i<v.size();i++) {
            ans -= a[v[i]];
            ans += p2[cnt[v[i]] - cnt[v[i-1]]]*a[v[i]];
        }

        cout << ans << " ";
    }

    cout << "\n";


}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
    init();
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