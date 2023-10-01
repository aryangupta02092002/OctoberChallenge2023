//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > mat, int n, int m) 
    {
        // code here
        vector<int> ans;
        int row = 0, col = 0;
        
        if(n == 1){
            while(col < m){
                ans.push_back(mat[row][col++]);
            }
        }
        else if(m == 1){
            while(row < n){
                ans.push_back(mat[row++][col]);
            }
        }
        else{
            while(col < m-1){
                ans.push_back(mat[row][col++]);
            }
            while(row < n-1){
                ans.push_back(mat[row++][col]);
            }
            
            col = m-1;
            while(col > 0){
                ans.push_back(mat[row][col--]);
            }
            
            row = n-1;
            while(row > 0){
                ans.push_back(mat[row--][col]);
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
