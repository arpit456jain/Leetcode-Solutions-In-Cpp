class Solution {
public:
    int sumOfsq(int n)
    {
        int ans=0;
        while(n>0)
        {
            int r=n%10;
            ans+=r*r;
            n=n/10;
        }
        return ans;
    }
    bool isHappy(int n) {
        
        int loop = 100;
        while(loop>0)
        {
            if(n==1)
                return true;
            n = sumOfsq(n);
            loop--;
        }
        
        return false;
    }
};