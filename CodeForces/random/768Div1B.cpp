/**
*    author:  lazyhash(yashkundu)
*    created: 05 Oct, 2024 | 21:40:29
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

int n, k;
int a[MAXN];
int cnt[MAXN] = {0};
 
void solve() {
    cin >> n >> k;
    for(int i=1;i<=n;i++) cnt[i] = 0;


    for(int i=0;i<n;i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    for(int i=1;i<=n;i++) cnt[i] += cnt[i-1];


    pair<int, int> p = {-1, -1};
    int diff = MAXN;

    int ptr = 0;
    for(int i=1;i<=n;i++) {
        ptr = max(i, ptr);
        while(ptr<n && 2*(cnt[ptr]-cnt[i-1])<n+k) ptr++;
        if(2*(cnt[ptr]-cnt[i-1])>=n+k) {
            // i, ptr
            if(diff>ptr-i) {
                diff = ptr-i;
                p = {i, ptr};
            }
        }
    }


    vector<pair<int, int>> v;

    int cnt = 0;
    int last = -1;



    for(int i=0;i<n;i++) {
        if(a[i]>=p.first && a[i]<=p.second) cnt++;
        else cnt--;
        if(cnt==1 && v.size()<k-1) {
            v.push_back({last+1, i});
            cnt = 0;
            last = i;
        }
    }

    v.push_back({last+1, n-1});



    cout << p.first << " " << p.second << "\n";
    for(auto x: v) cout << x.first +1 << " " << x.second+1 << "\n";

    















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