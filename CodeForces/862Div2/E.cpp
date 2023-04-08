/**
*   author: lazyhash(yashkundu)
*   created: 04 Apr, 2023 | 08:43:19
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <set>
 
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

const int N = 1e5+10;
vector<pair<int, int>> g[N];
vector<int> a(N);
vector<int> new_a(N);
vector<pair<int, int>> anc(N);
vector<int> cnt1(N), cnt2(N);
vector<int> ans(N, -1);
vector<bool> vis1(N, 0), vis2(N, 0);


void dfs1(int v, int p) {
    for(auto [u,  ind]: g[v]) {
        if(u==p) continue;
        anc[u] = {v, ind};
        dfs1(u, v);
    }
}

void addToSet(int v, int p, vector<int> &cnt, set<int> &s, vector<bool> &vis) {
    cnt[new_a[v]]++;
    vis[v] = 1;
    if(cnt[new_a[v]]==2) s.insert(new_a[v]);
    for(auto [u, ind]: g[v]) {
        if(u==p || vis[u]) continue;
        addToSet(u, v, cnt, s, vis);
    }
}

void removeFromSet(int v, int p, vector<int> &cnt, set<int> &s, vector<bool> &vis) {
    cnt[new_a[v]]--;
    vis[v] = 1;
    if(cnt[new_a[v]]==1) s.erase(new_a[v]);
    for(auto [u, ind]: g[v]) {
        if(u==p || vis[u]) continue;
        removeFromSet(u, v, cnt, s, vis);
    }
}
 
void solve() {
    int n;
    cin >> n;

    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }

    vector<int> cc;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        cc.push_back(a[i]);
    }

    sort(cc.begin(), cc.end());
    cc.resize(distance(cc.begin(), unique(cc.begin(), cc.end())));

    for(int i=0;i<n;i++) 
        new_a[i] = lower_bound(cc.begin(), cc.end(), a[i])-cc.begin();

    for(int i=0;i<n;i++) 
        cnt1[new_a[i]]++;

    int largest = -1;
    for(int i=0;i<n;i++) {
        if(cnt1[new_a[i]]>1) largest = max(largest, new_a[i]);
    }

    if(largest==-1) {
        for(int i=0;i<n-1;i++) {
            cout << "0\n";
        }
        return;
    }

    if(cnt1[largest]>2) {
        for(int i=0;i<n-1;i++) {
            cout << cc[largest] << "\n";
        }
        return;
    }

    int v1 = -1, v2 = -1;
    for(int i=0;i<n;i++) {
        if(new_a[i]==largest) {
            if(v1==-1) v1 = i;
            else v2 = i;
        }
    }

    anc[v1] = {v1, -1};
    dfs1(v1, -1);

    set<int> s1, s2;
    for(int i=0;i<n;i++) {
        if(cnt1[new_a[i]]>1) s1.insert(new_a[i]);
    }

    int x = v2;
    vis1[v1] = vis2[v1] = 1;
    while(anc[x].first!=x) {
        vis1[x] = vis2[x] = 1;
        x = anc[x].first;
    }


    x = v2;
    while(anc[x].first!=x) {
        addToSet(x, -1, cnt2, s2, vis2);
        removeFromSet(x, -1, cnt1, s1, vis1);
        int m1 = (s1.empty()?0:cc[(*s1.rbegin())]);
        int m2 = (s2.empty()?0:cc[(*s2.rbegin())]);
        ans[anc[x].second] = max(m1, m2);
        x = anc[x].first;
    }

    for(int i=0;i<n-1;i++) if(ans[i]==-1) ans[i] = cc[largest];

    for(int i=0;i<n-1;i++) cout << ans[i] << "\n";

    
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