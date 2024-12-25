/**
*    author:  lazyhash(yashkundu)
*    created: 18 Aug, 2024 | 18:58:16
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <numeric>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXA = int(1e7)+5;

int spf[MAXA];
int grundy[MAXA];


void init() {
    iota(spf, spf+MAXA, 0);

    for(int i=2;i*i<MAXA;i++) {
        if(spf[i]!=i) continue;
        for(int j=i*i;j<MAXA;j+=i) if(spf[j]==j) spf[j] = i;
    }

    grundy[0] = 0;
    grundy[1] = 1;


    int cntr = 2;
    for(int i=2;i<MAXA;i++) {
        if(i%2==0) {
            grundy[i] = 0;
            continue;
        }
        if(spf[i]==i) grundy[i] = cntr++;
        else grundy[i] = grundy[spf[i]];
    }

}

int n;
vector<int> a;
 
void solve() {
    cin >> n;
    a.resize(n);

    int x = 0;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        x ^= grundy[a[i]];
    }

    if(x) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }

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