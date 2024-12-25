/**
*    author:  lazyhash(yashkundu)
*    created: 16 Nov, 2024 | 22:14:22
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
 
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

const int MAXN = (int)1e6+10;

vector<int> g[MAXN];
int dep[MAXN];
int n;
int p;




bool check(vector<pair<int, int>> &v, int lim) {
    int num = 2, d = 1;
    int sz = v.size();
    for(int i=0;i<sz;i++) {
        while(d<lim-v[i].first) {
            d++;
            num *= 2;
            if(num>=MAXN) return true;
        }
        if(num<v[i].second) return false;
        num -= v[i].second;
    }
    return true;
}


int calc(vector<int> &childs) {
    map<int, int> mp;
    for(int x: childs) mp[dep[x]]++;
    vector<pair<int, int>> v;
    for(auto it = mp.rbegin(); it!=mp.rend(); it++) v.push_back({it->first, it->second});

    if(v.empty()) return 0;

    int L = v[0].first, R = v[0].first + 30;
    while(R-L>1) {
        int mid = (L+R)/2;
        if(check(v, mid)) R = mid;
        else L = mid;
    }

    return R;
}


void dfs(int v) {
    for(int u: g[v]) {
        dfs(u);
    }
    dep[v] = calc(g[v]);
}

 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) g[i].clear();
    for(int i=0;i<n;i++) dep[i] = 0;

    for(int i=1;i<n;i++) {
        cin >> p;
        p--;
        g[p].push_back(i);
    }

    dfs(0);

    cout << dep[0] << "\n";



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