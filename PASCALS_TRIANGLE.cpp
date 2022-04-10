#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
 vector<vector<int>> triangle(numRows);
        
        for(int i = 0 ; i < numRows ; i++){
            triangle[i].push_back(1);
            for(int j = 1 ; j < i ; j++){
                triangle[i].push_back(triangle[i-1][j-1] + triangle[i-1][j]);
            }
            if(i != 0){
                triangle[i].push_back(1);
            }
        }
        return triangle;
}


int main(){
    int numRows;
    vector<vector<int>> triangle;
    cin >> numRows ;
    triangle = generate(numRows);
    for(int i = 0 ; i < triangle.size() ; i++){
        for(int j = 0 ; j < triangle[i].size() ; j++){
            cout << triangle[i][j] << " "; 
        }
        cout << endl;
    }
    /*for(auto vec: triangle){
	    for(int i:vec){
	        cout<<vec[i]<<" ";
	    }
	    cout<<endl;
	}*/
}