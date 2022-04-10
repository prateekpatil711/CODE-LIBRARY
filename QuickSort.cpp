#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int *arr, int l, int h) {
  int pivot = arr[l];

  int i = l, j = h;
  while (i < j) {
    while (arr[i] <= pivot) {
      i++;
    };

    while (arr[j] > pivot) {
      j--;
    }

    if (i < j) {
      swap(&arr[i], &arr[j]);
    } else {
      swap(&arr[l], &arr[j]);
      break;
    }
  }

  return j;
}

void Quicksort(int *arr, int l, int h) {
  int j;

  if (l < h) {
    j = partition(arr, l, h);
    Quicksort(arr, l, j);
    Quicksort(arr, j + 1, h);
  }
}

int main() {

  int *arr , n_ele ;
    cin >> n_ele;
    arr = new int(n_ele);
    for(int i = 0 ; i < n_ele ; i++){
        cin >> arr[i];
    }
  Quicksort(arr, 0, n_ele - 1);
  for(int i = 0 ; i < n_ele ; i++){
        cout << arr[i] << " ";
    }

}