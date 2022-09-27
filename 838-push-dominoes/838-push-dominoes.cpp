class Solution {
public:
    void print(vector<int> arr)
    {
        for(auto i : arr)
            cout<<i<<" ";
        cout<<"\n";
    }
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        int count = 0;
        char prev = '.';
            
        // for right
        for(int i=0;i<n;i++)
        {
            char cur = dominoes[i];
            count++;
            
            // cout<<cur;
            if(cur != '.')
            {
                // cout<<"cur char is "<<cur<<" and count is "<<count<<"\n";
                count = 0;
            }
                
            if(prev == 'R')
                right[i] = count;
            else
            {
                // cout<<"putting 0 at "<<i<<" because prev is "<<prev<<"\n";
                right[i] = 0;
            }
            if(cur == 'L' or cur == 'R')
            prev = cur;
        }
        
        // print(right);
        
        count = 0;
        prev = '.';
            
        // for left
        for(int i=n-1;i>=0;i--)
        {
            char cur = dominoes[i];
            count++;
            
            // cout<<cur;
            if(cur != '.')
            {
                // cout<<"cur char is "<<cur<<" and count is "<<count<<"\n";
                count = 0;
            }
                
            if(prev == 'L')
                left[i] = count;
            else
            {
                // cout<<"putting 0 at "<<i<<" because prev is "<<prev<<"\n";
                left[i] = 0;
            }
            if(cur == 'L' or cur == 'R')
            prev = cur;
        }
        
        // print(left);
        
        string ans = "";
        
        for(int i=0;i<n;i++)
        {
             
            if(right[i] == left[i])
                ans += dominoes[i];
            else if(right[i] == 0 and left[i] != 0)
                ans+='L';
            else if(right[i] != 0 and left[i] == 0)
                ans+='R';
            else if(right[i]<left[i])
                ans+='R';
            else
                ans+='L';
        }
        
        return ans;
        
    }
};