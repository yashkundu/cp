/**
*    author:  lazyhash(yashkundu)
*    created: 19 Aug, 2024 | 13:18:54
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
string s;
string news;
vector<int> p;
vector<bool> vis;

vector<vector<int>> cycles;


bool check(vector<int> &c) {
    for(auto ind: c) {
        if(s[ind]!=news[ind]) return false;
    }
    return true;
}

void transition(vector<int> &c) {
    int sz = (int)c.size();
    char first = news[c[0]];
    for(int i=0;i<sz-1;i++) {
        news[c[i]] = news[c[i+1]];
    }
    news[c[sz-1]] = first;
}



ll gcd(ll a, ll b) {
    if(b==0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a/gcd(a, b)*b;
}

 
void solve() {
    cin >> n;
    cin >> s;
    news = s;
    p.resize(n);
    vis.resize(n);
    vis.assign(n, 0);

    for(int i=0;i<n;i++) cin >> p[i], p[i]--;

    cycles.clear();


    for(int i=0;i<n;i++) {
        if(vis[i]) continue;
        vector<int> c;
        c.push_back(i);
        int ind = i;
        vis[ind] = 1;
        while(p[ind]!=i) {
            ind = p[ind];
            c.push_back(ind);
            vis[ind] = 1;
        }
        cycles.push_back(c);
    }

    ll l = 1;
    for(auto &c: cycles) {
        for(int i=1;i<=c.size();i++) {
            transition(c);
            if(check(c)) {
                l = lcm(l, i);
                break;
            }
        }
    }

    cout << l << "\n";












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