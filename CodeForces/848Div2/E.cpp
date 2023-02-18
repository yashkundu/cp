/**
*    author:  lazyhash(yashkundu)
*    created: 11 Feb, 2023 | 12:51:53
**/
#include <iostream>
#include <vector>
#include <assert.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;


struct space {
    vector<int> v;
    space() {
        v.resize(30, 0);
    }
    space operator+=(int x) {
        for(int j=29,k=(1<<29);j>=0;j--,k/=2) {
            if((x&k)) {
                if(!v[j]) {
                    v[j] = x;
                    return *this;
                }
                else x ^= v[j];
            }
        }
        return *this;
    }
    space operator+=(const space &s1) {
        for(int j=29;j>=0;j--) {
            (*this) += s1.v[j];
        }
        return *this;
    }
    friend space operator+(const space &s1, const space &s2) {
        space s;
        for(int j=29;j>=0;j--) {
            s += s1.v[j];
            s += s2.v[j];
        }
        return s;
    }
    int maxxor() {
        int mx = 0;
        for(int i=29;i>=0;i--) {
            if((mx^v[i])>mx) mx = mx^v[i];
        }
        return mx;
    }
};

const int N = 2e5+10;
const int LG = 20;
vector<vector<int>> par(N, vector<int>(LG, 0));
vector<int> g[N];
vector<space> spaces(N);
vector<int> a(N), in(N), out(N);
vector<int> trail;


void dfs(int v, int p, int &t) {
    trail.push_back(v);
    par[v][0] = p;
    for(int i=1;i<LG;i++) {
        par[v][i] = par[v][i-1]==-1?-1:par[par[v][i-1]][i-1];
    }
    in[v] = t;
    for(int u: g[v]) {
        if(u==p) continue;
        dfs(u, v, ++t);
        spaces[v] += spaces[u];
    }
    out[v] = t + 1;
    spaces[v] += a[v];
}

bool is_ancestor(int v, int u) {
    if(v==-1) return true;
    return in[v]<=in[u] && out[v]>=out[u];
}

int get_immediate_child(int v, int u) {
    for(int j=LG-1;j>=0;j--) {
        if(!is_ancestor(par[u][j], v)) {
            u = par[u][j];
        }
    }
    return u;
}
 
void solve() {
    int n;
    cin >> n;

    for(int i=0;i<n;i++) cin >> a[i];

    for(int i=0;i<n;i++) {
        g[i].clear();
        spaces[i] = space();
    }
    trail = vector<int>();

    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v), g[v].push_back(u);
    }
    // tree rooted at 0
    int t = 0;
    dfs(0, -1, t);


    assert(trail.size()==n);
    vector<space> pre(n+1);
    for(int i=1;i<=n;i++) {
        pre[i] += pre[i-1];
        pre[i] += a[trail[i-1]];
    }
    vector<space> suf(n+2);
    for(int i=n;i>0;i--) {
        suf[i] += suf[i+1];
        suf[i] += a[trail[i-1]];
    }

    int q;
    cin >> q;
    while(q--) {
        int r, v;
        cin >> r >> v;
        r--, v--;
        if(r==v) {
            cout << pre[n].maxxor() << "\n";
        }
        else if(!is_ancestor(v, r)) {
            cout << spaces[v].maxxor() << "\n";
        } else {
            int x = get_immediate_child(v, r);
            space s = pre[in[x]] + suf[out[x]+1];
            cout << s.maxxor() << "\n";
        }
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