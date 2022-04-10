#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
  

	int t,ones=0,zeros=0,length;
	string binary;
	cin >> t;
	while(t--){
	    cin >> length;
	    cin >> binary;
	    bool ex1 = true,ex2 = true ;
	    ones=0;
	    zeros=0;
	    for(int i = 0 ; i<length ;i++){
	        if(binary[i] == '0'){
	            zeros++;
	        }
	        else{
	            ones++;
	        }

	    }
	    if(length%2 == 1){
	        length--;
	    }
	    for(int i = 0 ; i<length-1 ; i+=2){
	        if(binary[i] == '0' && binary[i+1] == '1'){
            
            }
            else{
                ex1 = false;
            }
            
            if(binary[i] == '1' && binary[i+1] == '0'){
                
            }
            else{
                ex2 = false;
            }

	    }
	    
	    if(ex1){
	        cout << length/2 << endl;
	    }
	    else if(ex2 && binary[length] == '1'){
	            cout << length/2 << endl;
	    }
	    else if(ones == zeros){
	        cout << ones-1 << endl;
	    }
	    else if(ones > zeros){
	        cout << zeros << endl;
	    }
	    else if(ones < zeros){
	        cout << ones << endl;
	    }
	    
	}
	return 0;
}


/*

Sample Input 1 
3
5
00100
5
01010
5
10001


Sample Output 1 
1
2
2

You are given a binary string S of length N (i.e. every character of S is either 0 or 1).

You can perform the following operation on S:

select any two indices i,j of the same parity, i.e. either both i,j are odd or both i,j are even
swap Si and Sj
For example, in the string 1110, we can swap the second and the fourth characters to get 1011. However, we can never obtain 1101 from 1110 by performing such swaps.

Find the maximum possible number of occurrences of the string 01 as a substring of S after performing the above operation any number of times (it is also allowed to not perform any operation).

For example, the string 1110 has no occurrence of the string 01 as a substring, whereas we can swap the second and fourth characters to obtain 1011 which has exactly one occurrence of 01 (colored red).


Input Format

The first line of input contains an integer T, denoting the number of testcases. The description of the T testcases follow.
Each testcase consists of two lines.
The first line contains a single integer N, the length of the string S.
The second line contains a binary string of length N.

Output Format
For each testcase, print in a single line, an integer — the answer as per the problem statement.

Constraints
1≤T≤4000
1≤|S|≤105
The sum of |S| over all testcases doesn't exceed 105

*/