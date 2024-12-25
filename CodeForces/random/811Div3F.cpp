/**
*    author:  lazyhash(yashkundu)
*    created: 28 Jul, 2024 | 13:44:34
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, d12, d23, d13;
vector<pair<int, int>> edges;
 
void solve() {
    cin >> n >> d12 >> d23 >> d13;

    int dep = (d12+d13) - d23;


    if(dep<0 || dep&1) {
        cout << "NO\n";
        return;
    }

    dep /= 2;

    if(d12<dep || d13<dep) {
        cout << "NO\n";
        return;
    }

    if(d12==dep && d13==dep) {
        cout << "NO\n";
        return;
    }

    int cnt = 1+d12+d13-dep;

    if(cnt>n) {
        cout << "NO\n";
        return;
    }


    int lca = -1;
    if(d12==dep) lca = 2;
    else if(d13==dep) lca = 3;

    edges.clear();
    int rem = 4;

    int last = 1;
    for(int i=0;i<dep-1;i++) {
        edges.push_back({last, rem});
        last = rem++;
    }

    if(dep) {
        if(lca==-1) {
            edges.push_back({last, rem});
            last = rem++;
        } else {
            edges.push_back({last, lca});
            last = lca;
        }
    }


    int last1 = last;
    for(int i=0;i<d12-dep-1;i++) {
        edges.push_back({last1, rem});
        last1 = rem++;
    }

    if(d12-dep) {
        edges.push_back({last1, 2});
    }

    last1 = last;
    for(int i=0;i<d13-dep-1;i++) {
        edges.push_back({last1, rem});
        last1 = rem++;
    }


    if(d13-dep) {
        edges.push_back({last1, 3});
    }

    last = 1;
    while(rem<=n) {
        edges.push_back({last, rem});
        last = rem++;
    }

    
    cout << "YES\n";
    for(auto p: edges) cout << p.first << " " << p.second << "\n";









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