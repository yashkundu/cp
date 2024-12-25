/**
*    author:  lazyhash(yashkundu)
*    created: 03 Jul, 2024 | 16:22:15
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


const int MAXN = int(5e5) + 10;

struct Ftree{
    vector<ll> tree;
    int n;
    Ftree(int n) {
        this->n = n;
        tree.assign(n+1, 0);
    }

    void update(int ind, int val) {
        for(;ind<=n;ind+=ind&-ind) tree[ind] += val;
    }

    ll query(int ind) {
        ll sum = 0;
        for(;ind>0;ind-=ind&-ind) sum += tree[ind];
        return sum;
    }

};

int q;
int tv[MAXN];
int sz;

vector<pair<int, int>> ops[MAXN];
vector<int> g[MAXN];
ll ans[MAXN];

Ftree ft(1);


void dfs(int v) {
    for(auto p: ops[v]) {
        ft.update(p.first, p.second);
    }   
    ans[v] = ft.query(q) - ft.query(tv[v]);
    for(int u: g[v]) dfs(u);
    for(auto p: ops[v]) {
        ft.update(p.first, -p.second);
    }
}


 
void solve() {
    cin >> q;
    for(int i=1;i<=q+1;i++) g[i].clear();
    for(int i=1;i<=q+1;i++) ops[i].clear();

    ft = Ftree(q);

    tv[1] = 0;
    sz = 1;


    for(int i=1;i<=q;i++) {
        int ty;
        cin >> ty;
        if(ty==1) {
            int v;
            cin >> v;
            ++sz;
            tv[sz] = i;
            g[v].push_back(sz);
        } else {
            int v, x;
            cin >> v >> x;
            ops[v].push_back({i, x});
        }
    }

    dfs(1);

    for(int i=1;i<=sz;i++) cout << ans[i] << " ";
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