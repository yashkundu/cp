/**
*   author: lazyhash(yashkundu)
*   created: 28 Apr, 2024 | 11:00:37
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
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

const int N = 2e5+2;
const int S = 600;
int x[N], y[N];
int cntStart[S][S] = {0};
int cntEnd[S][S] = {0};
int cnt[N] = {0};

vector<pair<int, int>> segs[N];


int n, m;


struct Event{
    int startDay, model;
    bool dir, type;
};


vector<Event> events[N];

 
void solve() {
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> x[i] >> y[i];



    for(int i=0;i<m;i++) {
        int op, model;
        cin >> op >> model;
        model--;
        if(op==1) {
            segs[model].push_back({i, m});
        } else {
            segs[model].back().second = i;
        }
    }

    for(int i=0;i<n;i++) {
        if(segs[i].empty()) continue;
        // x[i] + y[i]
        if(x[i]+y[i]>=S) {
            for(auto p: segs[i]) {
                int a = p.first, b = p.second;
                int start = a + x[i];
                while(start<b) {
                    // [start, start+y[i])
                    cnt[start] += 1;
                    int end = min(start+y[i], b);
                    cnt[end] -= 1;
                    start += (x[i]+y[i]);
                }
            }
        } else {
            for(auto p: segs[i]) {
                int a = p.first, b = p.second;
                events[a].push_back({a, i, 0, 1});
                events[b].push_back({a, i, 1, 1});
            }
        }
    }

    int cur = 0;

    for(int i=0;i<m;i++) {
        for(int j=1;j<S;j++) {
            cur -= cntEnd[j][i%j];
        }
        cur += cnt[i];
        for(Event ev: events[i]) {
            if(ev.type==0) {
                // normal event
                if(ev.dir==0) cur++;
                else cur--;
            } else {
                // modulus event
                int model = ev.model;
                int start = ev.startDay;
                int tot = x[model] + y[model];
                if(ev.dir==0) { 
                    cntStart[tot][(start+x[model])%tot] += 1;
                    cntEnd[tot][start%tot] += 1;
                } else {
                    cntStart[tot][(start+x[model])%tot] -= 1;
                    cntEnd[tot][start%tot] -= 1;
                    // check if they were active or not
                    int mod = (i - start)%tot;
                    if(mod>x[model]) cur--;
                }
            }
        }
        for(int j=1;j<S;j++) {
            cur += cntStart[j][i%j];
        }

        cout << cur << "\n";

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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/