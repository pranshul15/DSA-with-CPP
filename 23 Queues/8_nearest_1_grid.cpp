/*
Given a binary grid of n*m. 
Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, 
where i1, j1 are the row number and column number of the current cell, 
and i2, j2 are the row number and column number of the nearest cell 
having value 1. There should be atleast one 1 in the grid.*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>> grid)
	{
	    // Code here
	    int n = grid.size();
	    vector<vector<int>> ans ( n, vector<int> ( n, INT_MAX ) );
        queue<pair<int,int>> q;
        for ( int i=0 ; i<n ; i++ ) {
            for ( int j=0 ; j<n ; j++ ) {
                if ( grid[i][j] ) {
                    q.push( {i,j} );
                    ans[i][j] = 0;
                }
            }
        }
        while ( !q.empty() ) {
            pair<int,int> f = q.front();
            q.pop();
            int i = f.first;
            int j = f.second;
            int dist = ans[i][j] + 1;
            if ( (i-1 >= 0) && (grid[i-1][j] == 0) && (ans[i-1][j] > dist)) {
                ans[i-1][j] = dist;
                q.push( {i-1,j} );
            }
            if ( (i+1 < n) && (grid[i+1][j] == 0) && (ans[i+1][j] > dist)) {
                ans[i+1][j] = dist;
                q.push( {i+1,j} );
            }
            if ( (j-1 >= 0) && (grid[i][j-1] == 0) && (ans[i][j-1] > dist)) {
                ans[i][j-1] = dist;
                q.push( {i,j-1} );
            }
            if ( (j+1 < n) && (grid[i][j+1] == 0) && (ans[i][j+1] > dist)) {
                ans[i][j+1] = dist;
                q.push( {i,j+1} );
            }
        }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends