/**
*    author:  lazyhash(yashkundu)
*    created: 03 Aug, 2024 | 12:41:46
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
bool vis[26];

char query1(int i) {
    cout << "? 1 " << i << endl;
    char ch;
    cin >> ch;
    return ch;
}

int query2(int l, int r) {
    cout << "? 2 " << l << " " << r << endl;
    int x;
    cin >> x;
    return x;
}

void output(string s) {
    cout << "! " << s << endl;
}

int dist = 0;
vector<pair<char, int>> vec;


void update(int ind, char ch) {
    fill(vis, vis+26, 0);
    vector<pair<char, int>> nw;
    vis[ch-'a'] = 1;
    nw.push_back({ch, ind});
    while(!vec.empty()) {
        auto [c, i] = vec.back(); vec.pop_back();
        if(!vis[c-'a']) {
            vis[c-'a'] = 1;
            nw.push_back({c, i});
        }
    }
    vec = vector<pair<char,int>>(nw.rbegin(), nw.rend());
}



string s;
int sz;

void solve() {
    cin >> n;

    for(int i=1;i<=n;i++) {
        int cnt = query2(1, i);
        char ch;
        if(cnt>dist) {
            ch = query1(i);
        } else {
            sz = vec.size();
            int L = 0, R = sz;
            while(R-L>1) {
                int mid = (L+R)/2;
                if(query2(vec[mid].second, i)==sz-mid) L = mid;
                else R = mid;
            }
            ch = vec[L].first;
        }
        s += ch;
        update(i, ch);
        dist = cnt;
    }

    output(s);


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