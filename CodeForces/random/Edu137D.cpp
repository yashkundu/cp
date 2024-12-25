/**
*    author:  lazyhash(yashkundu)
*    created: 23 Jul, 2024 | 16:04:47
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

string s;
string ts;
 
vector<string> v;

void solve() {
    cin >> n;
    cin >> s;

    int first = -1;
    for(int i=0;i<n-1;i++) {
        if(s[i]=='1') {
            first = i;
            break;
        }
    }

    int zero = -1;
    for(int i=first;i<n;i++) {
        if(s[i]=='0') {
            zero = i-first;
            break;
        }
    }

    if(first==-1) {
        cout << 0 << "\n";
        return;
    }

    if(zero==-1) {
        cout << s.substr(first) << "\n";
        return;
    }

    

    v.push_back(s.substr(first));

    for(int i=first;i<n&&s[i]=='1';i++) {
        ts = s.substr(first);
        for(int j=zero;j<ts.size();j++) {
            if(s[i+j-zero]=='1') ts[j] = '1';
        }
        v.push_back(ts);
    }

    int ind = -1;

    for(int i=0;i<v.size();i++) {
        if(ind==-1 || v[i]>v[ind]) ind = i;
    }

    cout << v[ind] << "\n";

}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
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