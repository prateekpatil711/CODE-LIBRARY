#include <bits/stdc++.h>
using namespace std;

int main() {
	int n_ele , position;
	cin>>n_ele;
	int arr[n_ele+1];
	vector<vector<int>> dp;
	for(int i=1;i<=n_ele;i++){
	    cin>>arr[i];
	}
	
	for(int i=1;i<=n_ele;i++){
        position = i;
	    if(arr[i]==0) continue;
	    vector<int> temp;
	    while(true){
	        temp.push_back(position);
	        position = arr[position];
	        if(position == i){
	            temp.push_back(position);
	            break;
	        }
	    }
	    for(int value : temp){
	        arr[value] = 0;
	    }
	    dp.push_back(temp);
	}
	
	cout<<dp.size()<<endl;
	for(auto vec: dp){
	    for(int i:vec){
	        cout<<i<<" ";
	    }
	    cout<<endl;
		
	}
}
