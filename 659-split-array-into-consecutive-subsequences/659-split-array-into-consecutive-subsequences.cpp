class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> m1,m2;
        
        for(auto i : nums)
        {
            m1[i]+=1;
            
        }
        
        for(int i=0;i<nums.size();i++)
        {
            int cur = nums[i];
            // cout<<cur<<" ";
            if(m1[cur] == 0)
                continue;
              m1[cur]--;           
            // if its present in vacency
            if(m2[cur] > 0)
            {
                m2[cur]--;
              
                m2[cur + 1]++;
            }
            else if(m1[cur+1]>0 and m1[cur+2]>0) // check if other 2 consecutive numbers are there or not
            {
               
                m1[cur+1]--;
                m1[cur+2]--;
                m2[cur+3]++;
            }
            else
                return false;
                
                 
        }
        
        return true;
    }
};