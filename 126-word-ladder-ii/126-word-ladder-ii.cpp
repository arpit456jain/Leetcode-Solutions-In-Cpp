class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> m;
        for(auto i : wordList)
        {
            m.insert(i);
        }
        
        
        unordered_map<string,vector<string>> adj;
        unordered_map<string,int> vis;
        
        queue<string> q;
        q.push(beginWord);
        vis[beginWord] = 0;
      
        
        while(!q.empty())
        {
    
            int size = q.size();
          
            for(int i=0;i<size;i++)
            {
                string temp = q.front();
                string cur = temp;
                q.pop();
                for(int i=0;i<temp.size();i++)
                {
                    char tmp = temp[i];
                    for(char k = 'a';k<='z';k++)
                    {
                        if(k == tmp)
                            continue; // if same char appears
                        temp[i] = k;
                        if(m.find(temp) != m.end())
                        {
                          if(vis.find(temp) == vis.end()) // it means its noy present in vis
                          {
                                q.push(temp);
                                vis[temp] = vis[cur] + 1;
                                adj[temp].push_back(cur);   
                          }
                        else if(vis[temp] == vis[cur] + 1)
                            {
                                 adj[temp].push_back(cur);  
                            }
                        }
                        
                    }
                    
                    temp[i] = tmp; // backtrack
                }
            }
                
        }
        
        
        vector<vector<string>> ans;
        vector<string> t;
        DFS(endWord,beginWord,adj,ans,t);
        return ans;
    }
    
    void DFS(string beg,string end,unordered_map<string,vector<string>> &adj,vector<vector<string>> &ans,vector<string> &t)
    {
        if(beg == end)
        {
            t.push_back(end);
            reverse(t.begin(),t.end());
            ans.push_back(t);
            reverse(t.begin(),t.end());
            t.pop_back();
            return;
        }
        
        t.push_back(beg);
        for(auto i : adj[beg])
        {
            DFS(i,end,adj,ans,t);
        }
        t.pop_back();
    }
};