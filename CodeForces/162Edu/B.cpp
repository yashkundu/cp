/**
*   author: lazyhash(yashkundu)
*   created: 23 Feb, 2024 | 20:22:05
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


const int N = 3e5+10;
int a[N], x[N];
 
void solve() {
    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    for(int i=0;i<n;i++) {
        cin >> x[i];
        if(x[i]<0) x[i] *= -1;
    }

    vector<pair<int, int>> v;
    for(int i=0;i<n;i++) v.emplace_back(x[i], a[i]);

    sort(v.begin(), v.end());

    // debug(v);

    ll curSum=0;

    for(int i=0;i<v.size();) {
        int j = i;
        while(j<v.size() && v[i].first==v[j].first) {
            curSum += v[j].second;
            j++;
        }
        int x = v[i].first;
        // debug(i, curSum, x, k*x);
        if(1LL*k*x<curSum) {
            cout << "NO\n";
            return;
        }
        i = j;
    }

    cout << "YES\n";


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