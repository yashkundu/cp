// https://codeforces.com/problemset/problem/1879/E
/**
*   author: lazyhash(yashkundu)
*   created: 12 Jan, 2024 | 07:04:36
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
#include <assert.h>
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

const int N = 105;
vector<int> g[N];
int ans[N];
int parTracker[N];


void dfsColor(int v, int c, int k) {
    ans[v] = c;
    for(int u: g[v]) {
        int nextCol = c+1;
        if(nextCol==k+1) nextCol = 1;
        dfsColor(u, nextCol, k);
    }
}


// check if the ans can be 2 for a subtree, and if return the parity of the vertices with degree 2
bool dfsCheck2(int v, int dep, int &parity) {
    if(g[v].size()==1) {
        if(parity==-1) parity = dep&1;
        else if(parity!=dep%2) return false;
        parTracker[v] = parity;
    }
    for(int u: g[v]) {
        bool b = dfsCheck2(u, dep+1, parity);
        if(!b) return false;
    }
    return true;
}

 
void solve() {
    
    int n;
    cin >> n;

    for(int i=0;i<n;i++) g[i].clear();

    for(int i=1;i<n;i++) {
        int p;
        cin >> p;
        p--;
        g[p].push_back(i);
    }

    fill(parTracker, parTracker+n, -1);

    bool canBeDoneInOne = true;

    for(int u: g[0]) if(g[u].size()) canBeDoneInOne = false;

    bool canBeDoneInTwo = false;

    if(!canBeDoneInOne) {
        canBeDoneInTwo = true;
        for(int u: g[0]) {
            int par = -1;
            if(!dfsCheck2(u, 0, par)) {
                canBeDoneInTwo = false;
                break;
            }
            debug(u, par);
            if(par==-1) par = 0;
            parTracker[u] = par;
        }
    }

    if(canBeDoneInOne) {
        dfsColor(0, 0, 1);
    }
    else if(canBeDoneInTwo) {
        for(int u: g[0]) {
            dfsColor(u, parTracker[u]+1, 2);
        }
    } else {
        dfsColor(0, 0, 3);
    }

    int maxCols = (canBeDoneInOne?1:(canBeDoneInTwo?2:3));
    cout << maxCols << "\n";
    for(int i=1;i<n;i++) cout << ans[i] << " ";
    cout << endl;

    vector<int> ones;

    while(true) {
        int x;
        cin >> x;
        debug(x);
        if(x) break;
        
        ones.clear();
        for(int j=1;j<=maxCols;j++) {
            int f;
            cin >> f;
            if(f==1) ones.push_back(j);
        }

        if(canBeDoneInOne) {
            cout << 1 << endl;
        } else if(canBeDoneInTwo) {
            if(ones.size()==1) cout << ones[0] << endl;
            else {
                assert(ones.size()==2);
                cout << 1 << endl;
            }
        } else {
            if(ones.size()==1) cout << ones[0] << endl;
            else if(count(ones.begin(), ones.end(), 1) && count(ones.begin(), ones.end(), 2)) cout << 1 << endl;
            else if(count(ones.begin(), ones.end(), 2) && count(ones.begin(), ones.end(), 3)) cout << 2 << endl;
            else cout << 3 << endl;
        }

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