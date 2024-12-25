/**
*    author:  lazyhash(yashkundu)
*    created: 24 Jun, 2024 | 20:23:12
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
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

const int MAXN = 3e5+5;
int a[MAXN];


vector<int> ans;
set<int> used, not_used;
 
int n;

void solve() {
    cin >> n;

    ans.clear();
    used.clear();
    not_used.clear();

    for(int i=1;i<=n;i++) {
        cin >> a[i];
        a[i] += i;
    }


    for(int i=n;i>0;i--) {
        if(!used.count(a[i])) {
            not_used.insert(a[i]);
        }
        debug(i, a[i], used, not_used);
        auto it = not_used.upper_bound(a[i]);
        if(it==not_used.begin()) continue;
        --it;
        int cur = *it;
        if(cur<a[i]-i+1) continue;
        ans.push_back(cur);
        used.insert(cur);
        not_used.erase(cur);
        if(!used.count(cur-1)) not_used.insert(cur-1);
    }

    sort(ans.rbegin(), ans.rend());

    for(int x: ans) cout << x << " ";
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/