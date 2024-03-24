/**
*   author: lazyhash(yashkundu)
*   created: 14 Dec, 2023 | 09:47:13
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
 
void solve(int n, vector<pair<int, int>> tasks) {

    vector<pair<int, pair<int, int>>> v;
    // <enqueueTime, <processingTime, index>>

    for(int i=0;i<tasks.size();i++) {
        v.push_back({tasks[i].first, {tasks[i].second, i}});
    }

    set<pair<int, int>> st;
    // processingTime, index


    // sorting v according to enqueue time
    sort(v.begin(), v.end());


    int curTime = 1;

    int ptr = 0;

    vector<int> sequence;

    while(!st.empty() || ptr<n) {
        while(ptr<n && v[ptr].first<=curTime) {
            st.insert(v[ptr].second);
            ptr++;
        }
        if(st.empty() && ptr<n) {
            // curTime< nextEnqueTask
            curTime = v[ptr].first;
            continue;
        }
        pair<int, int> minTaskPair = *(st.begin());
        st.erase(st.begin());
        sequence.push_back(minTaskPair.second);
        curTime += minTaskPair.first;
    }

    for(int &x: sequence) cout << x << " " << tasks[x].first << " " << tasks[x].second << "\n";
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    
    int n = 5;
    vector<pair<int, int>> tasks = {{7,10},{7,12},{7,5},{7,4},{7,2}};
    solve(n, tasks);

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