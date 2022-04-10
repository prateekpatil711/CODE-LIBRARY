#include <bits/stdc++.h>

using namespace std;

int fact(int n) {
  int x = 1;
  for (int i = 1; i <= n; x *= i, i++)
    ;
  return x;
}

int main() {
  long long int n, catalan_no, temp;
  cout << "Enter the value of n" << endl;
  cin >> n;

  temp = fact(n);
  catalan_no = fact(2 * n) / (temp * temp);
  catalan_no /= (n + 1);

  cout << "Total no of mountain ranges for " << n << " are " << catalan_no;

  return 0;
}