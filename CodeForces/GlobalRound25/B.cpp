/**
*   author: lazyhash(yashkundu)
*   created: 06 Apr, 2024 | 20:23:49
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

const int N = 1e5+10;
int a[N];
int preMax[N], great[N];

int n, k;
 
void solve() {
    cin >> n >> k;
    k--;

    preMax[0] = 0;
    great[n] = n;


    for(int i=0;i<n;i++) cin >> a[i];

    int myCow = a[k];


    for(int i=0;i<n;i++) preMax[i+1] = max(preMax[i], a[i]);

    for(int i=n-1;i>=0;i--) {
        if(a[i]>myCow) great[i] = i;
        else great[i] = great[i+1];
    }


    int ans = 0;

    for(int i=0;i<k;i++) {
        if(preMax[i]>myCow) continue;
        int win = 0;
        if(i) win++;
        int biggestC = great[i+1];
        if(a[i]>myCow) biggestC = min(biggestC, k);
        win += (biggestC - i-1);
        ans = max(ans, win);
    }
    if(preMax[k]<myCow) {
        int win = 0;
        if(k) win++;
        ans = max(ans, great[k+1] - k - 1 + win);
    }
    for(int i=k+1;i<n;i++) {
        if(max(preMax[i], a[i])>myCow) continue;
        int win = 0;
        if(i) win++;
        win += great[i+1] - i - 1;
        ans = max(ans, win);
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/