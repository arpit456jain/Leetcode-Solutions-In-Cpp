class Solution {
public:
    bool isPowerOfFour(int n) {
      if(n<1)
            return false;
        return checkfor(n);
    }
    
    bool checkfor(int n)
    {
        
        if(n ==1)
            return true;
        if(n % 4 == 0)
            return checkfor(n/4);
        else
            return false;             
        
    }
};