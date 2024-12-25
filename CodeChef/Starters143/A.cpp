/**
*    author:  lazyhash(yashkundu)
*    created: 17 Jul, 2024 | 20:03:08
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, k;
string s, t;

int c1=0, c2 = 0;
int cnt = 0;
 
void solve() {
    cin >> n >> k;
    cin >> s >> t;
    c1 = c2 = 0;

    for(int i=0;i<n;i++) if(s[i]=='1') c1++;
    for(int i=0;i<n;i++) if(t[i]=='1') c2++;

    if(c1!=c2) {
        cout << "NO\n";
        return;
    }

    cnt = 0;
    for(int i=0;i<n;i++) if(s[i]!=t[i]) cnt++;


    if(n==2 && c1==1) {
        cnt = cnt/2;
        if(cnt%2!=k%2) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
        return;
    }

    if(k>=cnt/2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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