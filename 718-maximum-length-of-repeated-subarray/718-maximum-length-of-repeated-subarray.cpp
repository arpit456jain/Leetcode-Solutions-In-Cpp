class Solution {
public:
    int findLength(vector<int>& s1, vector<int>& s2) {
        int m = s1.size();
        int n = s2.size();

        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = 0;
            }
        }
        
        int mx=0;
        for(auto i : dp)
        {
            for(auto j : i)
                mx = max(mx,j);
        }
        return mx;
    }
};