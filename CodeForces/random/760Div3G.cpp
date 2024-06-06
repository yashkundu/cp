/**
*   author: lazyhash(yashkundu)
*   created: 21 Apr, 2024 | 12:25:37
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

const int N = 2e5+10;
int a[N], b[N];
int pCnt[2*N] = {0};
ll pSum[2*N] = {0};


int n, m, q;

ll getSum(pair<int, int> &seg) {
    int cnt = pCnt[seg.second] - pCnt[seg.first];
    return pSum[seg.second] - pSum[seg.second-cnt];
}

 
void solve() {
    cin >> n >> m >> q;

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];


    ll cur = 0;
    for(int i=0;i<n;i++) cur += a[i];

    vector<pair<int, int>> tot;
    for(int i=0;i<n;i++) tot.push_back({a[i], 1});
    for(int i=0;i<m;i++) tot.push_back({b[i], 0});

    sort(tot.begin(), tot.end());


    int z = n + m;
    for(int i=0;i<z;i++) {
        pCnt[i+1] = pCnt[i] + tot[i].second;
        pSum[i+1] = pSum[i] + tot[i].first;
    }


    set<pair<int, int>> segs;
    // [l, r)
    for(int i=0;i<z;i++) segs.insert({i, i+1});

    vector<pair<int, int>> ord;
    for(int i=0;i<z-1;i++) {
        ord.push_back({tot[i+1].first-tot[i].first, i});
    }
    sort(ord.begin(), ord.end());

    vector<pair<int, ll>> ans = {{0, cur}};

    for(int i=0;i<ord.size();) {
        int j = i;
        while(ord[j].first==ord[i].first) {
            // ord[j]
            int idx = ord[j].second;
            auto itr = segs.upper_bound(make_pair(idx, (int)1e9));
            auto itl = prev(itr);
            auto p1 = *itl;
            auto p2 = *itr;
            pair<int, int> p = {p1.first, p2.second};
            cur -= getSum(p1);
            cur -= getSum(p2);
            cur += getSum(p);
            segs.erase(p1);
            segs.erase(p2);
            segs.insert(p);
            j++;
        }
        ans.push_back({ord[i].first, cur});
        i = j;
    }

    for(int i=0;i<q;i++) {
        int k;
        cin >> k;
        int pos = upper_bound(ans.begin(), ans.end(), make_pair(k+1, -1LL)) - ans.begin() - 1;
        cout << ans[pos].second << "\n";
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