/**
*   author: lazyhash(yashkundu)
*   created: 15 Oct, 2023 | 23:51:18
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
 
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    ll pos;
    cin >> pos;

    ll curSum = 0;
    int cnt = 0;
    ll x = n;
    while(curSum+x<pos) {
        curSum += x;
        x--;
        cnt++;
    }

    vector<char> v;

    int i=0;
    while(cnt>0) {
        if(i>=n) break;
        if(!v.empty() && v.back()>s[i]) {
            v.pop_back();
            cnt--;
        }
        else v.push_back(s[i++]);
    }
    for(int j=i;j<n;j++) v.push_back(s[j]);

    assert(v.size()>=pos-curSum);
    cout << v[pos-curSum-1];




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