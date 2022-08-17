class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,int> m;
        for(auto i : wordList)
        {
            if(i == beginWord)
                continue;
            m[i]=1;
        }
        if(m.find(endWord) == m.end())
            return 0;
        
        map<string,vector<string>> adj;
        map<string,int> vis;
        queue<string> q;
        q.push(beginWord);
        vis[beginWord] = 0;
        int level = 0;
        while(!q.empty())
        {
    
            int size = q.size();
            level++;
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
                        temp[i] = k;
                        // cout<<temp<<" ";
                        if(m.find(temp) != m.end())
                        {
                          
                            q.push(temp);
                            vis[temp] = level;
                            adj[cur].push_back(temp);
                            m.erase(temp);
                        }
                    }
                    
                    temp[i] = tmp;
                }
            }
                
        }
        
        if(vis.find(endWord) == vis.end())
            return 0;
        
        return vis[endWord]+1;
    }
};