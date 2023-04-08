/**
*   author: lazyhash(yashkundu)
*   created: 31 Mar, 2023 | 14:00:43
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve() {
    int n;
    cin >> n;
    vector<int> pos, neg, zero;

    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        if(x>0) pos.push_back(x);
        else if(x<0) neg.push_back(x);
        else zero.push_back(x);
    }

    if(zero.size()==n) {
        cout << "No\n";
        return;
    }


    vector<int> ans;

    ll sum = 0;
    while(neg.size() || pos.size()) {
        if(sum>0 && neg.size()) {
            ans.push_back(neg.back());
            sum += neg.back();
            neg.pop_back();
        } else if(pos.size()) {
            ans.push_back(pos.back());
            sum += pos.back();
            pos.pop_back();
        } else {
            ans.push_back(neg.back());
            sum += neg.back();
            neg.pop_back();
        }
    }

    while(!zero.empty()) {
        ans.push_back(zero.back());
        zero.pop_back();
    }

    cout << "Yes\n";
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