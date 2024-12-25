/**
*    author:  lazyhash(yashkundu)
*    created: 28 Jul, 2024 | 15:46:49
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
string s, t;


vector<int> calc(string s) {
    vector<int> v;
    for(int i=0;i<n;) {
        int j = i;
        while(j<n && s[j]==s[i]) j++;
        v.push_back(j-i);
        i = j;
    }
    return v;
}


vector<int> a, b;
ll ops = 0;
 
void solve() {
    cin >> n;
    cin >> s >> t;

    if(s[0]!=t[0] || s[n-1]!=t[n-1]) {
        cout << "-1\n";
        return;
    }

    a = calc(s);
    b = calc(t);

    if(a.size()!=b.size()) {
        cout << "-1\n";
        return;
    }

    n = a.size();
    ops = 0;


    int j = 0;

    for(int i=0;i<n;i++) {
        if(a[i]>b[i]) {
            ops += a[i]-b[i];
            a[i+1] += (a[i]-b[i]);
        }
        j = max(j, i+1);
        while(a[i]<b[i]) {
            int del = min(a[j]-1, b[i]-a[i]);
            ops += 1LL*del*(j-i);
            a[j] -= del;
            a[i] += del;
            if(a[i]<b[i]) j++;
        }
    }

    cout << ops << "\n";






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