/**
*    author:  lazyhash(yashkundu)
*    created: 16 Jul, 2024 | 11:35:14
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

const int SQRT = 633;
const int MAXN = int(2e5) + 10;
const int LIM = int(1e9) + 10;


int sqr = 0;

int n;
int a[MAXN], b[MAXN];

int freq[SQRT][MAXN];
ll mul;

ll ans = 0;
 
void solve() {
    cin >> n;
    
    sqr = 0;
    while(sqr*sqr<=2*n) {
        sqr++;
    }

    for(int i=1;i<sqr;i++) for(int j=1;j<=n;j++) freq[i][j] = 0;



    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    for(int i=0;i<n;i++) {
        if(a[i]<sqr) {
            freq[a[i]][b[i]]++;
        }
    }

    ans = 0;
    for(int el=1;el<sqr;el++) {
        for(int i=0;i<n;i++) {
            mul = 1LL*el*a[i];
            if(mul-b[i]<=n && mul-b[i]>0 && freq[el][mul-b[i]]) {
                ans += freq[el][mul-b[i]]*(a[i]>=sqr?2:1);
            }
        }
    }

    for(int i=0;i<n;i++) {
        mul = 1LL*a[i]*a[i];
        if(mul==2*b[i]) ans--;
    }

    ans /= 2;

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