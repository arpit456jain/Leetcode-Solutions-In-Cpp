class Solution {
public:
    	void DFS1(int cur,vector<int> adj[],vector<int> &vis,stack<int> &s)
	{
	    vis[cur] = 1;
	    
	    for(auto i : adj[cur])
	    {
	        if(vis[i] == -1)
	        DFS1(i,adj,vis,s);
	    }
	    
	    s.push(cur);
	}
	void DFS2(int cur,vector<int> adj[],vector<int> &vis,vector<int> tmp)
{
    tmp.push_back(cur);
    vis[cur] = 1;
    
    for(auto i : adj[cur])
    {
        if(vis[i] == -1)
        DFS2(i,adj,vis,tmp);
    }
    
}
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int> s;
        vector<int> vis(V,-1);
        
        //first DF! to populate stack
        for(int i=0;i<V;i++)
        {
            if(vis[i] == -1)
            {
                DFS1(i,adj,vis,s);
            }
        }
        
        // reverse the graph
        vector<int> adj2[V];
        for(int i=0;i<V;i++)
        {
            vector<int> tmp =adj[i];
            for(auto j : tmp)
            {
                adj2[j].push_back(i);
            }
        }
        
        vector<int> vis2(V,-1);
        vector<vector<int>> ans;
        
        while(!s.empty())
        {
            
            int cur = s.top();
            // cout<<cur<<"\n";
            s.pop();
            vector<int> tmp;
            if(vis2[cur]== -1)
           {
                DFS2(cur,adj2,vis2,tmp);
                
            ans.push_back(tmp);
           }
            // cout<<"\n";
        }



// cout<<"\n";
return ans.size();
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> adj2[V];
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j] == 1)
                {
                    adj2[i].push_back(j);
                    adj2[j].push_back(i);
                }
            }
        }
        return kosaraju(V,adj2);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        return numProvinces(isConnected,isConnected.size());
    }
};