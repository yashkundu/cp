/**
*   author: lazyhash(yashkundu)
*   created: 16 Mar, 2024 | 20:40:27
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5+10;
int a[N];
int cnt[N];
vector<int> ord[N];
 
void solve() {
    int n;
    cin >> n;

    for(int i=0;i<n;i++) cnt[i] = 0;
    for(int i=1;i<=n;i++) ord[i].clear();

    for(int i=0;i<n;i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    int mex = n;
    for(int i=0;i<n;i++) {
        if(!cnt[i]) {
            mex = i;
            break;
        }
        ord[cnt[i]].push_back(i);
    }

    set<int> st;

    // n turns
    for(int i=1;i<=n;i++) {
        for(int v: ord[i]) {
            st.insert(v);
        }
        while(st.size()>i) {
            int bEl = *st.rbegin();
            mex = min(mex, bEl);
            st.erase(bEl);
        }
    }

    cout << mex << "\n";


    
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/