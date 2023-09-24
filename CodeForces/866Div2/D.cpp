/**
*   author: lazyhash(yashkundu)
*   created: 23 Apr, 2023 | 15:56:44
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve() {
    int n;
    cin >> n;

    vector<pair<ll, ll>> v(n);

    ll totArea = 0;
    ll maxH = 0, maxW = 0;
    for(int i=0;i<n;i++) {
        ll h, w;
        cin >> h >> w;
        v[i].first = h;
        v[i].second = w;
        totArea += h*w;
        maxH = max(maxH, h);
        maxW = max(maxW, w);
    }

    vector<pair<ll, ll>> ans;
    if(totArea%maxH==0) {
        ans.emplace_back(maxH, totArea/maxH);
    }
    if(totArea%maxW==0) {
        pair<ll, ll> cur = {totArea/maxW, maxW};
        if(ans.size()==0 || (ans[0]!=cur)) ans.push_back(cur);
    }


    auto check = [&v, &n](pair<ll, ll> p) {
        ll h = p.first, w = p.second;
        vector<pair<ll, ll>> a, b;
        vector<bool> vis(n, false);

        for(int i=0;i<v.size();i++) {
            a.emplace_back(v[i].first, i);
            b.emplace_back(v[i].second, i);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        while(true) {
            if(!a.empty() && a.back().first>=h) {
                auto [curH, ind] = a.back();
                if(!vis[ind] && curH==h) {
                    w -= v[ind].second;
                    vis[ind] = true;
                }
                a.pop_back();
                continue;
            } 
            if(!b.empty() && b.back().first>=w) {
                auto [curW, ind] = b.back();
                if(!vis[ind] && curW==w) {
                    h -= v[ind].first;
                    vis[ind] = true;
                }
                b.pop_back();
                continue;
            }
            break;
        }
        for(int i=0;i<n;i++) if(!vis[i]) return false;
        return true;
    };

    vector<pair<ll, ll>> finalAns;
    for(auto p: ans) if(check(p)) finalAns.push_back(p);

    cout << finalAns.size() << "\n";
    for(auto [h, w]: finalAns) {
        cout << h << " " << w << "\n";
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/