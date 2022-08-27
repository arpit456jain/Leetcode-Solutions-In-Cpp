class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // this question is similar to next greater element 
        // we have to deal with the index of next greater element
        vector<int> ans; 
        stack<pair<int,int>> s;
        int n =  temperatures.size();
        for(int i=n-1;i>=0;i--)
        {
            int cur = temperatures[i];
            
            while(!s.empty() and s.top().first<=cur)
                s.pop();
            
            if(s.empty())
                ans.push_back(0);
            else
            {
                int t = s.top().second;
                ans.push_back(t-i);
            }
            
            s.push({cur,i});
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
};