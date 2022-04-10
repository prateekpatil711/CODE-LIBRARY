#include <bits/stdc++.h>
using namespace std;
//Find the largest power of 2 (most significant bit in binary form), which is less than or equal to the given number N.

long largest_power_Value(long N) {
    N = N | (N>>1);
    N = N | (N>>2);
    N = N | (N>>4);
    N = N | (N>>8);
    N = N | (N>>16);
    return (N+1)>>1;
}

int main(){
    long  N;
    cin >> N;
    cout << largest_power_Value(N);
}