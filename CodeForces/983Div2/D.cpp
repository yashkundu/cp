/**
*    author:  lazyhash(yashkundu)
*    created: 01 Nov, 2024 | 21:01:23
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

const int MAXN = (int)1e4+10;

int p[MAXN] = {0};
set<int> st;


int query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int x;
    cin >> x;
    if(x==-1) exit(0);
    return x;
}

int n;
 
void solve() {

    cin >> n;
    st.clear();

    int last = n-1;
    for(int i=2;i<n;i++) {
        if(query(1, i)) {
            p[i] = 0;
            st.insert(i);
        } else {
            p[i] = 1;
            st.insert(i);
            last = i;
            break;
        }
    }
    last++;

    while(last<n) {
        int x = *st.begin();
        st.erase(x);
        if(x==n-2) {
            p[last] = n-2;
            break;
        }
        if(!query(x, last)) {
            p[last] = x;
            st.insert(last);
            last++;
        }
            
    }


    cout << "! ";
    for(int i=1;i<n;i++) cout << p[i] << " ";
    cout << endl;


    
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