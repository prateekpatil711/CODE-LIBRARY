#include <bits/stdc++.h>
using namespace std;

void LIS(int *arr, int n)
{
	vector<int> list;
	vector<int> longestlist;
	int highestCount = 0;
	int cm;
	for(int i = 0; i < n; i++)
	{
		cm = INT_MIN;
		for(int j = i; j < n; j++)
		{
			if (a[j] > cm)
			{
				list.push_back(a[j]);
				cm = a[j];
			}
		}
		if (highestCount < list.size())
		{
			highestCount = list.size();
			for(int k = 0; k < list.size(); k++)
			{
				longestlist.push_back(list[k]);
			}
		}
		list.clear();
	}

	for(int i = 0; i < longestlist.size(); i++)
	{
		cout << longestlist[i] << ' ';
	}
	cout << endl;
	cout << "length of longestlist is " << highestCount;
}

int main()
{
	int *arr , n_ele ;
    cin >> n_ele;
    arr = new int(n_ele);
    for(int i = 0 ; i < n_ele ; i++){
        cin >> arr[i];
    }
	LIS(arr, n_ele);

	return 0;
}
