/**
*   author: lazyhash(yashkundu)
*   created: 21 Apr, 2023 | 17:40:06
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

const int inf = 2e9;
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    for(int i=0;i<n;i++) cin >> v[i].first;
    for(int j=0;j<n;j++) cin >> v[j].second;
    int ans = inf;

    int curOne = 0, curNOne = 0;
    int tot = 0;
    for(auto [l, r]: v) {
        // if(tot+(r-l+1)<k) continue;
        if(tot-curOne>=k) break;
        if(tot+(r-l+1)>=k) {
            int leftOnes = k - (tot-curOne);
            int curAns = (l+min(r-l+1, leftOnes)-1) + 2*curNOne + 2*(leftOnes-min(leftOnes, r-l+1))+2;
            // debug(l, r, leftOnes, tot, curOne, curNOne, curAns);
            ans = min(ans, curAns);
        }
        if(l==r) curOne++;
        else curNOne++;
        tot += (r-l+1);
    }

    if(ans==inf) ans = -1;
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