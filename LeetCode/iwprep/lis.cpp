/**
*    author:  lazyhash(yashkundu)
*    created: 03 Nov, 2024 | 22:21:19
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

const int MAXN = 2510;

int a[MAXN];
 
int n;

// dp[i] -> the smallest last term for a lis of len i
// dp[i] is increasing
// for updateing state at index i (a[i]) -> for all those lens whose last term is > a[i] and last second term is < a[i] increment last term to be a[i]
// can be done by simply binary search O(nlogn)
// 1 2 3 6 8 10 -> 9 (only need to update on index of dp, 10 in this case make it 10 -> 9) 
// no need to maintain dp, use vectors

vector<int> v;


void solve() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    v.clear();

    for(int i=0;i<n;i++) {
        auto it = upper_bound(v.begin(), v.end(), a[i]);
        if(it==v.end()) v.push_back(a[i]);
        else {
            int ind = it - v.begin();
            v[ind] = a[i];
        }
    }

    cout << v.size() << "\n";


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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/