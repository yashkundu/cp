/**
*   author: lazyhash(yashkundu)
*   created: 15 Mar, 2024 | 18:44:52
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

const int N = 5e5+10;
int tree[N];
int inf = 1e9+100;
int a[N], ord[N];
int dp[N];

ll pre[N] = {0};

int n;

void update(int ind, int val) {
    for(;ind<=n;ind+=(ind&(-ind))) {
        tree[ind] = max(tree[ind], val); 
    }
}

int query(int ind) {
    int ans = -inf;
    for(;ind>0;ind-=(ind&(-ind))) {
        ans = max(ans, tree[ind]);
    }
    return ans;
}

void solve() {
    cin >> n;

    for(int i=1;i<=n;i++) tree[i] = -inf;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }

    vector<pair<int, int>> v;
    for(int i=1;i<=n;i++) {
        v.emplace_back(pre[i], -i);
    }
    sort(v.begin(), v.end());

    for(int i=0;i<n;i++) {
        ord[-v[i].second]  = i+1;
    }

    for(int i=1;i<=n;i++) dp[i] = -inf;
    dp[0] = 0;

    for(int i=1;i<=n;i++) {
        // taking subsegment of length 1 for case if s<=0
        dp[i] = max(dp[i], dp[i-1] + (a[i]>0?1:a[i]<0?-1:0));

        // considering all subsegments with s>0
        dp[i] = max(dp[i], query(ord[i]) + i);
        if(pre[i]>0) dp[i] = i;
        update(ord[i], dp[i] - i);
    }

    cout << dp[n] << "\n";




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