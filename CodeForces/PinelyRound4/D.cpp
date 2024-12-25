/**
*    author:  lazyhash(yashkundu)
*    created: 29 Jul, 2024 | 14:19:17
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
 
void solve() {
    cin >> n;
    if (n < 6) {
        if (n == 1)
            cout << 1 << '\n' << "1" << '\n';
        else if (n == 2)
            cout << 2 << '\n' << "1 2" << '\n';
        else if (n == 3)
            cout << 2 << '\n' << "1 2 2" << '\n';
        else if (n == 4)
            cout << 3 << '\n' << "1 2 2 3" << '\n';
        else if (n == 5)
            cout << 3 << '\n' << "1 2 2 3 3" << '\n';
    } else {
        cout << "4\n";
        for(int i=1;i<=n;i++) {
            cout << i%4+1 << " ";
        }
        cout << "\n";
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