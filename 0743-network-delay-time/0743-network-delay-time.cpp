class Solution {
public:
     void makeADJ(vector<vector<int>>& roads, vector<pair<int, int> > adj[])
    {
        
        for(auto i : roads)
        {
            int u = i[0];
            int v = i[1];
            int wt = i[2];
             adj[u].push_back(make_pair(v, wt));
            
        }
        
        return;
    }
    vector<int> dijakstra(int V,vector<pair<int,int>> adj[],int k,vector<int> &vis)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push(make_pair(0,k));
        vector<int> cost(V,0);
        
        while(!pq.empty())
        {
            pair<int,int> cur = pq.top();
            pq.pop();
            int curcost = cur.first;
            int curnode = cur.second;
            
            if(vis[curnode]==1)
                continue;
            
            // now mark the node visited
            vis[curnode]=1;
            cost[curnode]=curcost;
            
            // process the childs
            for(auto i : adj[curnode])
            {
                int node = i.first;
                int cost = i.second;
                
                if(vis[node]==1)
                    continue;
                
                pq.push({curcost+cost,node});
            }
            
        }
        
        return cost;
}
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int> > adj[n+1];
        makeADJ(times,adj);
        vector<int> vis(n+1,0);
        vector<int> ans = dijakstra(n+1,adj,k,vis);
        
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
                return -1;
        }
        
        int maxv=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            maxv = max(maxv,ans[i]);
        }
        
        return maxv;
        
    }
};