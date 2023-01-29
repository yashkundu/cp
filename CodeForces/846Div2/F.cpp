/**
*    author:  lazyhash(yashkundu)
*    created: 28 Jan, 2023 | 22:51:29
**/
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const int N = 3e5+5;
vector<int> pos(N, -1);
vector<ll> fTrip(N, 0); 

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >>x;

    sort(a.begin(), a.end());

    for(int i=0;i<n;i++) pos[a[i]] = i;

    // no. of bad triplets whose ends has a common factor i(not gcd)
    for(int i=2;i<N;i++) {
        // fTrip[2] 
        int cnt = 0;
        ll sum = 0;
        for(int j=i;j<N;j+=i) {
            if(pos[j]==-1) continue;
            fTrip[i] += 1LL*(pos[j]-1)*cnt - sum;
            cnt++;
            sum += pos[j];
        }
    }
    fTrip[1] = 1LL*n*(n-1)*(n-2)/6;
    // no. of bad triplets whose ends has a gcd of i
    for(int i=N-1;i>0;i--) {
        for(int j=2*i;j<N;j+=i) {
            fTrip[i] -= fTrip[j];
        }
    }

    cout << fTrip[1] << "\n";



}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
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