#include <bits/stdc++.h>
using namespace std;

void insertionSort(int *arr, int n) {
  int current, prev, i, j;
  for (i = 1; i < n; i++) {
    current = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > current) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = current;
  }
}

int main() {
  int *arr , n_ele ;
    cin >> n_ele;
    arr = new int(n_ele);
    for(int i = 0 ; i < n_ele ; i++){
        cin >> arr[i];
    }
  insertionSort(arr, n_ele);
  for(int i = 0 ; i < n_ele ; i++){
        cout << arr[i] << " ";
    }
}