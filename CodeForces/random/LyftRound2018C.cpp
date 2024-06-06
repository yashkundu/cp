/**
*   author: lazyhash(yashkundu)
*   created: 04 Apr, 2024 | 19:34:50
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
 

const int N = 3e5+10;
vector<pair<int, int>> v(N);

int n;


int mnDis(int i, int j) {
    return abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
}


int calcAns(int a, int b) {
    int ans = 0;
    vector<int> inds;
    for(int i=0;i<n;i++) {
        if(i==a || i==b) continue;
        inds.clear();
        inds.push_back(a), inds.push_back(b), inds.push_back(i);
        sort(inds.begin(), inds.end());
        int curAns = mnDis(inds[0], inds[1]) + mnDis(inds[1], inds[2]) + mnDis(inds[2], inds[0]);
        ans = max(ans, curAns);
    }
    return ans;
}


void solve() {

    cin >> n;

    int maxX = -1e9, minX = 1e9, maxY = -1e9, minY = 1e9;

    for(int i=0;i<n;i++) {
        cin >> v[i].first >> v[i].second;
        maxX = max(maxX, v[i].first);
        minX = min(minX, v[i].first);
        maxY = max(maxY, v[i].second);
        minY = min(minY, v[i].second);
    }

    int ans4 = 2*((maxX - minX) + (maxY-minY));


    vector<int> goodV;
    for(int i=0;i<n;i++) {
        if(v[i].first==maxX || v[i].first==minX || v[i].second==maxY || v[i].second==minY) goodV.push_back(i);
    }

    int ans3 = 0;

    for(int i=0;i<goodV.size();i++) {
        for(int j=i+1;j<goodV.size();j++) {
            ans3 = max(ans3, calcAns(goodV[i], goodV[j]));
        }
    }

    cout << ans3 << " ";
    for(int i=4;i<=n;i++) cout << ans4 << " ";
    cout << "\n";



    
    
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