class Solution {
public:
    int removeDuplicates(vector<int>& s) {
        sort(s.begin(),s.end());
        stack<int> s1;
        s1.push(s[0]);
        
        for(int i=1;i<s.size();i++)
        {
            if(s1.empty()==true)
            {
                s1.push(s[i]);
                continue;
            }
            int topval = int(s1.top());
            int curval = int(s[i]);
            if(topval == curval)
                continue;
           
            s1.push(s[i]);
        }
        
        int ans = 0;
       
        vector<int> nv;
        while(!s1.empty())
        {
            char top = s1.top();
            nv.push_back(top);
           ans++;
            s1.pop();
        }
        
        reverse(nv.begin(),nv.end());
        
        for(int i=0;i<nv.size();i++)
            s[i]=nv[i];
        
        return ans;
    }
};