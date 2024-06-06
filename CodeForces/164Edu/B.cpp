/**
*   author: lazyhash(yashkundu)
*   created: 12 Apr, 2024 | 20:17:34
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 3e5+10;
int a[N];
 
void solve() {

    int n;
    cin >> n;

    int el;

    for(int i=0;i<n;i++) {
        cin >> a[i];
        el = a[i];
    }


    int mn = 1e9;

    for(int i=0;i<n;) {
        if(a[i]!=el) {
            i++;
            continue;
        }
        int j = i;
        while(j<n && a[j]==el) j++;
        mn = min(mn, j-i);
        i = j;
    }

    if(mn==n) {
        cout << "-1\n";
        return;
    }
    cout << mn << "\n";
    return;


    
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