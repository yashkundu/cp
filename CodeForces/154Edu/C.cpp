/**
*   author: lazyhash(yashkundu)
*   created: 09 Sep, 2023 | 15:53:09
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <assert.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


// 1---++-
 
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int cur = 0;
    int oddElInd = -1;
    int cntr = 0;
    for(int i=0;i<n;i++) {
        char ch = s[i];
        switch (ch)
        {
        case '+':
            cntr++;
            cur++;
            break;
        case '-':
            if(cntr) cntr--;
            cur--;
            if(oddElInd>=cur) oddElInd = -1;
            assert(cur>=0);
            break;
        case '1':
            cntr = 0;
            if(oddElInd!=-1) {
                cout << "NO\n";
                return;
            }
            break;
        case '0':
            if(cur<=1) {
                cout << "NO\n";
                return;
            }
            if(oddElInd==-1) {
                if(cntr>0) 
                    oddElInd = cur-1;
                else {
                    cout << "NO\n";
                    return;
                }
            }
            break;
        }
    }

    cout << "YES\n";

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