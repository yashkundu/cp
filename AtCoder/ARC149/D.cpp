/**
*    author:  lazyhash(yashkundu)
*    created: 22 Jan, 2023 | 10:55:34
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

const int N = 1e6+1;
 
 
void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> X(n), D(m);

    for(int i=0;i<n;i++) cin >> X[i];
    for(int i=0;i<m;i++) cin >> D[i];

    vector<pair<bool, ll>> ans(N);
    vector<int> par(N, -1);
    vector<int> order;  // order of computation

    int l = 1, r = N + 1;
    ll add = 0;

    for(int i=0;i<m;i++) {
        if(l>=r) break;
        int d = D[i];
        add += (l+add>0?-d:d);
        ll m = -add;
        if(m<l || m>=r) continue;
        ans[int(m)] = {true, i+1};

        int lSize = m-l, rSize = r - m - 1;
        if(lSize<=rSize) {
            for(int x=l;x<m;x++) {
                int y = m + m - x;
                par[x] = y;
                order.push_back(x);
            }
            l = m+1;
       } else {
            for(int x=m+1;x<r;x++) {
                int y = m + m - x;
                par[x] = y;
                order.push_back(x);
            }
            r = m;
        }
    }
    for(int x =l;x<r;x++) ans[x] = {false, x+add};

    while(!order.empty()) {
        int x = order.back();
        order.pop_back();
        int y = par[x];
        if(ans[y].first) {
            ans[x] = ans[y];
        } else {
            ans[x] = {false, -ans[y].second};
        }
    }

    for(int x: X) {
        cout << (ans[x].first?"Yes":"No") << " ";
        cout << ans[x].second << "\n";
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