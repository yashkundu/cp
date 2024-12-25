/**
*    author:  lazyhash(yashkundu)
*    created: 03 Oct, 2024 | 23:16:58
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

int query(int i, int j, int k) {
    cout << "? " << i << " " << j << " " << k << endl;
    int x;
    cin >> x;
    if(x==-1) exit(0);
    return x;
}

void output(int i, int j) {
    cout << "! " << i << " " << j << endl;
}


pair<int, int> perform(int a, int b, int c, int d) {
    vector<pair<int, int>> v;
    v.push_back({query(b, c, d), a});
    v.push_back({query(a, c, d), b});
    v.push_back({query(a, b, d), c});
    v.push_back({query(a, b, c), d});
    sort(v.begin(), v.end());
    return {v[0].second, v[1].second};
}

int n;
 
void solve() {
    cin >> n;

    pair<int, int> p = {1, 2};


    for(int i=4;i<=n;i+=2) {
        p =  perform(p.first, p.second, i, i-1);
    }

    if(n&1) {
        int k = -1;
        for(int i=1;i<n;i++) {
            if(i!=p.first && i!=p.second) {
                k = i;
                break;
            }
        }
        p = perform(p.first, p.second, k, n);
    }

    output(p.first, p.second);



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