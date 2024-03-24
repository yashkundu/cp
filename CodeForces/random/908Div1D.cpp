/**
*   author: lazyhash(yashkundu)
*   created: 13 Jan, 2024 | 17:46:31
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int N = 2e5+10;
int cnt[N] = {0};
int a[N], s[N], d[N];


auto comp = [](const pair<int, int> p1, const pair<int, int> p2) {
        if(p1.first!=p2.first) return p1.first>p2.first;
        return p1.second>p2.second;
    };



bool fillShelves(set<pair<int, int>, decltype(comp)> &st, vector<vector<vector<int>>> &shelves) {
    for(int i=0;i<shelves.size();i++) {
        for(int j=0;j<shelves[i].size();j++) {
            auto &miniShelf = shelves[i][j];
            if(miniShelf.size()>st.size()) return false;
            vector<pair<int, int>> accPairs;
            for(int k=0;k<miniShelf.size();k++) {
                auto it = st.begin();
                accPairs.push_back(*it);
                st.erase(it);
            }
            for(int k=0;k<miniShelf.size();k++) {
                auto &p = accPairs[k];
                miniShelf[k] = p.second;
                p.first--;
                if(p.first) st.emplace(p.first, p.second);
            }
        }
    }
    return true;
}

void orderMiniShelf(vector<int> &prevMiniShelf, vector<int> &curMiniShelf) {
    set<int> st;
    for(int x: curMiniShelf) st.insert(x);
    vector<int> badCols, goodCols;
    for(int x: prevMiniShelf) if(st.count(x)) badCols.push_back(x);
    st.clear();
    for(int x: badCols) st.insert(x);
    for(int x: curMiniShelf) if(!st.count(x)) goodCols.push_back(x);
    for(auto it = curMiniShelf.rbegin();it!=curMiniShelf.rend();it++) {
        if(badCols.size()) {
            *it = badCols.back();
            badCols.pop_back();
        } else {
            *it = goodCols.back();
            goodCols.pop_back();
        }
    }
}


void orderShelf(vector<vector<int>> &shelf) {
    for(int i=1;i<shelf.size();i++) {
        orderMiniShelf(shelf[i-1], shelf[i]);
    }
}

 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> shelves;
    for(int i=1;i<=n;i++) cnt[i] = 0;

    for(int i=0;i<n;i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    
    
    set<pair<int, int>, decltype(comp)> st(comp);

    for(int i=1;i<=n;i++) if(cnt[i]) st.emplace(cnt[i], i);


    for(int i=0;i<m;i++) {
        cin >> s[i];
    }

    for(int i=0;i<m;i++) cin >> d[i];

    for(int i=0;i<m;i++) {
        int tot = s[i];
        int part = d[i];
        vector<vector<int>> v;
        while(tot>0) {
            v.push_back(vector<int>(min(tot, part), 0));
            tot -= min(tot, part);
        }
        shelves.push_back(v);
    }

    if(!fillShelves(st, shelves)) {
        cout << "-1\n";
        return;
    }


    for(int i=0;i<m;i++) {
        orderShelf(shelves[i]);
        for(auto v: shelves[i]) for(auto x: v) cout << x << " ";
        cout << "\n";
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/