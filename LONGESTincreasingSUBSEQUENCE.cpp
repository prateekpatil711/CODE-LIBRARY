#include <bits/stdc++.h>
using namespace std;
int lis(int arr[], int n)
{
	int LIS[n] , max = INT_MIN;

	LIS[0] = 1;
	for (int i = 1; i < n; i++) {
		LIS[i] = 1;
		for (int j = 0; j < i; j++){
            if (arr[i] > arr[j] && LIS[i] < LIS[j] + 1){
                LIS[i] = LIS[j] + 1;
                if(max < LIS[i]){
                    max = LIS[i];
                }
            }
        }	
	}
	return max;
}

int main()
{
	int *arr,n;
    cin >> n;
    arr = new int[n];
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
	printf("Length of LIS is %d\n", lis(arr, n));

	return 0;
}
