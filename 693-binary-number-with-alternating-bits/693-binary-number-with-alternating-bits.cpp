class Solution {
public:
    string DecimalToBinary(int num)
    {
        string str;
          while(num){
          if(num & 1) // 1
            str+='1';
          else // 0
            str+='0';
          num>>=1; // Right Shift by 1 
        }   
          return str;
    }
    bool hasAlternatingBits(int n) {
     string s = DecimalToBinary(n);
        reverse(s.begin(),s.end());
        
        int pos = 0;
        bool flag = true;
        while(pos < s.size())
        {
            if(flag == true and s[pos] != '1')
                return false;
            else if(flag == true and s[pos] == '1')
                flag = false;
            else if(flag == false and s[pos] != '0')
                return false;
            else if(flag == false and s[pos] == '0')
                flag = true;
            
            pos++;
            
        }
        
        return true;
        
    }
};