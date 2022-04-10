#include <bits/stdc++.h>
using namespace std;

//Reverse bits of a given 32 bits unsigned integer.

uint32_t reverseBits(uint32_t n) {
    unsigned int mask = 1<<31, res = 0;
    for(int i = 0; i < 32; ++i) {
        if(n & 1) res |= mask;
        mask >>= 1;
        n >>= 1;
    }
    return res;
}

int main(){
    unsigned int N;
    cin >> N;
    cout << reverseBits(N);
}