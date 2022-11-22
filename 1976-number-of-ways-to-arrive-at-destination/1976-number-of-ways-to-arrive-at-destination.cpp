#define ll long long
class Solution {
public:
    int mod=1e9 + 7;
     
    int dijakstra(int V,vector<pair<ll,ll>> adj[])
    {
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        
        pq.push(make_pair(0,0));
        vector<ll> cost(V,LONG_MAX);
        vector<ll> ways(V,0);
       
       
        ways[0] = 1;
        while(!pq.empty())
        {
            pair<ll,ll> cur = pq.top();
            pq.pop();
            ll curcost = cur.first;
            ll curnode = cur.second;
            
               
            cost[curnode]=curcost;
            
            // process the childs
            for(auto i : adj[curnode])
            {
                ll node = i.first;
                ll newcost = curcost + i.second;
                
                if(cost[node]>newcost)
                    {
                        cost[node]=newcost;
                        pq.push({newcost,node});
                        ways[node] = ways[curnode];
                    }
                               
                
                else if(cost[node] == newcost)
                {
                    ways[node]=(ways[node]+ ways[curnode])%mod;
                    
                }
                
                
            }
            
        }
        
        return ways[V-1];
}
    void makeADJ(vector<vector<int>>& roads, vector<pair<ll, ll> > adj[])
    {
        
        for(auto i : roads)
        {
            int u = i[0];
            int v = i[1];
            int wt = i[2];
             adj[u].push_back(make_pair(v, wt));
           adj[v].push_back(make_pair(u, wt));
            
        }
        
        return;
    }
    int countPaths(int n, vector<vector<int>>& roads) {
         // we have to make the adj matrix
        
       vector<pair<ll, ll> > adj[n];
        makeADJ(roads,adj);
          
        long long  ans = dijakstra(n,adj);
        
        return ans;
    }
    
   
    
};