#include <bits/stdc++.h>
using namespace std;


//function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
int hammingWeight(uint32_t n) {
	int count = 0;
	while(n) {
		n = n&(n-1);
		count++;
	}
	return count;
}



int main(){
    unsigned int N;
    cin >> N;
    cout << hammingWeight(N);
}