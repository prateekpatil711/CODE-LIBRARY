#include <bits/stdc++.h>
using namespace std;

unsigned long int binomialCoeff(unsigned int n,unsigned int k)
{
	unsigned long int res = 1;
	if (k > n - k)
		k = n - k;
	for (int i = 0; i < k; ++i) {
		res *= (n - i);
		res /= (i + 1);
	}
	return res;
}
unsigned long int catalan(unsigned int n)
{
	// Calculate value of 2nCn
	unsigned long int c = binomialCoeff(2 * n, n);

	// return 2nCn/(n+1)
	return c / (n + 1);
}

int main()
{
	unsigned int N;
    cout << "Enter the Nth Catalan Number Required : ";
    cin >> N;
    cout << "Nth CATALAN NUMBER : " << catalan(N);
}
