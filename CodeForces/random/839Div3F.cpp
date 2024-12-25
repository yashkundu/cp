/**
*    author:  lazyhash(yashkundu)
*    created: 20 Jul, 2024 | 13:13:09
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

const int MAXN = 31;
const int MAXK = 102;

int n, m, k;
vector<vector<vector<bool>>> a;

vector<vector<bool>> tmpa;

int cnt[MAXK];
bool vis[MAXK][MAXN][MAXN];

bool bad = false;
vector<pair<int, int>> v;

 
string s;

bool check(int i, int j) {
    if(i>0 && i<n && j>0 && j<m) {
        int x = tmpa[i-1][j] + tmpa[i+1][j] + tmpa[i][j-1] + tmpa[i][j+1];
        if((tmpa[i][j] && x==0) || (!tmpa[i][j] && x==4)) {
            tmpa[i][j] = !tmpa[i][j];
            return true;
        } 
        return false;
    } 
    return false;
}


void solve() {
    cin >> n >> m >> k;
    a.resize(k+1);
    for(int i=0;i<=k;i++) {
        a[i].resize(n);
        for(int j=0;j<n;j++) a[i][j].resize(m);
    }


    for(int c=0;c<=k;c++) {
        for(int i=0;i<n;i++) {
            cin >> s;
            for(int j=0;j<m;j++) a[c][i][j] = s[j]=='1';
        }
    }

    if(k==0) {
        cout << "1\n0\n";
        return;
    }


    for(int c1=0;c1<=k;c1++) {
        bad = false;
        v.clear();
        for(int i=0;i<=k;i++) cnt[i] = 0;
        for(int x=0;x<=k;x++) for(int i=0;i<n;i++) for(int j=0;j<m;j++) vis[x][i][j] = 0;
        for(int c2=0;c2<=k;c2++) {
            if(c1==c2) continue;
            tmpa = a[c1];
            for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
                if(tmpa[i][j]!=a[c2][i][j]) {
                    if(check(i, j)) {
                        cnt[c2]++;
                        vis[c2][i][j] = 1;
                    } else bad = true;
                }
            }
            v.push_back({cnt[c2], c2});
        }
        if(bad) continue;
        sort(v.begin(), v.end());

        for(int x=0;x<v.size()-1;x++)  {
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    if(vis[v[x].second][i][j] && !vis[v[x+1].second][i][j]) bad = true; 
                }
            }
        }
        if(bad) continue;
        
        cout << c1+1 << "\n";
        cout << k + cnt[v.back().second] << "\n";

        for(int x=0;x<v.size();x++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(vis[v[x].second][i][j] && (x==0 || !vis[v[x-1].second][i][j])) cout << 1 << " " << i+1 << " " << j+1 << "\n";
                }
            }
            cout << 2 << " " << v[x].second + 1 << "\n";
        }
        return;
    }


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