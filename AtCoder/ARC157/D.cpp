/**
*   author: lazyhash(yashkundu)
*   created: 05 Mar, 2023 | 16:08:34
**/
#include <iostream>
#include <vector>
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

const int N = 2010;
bool a[N][N] = {0};
int pre[N][N] = {0};
vector<int> nxtX(N, 0), nxtY(N, 0);
vector<int> rowSum(N, 0), colSum(N, 0);
 

bool calc(vector<int> &sums,int n, vector<int> &v, int x, int y) {
    int cnt = 0;
    for(int i=1;i<=n;i++) {
        cnt += sums[i];
        if(cnt==x*v.size()) {
            v.push_back(i);
        }
    }
    int last = v.back();
    if(last!=n) {
        int cnt = 0;
        v.pop_back();
        last = v.back();
        for(int i=last+1;i<=n;i++) {
            cnt += sums[i];
        }
        if(cnt!=x) return false;
        v.push_back(n);
    }
    return v.size()==y;
}

bool check(vector<int> &x, vector<int> &y) {
    for(int i=1;i<y.size();i++) {
        for(int j=1;j<x.size();j++) {
            if(pre[y[i]][x[j]] - pre[y[i-1]][x[j]] - pre[y[i]][x[j-1]] + pre[y[i-1]][x[j-1]]!=2) return false;
        }
    }
    return true;
}
 
void solve() {
    int n, m;
    cin >> n >> m;

    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        for(int j=0;j<m;j++) {
            a[i+1][j+1] = s[j]=='Y';
            pre[i+1][j+1] = pre[i][j+1] + pre[i+1][j] - pre[i][j] + a[i+1][j+1];
        }
    }

    for(int j=m-1;j>0;j--) if(pre[n][j+1]==pre[n][j]) nxtX[j] = 1 + nxtX[j+1];
    for(int i=n-1;i>0;i--) if(pre[i+1][m]==pre[i][m]) nxtY[i] = 1 + nxtY[i+1];


    if(pre[n][m]&1) {
        cout << "0\n";
        return;
    }
    int k = pre[n][m]/2;


    for(int i=1;i<=n;i++) rowSum[i] = pre[i][m] - pre[i-1][m];
    for(int j=1;j<=m;j++) colSum[j] = pre[n][j] - pre[n][j-1];

    mi ans = 0;

    for(int a=1;a<=k;a++) {
        if(k%a) continue;
        int b = k/a;
        // a X b
        vector<int> x = {0}, y={0};
        if(calc(rowSum, n, y, 2*b, a+1) && calc(colSum, m, x, 2*a, b+1) && check(x, y)) {   
            mi cur = 1;
            for(int i=1;i<y.size();i++) cur *= nxtY[y[i]]+1;
            for(int j=1;j<x.size();j++) cur *= nxtX[x[j]]+1;
            ans += cur;
        }

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