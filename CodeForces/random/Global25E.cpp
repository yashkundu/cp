/**
*    author:  lazyhash(yashkundu)
*    created: 18 Jun, 2024 | 20:24:15
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
    auto isPalindrome = [&s](int l, int r) {
        for(int i=l;2*(i-l)<r-l;i++) if(s[i]!=s[r-i+l]) return false;
        return true;
    };

    if(!isPalindrome(0,n-1)) {
        cout << "YES\n1\n" << s << "\n";
        return;
    }
    int ind = -1;
    for(int i=1;i<n;i++) if(s[i]!=s[0]) {
        ind = i;
        break;
    }
    if(ind==-1) {
        cout << "NO\n";
        return;
    }
    if(!isPalindrome(ind+1, n-1)) {
        cout << "YES\n2\n" << s.substr(0, ind+1) << " " << s.substr(ind+1) << "\n";
        return;
    }
    if(ind==1 || ind==n/2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n2\n" << s.substr(0, ind+2) << " " << s.substr(ind+2) << "\n";
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