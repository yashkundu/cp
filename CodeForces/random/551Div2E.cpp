/**
*   author: lazyhash(yashkundu)
*   created: 11 May, 2024 | 18:33:49
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<pair<int, int>> ans;

int n;


int query(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    int x;
    cin >> x;
    if(x==-1) {
        exit(1);
    }
    return x;
}

void result(int x1, int y1, int x2, int y2) {
    cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
}

int queryRow(int i) {
    return query(i, 1, i, n);
}

int queryCol(int j) {
    return query(1, j, n, j);
}


pair<int, int> searchRow(int i) {
    int l = 1, r = n;
    while(l<r) {
        int mid = (l+r)/2;
        if(query(i, l, i, mid)%2==1) r = mid;
        else l = mid + 1;
    }
    return {i, l};
}

pair<int, int> searchCol(int j) {
    int l =  1, r = n;
    while(l<r) {
        int mid = (l+r)/2;
        if(query(l, j, mid, j)%2==1) r = mid;
        else l = mid + 1;
    }
    return {l, j};
}



 
void solve() {
    cin >> n;

    for(int i=1;i<=n;i++) {
        if(queryRow(i)%2==1) {
            ans.push_back(searchRow(i));
        }
    }

    if(ans.size()==2) {
        result(ans[0].first, ans[0].second, ans[1].first, ans[1].second);
        return;
    }

    for(int j=1;j<n;j++) {
        if(queryCol(j)%2==1) {
            ans.push_back(searchCol(j));
        }
    }

    if(ans.size()==1) {
        ans.push_back(searchCol(n));
    }

    result(ans[0].first, ans[0].second, ans[1].first, ans[1].second);

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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/