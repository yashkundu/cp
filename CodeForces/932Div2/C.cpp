/**
*   author: lazyhash(yashkundu)
*   created: 05 Mar, 2024 | 20:39:50
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <set>

using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


const int N = 2005;
 
void solve() {
    int n;
    ll l;
    cin >> n >> l;

    vector<pair<ll, ll>> v(n);
    ll minA = 1e18;

    // [(b, a)]
    for(int i=0;i<n;i++) {
        cin >> v[i].second;
        cin >> v[i].first;
        minA = min(minA, v[i].second);
    }

    sort(v.begin(), v.end());


    if(minA>l) {
        cout << "0\n";
        return;
    }

    int ans = 1;

    multiset<ll> s1, s2;
    for(int i=0;i<n;i++) {
        s1.clear(), s2.clear();
        ll sum = 0;
        for(int j=i;j<n;j++) {
            // [i .... j]
            ll delB = v[j].first - v[i].first;
            if(l<delB) break;
            // add v[j] to the sets
            if(s1.empty() || (v[j].second>=(*s1.rbegin()))) {
                s2.insert(v[j].second);
            } else {
                s1.insert(v[j].second);
                sum += v[j].second;
                while(sum+delB>l) {
                    // remove the biggest element
                    sum -= *s1.rbegin();
                    s2.insert(*s1.rbegin());
                    s1.extract(*s1.rbegin());
                }
            }
            while(!s2.empty() && sum + delB + *s2.begin() <= l) {
                sum += *s2.begin();
                s1.insert(*s2.begin());
                s2.extract(*s2.begin());
            }
            ans = max(ans, (int)s1.size());
        }
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/