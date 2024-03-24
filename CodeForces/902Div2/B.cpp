/**
*   author: lazyhash(yashkundu)
*   created: 08 Oct, 2023 | 20:48:23
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve() {
    int n, p;
    cin >> n >> p;
    vector<int> a(n), b(n);
    for(int &x: a) cin >> x;
    for(int &x: b) cin >> x;

    vector<int> peoples(n);
    iota(peoples.begin(), peoples.end(), 0);
    sort(peoples.begin(), peoples.end(), [&b](int ind1, int ind2) {
        return b[ind1]<b[ind2];
    });

    vector<int> v;
    int curInd = 0;
    while(v.size()<n) {
        v.push_back(b[peoples[curInd]]);
        a[peoples[curInd]]--;
        if(!a[peoples[curInd]]) curInd++;
    }

    v[n-1] = p;
    for(int j=n-2;j>=0;j--) {
        if(v[j]>p) v[j] = p;
        else break;
    }

    ll res = 0;
    for(int &x: v) res += x;

    cout << res << "\n";


    
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