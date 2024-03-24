/**
*   author: lazyhash(yashkundu)
*   created: 09 Jul, 2023 | 16:29:41
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <numeric>
#include <assert.h>
 
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



struct UnionFind {
    vector<int> par;
    UnionFind(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
    }

    int find(int v) {
        if(par[v]==v) return v;
        return par[v] = find(par[v]);
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if(u!=v) par[u] = v;
    }
};


 
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    debug(n, m, q);
    string s;
    cin >> s;
    debug(s);
    int totones = 0;
    for(int i=0;i<n;i++) totones += (s[i]=='1');
    debug(totones);
    UnionFind dsu(n);
    vector<bool> vis(n, 0);
    vector<int> inds;
    for(int i=0;i<m;i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        while(l<=r) {
            debug(l, r);
            if(!vis[l]) {
                inds.push_back(l);
                vis[l] = 1;
            }
            else {
                l = dsu.find(l);
            }
            if(l-1>0 && vis[l-1]) dsu.merge(l-1, l);
            l++;
        }
    }
    
    debug(inds);
    assert(inds.size()<=n);
    // maintain cnt of ones upto totones length
    vector<int> newInds(n, -1);
    for(int i=0;i<inds.size();i++) newInds[inds[i]] = i;
    int cntOnes = 0;
    for(int i=0;i<min(totones, int(inds.size()));i++) cntOnes += (s[inds[i]]=='1');
    // ans = min(totOnes, inds.size()) - cntOnes

    while(q--) {
        int x;
        cin >> x;
        x--;
        if(s[x]=='1') {
            if(totones<=inds.size()) cntOnes -= (s[inds[totones-1]]=='1');
            totones--;
            debug(cntOnes, totones);
            if(newInds[x]!=-1 && newInds[x]<min(totones, int(inds.size()))) cntOnes--;
            debug(cntOnes);
            s[x]='0';
        } else {
            if(totones<inds.size()) cntOnes += (s[inds[totones]]=='1');
            totones++;
            debug(cntOnes, totones);
            if(newInds[x]!=-1 && newInds[x]<totones) cntOnes++;
            debug(cntOnes);
            s[x]='1';
        }
        cout << min(totones, int(inds.size())) - cntOnes << "\n";
    }
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