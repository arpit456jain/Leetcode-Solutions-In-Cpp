class Solution {
public:
    bool validate(int a,int b,int c)
    {
        if(a+b<=c or b+c<=a or a+c<=b)
            return false;
        return true;
            
    }
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        int maxp = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                
                for(int k=j+1;k<n;k++)
                {
                    if(nums[k] + nums[j] > nums[i])
                        return nums[k] + nums[j] + nums[i];
                    else
                        break;
                }
            }
        }
        
        return 0 ;
    }
};