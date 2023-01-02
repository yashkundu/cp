/**
*    author:  lazyhash(yashkundu)
*    created: 01 Jan,2023 | 16:26:41
**/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;

// 0 1 2

ll hsh(vector<int> &v) {
    ll ans = 0;
    ll x = 1;
    for(int i=v.size()-1;i>=0;i--) {
        ans += (v[i])*x;
        x = x*3;
    }
    return ans;
}

// 1 0 2   -- 3
ll thirdCardHash(vector<int> &v1, vector<int> &v2) {
    vector<int> v;
    for(int i=0;i<v1.size();i++) {
        v.push_back((6-v1[i]-v2[i])%3);
    }
    return hsh(v);
}

vector<vector<int>> v;
int n, k;

void solve() {
    cin >> n >> k;
    v.resize(n);

    map<ll, int> cnt; 
    for(int i=0;i<n;i++) {
        v[i].resize(k);
        for(int j=0;j<k;j++) cin >> v[i][j];
    }

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            cnt[thirdCardHash(v[i], v[j])]++;
        }
    }

    ll ans = 0;

    for(int i=0;i<n;i++) {
        ll h = hsh(v[i]);
        ans += (ll)cnt[h]*(cnt[h]-1)/2;
    }
    cout << ans << "\n";

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