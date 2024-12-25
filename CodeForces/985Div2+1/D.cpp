/**
*    author:  lazyhash(yashkundu)
*    created: 09 Nov, 2024 | 21:32:31
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


const int MAXN = (int)1e5+10;

set<int> g[MAXN];
set<int> bad;

int n, m;
int u, v;


vector<pair<int, pair<int, int>>> ops;


int get(set<int> &st) {
    int x = *st.begin();
    st.erase(st.begin());
    return x;
}


void check(int x) {
    if(g[x].size()>1) bad.insert(x);
    else bad.erase(x);
}

 
void solve() {
    cin >> n >> m;
    for(int i=0;i<n;i++) g[i].clear();

    for(int i=0;i<m;i++) {
        cin >> u >> v;
        u--, v--;
        g[u].insert(v);
        g[v].insert(u);
    }


    bad.clear();

    for(int i=0;i<n;i++) {
        if(g[i].size()>1) bad.insert(i);
    }

    ops.clear();




    while(!bad.empty()) {
        int v = get(bad);

        int a = get(g[v]), b = get(g[v]);
        g[a].erase(v), g[b].erase(v);

        ops.push_back({v, {a, b}});

        if(g[a].count(b)) {
            g[a].erase(b);
            g[b].erase(a);
        } else {
            g[a].insert(b);
            g[b].insert(a);
        }
        check(a), check(b), check(v);
    }   

    int v = -1;
    for(int i=0;i<n;i++) {
        if(g[i].size()) {
            v = i;
            break;
        }
    }

    if(v!=-1) {
        set<int> good;
        good.insert(v);
        for(int x: g[v]) good.insert(x);


        for(int i=0;i<n;i++) {
            if(!good.count(i)) {
                int x = get(g[v]);
                ops.push_back({v, {x, i}});
                g[v].insert(i);
                good.insert(i);
                for(int y: g[i]) good.insert(y);
            }
        }

    }



    cout << ops.size() << "\n";
    for(auto p: ops) {
        cout << p.first + 1 << " " << p.second.first + 1 << " " << p.second.second +1 << "\n";
    }



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