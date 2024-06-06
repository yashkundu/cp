/**
*   author: lazyhash(yashkundu)
*   created: 05 May, 2024 | 10:20:24
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int M = 51;
const int N = 1e5+5;

vector<pair<int, int>> g[N*M];

const int inf = 1e9+10;
int dis[N*M];



int n, m;

void solve() {
    cin >> n >> m;

    auto addEdge = [&](int u, int v, int w) {
        g[u*M].push_back({v*M + w, 0});
        for(int was=1;was<M;was++) {
            g[u*M + was].push_back({v*M, (was+w)*(was+w)});
        }
    };

    for(int i=0;i<m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    for(int i=0;i<n*M;i++) dis[i] = inf;
    dis[0] = 0;
    
    set<pair<int, int>> st;
    st.insert({0, 0});

    while(!st.empty()) {
        auto p = *st.begin();
        st.erase(st.begin());
        for(auto f: g[p.second]) {
            if(dis[f.first]>dis[p.second]+f.second) {
                st.erase({dis[f.first], f.first});
                dis[f.first] = dis[p.second] + f.second;
                st.insert({dis[f.first], f.first});
            }
        }
    }

    for(int i=0;i<n;i++) {
        if(dis[i*M]==inf) cout << "-1 ";
        else cout << dis[i*M] << " ";
    }
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/