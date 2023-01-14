/**
*    author:  lazyhash(yashkundu)
*    created: 14 Jan, 2023 | 10:06:44
**/
#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;


void solve() {
    int n;
    cin >> n;

    vector<int> a(n+1, 0);
    for(int i=1;i<=n;i++) cin >> a[i];

    vector<int> p(n+1, 0), q(n+1, 0);
    set<int> s1, s2;

    for(int i=1;i<=n;i++) s1.insert(i), s2.insert(i);


    for(int i=1;i<=n;i++) {
        if(s1.count(a[i])) p[i] = a[i], s1.erase(a[i]);
        else if(s2.count(a[i])) q[i] = a[i], s2.erase(a[i]);
        else {
            cout << "NO\n"; return;
        }
    }

    for(int i=1;i<=n;i++) {
        if(!p[i]) {
            set<int>::iterator it = s1.upper_bound(q[i]);
            if(it==s1.begin()) {
                cout << "NO\n"; return;
            }
            --it;
            p[i] = *it, s1.erase(*it);
        } else {
            set<int>::iterator it = s2.upper_bound(p[i]);
            if(it==s2.begin()) {
                cout << "NO\n"; return;
            }
            --it;
            q[i] = *it, s2.erase(*it);
        }
    }

    cout << "YES\n";
    for(int i=1;i<=n;i++) cout << p[i] << " ";
    cout << "\n";
    for(int i=1;i<=n;i++) cout << q[i] << " ";
    cout << "\n";



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