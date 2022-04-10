#include <bits/stdc++.h>
using namespace std;
vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> key_indices;
        vector<int> unique_indices;
        vector<int> indices;
        int i;
        for(i = 0 ; i<nums.size() ; i++){
            if(nums[i] == key){
                key_indices.push_back(i);
            }
        }
        sort(key_indices.begin(),key_indices.end());
        for(i = 0 ;i<key_indices.size() ; i++){
                cout << key_indices[i] << " ";
                for(int j = 1 ; j <= k ; j++){
                        unique_indices.push_back(key_indices[i]-j);
                    }
                for(int j = 1 ; j <= k ; j++){
                        unique_indices.push_back(j+key_indices[i]);
                }
                cout << key_indices[i] << " " << endl;
                unique_indices.push_back(key_indices[i]);
        }
        sort(unique_indices.begin(),unique_indices.end());
        for(i = 0 ; i<unique_indices.size()-1 ; i++){
            if(unique_indices[i] != unique_indices[i+1] && unique_indices[i]<nums.size() && unique_indices[i]>=0){
                indices.push_back(unique_indices[i]);
            }
        }
        if(unique_indices[i]<nums.size()){
            indices.push_back(unique_indices[i]);
        }
        return indices;
    }

int main(){
    int  n_ele ,key , k , x;
    cin >> n_ele >> key >> k;
    vector<int> nums;
    vector<int> indices;
    for(int i = 0 ; i < n_ele ; i++){
        cin >> x;
        nums.push_back(x);
    }
    indices = findKDistantIndices(nums,key,k);
    for(int x : indices){
        cout << x;
    }
}

//You are given a 0-indexed integer array nums and two integers key and k. A k-distant index is an index
// i of nums for which there exists at least one index j such that |i - j| <= k and nums[j] == key.

/*

Input: nums = [3,4,9,1,3,9,5], key = 9, k = 1
Output: [1,2,3,4,5,6]
Explanation: Here, nums[2] == key and nums[5] == key.
- For index 0, |0 - 2| > k and |0 - 5| > k, so there is no j where |0 - j| <= k and nums[j] == key. Thus, 0 is not a k-distant index.
- For index 1, |1 - 2| <= k and nums[2] == key, so 1 is a k-distant index.
- For index 2, |2 - 2| <= k and nums[2] == key, so 2 is a k-distant index.
- For index 3, |3 - 2| <= k and nums[2] == key, so 3 is a k-distant index.
- For index 4, |4 - 5| <= k and nums[5] == key, so 4 is a k-distant index.
- For index 5, |5 - 5| <= k and nums[5] == key, so 5 is a k-distant index.
- For index 6, |6 - 5| <= k and nums[5] == key, so 6 is a k-distant index.
Thus, we return [1,2,3,4,5,6] which is sorted in increasing order. 

*/