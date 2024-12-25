/**
*    author:  lazyhash(yashkundu)
*    created: 27 Jul, 2024 | 15:50:45
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int LIM = (int)1e9 + 1;


vector<int> seq;
vector<ll> ssum;
int sz;


void init() {
    seq.push_back(1);
    seq.push_back(1);
    while(seq.back()<LIM) {
        seq.push_back(seq.back() + seq[(int)seq.size() - 2]);
    }
    seq.pop_back();
    sz = seq.size();
    ssum.resize(sz);
    ssum[0] = 1;
    for(int i=1;i<sz;i++) ssum[i] = ssum[i-1] + seq[i];
}

int k;
set<pair<int, int>> st;
set<pair<int, int>> ts;
int c;

ll sum = 0;

 
void solve() {
    cin >> k;
    st.clear();

    sum = 0;
    for(int i=0;i<k;i++) {
        cin >> c;
        sum += c;
        st.insert({c, i});
    }



    for(int last=sz-1;last>=0;last--) {
        if(sum!=ssum[last]) continue;
        ts = st;
        bool good = true;
        pair<int, int> prv = {0, 0};
        for(int i=last;i>=0;i--) {
            if(ts.empty()) {
                good = false;
                break;
            }
            auto p = *ts.rbegin();
            ts.erase(p);
            if(p.first<seq[i]) {
                good = false;
                break;
            }
            p.first -= seq[i];
            if(prv.first) ts.insert(prv);
            prv = p;
        }
        if(good && ts.empty() && prv.first==0) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";






}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
    init();
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