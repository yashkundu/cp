/**
*   author: lazyhash(yashkundu)
*   created: 20 May, 2023 | 18:00:57
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


// tells if it is possible to make all the elements >= mxVal
bool check(vector<int> &a, int k, int mxVal) {
    int lesser=0, equal=0, greater = 0;
    ll spaceInLesser=0;
    ll spaceInGreater = 0;
    int n = a.size();
    for(int i=0;i<n;i++) {
        if(a[i]<mxVal) {
            lesser++;
            if (k-i<mxVal-a[i]) {
                return false;
            }
            spaceInLesser += k-i-(mxVal-a[i]);
        } else if(a[i]==mxVal) {
            equal++;
        } else {
            spaceInGreater += a[i]-mxVal;
            greater++;
        }
    }    
    if (lesser>k) return false;
    int leftOnes = k - lesser;

    // 1 - 2 + 3 - 4 + 5 - 6 + 7 - 8 + 9 - 10
    if(leftOnes&1) {
        if(lesser==n) return false;
        else return true;
    }
    if(lesser+2<=n) return true;
    if(leftOnes/2<=spaceInGreater+spaceInLesser) return true;
    return false;
}


 
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int &x: a) cin >> x;

    sort(a.begin(), a.end());



    while(q--) {
        int k;
        cin >> k;
        ll l = -2e9-10;
        ll r = 2e9+10;
        while(l<r) {
            ll mid = l + (r-l+1)/2;
            if(check(a, k, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << l << " ";
    }

    cout << "\n";



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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/