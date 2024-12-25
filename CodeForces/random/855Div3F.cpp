/**
*    author:  lazyhash(yashkundu)
*    created: 17 Jul, 2024 | 11:47:33
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <string>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<string> s;
vector<int> msks;
int cnt[26];

int freq[1<<26];


int getMask(string s) {
    fill(cnt, cnt+26, 0);
    for(int i=0;i<s.size();i++) {
        cnt[s[i]-'a']++;
    }
    int msk = 0;
    for(int i=0,f=1;i<26;i++,f=f*2) {
        if(cnt[i]&1) msk += f;
    }
    return msk;
}

ll ans = 0;

 
void solve() {
    cin >> n;
    s.resize(n);
    msks.resize(n);

    for(int i=0;i<n;i++) cin >> s[i];
    for(int i=0;i<n;i++) msks[i] = getMask(s[i]);

    vector<int> inds;
    char ch;

    ans = 0;

    for(int j=0;j<26;j++) {
        ch = 'a' + j;
        inds.clear();
        for(int i=0;i<n;i++) {
            if(s[i].find(ch)==string::npos) inds.push_back(i);
        }
        int req = (1<<26) - 1 - (1<<j);
        for(int ind: inds) {
            ans += freq[msks[ind]^req];
            freq[msks[ind]]++;
        }
        for(int ind: inds) freq[msks[ind]] = 0;
    }

    cout << ans << "\n";


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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/