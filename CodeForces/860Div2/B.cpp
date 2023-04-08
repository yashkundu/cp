/**
*   author: lazyhash(yashkundu)
*   created: 26 Mar, 2023 | 20:16:55
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 5e4+10;
vector<int> cnt(N, 0);
 
void solve() {
    int m;
    cin >> m;
    vector<vector<int>> v(m, vector<int>());

    for(int i=0;i<m;i++) {
        int x;
        cin >> x;
        for(int j=0;j<x;j++) {
            int y;
            cin >> y;
            v[i].push_back(y);
            cnt[y]++;
        }
    }

    vector<int> ans;

    for(int i=0;i<m;i++) {
        for(int &x: v[i]) {
            if(cnt[x]==1) {
                if(ans.size()<=i) ans.push_back(x);
            }
            cnt[x]--;
        }
        if(ans.size()!=i+1) {
            cout << "-1\n";

            for(int i=0;i<m;i++) {
                for(int x: v[i]) cnt[x] = 0;
            }

            return;
        }
    }

    for(int i=0;i<m;i++) {
        for(int x: v[i]) cnt[x] = 0;
    }
    

    for(int &x: ans) cout << x << " ";
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