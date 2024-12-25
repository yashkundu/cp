/**
*    author:  lazyhash(yashkundu)
*    created: 16 Sep, 2024 | 20:40:51
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

 

char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
int n;

void solve() {
    cin >> n;
    string s;
    int del = n%5;
    for(int i=0;i<5;i++) {
        for(int j=0;j<n/5;j++) s += vowels[i];
        if(del) {
            s += vowels[i];
            del--;
        }
    }
    cout << s << "\n";

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