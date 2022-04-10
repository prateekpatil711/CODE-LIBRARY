#include <bits/stdc++.h>
using namespace std;

// LARGEST SUB RECTANGULAR ARRAY SUM

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,*arr,arr_end,arr_begin,arr_begin_temp;
    long long max,tmax;
    cin >> n;
    arr = new int[n];
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    max = INT_MIN ;
    tmax = 0;
    for(int i = 0 ; i < n ; i++){
        tmax = tmax + arr[i];
        if(tmax<0) {
            tmax = 0;
        }
        else if(max<tmax){
            max=tmax;
            arr_end = i;
        }
    }
    cout << max ;
}

