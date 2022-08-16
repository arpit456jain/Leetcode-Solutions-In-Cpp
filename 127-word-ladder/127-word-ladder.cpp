class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,int> m;
        for(auto i : wordList)
        {
            if(m.find(i) != m.end())
                return 0;
            else
                m[i]=1;
        }
        if(m.find(endWord) == m.end())
            return 0;
        
        // approach
        // 1. push start word in queue
        queue<string> q;
        q.push(beginWord);
        int level = 0;
        while(!q.empty())
        {
            level++;
            int size = q.size();
            // cout<<size<<" ";
            for(int i=0;i<size;i++)
            {
                string temp = q.front();
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
                            if(temp == endWord)
                                return level+1;
                            q.push(temp);
                            m.erase(temp);
                        }
                    }
                    
                    temp[i] = tmp;
                }
            }
                
        }
        
        return 0;
    }
};