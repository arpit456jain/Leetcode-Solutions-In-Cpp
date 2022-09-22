class Solution {
public:
    string reverseWords(string s) {
     vector<string> v;
        
        string cur = "";
        for(auto i : s)
        {
            if(i == ' ')
            {
                v.push_back(cur);
                cur = "";
                continue;
            }
            cur+=i;
        }
        v.push_back(cur);
        
        for(auto i : v)
            cout<<i<<" ";
        
        string ans = "";
        for(int i=0;i<v.size();i++)
        {
            
            reverse(v[i].begin(),v[i].end());
            ans+=v[i];
            if(i == v.size()-1)
            continue;
            ans+=" ";
        }
        
        return ans;
    }
};