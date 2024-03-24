/**
*   author: lazyhash(yashkundu)
*   created: 21 May, 2023 | 22:53:19
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
#include <map>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


const int N = 1e5+10;
set<int> *s[N];
int minOps[N] = {0};
int xorPath[N] = {0};
int a[N];
vector<int> g[N];

int n;


void dfs(int v, int p) {
    if(p!=-1) xorPath[v] ^= xorPath[p];
    vector<int> childs;
    for(int u: g[v]) {
        if(u==p) continue;
        dfs(u, v);
        childs.push_back(u);
    }
    if(childs.size()==0) {
        minOps[v] = 0;
        s[v] = new set<int>{xorPath[v]};
        return;
    }
    if(childs.size()==1) {
        s[v] = s[childs.front()];
        minOps[v] = minOps[childs.front()];
        return;
    }
    s[v] = new set<int>();
    int num = 0;
    int ops = 0;
    for(int child: childs) {
        ops += minOps[child];
        num += s[child]->size();
        s[v]->insert(s[child]->begin(), s[child]->end());
    }
    if(num==s[v]->size()) {
        minOps[v] = ops + childs.size() - 1;
        for(int child: childs) delete s[child];
        return;
    }
    // choosing
    map<int, int> cnt;
    for(int child: childs) {
        for(auto it=s[child]->begin();it!=s[child]->end();it++) 
            cnt[*it]++;
    }

    int mxCnt = max_element(cnt.begin(), cnt.end(), 
    [](const auto &p1, const auto &p2) {
        return p1.second < p2.second;
    })->second;
    set<int> *nSet = new set<int>;
    for(auto it=cnt.begin();it!=cnt.end();it++) {
        if(it->second==mxCnt) nSet->insert(it->first);
    }
    delete s[v];
    s[v] = nSet;
    minOps[v] = ops + childs.size() - mxCnt;
    for(int child: childs) delete s[child];
}


 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) xorPath[i] = a[i];
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    int ans = minOps[0];
    if(s[0]->find(0)==s[0]->end()) ans++;
    cout << ans;
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