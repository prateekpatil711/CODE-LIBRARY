#include <bits/stdc++.h>
using namespace std;
int total_count(int arr[], int n)
{
	int count = 0;
	unordered_map<int, int> freq;

	for(int i=0;i<n;i++)
	{
		freq[arr[i]]++;
	}
	for(int i=0;i<n;i++)
	{
		for (int j=1;j<=sqrt(arr[i]);j++)
		{
			if(arr[i]%j==0)
			{
				if(arr[i]==j*j)		count+=freq[j];
				else	count+=freq[j]+ freq[arr[i]/j];
			}
		}
		count=count-1;
	}
	return count;
}


int main()
{
	int *arr , n_ele ;
    cin >> n_ele;
    arr = new int(n_ele);
    for(int i = 0 ; i < n_ele ; i++){
        cin >> arr[i];
    }
	cout<<total_count(arr,n_ele);
	return 0;
}
