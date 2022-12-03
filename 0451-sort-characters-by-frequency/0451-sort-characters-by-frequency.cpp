class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        for(auto i : s)
        {
            m[i]++;
        }
        
        string ans = "";
        vector<pair<int,char>> v;
        for(auto i : m)
        {
            v.push_back({i.second,i.first});
        }
        
        sort(v.begin(),v.end());
        
        for(auto i : v)
        {
            int n = i.first;
            char cur = i.second;
            
            for(int k=0;k<n;k++)
                ans+=cur;
        }
       
        reverse(ans.begin(),ans.end());
        return ans;
    }
};