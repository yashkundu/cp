/**
*    author:  lazyhash(yashkundu)
*    created: 30 Nov, 2024 | 21:26:34
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
#include <assert.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<int> a;
int cnt[3];
set<int> pos[3];

vector<pair<int, int>> ops;
 
void solve() {
    cin >> n;
    a.resize(n);
    for(int j=0;j<3;j++) cnt[j] = 0;
    for(int j=0;j<3;j++) pos[j].clear();

    ops.clear();


    for(int i=0;i<n;i++) {
        cin >> a[i];
        pos[a[i]].insert(i);
        cnt[a[i]]++;
    }


    for(int i=0;i<cnt[0];) {
        if(a[i]==1) {
            int ind = *pos[0].rbegin();
            pos[0].erase(ind);
            pos[0].insert(i);
            pos[1].erase(i);
            pos[1].insert(ind);
            swap(a[i], a[ind]);
            ops.push_back({i, ind});
            i++;
        } else if(a[i]==2) {
            int ind = *pos[1].rbegin();
            pos[1].erase(ind);
            pos[1].insert(i);
            pos[2].erase(i);
            pos[2].insert(ind);
            swap(a[i], a[ind]);
            ops.push_back({i, ind});
        } else {
            i++;
        }
    }

    for(int i=cnt[0];i<cnt[0]+cnt[1];i++) {
        if(a[i]==2) {
            int ind = *pos[1].rbegin();
            pos[1].erase(ind);
            pos[1].insert(i);
            pos[2].erase(i);
            pos[2].insert(ind);
            swap(a[i], a[ind]);
            ops.push_back({i, ind});
        }
    }

    assert(ops.size()<=n);

    cout << ops.size() << "\n";

    for(auto p: ops) cout << p.first + 1 << " " << p.second+1 << "\n";









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