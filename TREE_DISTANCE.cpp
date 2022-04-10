#include <bits/stdc++.h>
using namespace std;

long long int dp[200005],mod = 1e9 + 7,ans;
long long int sum[200005],square_sum[200005];
int siz[200005];
std::vector<int>arr[200005];

void DFS(int u,int V){
    siz[u] = 1;
    for(auto x:arr[u]){
        if(x == V)continue;
        DFS(x,u);
        dp[u] = (dp[u] + (sum[u]*(square_sum[x] + 2*sum[x] + siz[x])) + (sum[x] + siz[x])*(square_sum[u]))%mod;
        sum[u] = (sum[u] + sum[x] + siz[x])%mod;
        siz[u] += siz[x];
        square_sum[u] += square_sum[x] + 2*sum[x] + siz[x];
        square_sum[u] %= mod;
    }
    ans += dp[u];
    if(ans >= mod)ans -= mod;
}

int main() {
	// your code goes here
	int t;cin >> t;
	while(t--){
	    int n;cin >> n;
	    ans = 0;
	    for(int i = 0; i < n; i++){
	        siz[i] = sum[i] = dp[i] = square_sum[i] = 0;
	        arr[i].clear();
	    }
	    for(int i = 0; i < n - 1; i++){
	        int u,v;cin >> u >> v;
	        u--;v--;
	        arr[u].push_back(v);
	        arr[v].push_back(u);
	    }
	    DFS(0,0);
	    cout<<ans<<endl;
	}
	return 0;
}