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
    int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}
    
    int bitwiseComplement(int n) {
        if(n==0 or n==1)
            return 1 - n;
            
       string s = DecimalToBinary(n);
        reverse(s.begin(),s.end());
        string k = "";
        for(auto i : s)
        {
            if(i == '0')
                k+="1";
            else
                k+="0";
        }
        cout<<s<<" "<<k;
        return binaryToDecimal(k);
        // return 0;
    }
};