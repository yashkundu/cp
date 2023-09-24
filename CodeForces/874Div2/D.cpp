/**
*   author: lazyhash(yashkundu)
*   created: 27 May, 2023 | 21:08:51
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int num = 0;
    for(int i=0;i<n;i++) {
        if(s[i]=='(') num++;
    }

    if((n%2!=0) || (num!=n/2)) {
        cout << "-1\n";
        return;
    }


    vector<int> cls(n);

    auto hasEqualParity = [](int x, int y) {
        return (x>=0 && y>=0) || (x<=0 && y<=0);
    };

    auto pCalc = [](char ch) {
        if(ch=='(') return 1;
        return -1;
    };


    int ctr = 1;
    int vals[3] = {0, 0, 0};

    for(int i=0;i<n;) {
        int p = s[i]=='('?1:-1;
        if(vals[p+1]==0) vals[p+1] = ctr++;
        int bal = 0;
        int j = i;
        while(j<n && hasEqualParity(bal+pCalc(s[j]), p)) {
            bal += pCalc(s[j]);
            cls[j] = vals[p+1];
            j++;
        }
        i = j;
    }

    cout << ctr-1 << "\n";
    for(auto cl: cls) cout << cl << " ";
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/