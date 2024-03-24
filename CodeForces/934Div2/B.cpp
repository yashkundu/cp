/**
*   author: lazyhash(yashkundu)
*   created: 16 Mar, 2024 | 20:15:39
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
#include <assert.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

const int N = 5e4+10;
int cnt[N];

 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve() {
    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    set<int> ones1, ones2, doubles1, doubles2;
    for(int i=1;i<=n;i++) {
        if(cnt[i]==1) ones1.insert(i);
        else if(cnt[i]==2) doubles1.insert(i);
    }

    for(int i=1;i<=n;i++) cnt[i] = 0;

    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    for(int i=1;i<=n;i++) {
        if(cnt[i]==1) ones2.insert(i);
        else if(cnt[i]==2) doubles2.insert(i);
    }

    for(int i=1;i<=n;i++) cnt[i] = 0;

    int tot = 2*k;



    int cur = n;
    while(cur>tot) {
        if(!doubles1.empty() && cur-2>=tot) {
            doubles1.erase(doubles1.begin());
            cur -= 2;
        } else {
            assert(!ones1.empty());
            int x = *ones1.begin();
            ones1.erase(x);
            ones2.erase(x);
            cur--;
        }
    }

    for(int x: ones1) cout << x << " ";
    for(int x: doubles1) cout << x << " " << x << " ";
    cout << "\n";

    for(int x: ones2) cout << x << " ";
    int cntr = 0;
    for(auto it = doubles2.begin(); cntr<doubles1.size();it++, cntr++) cout << *it << " " << *it << " ";
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