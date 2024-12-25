/**
*    author:  lazyhash(yashkundu)
*    created: 09 Sep, 2024 | 23:28:52
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

using oset = tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>;


int n;
string s;

oset st[3];

const int inf = (int)1e9+10;

ll ans;
 
void solve() {
    cin >> n;
    cin >> s;

    for(int i=0;i<3;i++ ) st[i].clear();



    int cnt = 0;
    st[0].insert({0, -1});  

    ans = 0;

    for(int i=0;i<n;i++) {
        if(s[i]=='+') cnt--;
        else cnt++;
        int mod = (cnt%3+3)%3;
        ans += st[mod].order_of_key({cnt, inf});
        st[mod].insert({cnt, i});
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