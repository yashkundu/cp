/**
*    author:  lazyhash(yashkundu)
*    created: 06 Oct, 2024 | 11:49:53
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, x;
vector<int> a;

map<int, int> mp;
 
void solve() {
    cin >> n>>x;
    a.resize(n);
    mp.clear();

    for(int i=0;i<n;i++) cin >> a[i];

    sort(a.begin(), a.end());

    int mx = 0;
    for(int i=0;i<n;i++) {
        if(a[i]==mx) mx++;
        else if(a[i]<mx) mp[a[i]%x]++;
        else {
            while(mx<a[i] && mp[mx%x]) {
                mp[mx%x]--;
                mx++;
            }
            if(mx==a[i]) mx++;
            else break;
        }
    }

    while(mp[mx%x]) {
            mp[mx%x]--;
            mx++;
    }


    cout << mx << "\n";





    
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