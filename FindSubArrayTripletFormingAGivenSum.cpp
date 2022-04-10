#include <bits/stdc++.h>
using namespace std;
bool find3Numbers(int A[], int arr_size, int sum)
{
	for (int i = 0; i < arr_size - 2; i++)
	{
		unordered_set<int> s;
		int curr_sum = sum - A[i];
		for (int j = i + 1; j < arr_size; j++)
		{
			if (s.find(curr_sum - A[j]) != s.end())
			{
				printf("Triplet is %d, %d, %d", A[i],
					A[j], curr_sum - A[j]);
				return true;
			}
			s.insert(A[j]);
		}
	}
	return false;
}

int main()
{
	int A[] = { 1, 4, 45, 6, 10, 8 };
	int sum = 22;
	int arr_size = sizeof(A) / sizeof(A[0]);

	find3Numbers(A, arr_size, sum);

	return 0;
}


/*

Approach: This approach uses extra space but is simpler than the two-pointers approach. Run two loops outer loop from start to end and inner loop from i+1 to end. Create a hashmap or set to store the elements in between i+1 to j-1. So if the given sum is x, check if there is a number in the set which is equal to x – arr[i] – arr[j]. If yes print the triplet. 
 
Algorithm: 
Traverse the array from start to end. (loop counter i)

Create a HashMap or set to store unique pairs.

Run another loop from i+1 to end of the array. (loop counter j)

If there is an element in the set which is equal to x- arr[i] – arr[j], then print the triplet (arr[i], arr[j], x-arr[i]-arr[j]) and break

Insert the jth element in the set.




Input: array = {12, 3, 4, 1, 6, 9}, sum = 24; 
Output: 12, 3, 9 
Explanation: There is a triplet (12, 3 and 9) present 
in the array whose sum is 24. 
Input: array = {1, 2, 3, 4, 5}, sum = 9 
Output: 5, 3, 1 
Explanation: There is a triplet (5, 3 and 1) present 
in the array whose sum is 9.

*/