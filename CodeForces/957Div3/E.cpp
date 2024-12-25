/**
*    author:  lazyhash(yashkundu)
*    created: 11 Jul, 2024 | 20:55:46
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int n;
int cur = 0;
vector<int> digs;
vector<pair<int, int>> ans;

 
void solve() {
    cin >> n;

    int tmp = n;
    digs.clear();
    while(tmp>0) {
        digs.push_back(tmp%10);
        tmp /= 10;
    }

    reverse(digs.begin(), digs.end());
    
    ans.clear();

    


    cur = 0;
    pair<int, int> p(0, 0);
    for(int j=0;j<7;j++) {
        cur = cur*10 + digs[j%int(digs.size())];
        for(int a=1;a<=10000;a++) {
            int b = int(digs.size())*a-(j+1);
            if(b<=0 || b>10000) continue;
            if(n*a-b==cur) {
                ans.push_back({a, b});
            }
        }
    }

    cout << ans.size() << "\n";
    for(auto p: ans) cout << p.first <<" " << p.second << "\n";






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