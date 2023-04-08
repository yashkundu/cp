/**
*   author: lazyhash(yashkundu)
*   created: 28 Feb, 2023 | 20:19:27
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    string a, b;
    cin >> a >> b;

    if(a[0]==b[0]) {
        cout << "YES\n";
        cout << a[0] << "*";
        cout << "\n";
        return;
    } 

    if(a[a.size()-1]==b[b.size()-1]) {
        cout << "YES\n";
        cout << "*" << a[a.size()-1];
        cout << "\n";
        return;
    }

    string x;

    for(int i=0;i+1<a.size();i++) {
        x = a.substr(i, 2);
        if(b.find(x)!=string::npos) {
            cout << "YES\n";
            cout << '*' << x << '*';
            cout << "\n";
            return;
        }
    }

    cout << "NO\n";
    

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