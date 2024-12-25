/**
*    author:  lazyhash(yashkundu)
*    created: 15 Jun, 2024 | 12:06:57
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


map<int, set<pair<int, int>>> rowmp, colmp;

int a, b, n, m;
int x, y;
int tot[2] = {0};


void removeRow(set<pair<int, int>> &s) {
    for(auto [x, y]: s) {
        rowmp[x].erase({x, y});
        if(rowmp[x].size()==0) rowmp.erase(x);
    }
}

void removeCol(set<pair<int, int>> &s) {
    for(auto [x, y]: s) {
        colmp[y].erase({x, y});
        if(colmp[y].size()==0) colmp.erase(y);
    }
}

 
void solve() {
    cin >> a >> b >> n >> m;
    rowmp.clear();
    colmp.clear();


    for(int i=0;i<n;i++) {
        cin >> x >> y;
        if(!rowmp.count(x)) rowmp[x] = set<pair<int, int>>();
        rowmp[x].insert({x, y});
        if(!colmp.count(y)) colmp[y] = set<pair<int, int>>();
        colmp[y].insert({x,y});
    }


    int rowStart = 1, rowEnd = a, colStart = 1, colEnd = b;
    char ch;
    int k;

    int cnt = 0;

    tot[0] = tot[1] = 0;

    for(int i=0;i<m;i++) {
        cin >> ch >> k;
        cnt = 0;
        if(ch=='U') {
            while(!rowmp.empty() && rowmp.begin()->first<rowStart+k) {
                auto &s = rowmp.begin()->second;
                cnt += s.size();
                removeCol(s);
                rowmp.erase(rowmp.begin());
            }
            rowStart += k;
        } else if(ch=='D') {
            while(!rowmp.empty() && rowmp.rbegin()->first>rowEnd-k) {
                auto it = rowmp.end();
                it--;
                auto &s = it->second;
                cnt += s.size();
                removeCol(s);
                rowmp.erase(it);
            }
            rowEnd -= k;
        } else if(ch=='L') {
             while(!colmp.empty() && colmp.begin()->first<colStart+k) {
                auto &s = colmp.begin()->second;
                cnt += s.size();
                removeRow(s);
                colmp.erase(colmp.begin());
            }
            colStart += k;
        } else {
             while(!colmp.empty() && colmp.rbegin()->first>colEnd-k) {
                auto it = colmp.end();
                it--;
                auto &s = it->second;
                cnt += s.size();
                removeRow(s);
                colmp.erase(it);
            }
            colEnd -= k;
        }
        tot[i&1] += cnt;
    }

    cout << tot[0] << " " << tot[1] << "\n";


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