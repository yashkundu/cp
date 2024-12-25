/**
*    author:  lazyhash(yashkundu)
*    created: 12 Nov, 2024 | 08:18:07
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<int> p[3];

vector<pair<int, int>> ops;

vector<int> inds[3];
vector<int> mx[3];

char players[] = {'q', 'k', 'j'};


void calc(int ind) {
    if(ind==0) return;
    for(int j=0;j<3;j++) {
        if(mx[j][ind-1]>p[j][ind]) {
            ops.push_back({j, ind});
            calc(inds[j][mx[j][ind]]);
            return;
        }
    }
}

 
void solve() {
    cin >> n;
    for(int j=0;j<3;j++) p[j].resize(n);
    for(int j=0;j<3;j++) inds[j].resize(n+1);
    for(int j=0;j<3;j++) mx[j].resize(n+1);

    for(int j=0;j<3;j++) for(int i=0;i<n;i++) mx[j][i] = 0;


    for(int j=0;j<3;j++) for(int i=0;i<n;i++) {
        cin >> p[j][i];
        inds[j][p[j][i]] = i;
    }

    for(int j=0;j<3;j++) mx[j][0] = p[j][0];


    ops.clear();


    for(int i=1;i<n;i++) {
        bool good = false;
        for(int j=0;j<3;j++) {
            if(mx[j][i-1]>p[j][i]) {
                good = true;
                break;
            }
        }
        for(int j=0;j<3;j++) {
            mx[j][i] = mx[j][i-1];
            if(good) mx[j][i] = max(mx[j][i], p[j][i]);
        }
    }



    bool ans = false;
    for(int j=0;j<3;j++) if(mx[j][n-2]>p[j][n-1]) {
        ans = true;
        break;
    }


    if(!ans) {
        cout << "NO\n";
        return;
    }


    cout << "YES\n";

    calc(n-1);


    cout << ops.size() << "\n";

    int s = ops.size();

    for(int i=s-1;i>=0;i--) {
        cout << players[ops[i].first] << " " << ops[i].second+1 << "\n";
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