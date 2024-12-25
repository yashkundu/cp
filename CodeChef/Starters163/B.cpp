/**
*    author:  lazyhash(yashkundu)
*    created: 04 Dec, 2024 | 20:14:35
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


vector<int> calc(string s) {
    int n = s.size();
    vector<int> v;
    for(int i=0;i<n;) {
        int j = i;
        while(j<n && s[j]==s[i]) j++;
        v.push_back(j-i);
        i = j;
    }
    return v;
}

 
void solve() {
    cin >> n >> m;
    cin >> s >> t;


    vector<int> v1 = calc(s), v2 = calc(t);

    if(s[0]!=t[0] || v1.size()!=v2.size()) {
        cout << "NO\n";
        return;
    }

    if(v1.size()==1) {
        if(s==t) {
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
        return;
    }


    for(int i=0;i<v1.size();i++) {
        if(v2[i]>v1[i] || v1[i]%2!=v2[i]%2) {
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/