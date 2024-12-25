/**
*    author:  lazyhash(yashkundu)
*    created: 25 Sep, 2024 | 18:22:36
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
#include <map>
#include <queue>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


int n;
vector<pair<int, int>> v;


set<pair<int, int>> st;
map<pair<int, int>, pair<int, int>> ans;

queue<pair<int, int>> q;

int x, y;

 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> x >> y;
        v.push_back({x, y});
        st.insert({x, y});
    }


    for(auto [x, y]: v) {
        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(st.count({nx, ny})) continue;
            ans[{x, y}] = {nx, ny};
            q.push({x, y});
            break;
        }
    }


    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(!st.count({nx, ny}) || ans.count({nx, ny})) continue;
            ans[{nx, ny}] = ans[{x, y}];
            q.push({nx, ny});
        }
    }

    for(auto [x, y]: v) {
        cout << ans[{x, y}].first << " " << ans[{x, y}].second << "\n";
    }



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