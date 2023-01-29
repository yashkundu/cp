/**
*    author:  lazyhash(yashkundu)
*    created: 22 Jan, 2023 | 13:10:50
**/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

const int N = 1e5+2;

vector<vector<int>> factors(N, vector<int>());

void precalc() {
    for(int i=1;i<N;i++) {
        for(int j=i;j<N;j+=i) factors[j].push_back(i);
    }
}
 
 
void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(), a.end());

    int cnt = 0;
    int ans = 1e9;

    map<int, int> mp;

    int j = 0;
    for(int i=0;i<n;i++) {
        while(cnt<m && j<n) {
            for(int f: factors[a[j]]) {
                if(f>m) break;
                if(!mp[f]) cnt++;
                mp[f]++;
            }
            j++;
        }
        if(cnt==m) ans = min(ans, a[j-1]-a[i]);
        for(int f: factors[a[i]]) {
            if(f>m) break;
            mp[f]--;
            if(!mp[f]) cnt--;
        }
    }

    if(ans==1e9) ans = -1;

    cout << ans << "\n";


}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
    precalc();
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