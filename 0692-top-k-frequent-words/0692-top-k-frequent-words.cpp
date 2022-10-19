class Solution {
public:
    bool static cmp(pair<string,int> p1,pair<string,int> p2)
    {
        if(p1.second > p2.second)
            return true;
        else if(p1.second < p2.second)
            return false;
        else
        {
            if(p1.first < p2.first)
                return true;
            else
                return false;
        }
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m;
        
        for(auto i : words)
            m[i]++;
        
        vector<pair<string,int>> v;
        for(auto i : m)
        {
            
            v.push_back({i.first,i.second});
        }
        
        sort(v.begin(),v.end(),cmp);
        
        for(auto i : v)
            cout<<i.first<<" "<<i.second<<"\n"; 
        
        vector<string> ans;
        int i=0;
        while(k>0)
        {
            ans.push_back(v[i++].first);
            k--;
        }
        
        
        return ans;
    }
};