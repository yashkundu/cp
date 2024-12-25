/**
*    author:  lazyhash(yashkundu)
*    created: 05 Oct, 2024 | 12:18:34
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <numeric>
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

const int MAXN = (int)2e5+10;
const int LG = 20;

int tbl[MAXN][LG];
int a[MAXN];

int n;

void build() {
    for(int i=0;i<n;i++) tbl[i][0] = a[i];
    for(int j=1;j<LG;j++) {
        for(int i=0;i+(1<<j)<=n;i++) {
            tbl[i][j] = gcd(tbl[i][j-1], tbl[i+(1<<(j-1))][j-1]);
        }
    }
}

int query(int l, int r) {
    int x = __lg(r-l+1);
    return gcd(tbl[l][x], tbl[r-(1<<x)+1][x]);
}


 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    build();


    


    int cur = -1;
    int ans = 0;

    int ptr = 0;
    for(int i=0;i<n;i++) {
        while(query(ptr, i)<i-ptr+1) ptr++;
        if(query(ptr, i)==i-ptr+1) {
            if(ptr>cur) {
                ans++;
                cur = i;
            }
        }
        cout << ans << " ";
    }

    cout << "\n";




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