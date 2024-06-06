/**
*   author: lazyhash(yashkundu)
*   created: 27 Apr, 2024 | 18:31:23
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e6+10;
int preOdd[N], preEven[N];
 
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    for(int i=0;i<=n;i++) preOdd[i] = preEven[i] = 0;

    for(int i=0;i<n;i++) {
        if(i%2==1 && (s[i]=='[' || s[i]==']')) preOdd[i+1] = 1;
        if(i%2==0 && (s[i]=='[' || s[i]==']')) preEven[i+1] = 1;
        preOdd[i+1] += preOdd[i];
        preEven[i+1] += preEven[i];
    }

    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int x = abs(preEven[r+1]-preEven[l] - (preOdd[r+1]-preOdd[l]));
        cout << x << "\n";
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/