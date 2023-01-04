/**
*    author:  lazyhash(yashkundu)
*    created: 02 Jan,2023 | 15:49:49
**/
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;

int calcMin(vector<int> &cnt) {
    for(int i=0;i<10;i++) if(cnt[i]) return i;
    return 10;
}

void solve() {
    string str;
    cin >> str;

    int n = str.size();

    vector<int> v(n, 0), cnt(10, 0);
    for(int i=0;i<n;i++) v[i] = str[i]-'0';

    vector<vector<int>> next(n+1, vector<int>(10, n));
    for(int i=n-1;i>=0;i--) {
        for(int j=0;j<10;j++) next[i][j] = next[i+1][j];
        next[i][v[i]] = i;
    }
    vector<int> ans;

    int i = 0;
    while(true) {
        int k = 10, ind=-1;
        for(int j=0;j<10;j++) if(next[i][j]<n) {
            k = j;
            ind = next[i][j];
            break;
        }
        int x = calcMin(cnt);
        if(min(x, k)==10) break;
        if(x<=k) {
            ans.push_back(x);
            cnt[x]--;
        } else {
            while(i<ind) {
                cnt[min(v[i]+1, 9)]++;
                i++;
            }
            ans.push_back(k);
            i++;
        }
    }

    for(int x: ans) cout << x;
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/