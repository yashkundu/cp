/**
*   author: lazyhash(yashkundu)
*   created: 27 Mar, 2024 | 08:04:49
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 2e5 + 10;
int t[N], a[N], x[N];
int tot[2] = {0};
int ans[N] = {0};

set<pair<int, int>> st;
 

int h, w, m;

void solve() {
    cin >> h >> w >> m;
    st.clear();

    for(int i=0;i<m;i++) {
        cin >> t[i] >> a[i] >> x[i];
        t[i]--;
        a[i]--;
    }

    vector<pair<pair<int, int>, int>> v;


    for(int i=m-1;i>=0;i--) {
        if(st.find({t[i], a[i]})==st.end()) {
            v.push_back({{t[i], a[i]}, x[i]});
            st.insert({t[i], a[i]});
        }
    }

    for(int i=0;i<h;i++) {
        if(st.find({0, i})==st.end()) v.push_back({{0, i}, 0});
    }


    for(auto p: v) {
        int T = p.first.first, A = p.first.second, X = p.second;
        int curTotal = (T==0?w:h);
        ans[X] += curTotal - tot[T^1];
        tot[T]++;
    }

    vector<pair<int, int>> ansV;
    for(int i=0;i<N;i++) {
        if(ans[i]) ansV.push_back({i, ans[i]});
    }

    cout << ansV.size() << "\n";
    for(auto p: ansV) {
        cout << p.first << " " << p.second << "\n";
    }






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