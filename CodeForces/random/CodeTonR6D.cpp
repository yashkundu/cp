/**
*    author:  lazyhash(yashkundu)
*    created: 06 Jul, 2024 | 11:08:00
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = int(2e5)+10;

int c[MAXN], ans[MAXN];

int n, k;
int sz;

vector<int> v;
 
void solve() {

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> c[i];
        ans[i] = 0;
    }

    cin >> k;

    v.clear();

    for(int i=0;i<n;i++) {
        while(!v.empty() && c[v.back()]>=c[i]) v.pop_back();
        v.push_back(i);
    }

    sz = v.size();
    int del = 0;
    int num = 0;

    for(int i=0;i<sz;i++) {
        if(i==sz-1) {
            ans[v[i]] += k/c[v[i]];
        } else {
            num = k/c[v[i]];
            del = max(num - (k-c[v[i]]*num)/(c[v[i+1]] - c[v[i]]), 0);
            ans[v[i]] += del;
            k -= del*c[v[i]];
        }
    }

    for(int i=n-2;i>=0;i--) ans[i] += ans[i+1];


    for(int i=0;i<n;i++) cout << ans[i] << " ";
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