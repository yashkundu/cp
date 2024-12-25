/**
*    author:  lazyhash(yashkundu)
*    created: 20 Aug, 2024 | 20:45:06
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int x;
    cin >> x;
    return x;
}

const int MAXN = 1005;
bool vis[MAXN];

vector<pair<int, int>> edges;
int n;


void process(int u, int v) {
    int x = query(u, v);
    if(x==u) {
        edges.push_back({u, v});
        vis[v] = 1;
        return;
    }
    if(vis[x]) process(x, v);
    else process(u, x);
}

 
void solve() {
    cin >> n;
    fill(vis, vis+n+1, 0);
    edges.clear();

    vis[1] = 1;


    for(int iter=0;iter<n-1;iter++) {
        for(int i=1;i<=n;i++) {
            if(!vis[i]) {
                process(1, i);
                break;
            }
        }
    }



    cout << "! ";
    for(auto p: edges) cout << p.first << " " << p.second << " ";
    cout << endl;


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