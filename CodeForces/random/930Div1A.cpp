/**
*    author:  lazyhash(yashkundu)
*    created: 22 Jun, 2024 | 11:59:33
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


string query(int a, int b, int c, int d) {
    cout << "? " << a << " " << b << " " << c << " " << d << endl;
    string s;
    cin >> s;
    return s;
}

void output(int i, int j) {
    cout << "! " << i << " " << j << endl;
}

int n;
vector<int> inds;

 
void solve() {
    cin >> n;
    inds.clear();


    int mx = 0;
    string s;
    for(int i=1;i<n;i++) {
        s = query(mx, mx, i, i);
        if(s=="<") mx = i;
    }


    
    for(int i=0;i<n;i++) {
        if(i==mx) continue;
        if(inds.empty()) {
            inds.push_back(i);
        } else {
            s = query(inds.back(), mx, i, mx);
            if(s=="=") inds.push_back(i);
            else if(s=="<") {
                inds.clear();
                inds.push_back(i);
            }
        }
    }

    int mn = inds[0];
    for(int i=1;i<inds.size();i++) {
        s = query(mn, mn, inds[i], inds[i]);
        if(s==">") mn = inds[i];
    }

    output(mn, mx);


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