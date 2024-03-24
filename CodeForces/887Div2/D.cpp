/**
*   author: lazyhash(yashkundu)
*   created: 25 Jul, 2023 | 23:10:56
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
 
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    vector<int> ans(n, 0), tmp(n+2, 0);
    sort(a.begin(), a.end());

    for(auto [x, ind]: a) {
        tmp[n+1-x]++;
    }

    for(int i=1;i<=n;i++) tmp[i] += tmp[i-1];
    for(int i=0;i<n;i++) {
        if(tmp[i+1]!=a[i].first) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    int cntr = n;
    int i = n-1, j = 0;
    for(;i>=0 && i>=j;i--) {
        int x = a[i].first;
        bool ran = false;
        debug(i, x, j);
        while(n-j>x) {
            ans[j] = -cntr;
            j++;
            ran = true;
        }
        debug(j);
        if(ran) cntr--;
        debug(i, cntr);
        if(!ans[i]) ans[i] = cntr;
        cntr--;
        debug(i, cntr);
    }

    debug(ans);

    vector<int> fAns(n);

    for(int i=0;i<n;i++) {
        fAns[a[i].second] = ans[i];
    }

    for(int x: fAns) cout << x << " ";
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