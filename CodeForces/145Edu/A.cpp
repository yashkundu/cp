/**
*   author: lazyhash(yashkundu)
*   created: 23 Mar, 2023 | 20:35:13
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
    string str;
    cin >> str;

    map<char, int> mp;

    for(int i=0;i<4;i++) {
        mp[str[i]]++;
    }

    if(mp.size()==1) {
        cout << "-1\n";
    } else if(mp.size()==2 && mp[str[0]]!=2) {
        cout << "6\n";
    } else {
        cout << "4\n";
    }

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