/**
*    author:  lazyhash(yashkundu)
*    created: 27 Jun, 2024 | 21:00:43
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

const int MAXN = 1e6+5;

int a[MAXN], b[MAXN], c[MAXN];
ll ans[MAXN];
ll res[MAXN];

vector<pair<int, int>> wp;
vector<pair<int, int>> twp;

vector<pair<int, int>> metals;


int n, m;
 
void solve() {
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    for(int i=0;i<m;i++) cin >> c[i];


    wp.clear();
    twp.clear();
    metals.clear();

    for(int i=0;i<n;i++) wp.push_back({a[i], {a[i]-b[i]}});
    sort(wp.begin(), wp.end());

    for(auto p: wp) {
        if(twp.empty()) twp.push_back(p);
        else if(twp.back().second>p.second) twp.push_back(p);
    }

    swap(wp, twp);

    // debug(wp);

    ans[0] = 0;

    int j = -1;
    for(int i=1;i<MAXN;i++) {
        while(j+1<wp.size() && wp[j+1].first<=i) j++;
        if(j==-1) {
            ans[i] = 0;
            continue;
        }
        int del = i - wp[j].first+1;
        int cnt = (del+wp[j].second-1)/wp[j].second;
        ans[i] = ans[i-cnt*wp[j].second] + cnt;
    }

    // debug(ans[9], ans[10], ans[19], ans[20]);

    for(int i=0;i<m;i++) metals.push_back({c[i], i});

    sort(metals.begin(), metals.end());

    j = -1;
    for(auto [x, ind]: metals) {
        while(j+1<wp.size() && wp[j+1].first<=x) j++;
        if(j==-1) {
            res[ind] = 0;
            continue;
        }
        int del = x - wp[j].first+1;
        int cnt = (del+wp[j].second-1)/wp[j].second;
        // debug(x, j, wp[j], del, cnt, del*cnt);
        res[ind] = ans[x-cnt*wp[j].second] + cnt;
    }


    ll sum = 0;
    for(int i=0;i<m;i++) sum += res[i];

    cout << sum*2 << "\n";







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