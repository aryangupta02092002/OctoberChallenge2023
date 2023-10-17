class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> inDeg(n, 0);

        for(int i=0; i<n; i++){
            if(leftChild[i] != -1){
                inDeg[leftChild[i]]++;
                if(inDeg[leftChild[i]] > 1){
                    return false;
                }
            }
            if(rightChild[i] != -1){
                inDeg[rightChild[i]]++;
                if(inDeg[rightChild[i]] > 1){
                    return false;
                }
            }
        }

        int rootCnt = 0, rootCand = -1;
        for(int i=0; i<n; i++){
            if(inDeg[i] == 0){
                rootCnt++;
                if(rootCnt > 1){
                    return false;
                }
                rootCand = i;
            }
        }

        if(rootCnt == 0){
            return false;
        }
        if(rootCnt == 1){
            return isConnected(n, leftChild, rightChild, rootCand);
        }
        return false;
    }

    bool isConnected(int n, vector<int> &leftChild, vector<int> &rightChild, int root){
        vector<bool> vis(n, 0);
        stack<int> dfs;
        dfs.push(root);

        while(!dfs.empty()){
            int node = dfs.top();
            dfs.pop();

            if(vis[node]){
                return false;
            }
            vis[node] = true;

            if(leftChild[node] != -1){
                dfs.push(leftChild[node]);
            }
            if(rightChild[node] != -1){
                dfs.push(rightChild[node]);
            }
        }
        for(int i=0; i<n; i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};
