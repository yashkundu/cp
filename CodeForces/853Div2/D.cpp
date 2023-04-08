/**
*   author: lazyhash(yashkundu)
*   created: 26 Feb, 2023 | 22:54:28
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

 
void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    vector<int> a(n), b(n);
    int cnt1, cnt2 = 0;

    for(int i=0;i<n;i++) {
        a[i] = s1[i] - '0';
        cnt1 += a[i];
        b[i] = s2[i] - '0';
        cnt2 += b[i];
    }

    if((cnt1==0 && cnt2!=0) || (cnt1!=0 && cnt2==0)) {
        cout << "-1\n";
        return;
    }
    if(cnt1==0) {
        cout << "0\n";
        return;
    }

    vector<int> ans;
    int first = -1, last = -1;
    for(int i=0;i<n;i++) {
        if(a[i]) {
            first = i; break;
        }
    }

    for(int i=n-1;i>=0;i--) {
        if(a[i]) {
            last = i; break;
        }
    }

    auto update = [n](vector<int> &v, int k) {
        vector<int> cv(v);
        for(int i=0;i<n;i++) {
            if(i+k<0 || i+k>=n) continue;
            v[i] ^= cv[i+k];
        }
    };

    int bfirst = -1;
    for(int i=0;i<n;i++) {
        if(b[i]) {
            bfirst = i;
            if(!a[i]) {
                if(first<i) {
                    ans.push_back(first-i);
                    update(a, first-i);
                } else {
                    ans.push_back(last-i);
                    update(a, last-i);
                }
            }
            break;
        }
    }


    for(int i=n-1;i>=0;i--) {
        if(a[i]) {
            last = i;
            break;
        }
    }



    for(int i=bfirst-1;i>=0;i--) {
        if(a[i]!=b[i]) {
            ans.push_back(last-i);
            update(a, last-i);
        }
    }

    for(int i=0;i>=0;i++) {
        if(a[i]) {
            first = i;
            break;
        }
    }

    for(int i=bfirst+1;i<n;i++) {
        if(a[i]!=b[i]) {
            ans.push_back(first-i);
            update(a, first-i);
        }
    }


    cout << ans.size() << "\n";
    for(int &x: ans) cout << x << " ";
    if(ans.size()) cout << "\n";






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