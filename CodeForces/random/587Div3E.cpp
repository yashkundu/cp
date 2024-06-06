/**
*   author: lazyhash(yashkundu)
*   created: 08 May, 2024 | 19:42:38
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


ll calcTotLen(int n) {
    int cnt = 0;
    int x = n;
    while(x>0) {
        cnt++;
        x /= 10;
    }
    ll curAns = 0;
    ll curBlockLen = 0;
    int f = 9;
    int p10 = 1;
    for(int i=1;i<cnt;i++) {
        curAns += curBlockLen*f + (1LL*f*(f+1)/2)*i;
        curBlockLen += 1LL*f*i;
        f *= 10;
        p10 *= 10;
    }

    int newF = (n - p10 + 1);
    curAns += curBlockLen*newF + (1LL*newF*(newF+1)/2)*cnt;
    return curAns;
}

ll k;

void solve() {
    
    cin >> k;

    int l = 0, r = 1e9;
    // find the block

    while(l<r) {
        int mid = (l+r+1)/2;
        if(calcTotLen(mid)>=k) r = mid - 1;
        else l = mid;
    }

    k -= calcTotLen(l);

    int block = l + 1;

    int numDig = 1;
    int f = 9;
    int p10 = 1;
    while(k>0) {
        if(k>1LL*numDig*f) {
            k -= 1LL*numDig*f;
        } else {
            ll pos = (k+numDig-1)/numDig;
            k -= 1LL*(pos-1)*numDig;
            ll num = p10 + (pos-1);
            for(int j=0;j<(numDig-k);j++) {
                num /= 10;
            }
            cout << (num%10) << "\n";
            break;
        }
        numDig++;
        f *= 10;
        p10 *= 10;
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/