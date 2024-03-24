// https://codeforces.com/problemset/problem/1887/C


/**
*   author: lazyhash(yashkundu)
*   created: 10 Jan, 2024 | 22:49:46
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
#include <assert.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

const int N = 5e5+10;
ll a[N];
ll dA[N];
int l[N], r[N], x[N];
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve() {
    int n;
    cin >> n;

    for(int i=0;i<n;i++) cin >> a[i];


    int q;
    cin >> q;

    int minInd = 0;
    map<int, ll> mp;
    
    for(int i=1;i<=q;i++) {
        cin >> l[i] >> r[i] >> x[i];
        mp[l[i]] += x[i];
        if(!mp[l[i]]) mp.erase(l[i]);
        mp[r[i]+1] -= x[i];
        if(!mp[r[i]+1]) mp.erase(r[i]+1);

        auto it = mp.begin();
        if(it!=mp.end()) {
            int key = it->first;
            ll val = it->second;
            assert(val!=0);
            if(val<0) {
                minInd = i;
                mp.clear();
            } 
        }
    }


    dA[0] = a[0];
    for(int i=1;i<n;i++) dA[i] = a[i] - a[i-1];
    for(int i=1;i<=minInd;i++) {
        dA[l[i]-1] += x[i];
        dA[r[i]] -= x[i];
    }

    for(int i=1;i<n;i++) dA[i] += dA[i-1];

    for(int i=0;i<n;i++) cout << dA[i] << " ";
    




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