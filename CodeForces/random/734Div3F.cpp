/**
*   author: lazyhash(yashkundu)
*   created: 01 May, 2024 | 19:44:07
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

const int mod = 1e9+7;
using mi=mint<mod>;

const int N = 102;
int cnt[N][N] = {0};
mi dp[N][N];

vector<int> g[N];



int n, k;


void dfs(int v, int p, int dep, int ind) {
    cnt[ind][dep]++;
    for(int u: g[v]) {
        if(u==p) continue;
        dfs(u, v, dep+1, ind);
    }
}

mi calcWays(vector<int> &nums) {
    int sz = nums.size();
    for(int i=0;i<=sz;i++) for(int j=0;j<=k;j++) dp[i][j] = 0;
    dp[0][0] = 1;

    for(int i=0;i<sz;i++) {
        for(int j=0;j<=k;j++) {
            // choose nums[i]
            dp[i+1][j+1] += dp[i][j]*nums[i];
            // don't choose nums[i]
            dp[i+1][j] += dp[i][j];
        }
    }
    return dp[sz][k];
}

 
void solve() {
    cin >> n >> k;
    for(int i=0;i<n;i++) g[i].clear();

    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if(k==2) {
        mi ans = mi(n)*mi(n-1)/2;
        cout << ans.v << "\n";
        return;
    }

    mi ans = 0;

    for(int i=0;i<n;i++) {
        if(g[i].size()<k) continue;
        for(int j=0;j<g[i].size();j++) fill(cnt[j], cnt[j]+n, 0);
        for(int j=0;j<g[i].size();j++) {
            dfs(g[i][j], i, 0, j);
        }
        vector<int> curInds;
        for(int j=0;j<g[i].size();j++) curInds.push_back(j);

        vector<int> newCurInds;
        vector<int> nums;

        int dep = 0;
        while(curInds.size()>=k) {
            nums.clear();
            for(int j: curInds) nums.push_back(cnt[j][dep]);
            ans += calcWays(nums);

            dep++;
            newCurInds.clear();
            for(int j: curInds) if(cnt[j][dep]) newCurInds.push_back(j);
            curInds.clear();
            for(int j: newCurInds) curInds.push_back(j);
        }

    }

    cout << ans.v << "\n";



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