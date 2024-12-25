/**
*    author:  lazyhash(yashkundu)
*    created: 13 Nov, 2024 | 20:51:04
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


bool is_palindrome(string s) {
    int n = s.size();
    for(int i=0;i<n/2;i++) {
        if(s[i]!=s[n-i-1]) return false;
    }
    return true;
}

int n;
string s;
 
void solve() {
    cin >> n >> s;


    if(is_palindrome(s)) {
        cout << "0\n";
        return;
    }


    string s1 = s.substr(0, n-1), s2 = s.substr(1, n-1);

    if(!is_palindrome(s1) || !is_palindrome(s2)) {
        cout << "1\n";
        return;
    }

    cout <<"-1\n";

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