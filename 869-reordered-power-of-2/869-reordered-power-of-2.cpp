class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string num = to_string(n);
        sort(num.begin(),num.end());
        if(n==1)
            return true;
       int i = 2;
        while(i<=1000000000)
        {
            string cur = to_string(i);
            
            if(i == n)
                return true;
            
            sort(cur.begin(),cur.end());
            if(cur==num)
                return true;
            
            i=i*2;
        }
        
        return false;
    }
};