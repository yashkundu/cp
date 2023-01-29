/**
*    author:  lazyhash(yashkundu)
*    created: 28 Jan, 2023 | 10:08:18
**/
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

vector<pair<int, int>> fact;
vector<ll> divs;


void calcFact(int m1, int m2) {
    for(int i=2;i*i<=m1 || i*i<=m2;i++) {
        int cnt = 0;
        while(m1%i==0) {
            cnt++;
            m1 /= i;
        }
        while(m2%i==0) {
            cnt++;
            m2 /= i;
        }
        if(cnt>0) {
            fact.emplace_back(i, cnt);
        }
    }
    if(m1>m2) swap(m1, m2);
    if(m1>1) fact.emplace_back(m1, 1);
    if(m2>1) {
        if(m1==m2) fact.back().second++;
        else fact.emplace_back(m2, 1);
    }
}

void calcDivs(int i, ll val) {
    if(i>=fact.size()) {
        divs.push_back(val);
        return;
    }
    for(int p=0;p<fact[i].second+1;p++) {
        calcDivs(i+1, val);
        if(p < fact[i].second) val = val*fact[i].first;
    }
}
 
 
void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    fact.clear();
    calcFact(m1, m2);

    divs.clear();
    calcDivs(0, 1LL);

    sort(divs.begin(), divs.end());

    int sz = int(divs.size());
    vector<ll> dp(sz, -1);

    for(int i=0;i<sz;i++) {
        if(divs[i]<=n) {
            dp[i] = divs[i];
            continue;
        }
        for(auto [p, k]: fact){
            if(divs[i]%p!=0) continue;
            int ind = lower_bound(divs.begin(), divs.end(), divs[i]/p) - divs.begin();
            dp[i] = max(dp[i], dp[ind]);
        }
    }

    int cnt = 0;
    ll x = 0;

    for(int i=0;i<sz;i++) {
        ll res = divs[i]/dp[i];
        if(res>n) continue;
        cnt++;
        x ^= res;
    }

    cout << cnt << " " << x << "\n";
    

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