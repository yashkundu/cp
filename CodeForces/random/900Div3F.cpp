/**
*    author:  lazyhash(yashkundu)
*    created: 05 Jul, 2024 | 15:16:12
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

map<int, int> mp;

int n, q, x, k;
int cnt;

void factorize(int num) {
    cnt = 0;
    for(int i=2;i*i<=num;i++) {
        cnt = 0;
        while(num%i==0) {
            cnt++;
            num /= i;
        }
        mp[i] += cnt;
    }
    if(num>1) mp[num]++;
}


int nd = 1;

 
void solve() {
    cin >> n >> q;
    mp.clear();
    factorize(n);


    while(q--) {
        cin >> k;
        if(k==1) {
            cin >> x;
            factorize(x);
            nd = 1;
            for(auto p: mp) nd *= (p.second+1);
            for(auto p: mp) {
                cnt = 0;
                while(nd%p.first==0) {
                    cnt++;
                    nd /= p.first;
                }
                if(cnt>p.second) {
                    nd = 2;
                    break;
                }
            }
            cout << (nd==1?"YES":"NO") << "\n";
        } else {
            mp.clear();
            factorize(n);
        }
    }

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