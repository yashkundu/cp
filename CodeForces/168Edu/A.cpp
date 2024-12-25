/**
*    author:  lazyhash(yashkundu)
*    created: 30 Jul, 2024 | 20:06:52
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
string s;
int n;
int ans = 0;


int calc(string s) {
    int n = s.size();
    int res = 0;
    for(int i=0;i<n;i++) {
        if(i==0 || s[i]!=s[i-1]) res += 2;
        else res++;
    }
    return res;
}


void solve() {
    cin >> s;
    n = s.size();
    ans = 0;


    string ans;
    for(int l=0;l<=n;l++) {
        for(int i=0;i<26;i++) {
            char ch = 
        }
    }
    


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