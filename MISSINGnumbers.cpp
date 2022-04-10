#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	long long int n,a[4],b[8];
	cin >> n;
	while(n--){
	    cin >> a[0] >> a[1] >> a[2] >> a[3];
	    sort(a,a+4);
        b[0] = (a[0]+a[2])/2;
        b[1] = a[2]-b[0];
        b[2] = (a[0]+a[3])/2;
        b[3] = a[3]-b[2];
        b[4] = (a[1]+a[2])/2;
        b[5] = a[2]-b[4];

        if(b[1]!=0 && b[0]-b[1]==a[0] && b[0]/b[1]==a[1] && b[0]+b[1]==a[2] && b[0]*b[1]==a[3]){
            if(b[0]>=1 && b[1]>=1 && b[0]<=10000 && b[1]<=10000) {
                cout << b[0] <<" " <<b[1]<<endl;
            }
            else{
                cout << "-1 -1" << endl;
            }
        }
        else if(b[3]!=0 && b[2]-b[3]==a[0] && b[2]/b[3]==a[1] && b[2]+b[3]==a[3] && b[2]*b[3]==a[2]){
            if(b[2]>=1 && b[3]>=1 && b[2]<=10000 && b[3]<=10000){
                cout << b[2] <<" " <<b[3]<<endl;
            }
            else{
                cout << "-1 -1" << endl;
            }
        }
        else if(b[5]!=0 && b[4]-b[5]==a[1] && b[4]/b[5]==a[0] && b[4]+b[5]==a[2] && b[4]*b[5]==a[3]){
            if(b[4]>=1 && b[5]>=1 && b[4]<=10000 && b[5]<=10000){
                cout << b[4] <<" " <<b[5]<<endl;
            }
            else{
                cout << "-1 -1" << endl;
            }
        }
        else{
            cout << "-1 -1" << endl;
        }
        
	}
	return 0;
}




/*

Alice (uniformly and independently) randomly picks two integers a,b from the range [1,104], and writes down the values of a+b, a−b, a⋅b and ⌊ab⌋ (integer division) in some random order. Unfortunately, she forgot the values of a and b. You need to help her to find out if there exists two integers a,b such that 1≤a,b≤104 and a+b, a−b, a⋅b, ⌊ab⌋ are the numbers she has written down.

If a solution exists, it is guaranteed to be unique.

Input Format
The first line of input contains a single integer T, denoting the number of testcases. The description of T testcases follows.
Each testcase consists of a single line of input, containing four space-separated integers A,B,C,D — the values written down by Alice. It is guaranteed that at most one of the four numbers A,B,C,D will be negative.

Output Format
For each testcase, output in a single line, separated by a space, the two numbers Alice has chosen in order (i.e, if the solution is a=1 and b=2, print 1 2 and not 2 1). If there does not exist any such choice of integers, print −1 twice, separated by a space, instead.

Constraints
1≤T≤105
−109≤A,B,C,D≤109
At most one of A,B,C,D is negative.


Sample Input 1 
2
-1 72 0 17
1 4 5 6

Sample Output 1 
8 9
-1 -1

*/