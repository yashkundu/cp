/**
*   author: lazyhash(yashkundu)
*   created: 14 Mar, 2023 | 00:11:59
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <iomanip>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ld calc(int a, int b, int c){
    ld den = (ld)a*b*c;
    return (ld)(a+b+c)/den;
}

void solve() {
    int n;
    cin >> n;


    vector<int> pos, neg;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        if(x>0) pos.push_back(x);
        else neg.push_back(-x);
    }

    // i/x increasing
    sort(pos.rbegin(), pos.rend());
    sort(neg.begin(), neg.end());
    for(int &x: neg) x *= -1;
    for(int &x: pos) neg.push_back(x);
    vector<int> v;
    for(int i=0;i<3;i++) {
        v.push_back(neg.back());
        neg.pop_back();
    }
    for(int i=0;i<min(3, (int)neg.size());i++) v.push_back(neg[i]);

    ld ansmin = 1e18;
    ld ansmax = -1e18;

    int m = v.size();


    for(int i=0;i<m;i++) {
        for(int j=i+1;j<m;j++) {
            for(int k=j+1;k<m;k++) {
                ansmin = min(ansmin, calc(v[i], v[j], v[k]));
                ansmax = max(ansmax, calc(v[i], v[j], v[k]));
            }
        }
    }

    cout << setprecision(20) << ansmin << "\n" << ansmax << "\n";


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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/