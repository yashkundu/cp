/**
*    author:  lazyhash(yashkundu)
*    created: 17 Jun, 2024 | 10:45:08
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
 
const int MAXN = 2e5+10;
int a[MAXN], pref[MAXN];

int n, q;
int l, r;

map<int, vector<int>> mp;


void solve() {
    cin >> n >> q; 
    mp.clear();

    pref[0] = 0;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        pref[i+1] = pref[i]^a[i];
    }

    for(int i=0;i<=n;i++) {
        if(!mp.count(pref[i])) mp[pref[i]] = vector<int>();
        mp[pref[i]].push_back(i);
    }


    while(q--) {
        cin >> l >> r;
        if(pref[l-1]==pref[r]) {
            cout << "Yes\n";
            continue;
        }
        else {
            int val = pref[l-1]^pref[r];
            auto &v = mp[val^pref[l-1]];
            auto it = lower_bound(v.begin(), v.end(), l);
            if(it==v.end() || *it>=r-1) {
                cout << "No\n";
                continue;
            }
            int ind = *it;
            auto &v2 = mp[pref[l-1]];
            auto it2 = lower_bound(v2.begin(), v2.end(), ind+1);
            if(it2==v2.end() || *it2>=r) {
                cout << "No\n";
                continue;
            }
            cout << "Yes\n";
        }
    }

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