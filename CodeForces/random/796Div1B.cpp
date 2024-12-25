/**
*    author:  lazyhash(yashkundu)
*    created: 22 Aug, 2024 | 21:51:24
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
 

int n, m;
vector<pair<int, int>> edges;


int query(string s) {
    cout << "? " << s << endl;
    int x;
    cin >> x;
    return x;
}


void solve() {
    cin >> n >> m;
    edges.clear();

    string s = "";
    for(int i=0;i<m;i++) s += "0";



    for(int i=0;i<m;i++) {
        s[i] = '1';
        int x = query(s);
        edges.push_back({x, i});
        s[i] = '0';
    }


    sort(edges.begin(), edges.end());

    int wt = 0;
    int prval = 0;



    for(auto [w, i]: edges) {
        s[i] = '1';
        int x = query(s);
        if(x-prval==w) {
            wt += w;
        }
        prval = x;
    }

    cout << "! " << wt << endl;









    
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