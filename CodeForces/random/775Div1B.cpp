/**
*    author:  lazyhash(yashkundu)
*    created: 28 Sep, 2024 | 21:09:23
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = (int)1e6+10;

int n, c;
int cnt[MAXN];

int a;
 
void solve() {
    cin >> n >> c;
    fill(cnt, cnt+c+1, 0);

    for(int i=0;i<n;i++) {
        cin >> a;
        cnt[a]++;
    }

    for(int i=1;i<=c;i++) cnt[i] += cnt[i-1];


    for(int i=1;i<=c;i++) {
        if(cnt[i]==cnt[i-1]) continue;
        for(int j=i,f=1;j<=c;j+=i,f++) {
            if(cnt[min(c, j+i-1)]-cnt[j-1] && cnt[f]==cnt[f-1]) {
                cout << "NO\n";
                return;
            }
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