class Solution {
public:
    vector<int> findOriginalArray(vector<int>& ch) {
        int n = ch.size();
        if(n%2==1)
            return {};
        
        map<int,int> m;
        for(auto i : ch)
            m[i]++;
        
        vector<int> ans;
        sort(ch.begin(),ch.end());
        
        for(auto i : ch)
        {
            if(m.find(i) != m.end() and m[i] == 0)
                continue;
            
            if(m.find(2*i) != m.end() and m[2*i] == 0)
                return {};
            
            
            ans.push_back(i);
            m[i]--;
            m[2*i]--;
                
        }
        if(ans.size() == n/2)
            return ans;
        else
            return {};
        
    }
};