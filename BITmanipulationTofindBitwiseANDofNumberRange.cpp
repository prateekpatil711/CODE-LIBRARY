#include <bits/stdc++.h>
using namespace std;


int rangeBitwiseAnd(int m, int n) {
    int a = 0;
    while(m != n) {
        m >>= 1;
        n >>= 1;
        a++;
    }
    return m<<a; 
}

int main(){
    int x , y ;
    cin >> x >> y;
    cout << rangeBitwiseAnd(x , y);
}