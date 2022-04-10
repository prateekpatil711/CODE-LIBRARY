#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, maximum;
  cin >> n;

  // init an array with 0
  int *arr = new int[n]();

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i / 2; j++) {
      maximum = max(j * (i - j), j * arr[i - j]);
      arr[i] = max(maximum, arr[i]);
    }
  }

  for (int i = 0; i < n; i++) {
    cout << arr[i] << "\n";
  }
}