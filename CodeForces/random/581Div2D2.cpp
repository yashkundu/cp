/**
*   author: lazyhash(yashkundu)
*   created: 30 Mar, 2024 | 17:13:25
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
    string s;
    cin >> s;

    vector<int> v;


    int n = s.size();

    for(int i=0;i<n;i++) {
        if(s[i]=='1') v.push_back(i);
        else {
            if(!v.empty() && s[v.back()]=='1') v.pop_back();
            else v.push_back(i);
        }
    }

    for(int i: v) if(s[i]=='1') s[i] = '0';

    cout << s << "\n";


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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/