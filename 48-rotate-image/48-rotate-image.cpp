class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // a[i][j] = temp[j][n-i-1]
        int n = matrix.size();
        vector<vector<int>> deepcopy(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                deepcopy[i][j] = matrix[i][j];
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                matrix[i][j] = deepcopy[n-j-1][i];
            }
        }
        
    }
};