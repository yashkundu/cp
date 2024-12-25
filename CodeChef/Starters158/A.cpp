/**
*    author:  lazyhash(yashkundu)
*    created: 30 Oct, 2024 | 20:03:23
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
string s;
 
vector<int> v;

void solve() {
    cin >> n;
    cin >> s;

    v.clear();

    for(int i=0;i<n;) {
        int j = i;
        while(j<n && s[j]==s[i]) j++;
        v.push_back(j-i);
        i = j;
    }


    if(v.size()%2!=0) {
        cout << n << "\n";
        return;
    }


    cout << n - min(v[0], v.back()) << "\n";



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