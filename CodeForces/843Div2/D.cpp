/**
*    author:  lazyhash(yashkundu)
*    created: 15 Jan, 2023 | 13:27:58
**/
#include <iostream>
#include <vector>
#include <numeric>
#include <assert.h>
#include <deque>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

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

const int N = 3e5+100;
vector<int> spf(N, 0);

vector<int> g[2*N];
vector<int> par(2*N, -1);

void precalc() {
    iota(spf.begin(), spf.end(), 0);
    for(int i=2;i<N;i++) {
        if(spf[i]!=i) continue;
        for(ll j=(ll)i*i;j<N;j+=i) {
            if(spf[j]!=j) continue;
            spf[j] = i;
        }
    }
}
 
 vector<int> factorize(int n) {
    vector<int> pFactors;
    while(n>1) {
        int p = spf[n];
        pFactors.push_back(p);
        while(!(n%p)){ 
            n /= p;
        }
    }
    return pFactors;
 }

void bfs(int source) {
    deque<int> queue;
    queue.push_back(source);
    par[source] = source;
    while(!queue.empty()) {
        int v = queue.front();
        queue.pop_front();
        for(int u: g[v]) {
            if(par[u]!=-1) continue;
            par[u] = v;
            queue.push_back(u); 
        }
    }
}
 
void solve() {
    precalc();
    int n;
    cin >> n;

    vector<int> a(n, 0);

    for(int i=0;i<n;i++) {
        cin >> a[i];
        vector<int> pFactors = factorize(a[i]);
        assert(pFactors.size()<=7);
        for(int p: pFactors) {
            g[i].push_back(p+N);
            g[p+N].push_back(i);
        }
    }

    int s, t;
    cin >> s >> t;
    s--, t--;

    bfs(s);

    if(par[t]==-1) {
        cout << "-1" << "\n";
        return;
    }

    vector<int> path;
    path.push_back(t);

    while(t!=s) {
        t = par[t];
        path.push_back(t);
    }

    int size = (path.size()+1)/2;

    cout << size << "\n";
    reverse(path.begin(), path.end());

    for(int i=0;i<path.size();i+=2) cout << path[i]+1 << " ";
    cout << "\n";

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