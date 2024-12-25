/**
*    author:  lazyhash(yashkundu)
*    created: 16 Nov, 2024 | 21:01:43
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

vector<int> v;

void init() {
    v.resize(28);
    v[1] = v[10] = v[26] = 1;
    int p = 2;
    for(int i=2;i<10;i+=2) {
        v[i] = v[i+1] = p++;
    }

    for(int i=11;i<23;i+=2) {
        v[i] = v[i+1] = p++;
    }

    v[24] = v[25] = p++;
    v[23] = v[27] = p++;
}
 
void solve() {
    cin >> n;
    if(n%2==0) {
        for(int i=0;i<n/2;i++) {
            cout << i+1 << " " << i+1 << " " ;
        }
        cout << "\n";
        return;
    }

    if(n<27) {
        cout << "-1\n";
        return;
    }


    for(int i=1;i<=27;i++) cout << v[i] << " ";
    int p = 28;
    for(int i=0;i<(n-27)/2;i++) {
        cout << p << " " << p << " ";
        p++;
    }

    cout << "\n";





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