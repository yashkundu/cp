/**
*    author:  lazyhash(yashkundu)
*    created: 04 Jul, 2024 | 12:30:30
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = int(1e5)+10;

ll a[MAXN], b[MAXN];
bool taken[MAXN];

ll n, m;
 
void solve() {
   	cin>>n>>m;
	for (int i=2; i<=n; i++){
		cin>>a[i];
	}
	for (int i=1; i<=n; i++){
		cin>>b[i];
		taken[i]=0;
	}
	sort(a+2,a+1+n);
	sort(b+1,b+1+n);
	int i=2,j=1;
	while (i<=n && j<=n){
		if (a[i]<b[j]){
			taken[j]=1;
			i++,j++;
		}
		else{
			j++;
		}
	}
	vector<ll> v;
	for (int i=1; i<=n; i++){
		if (!taken[i]){
			v.push_back(b[i]);
		}
	}
	ll mx=v.back();

	ll left=n-i+2;
	ll ans=left*m-min((mx-1),m);

	cout<<ans<<"\n";


    

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