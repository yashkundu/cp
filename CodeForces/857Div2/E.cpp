/**
*   author: lazyhash(yashkundu)
*   created: 11 Mar, 2023 | 22:37:42
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <numeric>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5+100;
vector<int> dp(N, 0), mx(N, 0);

void normalize(vector<int> &v) {
    vector<int> nV;
    int cur = -1;
    for(int &x: v) {
        if(x>cur) {
            cur = x;
            nV.push_back(cur);
        }
    }
    v = nV;
}
 
void solve() {
    int n;
    cin >> n;

    vector<vector<int>> v(n);
    vector<pair<int, int>> indS;

    for(int i=0;i<n;i++) {
        int k;
        cin >> k;
        for(int j=0;j<k;j++) {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
        normalize(v[i]);
        indS.emplace_back(v[i].back(), i);
    }

    sort(indS.begin(), indS.end());


    for(int i=0;i<=n;i++) dp[i] = mx[i] = 0;

    for(int i=0;i<n;i++) {
        // v[i] = 2, 4, 7, 9, 13
        vector<int> &vec = v[indS[i].second];
        for(int j=1;j<=vec.size();j++) {
            int x = vec[vec.size()-j];
            int ptr = lower_bound(indS.begin(), indS.end(), make_pair(x, 0)) - indS.begin();
            dp[i+1] = max(dp[i+1], mx[ptr] + j);
        }
        mx[i+1] = max(mx[i], dp[i+1]);
    }

    cout << mx[n] << "\n";





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