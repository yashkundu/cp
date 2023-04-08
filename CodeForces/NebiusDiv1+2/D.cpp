/**
*   author: lazyhash(yashkundu)
*   created: 18 Mar, 2023 | 12:34:04
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <assert.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int getMax(vector<bool> &v) {
    int n = v.size();
    int tot = 0, good = 0;
    for(int i=0;i<n;i++) tot += v[i];
    for(int i=0;i<n-1;i++) if(!(v[i]&&v[i+1])) good++, i++;
    return tot - (n/4-min(n/4, good));
}

int getMin(vector<bool> &v) {
    int n = v.size();
    int tot = 0, good = 0;
    for(int i=0;i<n;i++) tot += v[i];
    for(int i=0;i<n-1;i++) if(v[i]&&v[i+1]) good++, i++;
    return tot-min(good, n/4);
}

 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> v(n, vector<bool>(m, 0));

    for(int i=0;i<n;i++) {
        string str;
        cin >> str;
        for(int j=0;j<m;j++) v[i][j] = str[j] == '1';
    }

    int ansMax = 0, ansMin = 0;
    for(int i=0;i<n;i++) {
        ansMax += getMax(v[i]); ansMin += getMin(v[i]);
    }

    cout << ansMin << " " << ansMax << "\n";


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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/