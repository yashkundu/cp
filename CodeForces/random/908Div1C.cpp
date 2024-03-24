/**
*   author: lazyhash(yashkundu)
*   created: 04 Feb, 2024 | 17:11:24
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e5+10;
ll l[N], r[N], totSize[N];
ll els[N];
ll minSizeX = 0, maxSizeX = 0;

// mp[i] -  A list of pair of {multiset, frequency of i in that multiset}
map<int, vector<pair<int, int>>> mp;
 
void solve() {
    int m;
    cin >> m;

    mp.clear();
    minSizeX = 0, maxSizeX = 0;

    for(int i=0;i<m;i++) {
        int cnt;
        cin >> cnt >> l[i] >> r[i];
        minSizeX += l[i];
        maxSizeX += r[i];
        
        for(int j=0;j<cnt;j++) cin >> els[j];
        ll sum = 0;
        for(int j=0;j<cnt;j++) {
            ll c;
            cin >> c;
            if(mp.find(els[j])==mp.end()) {
                mp[els[j]] = vector<pair<int, int>>();
            }
            mp[els[j]].emplace_back(i, c);
            sum += c;
        }
        totSize[i] = sum;
    }

    for(ll s=minSizeX;s<=maxSizeX;s++) {
        if(mp.find(s)==mp.end()) {
            cout << "0\n";
            return;
        }
    }


    // iterate over all the unique elements as the size of the new multiset X

    ll ans = maxSizeX;

    for(auto it=mp.begin();it!=mp.end();it++) {
        int uniqEl = it->first;
        // find the minumum number of times the el uniqEl can occur in multiset X
        if(uniqEl<minSizeX || uniqEl>maxSizeX) continue;

        // the number of time uniqEl will occur in the multiset x if we choose min
        ll cntr = 0;
        // we can use it to prevent selecting uniqEl
        ll antiCntr = 0;


        ll goodMaxs = 0;
        ll goodMins = 0;
        for(auto [msInd, freq]: it->second) {
            goodMaxs += r[msInd];
            goodMins += l[msInd];

            cntr += max(0LL, l[msInd] - (totSize[msInd]-freq));
            antiCntr += max(0LL, (totSize[msInd]-freq) - l[msInd]);
        }
        ll todoElsSize = max(goodMins, uniqEl-(maxSizeX-goodMaxs));
        
        // add the left number of uniqEls to cntr
        cntr += max(0LL, todoElsSize-goodMins-antiCntr);
        ans = min(ans, cntr);
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