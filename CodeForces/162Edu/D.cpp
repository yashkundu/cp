/**
*   author: lazyhash(yashkundu)
*   created: 24 Feb, 2024 | 13:06:07
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
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



const int N = 3e5+10;
ll a[N];
ll pre[N] = {0}, suf[N] = {0};

int nxt[N], prevEl[N];
int ans[N];

 
void solve() {
    int n;
    cin >> n;

    for(int i=0;i<n;i++) cin >> a[i];
    fill(ans, ans+n, n);

    nxt[n-1] = n;
    prevEl[0] = -1;

    for(int i=n-2;i>=0;i--) {
        if(a[i]==a[i+1]) nxt[i] = nxt[i+1];
        else nxt[i] = i+1;
    }

    for(int i=1;i<n;i++) {
        if(a[i]==a[i-1]) prevEl[i] = prevEl[i-1];
        else prevEl[i] = i-1;
    }


    for(int i=1;i<=n;i++) {
        pre[i] = pre[i-1] + a[i-1];
    }

    suf[n+1] = 0;
    for(int i=n;i>0;i--) {
        suf[i] = suf[i+1] + a[i-1];
    }


    // debug(pre[0], pre[1], pre[2], pre[3], pre[4], pre[5]);
    // debug(suf[0], suf[1], suf[2], suf[3], suf[4], suf[5]);


    // debug(nxt[0], nxt[1], nxt[2], nxt[3]);
    // debug(prevEl[0], prevEl[1], prevEl[2], prevEl[3]);

    for(int i=0;i<n;i++) {
        //.... a[i-1] a[i] a[i+1] a[i+2] ...

        // 5, (1, 3, 4)
        // right
        // debug(i);
        auto it = upper_bound(pre+1, pre+n+1, pre[i+1]+a[i]);
        int ind = it-pre-1;
        // debug("right", ind, pre[i+1]+a[i]);
        if(ind!=n) {
            if(ind==i+1) ans[i] = min(ans[i], 1);
            else if(nxt[i+1]<=ind) ans[i] = min(ans[i], ind-i);
            else if(nxt[i+1]<n) ans[i] = min(ans[i], nxt[i+1]-i);
        }
        // debug(ans[i]);
        // left
        // 65, 54, 51, 48, 42, 32, 26, 14, 7, 3
        auto it2 = lower_bound(suf+1, suf+n+1, suf[i+1]+a[i] ,greater<long long>());
        ind = it2 - suf-2;
        // debug("left", ind, suf[i+1]+a[i-1]);
        if(ind>=0) {
            if(ind==i-1) ans[i] = min(ans[i], i-ind);
            else if(prevEl[i-1]>=ind) ans[i] = min(ans[i], i-ind);
            else if(prevEl[i-1]>=0) ans[i] = min(ans[i], i - prevEl[i-1]);
        }
        // debug(ans[i]);
    }

    for(int i=0;i<n;i++) if(ans[i]==n) ans[i] = -1;

    for(int i=0;i<n;i++) cout << ans[i] << " ";
    cout << "\n";






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