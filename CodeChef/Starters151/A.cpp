/**
*    author:  lazyhash(yashkundu)
*    created: 11 Sep, 2024 | 20:07:56
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


int n;
vector<ll> a, b;

int cnt = 0;
int mx = 0;

vector<pair<ll, ll>> v;
 
void solve() {
    cin >> n;
    a.resize(n); b.resize(n);

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    v.clear();

    for(int i=0;i<n;i++) {
        v.push_back({a[i], b[i]});
    }



    sort(v.begin(), v.end(), [](const pair<ll, ll> &p1, const pair<ll, ll> &p2) {
        if(p1.first*p2.second==p1.second*p2.first) return p1.first < p2.first;
        return p1.first*p2.second<p1.second*p2.first;
    });


    cnt = 0;
    mx = 0;
    for(auto p: v) {
        if(p.first>mx) {
            cnt++;
            mx = p.first;
        }
    }

    cout << cnt << "\n";





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