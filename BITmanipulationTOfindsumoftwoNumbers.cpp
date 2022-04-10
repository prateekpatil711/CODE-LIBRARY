#include <bits/stdc++.h>
using namespace std;

int getSum(int a, int b) {
    return b==0? a:getSum(a^b, (a&b)<<1); 
}

int main(){
    int  a,b;
    cin >> a >> b;
    cout << getSum(a,b);
}