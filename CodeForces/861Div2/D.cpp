/**
*   author: lazyhash(yashkundu)
*   created: 02 Apr, 2023 | 12:44:38
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


const int N = 2e5+10;
vector<int> cnt[N][2];
 
void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for(int i=0;i<n;i++) {
        cin >> a[i];
        cnt[a[i]][i&1].push_back(i);
    }

    debug(cnt[1][0], cnt[1][1]);
    debug(cnt[2][0], cnt[2][1]);
    debug(cnt[5][0], cnt[5][1]);
    debug(cnt[6][0], cnt[6][1]);
    debug(cnt[8][0], cnt[8][1]);

    ll ans = 0;
    for(int i=0;i<n;i++) {
        // max(k - 1 - 2*i, 2) 4 6 8 10 min(k-1, 2*(n-(k+1)/2-i))
        int x1 = max(k-1-2*i, 2), x2 = min(k-1, 2*(n-(k+1)/2-i));
        if(x1>x2 || max(x1, x2)==0) continue;
        int ind1 = ((i&1)?min(i+x1, n-1 - (((n-1)&1)^1)):min(i+x1, n-1-((n-1)&1)));
        int ind2 = ((i&1)?min(i+x2, n-1 - (((n-1)&1)^1)):min(i+x2, n-1-((n-1)&1)));
        debug(i, a[i], x1, ind1, x2, ind2);
        int same_elements = upper_bound(cnt[a[i]][i&1].begin(), cnt[a[i]][i&1].end(), ind2) - lower_bound(cnt[a[i]][i&1].begin(), cnt[a[i]][i&1].end(), ind1);
        ans += (ind2-ind1)/2+1-same_elements;
        debug(ans, same_elements);
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/