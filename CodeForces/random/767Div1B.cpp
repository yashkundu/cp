/**
*    author:  lazyhash(yashkundu)
*    created: 06 Oct, 2024 | 21:57:53
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<string> v;

map<string, bool> mp;
 
void solve() {
    cin >> n;
    v.resize(n);
    mp.clear();


    for(int i=0;i<n;i++) cin >> v[i];


    for(int i=0;i<n;i++) if(v[i].size()==1) {
        cout << "YES\n";
        return;
    }

    for(int i=0;i<n;i++) {
        string s = v[i];
        if(s[0]==s[s.size()-1]) {
            cout << "YES\n";
            return;
        }
    }


    for(int i=0;i<n;i++) {
        string s = v[i];
        reverse(s.begin(), s.end());
        if(mp[s] || (s.pop_back(), mp[s])) {
            cout << "YES\n";
            return;
        }
        mp[v[i]] = 1;
    }

    mp.clear();
    for(int i=n-1;i>=0;i--) {
        string s = v[i];
        s.pop_back();
        reverse(s.begin(), s.end());
        if(mp[s]) {
            cout << "YES\n";
            return;
        }
        mp[v[i]] = 1;
    }


    cout << "NO\n";








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