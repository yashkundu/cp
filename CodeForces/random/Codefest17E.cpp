/**
*    author:  lazyhash(yashkundu)
*    created: 10 Jun, 2024 | 19:19:45
**/
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 

ll cacheC[100][100];
ll cacheDp[65][11][11];

int cnt[10];
vector<int> digs;


void precompute() {
    for(int i=0;i<100;i++) for(int j=0;j<100;j++) cacheC[i][j] = -1;
    for(int i=0;i<65;i++) for(int j=0;j<11;j++) for(int k=0;k<11;k++) cacheDp[i][j][k] = -1;
}


ll C(int n, int r) {
    if(cacheC[n][r]!=-1) return cacheC[n][r];
    if(n<r) return cacheC[n][r] = 0;
    if(n==0 || r==0) return cacheC[n][r] = 1;
    cacheC[n][r] = C(n-1, r-1) + C(n-1, r);
    return cacheC[n][r];
}


ll dp(int n, int a, int b) {
    if(cacheDp[n][a][b]!=-1) return cacheDp[n][a][b];
    if(n==0) {
        if(b==0) return cacheDp[n][a][b] = 1;
        else cacheDp[n][a][b] = 0;
    } else if(a==0 && b==0) return cacheDp[n][a][b] = 0;
    cacheDp[n][a][b] = 0;
    if(a) {
        // putting even nums
        for(int i=2;i<=n;i+=2) {
            cacheDp[n][a][b] += 1LL*a*C(n, i)*dp(n-i, a-1, b);
        }
    }
    if(b) {
        // putting odd nums
        for(int i=1;i<=n;i+=2) {
            cacheDp[n][a][b] += 1LL*b*C(n, i)*dp(n-i, a, b-1);  
        }
    }
    return cacheDp[n][a][b];
}


ll getQuery(ll n, int base) {
    if(n==0) return 0LL;
    for(int i=0;i<10;i++) cnt[i] = 0;
    digs.clear();


    while(n>0) {
        digs.push_back(n%base);
        n = n/base;
    }

    reverse(digs.begin(), digs.end());

    ll ans = 0;
    int odds = 0;

    for(int i=0;i<digs.size();i++) {
        for(int j=0;j<digs[i];j++) {
            if(i==0 & j==0) continue;
            cnt[j]++;
            if(cnt[j]&1) odds++;
            else odds--;
            ans += dp((int)digs.size() - i - 1, base-odds, odds);
            cnt[j]--;
            if(cnt[j]&1) odds++;
            else odds--;
        }
        cnt[digs[i]]++;
        if(cnt[digs[i]]&1) odds++;
        else odds--;
    }

    for(int i=1;i<digs.size();i++) ans += 1LL*(base-1)*dp(i-1, base-1, 1);

    return ans;
}

int base;
ll l, r;

void solve() {
    cin >> base >> l >> r;
    ll ans = getQuery(r+1, base) - getQuery(l, base);
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