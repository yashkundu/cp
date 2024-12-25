/**
*    author:  lazyhash(yashkundu)
*    created: 21 Aug, 2024 | 21:52:13
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
string s;

int freq[26];
 
void solve() {
    cin >> n;
    for(int i=0;i<26;i++) freq[i] = 0;

    for(int i=0;i<=2*n;i++) {
        cin >> s;
        for(int j=0;j<s.size();j++) freq[s[j]-'a']++;
    }

    for(int i=0;i<26;i++) {
        if(freq[i]&1) {
            cout << (char)('a'+i) << "\n";
            return;
        }
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/