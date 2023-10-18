class Solution {
public:
    vector<vector<int>> adj;
    vector<int> indeg;

    int calcMinTime(int n, vector<int> &time){
        vector<int> waitTime(n+1);
        queue<int> q;
        int mxWait = 0;

        for(int i=1; i<=n; i++){
            if(indeg[i] == 0){
                q.push(i);
                waitTime[i] = time[i-1];
                mxWait = max(mxWait, waitTime[i]);
            }
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto child : adj[curr]){
                indeg[child]--;
                waitTime[child] = max(time[child-1] + waitTime[curr], waitTime[child]);
                mxWait = max(mxWait, waitTime[child]);

                if(indeg[child] == 0){
                    q.push(child);
                }
            }
        }
        return mxWait;
    }

    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        adj.resize(n+1);
        indeg.resize(n+1);

        for(int i=0; i<relations.size(); i++){
            auto curr = relations[i];
            adj[curr[0]].push_back(curr[1]);
            indeg[curr[1]]++;
        }
        return calcMinTime(n, time);
    }
};
