/**
*    author:  lazyhash(yashkundu)
*    created: 29 Jan, 2023 | 21:03:07
**/
#include <iostream>
#include <vector>
#include <stack>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

vector<int> suffix_array(string s) {
    s = s + "$";
    int n = s.length();
    const int alphabet = 256;
    vector<int> cnt(max(alphabet, n), 0);
    vector<int> p(n), c(n);
    for(int i=0;i<n;i++) {
        cnt[s[i]]++;
    }
    for(int i=1;i<alphabet;i++) cnt[i] += cnt[i-1];
    for(int i=0;i<n;i++) p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int eqClass = 1;
    for(int i=1;i<n;i++) {
        if(s[p[i]]==s[p[i-1]]) c[p[i]] = c[p[i-1]];
        else c[p[i]] = eqClass++;
    }
    vector<int> pt(n), ct(n);
    for(int k=0;(1<<k)<n;k++){
        for(int i=0;i<n;i++) {
            pt[i] = p[i] - (1<<k);
            if(pt[i]<0) pt[i] += n;
        }
        fill(cnt.begin(), cnt.begin()+eqClass, 0);
        for(int i=0;i<n;i++) cnt[c[pt[i]]]++;
        for(int i=1;i<eqClass;i++) cnt[i] += cnt[i-1];
        for(int i=n-1;i>=0;i--) {
            p[--cnt[c[pt[i]]]] = pt[i];
        }
        ct[p[0]] = 0;
        eqClass = 1;
        for(int i=1;i<n;i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1<<k))%n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1<<k))%n]};
            if(cur==prev) ct[p[i]] = ct[p[i-1]];
            else ct[p[i]] = eqClass++;
        }
        for(int i=0;i<n;i++) c[i] = ct[i];
    }
    vector<int> ans(n-1, 0);
    for(int i=0;i<n-1;i++) ans[i] = p[i+1];
    return ans;
}
 
vector<int> generate_lcp(string s, vector<int> &sufArray) {
    int n = s.length();
    vector<int> rank(n, -1);
    for(int i=0;i<n;i++) rank[sufArray[i]] = i;
    int k = 0;
    vector<int> lcp(n-1, 0);
    for(int i=0;i<n;i++) {
        if(rank[i]==n-1) {
            k = 0;
            continue;
        }
        int j = sufArray[rank[i]+1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
        lcp[rank[i]] = k;
        if(k) k--;
    }
    return lcp;
}

const int N = 1e6+10;
vector<vector<int>> pos(N, vector<int>());
vector<int> cnt(N, 0), l(N, N), r(N, 0);

void solve() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<int> sufArray = suffix_array(str);
    vector<int> lcp = generate_lcp(str, sufArray);

    for(int i=0;i<n-1;i++) pos[lcp[i]].push_back(i+1);

    // 1 0 3 2 4 5 9 1
    vector<int> v(n+1, 0);
    ll ans = 0;
    for(int k=n;k>1;k--) {
        for(int &p: pos[k]) {
            if(v[p-1]) cnt[p-l[p-1]+1]--;
            if(v[p+1]) cnt[r[p+1]-p+1]--;
            v[p] = 1;
            int rMost = v[p+1]?r[p+1]:p;
            int lMost = v[p-1]?l[p-1]:p;
            cnt[rMost-lMost+2]++;
            l[rMost] = lMost;
            r[lMost] = rMost;
        }
        for(int y=k;y<=n;y+=k) {
            ans += (ll)y*cnt[y];
        }
    }
    ans += n;
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