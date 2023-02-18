/**
*    author:  lazyhash(yashkundu)
*    created: 06 Feb, 2023 | 20:01:15
**/
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

ll check(string &a, string &b, vector<bool> &v) {
    int n = a.length();
    ll ans = 0;
    int len = 0;
    for(int i=0;i<n;i++) {
        if(a[i]!=b[i] && !v[a[i]-'a']) {
            ans += 1LL*len*(len+1)/2;
            len = 0;
        }
        else len++;
    } 
    ans += 1LL*len*(len+1)/2;
    return ans;
}
 
 
void solve() {
    int n, k;
    cin >> n >> k;

    string a, b;
    cin >> a >> b;

    vector<char> ch;

    for(int i=0;i<n;i++) ch.push_back(a[i]);
    sort(ch.begin(), ch.end());
    ch.resize(distance(ch.begin(), unique(ch.begin(), ch.end())));
    int cnt = int(ch.size());

    vector<bool> v(26, false);
    ll ans = 0;

    for(int mask=0;mask<(1<<cnt);mask++) {
        int num = 0;
        v.assign(26, false);
        int f = 1;
        for(int j=0;j<cnt;j++,f*=2) {
            if(mask&f) {
                v[ch[j]-'a'] = true;
                num++;
            }
        }
        if(num!=min(cnt, k)) continue;
        ans = max(ans, check(a, b, v));
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/