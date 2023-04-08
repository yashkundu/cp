/**
*   author: lazyhash(yashkundu)
*   created: 19 Mar, 2023 | 13:23:25
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

const int N = 20;
vector<int> g[N];
int n;

// dp[msk][cur] - if it is possible to traverse mks vertices cur being the last traversed or current vertex, -1 if not possible otherwise it stores the penultimate vertex in the path or the cur vertex if path length is 1
vector<vector<int>> dp((1<<N), vector<int>(N, -1));
vector<vector<int>> cmb((1<<N), vector<int>(N, -1));

int lsb(int n) {
    int i=0;
    while(!(n&1)) {
        n = n>>1;
        i++;
    }
    return i;
}

bool check(int msk, vector<int> &a) {
    for(int u=0;u<n;u++) {
        if(cmb[msk][u]==-1) continue;
        bool b = true;
        for(int v: g[u]) {
            if(cmb[msk][v]==-1) {
                b = false;
                break;
            }
        }
        if(b) return false;
    }
    int k = msk;
    int start = lsb(msk);
    int last = dp[msk][start];
    fill(a.begin(), a.end(), -1);
    a[last] = start;
    while(k>0) {
        int penultimate = dp[k][last];
        k = k - (1<<last);
        if(k>0) a[penultimate] = last;
        last = penultimate;
    }
    for(int u=0;u<n;u++) {
        if(cmb[msk][u]==-1) continue;
        for(int v: g[u]) {
            if(cmb[msk][v]==-1) 
                a[u] = v;
        }
    }
    return true;
}
 
void solve() {
    int m;
    cin >> n >> m;

    for(int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=0,k=1;i<n;i++, k*=2) dp[k][i] = i;
    for(int msk = 0;msk<(1<<n);msk++) {
        int k = msk;
        for(int j=0,k=1;j<n;j++,k*=2) {
            if(!(msk&k)) cmb[msk][j] = msk+k;
        }
    }

    vector<int> cycles;

    for(int msk=0;msk<(1<<n);msk++) {
        for(int cur=0;cur<n;cur++) {
            if(dp[msk][cur]==-1) continue;
            int start = lsb(msk);
            bool b = msk>>(start+1);
            for(int u: g[cur]) {
                if(u==start && b) {
                    dp[msk][u] = cur;
                    cycles.push_back(msk);
                } else if(u>start && cmb[msk][u]!=-1) {
                    dp[cmb[msk][u]][u] = cur;
                }
            }
        }
    }

    

    sort(cycles.begin(), cycles.end());
    cycles.resize(distance(cycles.begin(), unique(cycles.begin(), cycles.end())));


    vector<int> a(n, 0);

    for(int cycle: cycles) {
        if(check(cycle, a)) {
            cout << "Yes\n";
            for(int &x: a) cout << x+1 << " ";
            cout << "\n";
            return;
        }
    }


    cout << "No\n";
    
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