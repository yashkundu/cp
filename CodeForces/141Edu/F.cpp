/**
*    author:  lazyhash(yashkundu)
*    created: 05 Feb, 2023 | 21:16:35
**/
#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

const int N = 3005;

vector<int> g[N], pos[N];
vector<bool> used(N, false);

vector<int> mt(N, 0);

 
bool get_aug_path(int v) {
    if(used[v]) return false;
    used[v] = true;
    for(int u: g[v]) {
        if(!mt[u] || get_aug_path(mt[u])) {
            mt[u] = v;
            return true;
        }
    }
    return false;
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1, 0), b(n+1, 0);

    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];

    vector<int> cycleA(n+1, 0), cycleB(n+1, 0);
    int cntA = 0, cntB = 0;

    for(int i=1;i<=n;i++) {
        if(!cycleA[i]) {
            int ptr = ++cntA;
            int j = a[i];
            cycleA[i] = ptr;
            while(j!=i) {
                cycleA[j] = ptr;
                j = a[j];
            }
        }
        if(!cycleB[i]) {
            int ptr = ++cntB;
            int j = b[i];
            cycleB[i] = ptr;
            pos[ptr].push_back(i);
            while(j!=i) {
                cycleB[j] = ptr;
                pos[ptr].push_back(j);
                j = b[j];
            }
        }
    }

    for(int i=1;i<=n;i++) {
        g[cycleA[i]].push_back(cycleB[i]);
    }
    

    int num = 0;
    for(int i=1;i<=cntA;i++) {
        used.assign(cntA+1, false);
        num += get_aug_path(i);
    }

    vector<int> ans;

    for(int i=1;i<=cntB;i++) {
        if(!mt[i]) continue;
        for(int &x: pos[i]) if(cycleA[x]==mt[i]) {
            ans.push_back(x);
            break;
        }
    }


    assert(ans.size()==num);

    cout << n - num << "\n";
    sort(ans.begin(), ans.end());

    int j = 0;
    for(int i=1;i<=n;i++) {
        if(ans[j]==i) {
            j++; continue;
        }
        cout << i << " ";
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/