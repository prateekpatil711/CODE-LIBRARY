#include <iostream>
using namespace std;

int main() {
    int n,length;
    string data;
    cin >> n;
    while(n--){
        cin >> length;
        cin >> data;
        int zeros = 0 , ones = 0 ;
        for (int i = 0 ; i<length ;i++){
            switch(data[i]){
                case '0' : zeros++;
                            break;
                case '1' : ones++;
                            break;
            }
        }
        int x = zeros%2;
        int y = ones % 2;
        if(zeros == ones){
            cout << "YES" << endl;
        }
        else if (x == 1 && y == 1){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
	// your code goes here
	return 0;
}




/*

A (1-indexed) binary string S of length N is called a xor palindrome if the value of Si⊕S(N+1−i) is the same for all 1≤i≤N.

For example, 0, 1111 and 0101 are xor palindromes, while 1110 and 110101 are not.

You are given a binary string S of length N. Determine if it is possible to rearrange it to form a xor palindrome or not.

Input Format
The first line of input contains a single integer T — the number of test cases. The description of T test cases follows.
The first line of each test case contains an integer N — the length of the binary string S.
The second line of each test case contains the binary string S containing 0s and 1s only.
Output Format
For each test case, output YES if it is possible to rearrange S to convert it into a xor palindrome. Otherwise output NO.

You may print each character of YES and NO in uppercase or lowercase (for example, yes, yEs, Yes will be considered identical).

Constraints
1≤T≤1000
1≤N≤105
S is a binary string, i.e, contains only the characters 0 and 1
It is guaranteed that the sum of N over all test cases does not exceed 2⋅105.
Subtasks
Subtask #1 (100 points): Original constraints

Sample Input 1 
4
2
00
4
0011
3
001
4
0001
Sample Output 1 
YES
YES
YES
NO
Explanation
Test case 1: 00 is already a xor palindrome. [The value of Si⊕S(N+1−i) is 0 for all 1≤i≤N.]

Test case 2: 0011 is already a xor palindrome. [The value of Si⊕S(N+1−i) is 1 for all 1≤i≤N.]

Test case 3: 001 can be rearranged to form 010 which is a xor palindrome. [The value of Si⊕S(N+1−i) is 0 for all 1≤i≤N.]

Test case 4: It can be proved that 0001 can not be rearranged to form a xor palindrome.

*/