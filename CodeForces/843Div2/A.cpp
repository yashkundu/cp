/**
*    author:  lazyhash(yashkundu)
*    created: 15 Jan, 2023 | 01:37:52
**/
#include <iostream>
#include <vector>
#include <string.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
void print(string s1, string s2, string s3) {
    cout << s1 << " " << s2 << " " << s3 << "\n";
}
 
void solve() {
    string str;
    cin >> str;

    int n = str.length();

    if(str.length()==3) {
        cout << str[0] << " " << str[1] << " " << str[2];
    } else if(str.length()==4) {
        if(str[0]==str[3]) {
            cout << str[0] << " " << str.substr(1, 2) << " " << str[3];
        } else if(str[0]==str[1]) {
            cout << str[0] << " " << str[1] << " " << str.substr(2, 2);
        } else if(str[2]==str[3]) {
            cout << str.substr(0, 2) << " " << str[2] << " " << str[3];
        } else {
            if(str[0]=='a') {
                cout << str.substr(0, 2) << " " << str[2] << " " << str[3];
            } else {
                 cout << str[0] << " " << str[1] << " " << str.substr(2, 2);
            }
        }
    } else {
        if(str[0]==str[n-1]) {
            cout << str[0] << " " << str.substr(1, n-2) << " " << str[n-1];
        } else if(str[0]==str[1]) {
            cout << str[0] << " " << str[1] << " " << str.substr(2, n-2);
        } else if(str[n-2]==str[n-1]) {
            cout << str.substr(0, n-2) << " " << str[n-2] << " " << str[n-1];
        } else {
            cout << str.substr(0, 2) << " " << str.substr(2, n-4) << " " << str.substr(n-2, 2);
        }
    }
    cout << "\n";
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