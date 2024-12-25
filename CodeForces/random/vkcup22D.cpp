/**
*    author:  lazyhash(yashkundu)
*    created: 19 Jul, 2024 | 14:48:56
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

int m;
string s;

map<char, int> mp = {{'i', 0}, {'n', 1}, {'w', 2}};
vector<char> ch = {'i', 'n', 'w'};

vector<int> edges[3][3];

void addEdges(string s, int ind) {
    int cnt[3] = {0};
    for(int i=0;i<3;i++) {
        cnt[mp[s[i]]]++;
    }
    for(int k=0;k<2;k++) {
        for(int i=0;i<3;i++) {
            if(cnt[i]<=1) continue;
            for(int j=0;j<3;j++) {
                if(cnt[j]==0) {
                    edges[i][j].push_back(ind);
                    cnt[j]++;
                    cnt[i]--;
                    break;
                }
            }
        }
    }
}

vector<pair<pair<int, int>, pair<int, int>>> ans;

void solve2(int i, int j) {
    while(!edges[i][j].empty() && !edges[j][i].empty()) {
        int x = edges[i][j].back(); edges[i][j].pop_back();
        int y = edges[j][i].back(); edges[j][i].pop_back();
        ans.push_back({{x, i}, {y, j}});
    }
}


void solve3(int i, int j, int k) {
    while(!edges[i][j].empty() && !edges[j][k].empty() && !edges[k][i].empty()) {
        int x = edges[i][j].back(); edges[i][j].pop_back();
        int y = edges[j][k].back(); edges[j][k].pop_back();
        int z = edges[k][i].back(); edges[k][i].pop_back();
        ans.push_back({{x, i}, {y, j}});
        ans.push_back({{y, i}, {z, k}});
    }
}

 
void solve() {
    cin >> m;

    for(int i=0;i<3;i++) for(int j=0;j<3;j++) edges[i][j].clear();

    for(int i=1;i<=m;i++) {
        cin >> s;
        addEdges(s, i);
    }

    
    ans.clear();
    solve2(0, 1);
    solve2(0, 2);
    solve2(1, 2);

    vector<int> v = {0, 1, 2};
    do {
        solve3(v[0], v[1], v[2]);
    } while(next_permutation(v.begin(), v.end()));


    cout << ans.size() << "\n";
    for(auto p: ans) {
        cout << p.first.first << " " << ch[p.first.second] << " " << p.second.first << " " << ch[p.second.second] << "\n";
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