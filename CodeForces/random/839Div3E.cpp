/**
*    author:  lazyhash(yashkundu)
*    created: 20 Jul, 2024 | 15:27:09
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
vector<int> p;
int cnt1, cnt2;
 
void solve() {
    cin >> n;
    p.resize(n+1);

    for(int i=1;i<=n;i++) cin >> p[i];

    cnt1 = cnt2 = 0;
    for(int i=1;i<=n;i++) if(p[i]!=i) cnt1++;
    for(int i=1;i<=n;i++) if(p[i]!=n-i+1) cnt2++;


    if(n%2==0) {
        if(cnt1<=n/2) {
            cout << "First\n";
            return;
        }
        if(cnt2<n/2) {
            cout << "Second\n";
            return;
        }
        cout << "Tie\n";
        return;
    }

    if(p[(n+1)/2]==(n+1)/2) {
        if(cnt1<=n/2) {
            cout << "First\n";
            return;
        } 
        if(cnt2<n/2) {
            cout << "Second\n";
            return;
        }
        cout << "Tie\n";
        return;
    }

    if(cnt1<=n/2) {
        cout << "First\n";
        return;
    }
    if(cnt2<=n/2) {
        cout << "Second\n";
        return;
    }

    cout << "Tie\n";



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