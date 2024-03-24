/**
*   author: lazyhash(yashkundu)
*   created: 27 Aug, 2023 | 17:08:07
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
    int n = s.size();
    string s1, s2;
    for(int i=0;i<n;i++) s1 += "()";
    for(int i=0;i<n;i++) s2 += "(";
    for(int i=0;i<n;i++) s2 += ")";

    if(s1.find(s)==string::npos) {
        cout << "YES\n";
        cout << s1 << "\n";
        return;
    }
     
    if(s2.find(s)==string::npos) {
        cout << "YES\n";
        cout << s2 << "\n";
        return;
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/