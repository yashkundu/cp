/**
*   author: lazyhash(yashkundu)
*   created: 11 Nov, 2023 | 20:18:06
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve() {
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> del;

    for(int i=0;i<n;i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if(!del.count(l)) del[l] = vector<int>();
        if(!del.count(r)) del[r] = vector<int>();
        del[l].push_back(r-l+1);
        del[r].push_back(-1*(r-l+1));
    }

    auto inMiddle = [](int first, int last, int x) {
        return x>=first && x<=last;
    };

    int firstEl = 0, lastEl = 0;
    int cntr = -0;
    int ans = 0;



    for(auto it: del) {
        const int &i = it.first;
        vector<int> &v = it.second;
        for(int dis: v) {
            if(dis>0) {
                cntr++;
                if(inMiddle(i,i+dis-1, 0)) firstEl++;
                if(inMiddle(i,i+dis-1, m-1)) lastEl++;
            }
        }
        ans = max(ans, cntr-min(firstEl, lastEl));
        for(int dis: v) {
            if(dis<0) {
                cntr--;
                if(inMiddle(i+dis+1, i, 0)) firstEl--;
                if(inMiddle(i+dis+1, i, m-1)) lastEl--;
            }
        }
    }

    cout << ans << "\n";

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