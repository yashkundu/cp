/**
*   author: lazyhash(yashkundu)
*   created: 31 Dec, 2023 | 15:39:29
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


const int N = 1e5+10;

int a[N];
int vis[N];
bool isOn[N];
int nxt[N];
int deg[N];
vector<int> cStarts;


void colorCycle(int v) {
    cStarts.push_back(v);
}


void dfs(int v) {
    if(vis[v]) return;
    vis[v] = 1;
    int u = nxt[v];
    if(vis[u]==1) {
        // cycle 
        colorCycle(u);
    }
    else dfs(u);
    vis[v] = 2;
}


bool calcResForCycle(int v, vector<int> &ans) {
    int x = v;
    int sPoint = 0;
    if(isOn[v]) sPoint = v;

    if(!sPoint)
        while(nxt[x]!=v) {
            if(isOn[nxt[x]]) {
                sPoint = nxt[x];
                break;
            }
            x = nxt[x];
        }

    if(!sPoint)
        return true;


    v = sPoint;

    x = v;
    vector<vector<int>> segs;
    do {
        vector<int> seg;
        seg.push_back(x);
        x = nxt[x];
        while(!isOn[x]) {
            seg.push_back(x);
            x = nxt[x];
        }
        segs.push_back(seg);
    } while(x!=v);


    if(segs.size()&1) return false;

    int oddSize = 0, evenSize = 0;
    for(int i=0;i<segs.size();i++) {
        if(i&1) oddSize += segs[i].size();
        else evenSize += segs[i].size();
    }

    if(evenSize<oddSize) {
        for(int i=0;i<segs.size();i+=2) {
            for(int x: segs[i]) ans.push_back(x);
        }
    } else {
        for(int i=1;i<segs.size();i+=2) {
            for(int x: segs[i]) ans.push_back(x);
        }
    }
    return true;

}


 
void solve() {
    int n;
    cin >> n;
    fill(vis, vis+n+1, 0);
    fill(nxt, nxt+n+1, 0);
    fill(deg, deg+n+1, 0);
    cStarts.clear();

    string s;
    cin >> s;
    for(int i=1;i<=n;i++) isOn[i] = (s[i-1]=='1');

    for(int i=1;i<=n;i++) {
        cin >> a[i];
        nxt[i] = a[i];
        deg[a[i]]++;
    }

    // coloring all the cycles
    for(int i=1;i<=n;i++) dfs(i);

    vector<int> leaves;
    for(int i=1;i<=n;i++) if(!deg[i]) leaves.push_back(i);


    vector<int> ans;

    while(!leaves.empty()) {
        int v = leaves.back();
        leaves.pop_back();
        if(isOn[v]) {
            ans.push_back(v);
            isOn[v] = 0;
            isOn[nxt[v]] ^= 1;
        }
        deg[nxt[v]]--;
        if(!deg[nxt[v]]) leaves.push_back(nxt[v]);
    }


    for(int v: cStarts) {
        if(!calcResForCycle(v, ans)) {
            cout << "-1\n";
            return;
        }
    }

    cout << ans.size() << "\n";
    for(int x: ans) cout << x << " ";
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/