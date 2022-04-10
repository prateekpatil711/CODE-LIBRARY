#include<bits/stdc++.h>
using namespace std;


int count( int sum )
{
    vector<int> dp(sum + 1 , 0);
    dp[0] = 1;
    for(int i = 1 ; i <= sum ; i++){
        for(int j = 1 ; j <= 6 && i-j >=0 ; j++){
            dp[i] = dp[i] + dp[i - j];
        }
    }

    return dp[sum];

}

int main()
{
	int  sum;
    cin >>  sum;
	cout << count(sum);
	return 0;
}


// 0  1  2  3  4  5  6  7  8    ...... SUM
// 1  1  2  4  8  16 32 63 125  ...... POSIIBLE combinations when you throw a dice multiple times to get the sum8