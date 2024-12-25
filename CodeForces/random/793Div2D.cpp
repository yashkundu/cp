/**
*    author:  lazyhash(yashkundu)
*    created: 25 Aug, 2024 | 16:39:33
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
vector<int> odds;
string s;


void printedge(int a, int b) {
    cout << a << " " << b << "\n";
}


void printedgechain(int a, int b) {
    if(a==b) return;
    int cur = a;
    while(true) {
        int nxt = cur%n+1;
        printedge(cur, nxt);
        if(nxt==b) break;
        cur = nxt;
    }
}

 
void solve() {
    cin >> n;
    odds.clear();
    cin >> s;

    for(int i=0;i<n;i++) {
        if(s[i]=='1') odds.push_back(i+1);
    }

    int sz = odds.size();

    if(sz==0 || sz%2==1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    if(sz==2) {
        int first = odds[0], second = odds[1];
        while(true) {
            int nxt = first-1;
            nxt = (nxt-1+n)%n+1;
            if(nxt==odds[1]) break;
            printedge(first, nxt);
            first = nxt;
        }
        while(true) {
            int nxt = second-1;
            nxt = (nxt-1+n)%n+1;
            if(nxt==odds[0]) break;
            printedge(second, nxt);
            second = nxt;
        }
        printedge(first, second);
        return;
    }

    int first = odds[0];
    printedge(first, first+1);
    printedgechain(first+1, odds[1]);
    printedge(first, odds[1]+1);
    printedgechain(odds[1]+1, odds[2]);

    int last = odds[2]+1;
    printedgechain(last, odds[3]);


    for(int i=4;i<sz;i+=2) {
        printedge(last, odds[i-1]+1);
        printedgechain(odds[i-1]+1, odds[i+1]);
        last = odds[i];
    }

    printedge(last, odds[sz-1]%n+1);
    printedgechain(odds[sz-1]%n+1, first);
    
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