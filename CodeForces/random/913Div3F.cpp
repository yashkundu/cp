/**
*    author:  lazyhash(yashkundu)
*    created: 30 Jun, 2024 | 16:25:34
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

const int MAXN = 1e5+10;

int n;
vector<int> a;
int pre[MAXN][2], suf[MAXN][2];

// 0 - inc, 1 - dec


int calc(vector<int> a) {
    pre[0][0] = pre[0][1] = 0;

    for(int i=1;i<n;i++) {
        pre[i][0] = pre[i-1][0];
        pre[i][1] = pre[i-1][1];
        if(a[i]>a[i-1]) pre[i][0]++;
        else if(a[i]<a[i-1]) pre[i][1]++;
    }

    suf[n-1][0] = suf[n-1][1] = 0;

    for(int i=n-2;i>=0;i--) {
        suf[i][0] = suf[i+1][0];
        suf[i][1] = suf[i+1][1];
        if(a[i]<a[i+1]) suf[i][0]++;
        else if(a[i]>a[i+1]) suf[i][1]++;
    }

    if(pre[n-1][0] >= 0 && pre[n-1][1]==0) {
        return 0;
    }

    if(pre[n-1][1] && !pre[n-1][0]) {
        return 1;
    }


    int ans = 1e9;

    for(int i = n-1;i>0;i--) {
        if((suf[i][0] && suf[i][1]) || (pre[i-1][0] && pre[i-1][1])) continue;
        if((suf[i][0] && pre[i-1][1]) || (suf[i][1] && pre[i-1][0])) continue;
        int del = suf[i][0]?0:suf[i][1]?1:pre[i-1][0]?0:1;
        if(del==0 && a[n-1]<=a[0]) {
            ans = min(ans, n-i);
        }
        if(del==1 && a[n-1]>=a[0]) {
            ans = min(ans, n-i+1);
        }
    }

    return ans;
}


 
void solve() {
    cin >> n;

    a.resize(n);
    for(int i=0;i<n;i++) cin >> a[i];


    int ans = 1e9;
    ans = min(ans, calc(a));


    reverse(a.begin(), a.end());
    ans = min(ans, calc(a)+1);

    if(ans==1e9) ans = -1;

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