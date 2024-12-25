/**
*    author:  lazyhash(yashkundu)
*    created: 25 Jun, 2024 | 13:48:40
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

const int MAXN = 2e5+10;
int c[MAXN];

int n, b, x;
ll tot = 0;
ll del = 0;
ll ans = 0;
int sum = 0;


ll pairs(int x) {
    return 1LL*x*(x-1)/2;
}
 
void solve() {
    cin >> n >> b >> x;

    tot = 0;
    sum = 0;
    ans = 0;

    for(int i=0;i<n;i++) {
        cin >> c[i];
        sum += c[i];
        tot += 1LL*c[i]*(c[i]-1)/2;
    }

    // debug(tot, sum);

    sort(c, c+n);

    int j = 0;
    for(int k=1;k<=sum;k++) {
        while(j<n && c[j]<=k) j++;
        del = 0;
        for(int i=j;i<n;i++) {
            del += pairs(c[i]/k)*(k-c[i]%k) + pairs(c[i]/k+1)*(c[i]%k);
        }
        ans = max(ans, (tot - del)*b - 1LL*(k-1)*x);
        // debug(k, j, del, ans, (tot - del)*b, (k-1)*x);
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/