/**
*    author:  lazyhash(yashkundu)
*    created: 12 Oct, 2024 | 15:34:47
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 

bool check(string s, string t) {
    int pos = s.find(t);
    if(pos==-1) return false;

    for(int i=0;i<pos;i++) if(s[i]!='1') return false;
    for(int i=pos+t.size();i<s.size();i++) if(s[i]!='1') return false;
    return true;
}

ll x, y;
string s, t;

void solve() {
    cin >> x >> y;

    if(x==y) {
        cout << "YES\n";
        return;
    }

    s = "";

    while(x) {
        if(x&1) s = '1' + s;
        else s = '0' + s;
        x >>= 1;
    }

    t = "";
    while(y) {
        if(y&1) t = '1' + t;
        else t = '0' + t;
        y >>= 1;
    }

    string ns = s + '1';
    while(s.back()=='0') s.pop_back();

    if(check(t, s) || (reverse(s.begin(), s.end()), check(t, s)) || check(t, ns) || (reverse(ns.begin(), ns.end()), check(t, ns))) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";


    
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