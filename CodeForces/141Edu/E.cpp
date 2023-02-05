/**
*    author:  lazyhash(yashkundu)
*    created: 05 Feb, 2023 | 10:31:25
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

const int A = 2e5+10;

vector<int> l(A, 0), g(A, 0);
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int &x: a) cin >> x;
    for(int &x: b) cin >> x;

    l.assign(n+1, 0), g.assign(n+1, 0);

    for(int i=0;i<n;i++) if(a[i]>b[i]) g[a[i]]++, l[b[i]]++;
    for(int i=1;i<=n;i++) l[i] += l[i-1], g[i] += g[i-1];
    vector<int> ans;

    for(int i=1;i<=n;i++) {
        bool isAns = true;
        for(int j=i;j<=n;j+=i) {
            if(l[j]!=g[j]) {
                isAns = false;
                break;
            }
        }
        if(isAns) ans.push_back(i);
    }


    cout << int(ans.size()) << "\n";
    for(int &x: ans) cout << x << " ";
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