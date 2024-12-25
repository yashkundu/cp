/**
*    author:  lazyhash(yashkundu)
*    created: 10 Nov, 2024 | 14:48:23
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = (int)4e5+10;

int sf[MAXN];

void init() {
    for(int i=2;i<MAXN;i++) sf[i] = i;
    for(int i=2;i<MAXN;i++) {
        if(sf[i]!=i) continue;
        for(int j=2*i;j<MAXN;j+=i) if(sf[j]==j) sf[j] = i;
    }
}

int n;
vector<int> a;
 
void solve() {
    
    cin >> n;
    a.resize(n);

    int cnt = 0;

    for(int i=0;i<n;i++) {
        cin >> a[i];
        if(sf[a[i]]==a[i]) cnt++;
    }

    if(cnt==0) {
        cout << "2\n";
        return;
    }

    if(cnt>1) {
        cout << "-1\n";
        return;
    }

    sort(a.begin(), a.end());


    if(sf[a[0]]!=a[0]) {
        cout << "-1\n";
        return;
    }


    for(int i=1;i<n;i++) {
        if(a[i]%2==0 && a[i]<2*a[0]) {
            cout << "-1\n";
            return;
        }
        if(a[i]%2==1 && (a[i]-sf[a[i]])<2*a[0]) {
            cout << "-1\n";
            return;
        }
    }

    cout << a[0] << "\n";








}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
    init();
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