#include <bits/stdc++.h>
using namespace std;

int max(int x, int y)
{
	return (x > y) ? x : y;
}
int minJumps(int arr[], int n)
{

	if (n <= 1)
		return 0;

	if (arr[0] == 0)
		return -1;

	int maxReach = arr[0];
	int step = arr[0];
	int jump = 1;
	int i = 1;
	for (i = 1; i < n; i++) {
		if (i == n - 1)
			return jump;
		maxReach = max(maxReach, i + arr[i]);
		step--;
		if (step == 0) {
			jump++;
			if (i >= maxReach)
				return -1;
			step = maxReach - i;
		}
	}

	return -1;
}

int main()
{
	int *arr,N;
    cin >> N ;
    arr =new int[N];
    for(int i = 0 ; i < N ; i++){
        cin >> arr[i];
    }
	cout << ("Minimum number of jumps to reach end is %d ",
			minJumps(arr, N));
	return 0;
}


/*

Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output: 3 (1-> 3 -> 9 -> 9)
Explanation: Jump from 1st element 
to 2nd element as there is only 1 step, 
now there are three options 5, 8 or 9. 
If 8 or 9 is chosen then the end node 9 
can be reached. So 3 jumps are made.

Input:  arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
Output: 10
Explanation: In every step a jump 
is needed so the count of jumps is 10.

*/