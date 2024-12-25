/**
*    author:  lazyhash(yashkundu)
*    created: 28 Aug, 2024 | 20:24:47
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int n;
ll x, k;

map<ll, int> freq;

vector<ll> svec;
vector<ll> dvec;


ll h;

 
void solve() {
    cin >> n >> x >> k;

    freq.clear();

    for(int i=0;i<n;i++) {
        cin >> h;
        freq[h]++;
    }

    svec.clear(); dvec.clear();


    for(auto p: freq) {
        svec.push_back(p.first);
        if(p.second>1) dvec.push_back(p.first);
    }



    ll tot = x*k;

    int sz = svec.size();
    int ind = sz-1;

    for(;ind>=0;ind--) {
        if(svec[ind]<tot) break;
    }

    int ans = ind+1;


    int start = sz-1;
    for(;start>=0;start--) {
        if(svec[start]<x) break;
    }


    for(int i=start;i>=0;i--) {
        int snum = max((lower_bound(svec.begin(), svec.end(), svec[i]*k) - svec.begin()) - start - 1, 0L);
        int dnum = lower_bound(dvec.begin(), dvec.end(), min(svec[i]*k, svec[start]+1)) - lower_bound(dvec.begin(), dvec.end(), svec[i]);
        ans = max(ans, start - i + 1 + snum + dnum + i);
    }

    cout << ans << "\n";


    




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