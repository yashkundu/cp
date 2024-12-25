/**
*    author:  lazyhash(yashkundu)
*    created: 10 Oct, 2024 | 22:55:48
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

const int inf = (int)1e9+10;

int n;
vector<int> a;


int calccoins(int x, vector<int> &coins) {
    int ans = inf;
    int k = coins.size();
    for(int msk=0;msk<(1<<k);msk++) {
        int cur = 0;
        for(int j=0;j<k;j++) if((msk>>j)&1) {
            cur += coins[j];
        }
        if(cur>x) continue;
        if((x-cur)%3) continue;
        ans = min(ans, k + (x-cur)/3);
    }
    return ans;
}

int calcans(vector<int> &coins) {
    int ans = 0;
    for(int i=0;i<n;i++) ans = max(ans, calccoins(a[i], coins));
    return ans;
}

 
void solve() {
    cin >> n;
    a.resize(n);

    for(int i=0;i<n;i++) cin >> a[i];

    int ans = inf;
    vector<vector<int>> v = {
        {},
        {1},
        {2},
        {2, 2},
        {1, 2},
        {1, 2, 2}
    };
    
    // calccoins(a[0], v[2]);

    for(auto p: v) {
        ans = min(ans, calcans(p));
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