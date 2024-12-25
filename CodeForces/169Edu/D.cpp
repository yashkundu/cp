/**
*    author:  lazyhash(yashkundu)
*    created: 15 Aug, 2024 | 20:34:36
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int n, q;
vector<string> s;
map<string, vector<int>> mp;
int x, y;

void sortstring(string &s) {
    if(s[0]>s[1]) swap(s[0], s[1]);
}

bool haveCommmon(string s1, string s2) {
    return s1[0]==s2[0] || s1[0]==s2[1] || s1[1]==s2[0] || s1[1]==s2[1];
}

const int inf = (int)1e9 + 10;

 
void solve() {
    cin >> n >> q;
    s.resize(n);
    mp.clear();


    for(int i=0;i<n;i++) {
        cin >> s[i];
        sortstring(s[i]);
        if(!mp.count(s[i])) mp[s[i]] = vector<int>();
        mp[s[i]].push_back(i);
    }


    while(q--) {
        cin >> x >> y;
        x--; y--;
        if(x>y) swap(x, y);
        if(haveCommmon(s[x], s[y])) {
            cout << abs(x-y) << "\n";
            continue;
        }

        int ans = inf;

        for(int i=0;i<2;i++) for(int j=0;j<2;j++) {
            string newS = "";
            newS += s[x][i];
            newS += s[y][j];
            sortstring(newS);

            if(!mp.count(newS)) continue;

            int ind = lower_bound(mp[newS].begin(), mp[newS].end(), x) - mp[newS].begin();
            if(ind>0) {
                int sind = mp[newS][ind-1];
                ans = min(ans, abs(sind-x) + abs(sind-y));
            }
            if(ind<mp[newS].size()) {
                int sind = mp[newS][ind];
                ans = min(ans, abs(x-sind)+abs(sind-y));
            }

            ind = upper_bound(mp[newS].begin(), mp[newS].end(), y) - mp[newS].begin();
            if(ind<mp[newS].size()) {
                int sind = mp[newS][ind];
                ans = min(ans, abs(x-sind) + abs(sind-y));
            }

        }

        if(ans==inf) ans = -1;

        cout << ans << "\n";



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