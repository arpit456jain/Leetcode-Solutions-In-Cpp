class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
     
     int xor1 = 0;
        for(auto i : nums)
            xor1=xor1^i;
        
        int cnt=0;
        while(xor1)
        {
            if(xor1&1)
                break;
            else
            {
                cnt++;
                xor1 = xor1>>1;
            }
        }
        int xor2 = 0;
        int xor3 =0 ;
        
        for(auto i :nums)
        {
            if(i&(1<<cnt))
                xor2 = xor2 xor i;
            else
                xor3 =  xor3^i;
        }
            
        return {xor2,xor3};
    }
};