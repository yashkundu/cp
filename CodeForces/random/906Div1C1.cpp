/**
*    author:  lazyhash(yashkundu)
*    created: 04 Jul, 2024 | 15:01:24
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


const int MAXN = int(2e5)+5;

map<int, int> cnt1;
map<pair<int, int>, int> cnt2;
set<int> st;

int n, m, k, l, r;
vector<pair<int, int>> events[MAXN];

int ans = 0;
 
void solve() {
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) events[i].clear();

    cnt1.clear();
    cnt2.clear();

    for(int i=1;i<=m;i++) {
        cin >> l >> r;
        events[l].push_back({1, i});
        events[r+1].push_back({-1, i});
    }

    ans = 0;
    st.clear();
    for(int i=1;i<=n;i++) {
        for(auto p: events[i]) {
            if(p.first==1) st.insert(p.second);
            else st.erase(p.second);
        }
        if(st.empty()) ans++;
        else if(st.size()==1) cnt1[*st.begin()]++;
        else if(st.size()==2) cnt2[{*st.begin(), *next(st.begin())}]++;
    }

    int mx1 = 0, mx2 = 0;
    for(auto p: cnt1) {
        if(p.second>=mx1) {
            mx2 = mx1;
            mx1 = p.second;
        } else if(p.second>mx2) mx2 = p.second;
    }

    int del = mx1+mx2;

    for(auto p: cnt2) {
        del = max(del, p.second + cnt1[p.first.first] + cnt1[p.first.second]);
    }

    ans += del;
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