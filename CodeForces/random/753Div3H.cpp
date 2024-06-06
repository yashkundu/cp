/**
*   author: lazyhash(yashkundu)
*   created: 24 Apr, 2024 | 09:16:35
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

const int N = 2e5+10;
int a[N], b[N], m[N];
pair<int, int> ans[N];


struct Dish{
    int ind, a, b, m;
};


map<int, vector<Dish>> dishMap;

int n;


// calculates for a set of possible same dishes
int calc(vector<Dish> &dishes, int totWeight) {
    vector<pair<int, pair<int, int>>> events;
    for(Dish &dish: dishes) {
        // [max(0, a-m), a - max(0, m-b)]
        // 0 start | 1 end
        int l = max(0, dish.a-dish.m), r = dish.a - max(0, dish.m - dish.b);
        events.push_back({l, {0, dish.ind}});
        events.push_back({r, {1, dish.ind}});
    }
    sort(events.begin(), events.end());

    int cnt = 0;
    vector<int> curDishes;
    for(int i=0;i<events.size();) {
        int j = i;
        while(j<events.size() && events[j].first==events[i].first) {
            int ind = events[j].second.second;
            int type = events[j].second.first;
            if(!type) 
                curDishes.push_back(ind);
            j++;
        }
        if(events[j-1].second.first && ans[events[j-1].second.second].first==-1) {
            // of type ending
            cnt++;
            for(int ind: curDishes) {
                ans[ind] = {events[j-1].first, totWeight - events[j-1].first};
            }
            curDishes.clear();
        }
        i = j;
    }
    return cnt;
}

 
void solve() {

    cin >> n;
    dishMap.clear();
    for(int i=0;i<n;i++) ans[i].first = ans[i].second = -1;

    for(int i=0;i<n;i++) {
        cin >> a[i] >> b[i] >> m[i];
        int val = a[i] + b[i] - m[i];
        if(dishMap.find(val)==dishMap.end()) dishMap[val] = vector<Dish>();
        dishMap[val].push_back({i, a[i], b[i], m[i]});
    }


    int cnt = 0;
    for(auto it=dishMap.begin(); it!=dishMap.end(); it++) {
        cnt += calc(it->second, it->first);
    }

    cout << cnt << "\n";
    for(int i=0;i<n;i++) {
        cout << a[i] - ans[i].first << " " << b[i] - ans[i].second << "\n";
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