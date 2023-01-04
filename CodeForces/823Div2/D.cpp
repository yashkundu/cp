/**
*    author:  lazyhash(yashkundu)
*    created: 02 Jan,2023 | 22:38:07
**/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;

void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    reverse(s2.begin(), s2.end());

    map<pair<int, int>, int> m;

    for(int i=0;i<n;i++) {
        int x1 = s1[i]-'a', x2 = s2[i]-'a';
        m[{min(x1, x2), max(x1, x2)}]++;
    }

    bool odd = n%2==1;
    bool ans = true;
    map<pair<int, int>, int>::iterator it;
    for(it=m.begin();it!=m.end();it++) {
        if((it->second)%2==1) {
            if(odd && it->first.first==it->first.second) odd = false;
            else ans = false;
        }
    }

    cout << (ans?"YES":"NO") << "\n";
    

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