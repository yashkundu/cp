/*
5
3 4 2 2 3

rem = ops


ops -> order doesn't matters
// distinct -> 


rem -> 3
ops -> 3


   _, _
3, 4, 2, 2, 3

(3, 1), (4, 2), (2, 3), (2, 4), (3, 5)

(xi, yi)

seconds will be unique, and increasing, and they should be equal to set of firsts


[2, 3, 5] -> ()
is such an arrangement possible?

O(n)

a sequence which satisfies our requirement

    
 1 -> 4 -> 6 ->  8
 ^               |
 |               v
 11  <- 7  <-    9

1 <=

6
_ _   _
3 5 6 6 4 5 

functional graph is not connected, there can be multiple functional graph, need to process all of them
// bad test case
10
1 5 6 4 7 8 3 5 1 3
5 1 3


*/


/**
*   author: lazyhash(yashkundu)
*   created: 01 Feb, 2024 | 13:20:51
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <queue>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5+10;
int a[N];
// taken[x] -> true if heads is chosen for some y -> x
bool taken[N];
bool inAns[N];
int inDeg[N] = {0};
bool vis[N];




bool checkCycle(int u) {
   // lenght of cycle if there is non taken in the cycle
   bool isSomeOneTaken = taken[u];
   int x = u;
   int cnt = 0;
   vis[u] = 1;

   while(a[x]!=u) {
      isSomeOneTaken |= taken[a[x]];
      cnt++;
      vis[a[x]] = 1;
      x = a[x];
   }

   cnt++;

   if(!isSomeOneTaken && cnt%2==1) {
      // no possible configuration
      return false;
   }


   if(isSomeOneTaken) {
      x = u;
      while(a[x]!=u) {
         if(taken[x]) {
            u = x;
            break;
         }
         x = a[x];
      }
   } else {
      // make first one h
      inAns[u] = true;
      u = a[u];
      taken[u] = true;
   }

   x = u;
   while(a[x]!=u) {
      if(!taken[a[x]] && !taken[x]) inAns[x] = true;
      taken[a[x]] |= !taken[x];
      x = a[x];
   }

   return true;

}



 
void solve() {
   int n;
   cin >> n;

   for(int i=1;i<=n;i++) {
      cin >> a[i];
      inDeg[a[i]]++;
   }

   for(int i=1;i<=n;i++) taken[i] = inAns[i] = false;
   for(int i=1;i<=n;i++) vis[i] = false;

   queue<int> q;
   for(int i=1;i<=n;i++) if(!inDeg[i]) q.push(i);

   while(!q.empty()) {
      int x = q.front();
      q.pop();
      // if it has atleast one incident H edge, this edge will be T
      // else this edge will be H
      // if atleast one incident edge is H, then taken[x] == true
      if(taken[x]) {
         // atleast one incident h edge
         // x -> a[x] will be T
      } else {
         // x -> a[x] will be H
         taken[a[x]] = true;
         inAns[x] = true;
      }
      inDeg[a[x]]--;
      if(!inDeg[a[x]]) q.push(a[x]);
   }

   // consider the cycle left at the last


   for(int i=1;i<=n;i++) {
      if(!vis[i] && inDeg[i]==1) {
         // check
         if(!checkCycle(i)) {
            cout << "-1\n";
            return;
         }
      }
   }


   int num = 0;
   for(int i=1;i<=n;i++) if(inAns[i]) num++;

   cout << num << "\n";

   for(int i=1;i<=n;i++) if(inAns[i]) cout << a[i] << " ";
   cout << "\n";



}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
   //  cin >> t;
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




