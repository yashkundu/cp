/**
*    author:  lazyhash(yashkundu)
*    created: 26 Nov, 2024 | 23:01:56
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = (int)3e5+10;
vector<int> divs[MAXN];

void init() {
    for(int i=1;i<MAXN;i++) {
        for(int j=2*i;j<MAXN;j+=i) divs[j].push_back(i);
    }
}

int n, m;
vector<int> a;
vector<int> ans;
map<int, int> mp;
 
void solve() {
    cin >> n >> m;
    a.resize(m);
    ans.clear();

    for(int i=0;i<m;i++) cin >> a[i];
    sort(a.rbegin(), a.rend());


    for(int i=1;i<=n;i++) {
        mp.clear();
        for(int d: divs[i]) mp[ans[d-1]]++;
        for(int j=0;j<m;j++) {
            if(!mp[a[j]]) {
                ans.push_back(a[j]);
                break;
            }
        }
        if(ans.size()!=i) {
            cout << "-1\n";
            return;
        }
    }

    for(int i=0;i<n;i++) cout << ans[i] << " ";
    cout << "\n";




}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
    init();
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