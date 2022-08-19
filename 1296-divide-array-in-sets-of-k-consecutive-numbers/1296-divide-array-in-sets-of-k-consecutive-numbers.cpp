class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
         map<int,int> m1;
        
        for(auto i : nums)
        {
            m1[i]+=1;
            
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int cur = nums[i];
            if(m1[cur] == 0)
                continue;
            cout<<cur<<"\n";
            int l = k;
            while(l>0)
            {
                cout<<cur<<" ";
                if(m1[cur]==0)
                {
                    return false;
                }
                m1[cur]--;
                cur++;
                l--;
            }
            cout<<endl;
        }
        return true;
        
    }
};