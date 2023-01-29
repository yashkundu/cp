/**
*    author:  lazyhash(yashkundu)
*    created: 21 Jan, 2023 | 17:39:45
**/
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int n;
    cin >> n;

    int a3[3][3] = {{9,5,1},{3,7,8},{6,2,4}};
    int a4[4][4] = {{15,11,16,12}, {13,3,6,9}, {14,7,8,1},{4, 2, 10, 5}};
    int a5[5][5] = {{1,5,7,11,13},{17,19,23,21,25},{3,9,15,24,20},{6,12,18,16,22},{2,4,8,10,14}};

    if(n==3) {
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) cout << a3[i][j] << " ";
            cout << "\n";
        }
        return;
    }

    if(n==4) {
        for(int i=0;i<4;i++) {
            for(int j=0;j<4;j++) cout << a4[i][j] << " ";
            cout << "\n";
        }
        return;
    }
    if(n==5) {
        for(int i=0;i<5;i++) {
            for(int j=0;j<5;j++) cout << a5[i][j] << " ";
            cout << "\n";
        }
        return;
    }

    vector<int> threes;
    for(int i=3;i<=n*n;i+=3) threes.push_back(i);
    reverse(threes.begin(), threes.end());

    vector<vector<int>> ans(n, vector<int>(n, 0));

    for(int j=0;j<(n+1)/2;j++) {
        int i = (n+1)/2 - 1;
        ans[i][j] = threes.back();
        threes.pop_back();
        ans[i+1][j] = threes.back();
        threes.pop_back();
    }

    for(int j=(n+1)/2;j<n;j++) {
        int i = n/2 - 1;
        ans[i][j] = threes.back();
        threes.pop_back();
        ans[i+1][j] = threes.back();
        threes.pop_back();
    }

    vector<int> odd, even;
    for(int t: threes) (t&1)?(odd.push_back(t)):(even.push_back(t));
    for(int i=1;i<=n*n;i++) if(i%3) (i&1)?(odd.push_back(i)):(even.push_back(i));

    for(int j=0;j<n/2;j++) {
        for(int i=0;i<n;i++) {
            if(!ans[j][i]) {
                ans[j][i] = odd.back();
                odd.pop_back();
            }
        }
    }

    for(int j=(n+1)/2;j<n;j++) {
        for(int i=0;i<n;i++) {
            if(!ans[j][i]) {
                ans[j][i] = even.back();
                even.pop_back();
            }
        }
    }

    


    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) cout << ans[i][j] << " ";
        cout << "\n";
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