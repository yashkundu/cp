/**
*    author:  lazyhash(yashkundu)
*    created: 09 Jul, 2024 | 11:25:05
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

const int MAXN = int(2e5)+10;

vector<pair<int, int>> events[MAXN];
int a[MAXN];
int d[MAXN];
 
int n;

map<int, ll> mp;
int sum;
int del;


bool check(int x) {
    mp.clear();

    for(int i=1;i<=n;i++) {
        for(auto p: events[i]) mp[p.first] += p.second;
        sum = 0;
        while(sum<x && !mp.empty()) {
            int ind = mp.begin()->first;
            if(ind<i) return false;
            del = min(mp[ind], ll(x-sum));
            sum += del;
            mp[ind] -= del;
            if(!mp[ind]) mp.erase(mp.begin());
        }
    }
    if(!mp.empty()) return false;
    return true;
}


void solve() {
    cin >> n;

    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> d[i];

    for(int i=1;i<=n;i++) {
        if(a[i]) events[max(1, i-d[i])].push_back({min(n, i+d[i]), a[i]});
    }


    int L = -1, R = int(1e9);

    while(R-L>1) {
        int mid = (L+R)/2;
        if(check(mid)) R = mid;
        else L = mid;
    }

    cout << R << "\n";





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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/