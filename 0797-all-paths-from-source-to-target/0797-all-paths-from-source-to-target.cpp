class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        // we already have adj matrix
        
        vector<int> temp;
        vector<vector<int>> ans;
        vector<int> vis(n+1,-1);
        findpath(ans,temp,0,vis,n,graph);
        
        return ans;
        
    }
    
    void findpath(vector<vector<int>> &ans,vector<int> &tmp,int cur,vector<int> &vis,int n,vector<vector<int>>& graph)
    {
        if(cur == n-1)
        {
            tmp.push_back(cur);
            ans.push_back(tmp);
            tmp.pop_back();
        }
        
      
        
        vis[cur]=1;
        tmp.push_back(cur);
        for(auto i : graph[cur])
        {
            findpath(ans,tmp,i,vis,n,graph);
        }
        vis[cur] = -1;
        tmp.pop_back();
        return;
    }
    
};