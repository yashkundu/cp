/**
*    author:  lazyhash(yashkundu)
*    created: 13 Jun, 2024 | 14:49:32
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

const int mod = 1e9+9;
using mi=mint<mod>;

int base = uniform_int_distribution<int>(26, mod-1)(rng);

const int N = 2e5+10;
mi pBase[N];
mi rhash[N];
int nxt[N];


string s;
int n;
 

void precompute() {
    pBase[0] = 1;
    for(int i=1;i<N;i++) pBase[i] = pBase[i-1]*base;
}

mi calcHash(int l, int r) {
    return (rhash[r]-rhash[l])/pBase[l];
}


void solve() {
    cin >> s;
    n = s.size();

    int ind = -1;
    for(int i=0;i<n;i++) if(s[i]!='a')  {
        ind = i;
        break;
    }

    if(ind==-1) {
        cout << n-1 << "\n";
        return;
    }

    rhash[0] = 0;
    for(int i=1;i<=n;i++) {
        rhash[i] = rhash[i-1] + (s[i-1]-'a'+1)*pBase[i-1];
    }

    nxt[n] = -1;
    for(int i=n-1;i>=0;i--) {
        if(s[i]!='a') nxt[i] = i;
        else nxt[i] = nxt[i+1];
    }


    ll ans = 0;
    int curInd = ind;
    int minA = ind;
    int tmp = -1;

    for(int l=1;l+ind<=n;l++) {
        curInd = ind;
        mi origHash = calcHash(ind, ind+l);
        minA = ind;

        bool isGood = true;
        curInd += l;
        tmp = nxt[curInd];
        if(tmp!=-1) minA = min(minA, tmp-curInd);
        curInd = tmp;
        while(curInd+l<=n && curInd!=-1) {
            if(calcHash(curInd, curInd+l)!=origHash) {
                isGood = false;
                break;
            }
            curInd += l;
            tmp = nxt[curInd];
            if(tmp!=-1) minA = min(minA, tmp-curInd);
            curInd = tmp;
        }
        if(curInd==-1 && isGood) ans += (minA+1);
    }


    cout << ans << "\n";    


}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
    precompute();
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