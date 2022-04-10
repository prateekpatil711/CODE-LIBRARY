#include <iostream>
using namespace std;
long long Modulo = 998244353;

int main() {
	// your code goes here
	int t,*arr1,*arr2,n;
	char x;
	cin >> t;
	while(t--){
	    cin >> n >> x;
	    arr1 = new int[n];
	    if(x == '1'){
	        arr1[0] = 1;
	    }
	    else{
	        arr1[0] = 0;
	    }
	    
	    long long prev = arr1[0];
	    for(int i = 1 ; i < n ; i++){
	        cin >> x;
	        if(x == '1'){
	            prev += (i+1);
	        }
	        arr1[i] = prev % 2;
	    }
	    
	    long long product = 1;
	    long long xor_value = 0;
	    for(int i = n - 1 ; i >= 0 ; i--){
	        if(arr1[i]==1){
	            xor_value = (xor_value+product)%Modulo;
	        }
	        product = (product*2)%Modulo;
	    }
        cout << xor_value << endl;
	}
	return 0;
}


/*
Mary loves binary strings.
Given a binary string S, she defines the beauty of the string as the bitwise XOR of decimal representations of all substrings of S.

Find the beauty of string S. Since the answer can be huge, print it modulo 998244353.

For example, the decimal representation of binary string 1101 is 1⋅23+1⋅22+0⋅21+1⋅20=8+4+0+1=13. Kindly refer sample explanation for more such examples.

A string A is a substring of a string B if A can be obtained from B by deleting several (possibly zero) characters from the beginning and several (possibly zero) characters from the end.

Input Format
The first line of input contains a single integer T, denoting the number of test cases. The description of test cases follow.
First line of each test case contains one integer N - the length of the binary string.
Second line of each test case contains the binary string S.
Output Format
For each test case, output in a single line, beauty of the string modulo 998244353.

Constraints
1≤T≤100
1≤N≤105
Sum of N over all test cases does not exceed 2⋅105
Sample Input 1 
3
2
10
3
101
4
1111
Sample Output 1 
3
6
12
Explanation
Test Case 1: All substrings of the string S=10 are [1,0,10]. The decimal representation of these substrings is denoted by the array [1,0,2]. Bitwise XOR of all these values is 1⊕0⊕2=3.

Test Case 2: All substrings of the string S=101 are [1,0,1,10,01,101]. The decimal representation of these substrings is denoted by the array [1,0,1,2,1,5]. Bitwise XOR of all these values is: 1⊕0⊕1⊕2⊕1⊕5=6.

Test Case 3: All substrings of the string S=1111 are [1,1,1,1,11,11,11,111,111,1111]. The decimal representation of these substrings is denoted by the array [1,1,1,1,3,3,3,7,7,15]. Bitwise XOR of all these values is: 1⊕1⊕1⊕1⊕3⊕3⊕3⊕7⊕7⊕15=12.

*/