#include <bits/stdc++.h>
using namespace std;
 
int swapBits(unsigned int x, unsigned int p1, unsigned int p2, unsigned int n)
{
    /* xor contains xor of two sets */
    unsigned int xor = ((x >> p1) ^ (x >> p2)) & ((1U << n) - 1);
 
    /* To swap two sets, we need to again XOR the xor with original sets */
    return x ^ ( (xor << p1) | (xor << p2));
}

int main()
{
    int res = swapBits(28, 0, 3, 2);
    cout << "Result = " << res;
    return 0;
}
 




/*


Example 1 

Input:
x = 47 (00101111)
p1 = 1 (Start from the second bit from the right side)
p2 = 5 (Start from the 6th bit from the right side)
n = 3 (No of bits to be swapped)
Output:
227 (11100011)
The 3 bits starting from the second bit (from the right side) are 
swapped with 3 bits starting from 6th position (from the right side)
Example 2 

Input:
x = 28 (11100)
p1 = 0 (Start from first bit from right side)
p2 = 3 (Start from 4th bit from right side)
n = 2 (No of bits to be swapped)
Output:
7 (00111)
The 2 bits starting from 0th position (from right side) are
swapped with 2 bits starting from 4th position (from right side)

*/