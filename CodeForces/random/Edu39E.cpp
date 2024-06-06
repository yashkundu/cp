/**
*   author: lazyhash(yashkundu)
*   created: 21 May, 2024 | 08:47:28
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string s;
int n;
vector<int> v;
int cnt[10];
 
void solve() {
    cin >> s;
    n = s.size();

    v.resize(n);

    for(int i=0;i<10;i++) cnt[i] = 0;

    for(int i=0;i<n;i++) v[i] = s[i] - '0';
    for(int i=0;i<n;i++) cnt[v[i]]++;

    int odd = 0;
    for(int i=0;i<10;i++) if(cnt[i]&1) odd++;

    for(int i=n-1;i>=0;i--) {
        cnt[v[i]]--;
        if(cnt[v[i]]&1) odd++;
        else odd--;
        for(int j=v[i]-1;j>=0;j--) {
            if(i==0 && j==0) continue;
            cnt[j]++;
            int newOdd = odd + (cnt[j]%2==1?1:-1);
            int left = n-1-i;
            if(newOdd<=left && (left-newOdd)%2==0) {
                vector<int> oddsV;
                for(int k=0;k<10;k++) if(cnt[k]&1) oddsV.push_back(k);
                sort(oddsV.rbegin(), oddsV.rend());
                for(int k=0;k<i;k++) cout << v[k];
                cout << j;
                for(int k=0;k<left-newOdd;k++) cout << 9;
                for(int k: oddsV) cout << k;
                cout << "\n";
                return;
            }
            cnt[j]--;
        }
    } 

    // same len ans does not exist
    int newLen = n - 1;
    if(newLen&1) newLen--;

    for(int i=0;i<newLen;i++) cout << 9;
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