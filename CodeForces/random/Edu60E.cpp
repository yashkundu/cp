/**
*   author: lazyhash(yashkundu)
*   created: 12 May, 2024 | 15:37:32
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
    string t;
    cin >> t;

    int n = t.size();

    string s1(n, 'a'), s2(n, 'a'), s3(n, 'a');

    for(int i=0;i<n;i++) {
        s1[i] = char('a' + (i%26));
        s2[i] = char('a' + ((i/26)%26));
        s3[i] = char('a'+((i/26/26)%26));
    }

    string t1, t2, t3;

    cout << "? " << s1 << endl;
    cin >> t1;

    cout << "? " << s2 << endl;
    cin >> t2;

    cout << "? " << s3 << endl;
    cin >> t3;


    vector<int> p(n);


    for(int i=0;i<n;i++) {
        p[i] = (t1[i]-'a') + (t2[i]-'a')*26 + (t3[i]-'a')*26*26;
    }

    string s(n, 'a');

    for(int i=0;i<n;i++) {
        s[p[i]] = t[i];
    }

    cout << "! " << s << endl;




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