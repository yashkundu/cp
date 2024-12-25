/**
*    author:  lazyhash(yashkundu)
*    created: 15 Dec, 2024 | 17:47:47
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

const int MAXN = (int)4e5+10;
const int LG = 20;

int n;
int a[MAXN];
int nxt[MAXN];

int st[MAXN][LG] = {0};

int query(int l, int r) {
    if(l==r) return st[l][0];
    int x = __lg(r-l+1);
    return __gcd(st[l][x], st[r-(1<<(x))+1][x]);
}

 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }

    if(n==1) {
        cout << "1\n";
        return;
    }

    nxt[n-1] = n-1;
    for(int i=n-2;i>=0;i--) {
        if(a[i]==a[i+1]) nxt[i] = nxt[i+1];
        else nxt[i] = i;
    }

    for(int i=0;i<n-1;i++) {
        st[i][0] = abs(a[i+1]-a[i]);
    }

    for(int j=1;j<LG;j++) {
        for(int i=0;i+(1<<j)<n;i++) {
            st[i][j] = __gcd(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }

    ll ans = 1;

    int r = 0;
    int l = 0;
    

    for(int i=0;i<n-1;i++) {
        l = nxt[i], r = max(l, r);
        while(r<n-1 && __builtin_popcount(query(l, r))>1) r++;
        ans += n-1-r;
        ans += nxt[i] - i + 1;
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