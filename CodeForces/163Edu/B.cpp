/**
*   author: lazyhash(yashkundu)
*   created: 15 Mar, 2024 | 20:11:30
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


const int N = 60;
int a[N];
 
void solve() {

    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    int mn = 0;
    for(int i=0;i<n;i++) {
        if(a[i]<10) {
            if(a[i]<mn) {
                cout << "NO\n";
                return;
            }
            mn = a[i];
        } else {
            int first = a[i]/10, second = a[i]%10;
            if(second>=first && first>=mn) {
                mn = second;
                continue;
            }
            if(a[i]>=mn) {
                mn = a[i];
                continue;
            }
            cout << "NO\n";
            return;
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