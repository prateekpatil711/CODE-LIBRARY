#include <bits/stdc++.h>
using namespace std;

int kadaneAlgo(int arr[], int &start, int &end, int n) {    
   int sum = 0, maxSum = INT_MIN;

   end = -1;    //at first no place is selected

   int tempStart = 0;    //starting from 0

   for (int i = 0; i < n; i++) {
      sum += arr[i];
      if (sum < 0) {
         sum = 0;
         tempStart = i+1;
      }else if (sum > maxSum) {     
         maxSum = sum;
         start = tempStart;
         end = i;
      }
   }

   if (end != -1)
      return maxSum;
   else{
       maxSum = arr[0];
       start = end = 0;

       // Find the maximum element in array
       for (int i = 1; i < n; i++) {
          if (arr[i] > maxSum) {
     maxSum = arr[i];
             start = end = i;
          }
       }
       return maxSum;
   }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int n,m;
    cin >>n>>m;
    
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j]; 
        }
    }
    
    int maxSum = INT_MIN, endLeft, endRight, endTop, endBottom;
    int left, right;
    int temp[n], sum, start, end;

    for (left = 0; left < m; left++) {
        for(int i = 0; i<n; i++)
           temp[i] = 0;

        for (right = left; right < m; ++right) {
           for (int i = 0; i < n; ++i){
                temp[i] += arr[i][right];
           }     
            sum = kadaneAlgo(temp, start, end, n);    

             if (sum > maxSum) {
                maxSum = sum;
                endLeft = left;
                endRight = right;
                endTop = start;
                endBottom = end;
             }
         }
    }
    
    cout << maxSum << endl;
    
    return 0;
}






