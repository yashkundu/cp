/**
*   author: lazyhash(yashkundu)
*   created: 29 Feb, 2024 | 20:22:43
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5+10;
int a[2][N];
 
void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;
    for(int i=0;i<n;i++) a[0][i] = s[i]-'0';
    cin >> s;
    for(int i=0;i<n;i++) a[1][i] = s[i] - '0';

    int left = 0, right = n;

    for(int i=1;i<n;i++) {
        if(a[0][i]<a[1][i-1]) left = i;
        if(a[0][i]>a[1][i-1]) {
            right = i;
            break;
        }
    }


    int i = 0;
    while(i<=left) {
        cout << a[0][i];
        i++;
    }
    i--;
    while(i<=n-1) {
        cout << a[1][i];
        i++;
    }

    cout << "\n";
    cout << right - left << "\n";

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