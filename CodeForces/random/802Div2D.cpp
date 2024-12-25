/**
*    author:  lazyhash(yashkundu)
*    created: 30 Jul, 2024 | 16:49:48
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

int n, q;
vector<ll> v;
vector<pair<ll, int>> qs;

vector<ll> ans;
vector<ll> times;

ll tot = 0;
ll psum = 0;
ll del;
ll qt;
 
void solve() {
    cin >> n;
    v.resize(n);
    times.resize(n);

    tot = 0;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        tot += v[i];
    }


    times[0] = v[0];
    psum = v[0];

    for(int i=1;i<n;i++) {
        psum += v[i];
        del = psum - (1LL*times[i-1]*(i+1));
        if(del<=0) times[i] = times[i-1];
        else times[i] = times[i-1] + (del+i)/(i+1);
    }

    for(int i=0;i<n;i++) {
        times[i] = max(times[i], (tot+i)/(i+1));
    }

    cin >> q;
    qs.resize(q);
    ans.resize(q);

    for(int i=0;i<q;i++) {
        cin >> qt;
        qs[i] = {qt, i};
    }

    sort(qs.begin(), qs.end());

    int j = n-1;
    for(auto [t, ind]: qs) {
        while(j>=0 && times[j]<=t) j--;
        ans[ind] = j+2;
        if(ans[ind]==n+1) ans[ind] = -1;
    }


    for(int i=0;i<q;i++) cout << ans[i] << "\n";










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