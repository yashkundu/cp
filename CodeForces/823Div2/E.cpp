/**
*    author:  lazyhash(yashkundu)
*    created: 03 Jan,2023 | 16:46:31
**/
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;


const int A = 1e6+10;

vector<int> divs[A];
vector<int> pos[A];

vector<int> geLeft(A, 0), gRight(A, 0);
vector<int> lLeft(A, 0), lRight(A, 0);

vector<int> cnt(A, 0);

vector<int> a(A, 0);



void precalc() {
    for(int i=1;i<A;i++) {
        for(int j=i;j<A;j+=i) divs[j].push_back(i);
    }
}

void solve() {
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }

    vector<int> v;
    for(int i=0;i<n;i++) {
        while(!v.empty() && a[v.back()]<a[i]) v.pop_back();
        if(v.empty()) geLeft[i] = -1;
        else geLeft[i] = v.back();
        v.push_back(i);
    }

    v.clear();
    for(int i=n-1;i>=0;i--) {
        while(!v.empty() && a[v.back()]<=a[i]) v.pop_back();
        if(v.empty()) gRight[i] = n;
        else gRight[i] = v.back();
        v.push_back(i);
    }

    v.clear();
    for(int i=0;i<n;i++) {
        while(!v.empty() && a[v.back()]>=a[i]) v.pop_back();
        if(v.empty()) lLeft[i] = -1;
        else lLeft[i] = v.back();
        v.push_back(i);
    }

    v.clear();
    for(int i=n-1;i>=0;i--) {
        while(!v.empty() && a[v.back()]>=a[i]) v.pop_back();
        if(v.empty()) lRight[i] = n;
        else lRight[i] = v.back();
        v.push_back(i);
    }

    ll ans = 0;

    for(int i=0;i<n;i++) {
        // geLeft  a[i]  gRight      
        for(int d: divs[a[i]]) {
            // [l, r] - a[i] is max, d is min
            // left d -   (d    a[i])
            if(cnt[d]>0) {
                int j = pos[d][cnt[d]-1];
                ans += (ll)max(0, min(j-lLeft[j], j-geLeft[i]))*max(0, min(gRight[i]-i, lRight[j]-i));
            }
            // right d  -  (a[i]    d)
            if(cnt[d]<pos[d].size()) {
                int j = pos[d][cnt[d]];
                ans += (ll)max(0, min(min(i - (cnt[d]>0?pos[d][cnt[d]-1]:-1), i-lLeft[j]), i-geLeft[i]))*max(0, min(gRight[i]-j, lRight[j]-j));
            }
        }
        cnt[a[i]]++;
    }

    cout << ans << "\n";
    for(int i=0;i<n;i++) {
        pos[a[i]].clear();
        cnt[a[i]] = 0;
    }

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    precalc();
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