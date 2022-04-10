#include <bits/stdc++.h>
using namespace std;
void longestSubsequence(int a[], int n)
{
	unordered_map<int, int> mp;
	int dp[n];
	memset(dp, 0, sizeof(dp));

	int maximum = INT_MIN;
	int index = -1;
	for (int i = 0; i < n; i++) {
		if (mp.find(a[i] - 1) != mp.end()) {
			int lastIndex = mp[a[i] - 1] - 1;
			dp[i] = 1 + dp[lastIndex];
		}
		else	dp[i] = 1;
		mp[a[i]] = i + 1;

		if (maximum < dp[i]) {
			maximum = dp[i];
			index = i;
		}
	}
	for (int curr = a[index] - maximum + 1;
		curr <= a[index]; curr++)
		cout << curr << " ";
}
int main()
{
	int *arr , n_ele ;
    cin >> n_ele;
    arr = new int(n_ele);
    for(int i = 0 ; i < n_ele ; i++){
        cin >> arr[i];
    }
	longestSubsequence(arr, n_ele);
	return 0;
}
