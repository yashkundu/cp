/**
*    author:  lazyhash(yashkundu)
*    created: 09 Oct, 2024 | 20:11:00
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m;
string s, t;



bool check(string a, string b) {
    int n = a.size(), m = b.size();
    if(n<=m) return false;

    int ind = m;
    for(int i=0;i<m;i++) {
        if(a[i]!=b[i]) {
            ind = i;
            break;
        }
    } 

    for(int i=0;i<m-ind;i++) {
        if(a[n-1-i]!=b[m-1-i]) return false;
    }

    return true;



}

 
void solve() {
    cin >> n >> m;
    cin >> s >> t;


    if(s==t) {
        cout << "0\n";
        return;
    }


    if(s[0]!=t[0]) {
        cout << "-1\n";
        return;
    }

    if(check(s, t) || check(t, s)) {
        cout << "1\n";
    } else {
        cout << "2\n";
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