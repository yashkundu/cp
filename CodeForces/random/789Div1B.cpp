/**
*    author:  lazyhash(yashkundu)
*    created: 02 Sep, 2024 | 21:01:08
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m;
string s;

vector<int> ans;
vector<int> colcnt;


 
void solve() {
    cin >> n >> m;
    cin >> s;
    ans.resize(n*m);
    fill(ans.begin(), ans.end(), 0);


    colcnt.resize(m);
    fill(colcnt.begin(), colcnt.end(), 0);



    int zcnt = m;



    for(int i=0;i<n*m;i++) {
        if(s[i]=='1') {
            if(zcnt>=m) {
                ans[i]++;
            }
            zcnt = 0;
        } else {
            zcnt++;
        }
         if(zcnt==m && i>=zcnt) {
            ans[i]--;
        }
    }

    for(int i=0;i<n*m;i++) {
        if(i-m>=0) ans[i] += ans[i-m];
    }


    for(int i=0;i<n*m;i++) {
        if(s[i]=='1') {
            int cind = m-1-i%m;
            if(colcnt[cind]==0) ans[i]++;
            colcnt[cind]++;
        }
    }

    for(int i=1;i<n*m;i++) ans[i] += ans[i-1];

    for(int i=0;i<n*m;i++) cout << ans[i] << " ";
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