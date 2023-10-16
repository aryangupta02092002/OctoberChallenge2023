//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class disjointSet{
    public:
        vector<int> sizes,parents;
        
        disjointSet(int n){
            sizes.assign(n, 1);
            parents.resize(n);
            for(int i=0; i<n; i++){
                parents[i]=i;
            }
        }
        
        int findParent(int node){
            if(parents[node] == node)
                return parents[node];
            return parents[node] = findParent(parents[node]);
        }
        
        void unionn(int u, int v){
            int paru = findParent(u);
            int parv = findParent(v);
            if(paru == parv)
                return;
            int sizeu = sizes[paru];
            int sizev = sizes[parv];
            if(sizeu < sizev){
                parents[paru] = parv;
                sizes[parv] += sizes[paru];
            }
            else{
                parents[parv] = paru;
                sizes[paru] += sizes[parv];
            }
        }
        
        int getSize(int node){
            int par = findParent(node);
            return sizes[par];
        }
};
class Solution
{
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        // Your code goes here.
        int n = grid.size();
        int x[] = {0, 0, 1, -1};
        int y[] = {1, -1, 0, 0};
        disjointSet dsu(n*n);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    for(int k=0; k<4; k++){
                        int nr = i + x[k];
                        int nc = j + y[k];
                        
                        if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                            dsu.unionn(i*n+j , nr*n+nc);
                        }
                    }
                }
            }
        }
        
        int out = 0;
        bool zero = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    zero = true;
                    int temp = 1;
                    unordered_map<int, bool> vis;
                    
                    for(int k=0; k<4; k++){
                        int nr = i+x[k];
                        int nc = j+y[k];
                        
                        if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                            int node = nr*n+nc;
                            int par = dsu.findParent(node);
                            if(vis[par])
                                continue;
                            vis[par] = true;
                            int s = dsu.getSize(node);
                            temp += s;
                        }
                    }
                    out = max(out, temp);
                }
            }
        }
        
        if(!zero)
            return n*n;
        return out;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends
