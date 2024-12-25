/**
*    author:  lazyhash(yashkundu)
*    created: 08 Sep, 2024 | 18:47:44
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
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

const int MAXN = (int)3e5+10;
 

int n, k;
ll b[MAXN];
ll opsend[MAXN];
ll curops = 0;
ll cursum = 0;
ll remval;
ll numops;

ll ans = 0;


void solve() {
    cin >> n >> k;
    for(int i=0;i<n;i++) opsend[i] = 0;


    for(int i=0;i<n;i++) cin >> b[i];

    ans = 0;
    cursum = 0;
    curops = 0;

    for(int i=n-1;i>=0;i--) {
        // cursum -= curops;
        remval = b[i] - cursum;
        // debug(i, cursum, curops, remval, ans);
        if(remval>0) {
            int x = min(k, i+1);
            numops = (remval+x-1)/x;
            ans += numops;
            cursum += numops*x;
            curops += numops;
            opsend[i-x+1] += numops;
        }
        cursum -= curops;
        curops -= opsend[i];
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/