//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int dijakstra(int V,vector<pair<int,int>> adj[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push(make_pair(0,0));
        vector<int> cost(V,INT_MAX);
        vector<int> vis(V,0);
        int ans=0;
        while(!pq.empty())
        {
            pair<int,int> cur = pq.top();
            pq.pop();
            int curcost = cur.first;
            int curnode = cur.second;
            
            
            
            // now mark the node visited
            vis[curnode]=1;
            cost[curnode]=curcost;
            
            // process the childs
            for(auto i : adj[curnode])
            {
                int node = i.first;
                int newcost = curcost + i.second;
                
                if(node == V-1)
                {
                    if(newcost==cost[node])
                    {
                        ans++;
                    }
                    else if(cost[node]>newcost)
                    {
                        ans=1;
                        cost[node]=newcost;
                    }
                }
                else
                {
                    if(cost[node]>=newcost)
                    {
                        cost[node]=newcost;
                        pq.push({newcost,node});
                    }
                }
                
                
            }
            
        }
        
        return ans;
}
    void makeADJ(vector<vector<int>>& roads, vector<pair<int, int> > adj[])
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
        // code here
        vector<pair<int, int> > adj[n+1];
        makeADJ(roads,adj);
          
        int ans = dijakstra(n,adj);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends