/**
*    author:  lazyhash(yashkundu)
*    created: 02 Jan,2023 | 09:46:31
**/
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;


void solve() {
    int n, c;
    cin >> n >> c;

    vector<int> cnt(101, 0);

    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        cnt[a]++;
    } 

    ll sum = 0;

    for(int i=1;i<=100;i++) {
        sum += min(c, cnt[i]);
    }

    cout << sum << "\n";
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