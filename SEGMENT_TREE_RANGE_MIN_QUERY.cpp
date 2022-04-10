#include <bits/stdc++.h>
using namespace std;

int *arr;
 

int minVal(int x, int y) { return (x < y)? x: y; }
int getMid(int s, int e) {  return s + (e-s)/2;  }
int RMQ(int *segTree, int segStart, int segEnd, int queryStart, int queryEnd, int segIndex)
{

    if (queryStart <= segStart && queryEnd >= segEnd)
        return segTree[segIndex];
 

    if (segEnd < queryStart || segStart > queryEnd)
        return INT_MAX;
 

    int mid = getMid(segStart, segEnd);
    return minVal(RMQ(segTree, segStart, mid, queryStart, queryEnd, 2*segIndex+1),
                  RMQ(segTree, mid+1, segEnd, queryStart, queryEnd, 2*segIndex+2));
}
 
int constructST(int *arr, int segStart, int segEnd, int *segTree, int segIndex)
{

    if (segStart == segEnd)
    {
        segTree[segIndex] = arr[segStart];
        return arr[segStart];
    }
 

    int mid = getMid(segStart, segEnd);
    segTree[segIndex] =  minVal(constructST(arr, segStart, mid, segTree, segIndex*2+1),
                     constructST(arr, mid+1, segEnd, segTree, segIndex*2+2));
    return segTree[segIndex];
}

int main()
{
    
    int n ,query ;
    scanf("%d%d",&n,&query);
    arr = (int *) malloc (sizeof(int)*n);
    for(int i = 0 ; i<n;i++){
        scanf("%d",&arr[i]);
    }
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    int *segTree = malloc(sizeof(int)*max_size);
    constructST(arr, 0, n-1, segTree, 0);
    int queryStart ,queryEnd; 

    for(int i = 0 ; i < query ; i++){
        scanf("%d%d",&queryStart,&queryEnd);
        printf("%d\n", RMQ(segTree, 0 , n - 1, queryStart, queryEnd , 0));
    }
    return 0;
}
