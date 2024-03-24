/**
*   author: lazyhash(yashkundu)
*   created: 17 Mar, 2024 | 19:20:57
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
#include <map>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 3e5+10;
int a[N];
vector<int> cnt[N];

set<pair<int, int>> st;
map<int, int> mp;
 
void solve() {
    int n, m;
    cin >> n >> m;

    st.clear();
    mp.clear();
    for(int i=1;i<=n;i++) cnt[i].clear();


    for(int i=0;i<n;i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    for(int i=0;i<m;i++) {
        int x, y;
        cin >> x >> y;
        st.emplace(min(x, y), max(x, y));
    }


    for(auto it=mp.begin(); it!=mp.end(); it++) {
        int el = it->first, freq = it->second;
        cnt[freq].push_back(el);
    }


    ll ans = 0;

    // iterate over x
    for(auto &p: mp) {
        int x = p.first, freq = p.second;
        // iterating over all freq<=p.second
        for(int y=freq;y>0;y--) {
            for(auto it = cnt[y].rbegin(); it!=cnt[y].rend(); it++) {
                int el = *it;
                if(el!=x && (st.find({min(x, el), max(x, el)})==st.end())) {
                    // it is a good pair
                    ans = max(ans, 1LL*(freq+y)*(x+el));
                    break;
                }
            }
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