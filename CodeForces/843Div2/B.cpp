/**
*    author:  lazyhash(yashkundu)
*    created: 15 Jan, 2023 | 10:01:10
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

const int N = 2e5+100;

vector<int> cnt(N, 0);
 
 
void solve() {
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>());
    for(vector<int> &a: v) {
        int k;
        cin >> k;
        for(int j=0;j<k;j++) {
            int x;
            cin >> x;
            a.push_back(x);
            cnt[x]++;
        }
    }

    bool ans = false;

    for(vector<int> &a: v) {
        bool cur = true;
        for(int x: a) {
            cur = cur && cnt[x]>1;
        }
        ans = ans || cur;
    }

    for(vector<int> &a: v) {
        for(int x: a) cnt[x] = 0;
    }

    cout << (ans?"YES":"NO");
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