/**
*    author:  lazyhash(yashkundu)
*    created: 07 Sep, 2024 | 17:21:50
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


const int MAXN = (int)2e5+10;

int n;
vector<int> a, b;
int cnt[MAXN];

 
void solve() {
    cin >> n;
    a.resize(n), b.resize(n);
    for(int i=1;i<=n;i++) cnt[i] = 0;


    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];




    int ptr = 0;
    int prev = 0;

    for(int i=0;i<n;i++) {
        if(prev==b[i] && cnt[prev]) cnt[prev]--;
        else {
            while(ptr<n && a[ptr]!=b[i]) {
                cnt[a[ptr]]++;
                ptr++;
            }
            if(ptr==n) {
                cout << "NO\n";
                return;
            }
            prev = a[ptr];
            ptr++;
        }
    }

    cout << "YES\n";




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