#include <bits/stdc++.h>
using namespace std;

void selectionSort (int *arr, int n) {
        int min;        
        for(int i = 0; i < n-1 ; i++)  {
            min = i ;
            for(int j = i+1; j < n ; j++ ) {
                if(arr[j] < arr[min])  min = arr[j];
            }
            swap (arr[min], arr[i]) ; 
        }
   }


int main(){
    int *arr , n_ele ;
    cin >> n_ele;
    arr = new int(n_ele);
    for(int i = 0 ; i < n_ele ; i++){
        cin >> arr[i];
    }
    selectionSort(arr,n_ele);
    for(int i = 0 ; i < n_ele ; i++){
        cout << arr[i] << " ";
    }
}
