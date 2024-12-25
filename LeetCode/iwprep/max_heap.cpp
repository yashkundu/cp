/**
*    author:  lazyhash(yashkundu)
*    created: 03 Nov, 2024 | 16:59:47
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


struct MaxHeap{

    int cap, n;
    vector<int> a;

    MaxHeap(int cap): cap(cap), n(0) {
        a.resize(cap+1) ;
    }

    void heapify(int i) {
        int left = 2*i, right = 2*i+1;
        int largest = i;
        if(left<=n && a[left]>a[largest]) largest = left;
        if(right<=n && a[right]>a[largest]) largest = right;
        if(largest!=i) {
            swap(a[i], a[largest]);
            heapify(largest);
        }
    }

    void move_up(int i) {
        if(i==1) return;
        if(a[i]>a[i/2]) {
            swap(a[i], a[i/2]);
            move_up(i/2);
        }
    }


    bool build(vector<int> &v) {
        int sz = v.size();
        if(sz>cap) return false;
        n = sz;
        for(int i=1;i<=sz;i++) a[i] = v[i-1];
        for(int i=n/2;i>0;i--) heapify(i);
        return true;
    }

    bool insert(int el) {
        if(n==cap) return false;
        a[++n] = el;
        move_up(n);
        return true;
    }

    int get_max() {
        return a[1];
    }

    bool del_max() {
        if(n==0) return false;
        swap(a[1], a[n]);
        n--;
        heapify(1);
        return true;
    }

};


 
void solve() {
    MaxHeap mh(10);
    vector<int> v = {1, 18, 4, 75, 23, 43, 67};
    mh.build(v);

    // cout << mh.get_max();


    for(int i=0;i<7;i++) {
        cout << mh.get_max() << "\n";
        mh.del_max();
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