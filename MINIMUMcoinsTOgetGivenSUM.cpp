#include<bits/stdc++.h>
using namespace std;


int count( int *coins, int sum, int N )
{
    vector<int> dp(sum + 1 , INT_MAX);
    dp[0] = 0;
    for(int i = 1 ; i <= sum ; i++){
        for(int j = 0 ; j < N ; j++){
            if(i - coins[j] >=0 ){
                dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
        }
    }

    return dp[sum];

}

int main()
{
	int *coins, sum , N;
    cin >> N >> sum;
    coins = new int[N];
    for(int i = 0 ; i < N ; i++){
        cin >> coins[i];
    }
	cout << count(coins , sum , N);
	return 0;
}