#include <bits/stdc++.h>
using namespace std;

int fib(int n , vector<int> dp) {
  if (dp[n] != -1) {
    return dp[n];
  }
  dp[n] = fib(n - 1) + fib(n - 2);
  return dp[n];
}

int main() {
  int n;
  cin >> n;
  vector<int> dp(n+1, -1);
  dp[0] = 0;
  dp[1] = 1;

  cout << fib(n,dp);
}