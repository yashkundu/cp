/**
*   author: lazyhash(yashkundu)
*   created: 04 Mar, 2023 | 12:43:12
**/
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int cur = 0;
    for(int i=0;i<n-1;i++) if(s[i]==s[i+1] && s[i]=='Y') cur++;

    vector<int> middles;
    int first = 0, last = 0;

    int i = 0;
    while(i<n && s[i++]=='X') first++;
    i = n-1;
    while(i>=0 && s[i--]=='X') last++;

    if(first==n) {
        cout << max(k-1, 0) << "\n";
        return; 
    }

    i = first;
    while(i+last<n) {
        int j = i;
        while(j<n && s[j]=='X') j++;
        if(i==j) i++;
        else {
            middles.push_back(j-i); 
            i = j;
        }
    }

    sort(middles.rbegin(), middles.rend());

    int ans = 0;

    while(k>0 && !middles.empty()) {
        int back = middles.back();
        middles.pop_back();
        int del = min(k, back);
        k -= del; back -= del;
        ans += del;
        if(!back) ans++;
        else middles.push_back(back);
    }

    int del = min(k, first);
    k -= del; ans += del;
    del = min(k, last);
    k -= del; ans += del;

    if(k==0) {
        cout << (cur+ans) << "\n";
        return;
    }


    // all converted to zeros, now convert original zeros to ones
    // 11100000

    if(first==0) {
        while(first<n && s[first]=='Y') first++;
        int del = min(k, first);
        k -= del; ans -= min(del, n-1);
    }

    if(last==0) {
        while(last<n && s[n-last-1]=='Y') last++;
        int del = min(k, last);
        k -= del; ans -= min(del, n-1);
    }


    vector<int> zeros;
    i = first;
    while(i+last<n) {
        int j = i;
        while(j<n && s[j]=='Y') j++;
        if(i==j) i++;
        else {
            zeros.push_back(j-i);
            i = j;
        }
    }
    sort(zeros.begin(), zeros.end());

    while(k>0 && !zeros.empty()) {
        int back = zeros.back();
        zeros.pop_back();
        int del = min(k, back);
        k -= del; back -= del;
        ans -= del+1;
        if(back) zeros.push_back(back);
    }

    cout << (ans + cur) << "\n";



    


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