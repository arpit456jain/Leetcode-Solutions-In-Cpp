class Solution {
public:
    int numDecodings(string s) {
       map<int,char> m;
       m[1] = 'A', m[2] = 'B' , m[3]='C',m[4]='D',m[5]='E',m[6]='F';
       m[7] = 'G', m[8] = 'H' , m[9]='I',m[10]='J',m[11]='K',m[12]='L';
       m[13] = 'M', m[14] = 'N' , m[15]='O',m[16]='P',m[17]='Q',m[18]='R';
       m[19] = 'S', m[20] = 'T' , m[21]='U',m[22]='V',m[23]='W',m[24]='X';
       m[25] = 'Y', m[26] = 'Z' ;
        
        
        int n = s.size();
        vector<int> v(n+1,-1);
        return getans(s,0,n,m,v);
    }
    
    int getans(string s ,int start , int end,map<int,char> &m,vector<int> &v)
    {
      
        if(start>=end)
            return 1;
        
        if(s[start] == '0')
            return 0;
        if(v[start] != -1)
            return v[start];
        int ans = 0;
        if(s[start] == '1' or s[start] == '2')
        {
            if(start+1<end)
            {
                string cur = "";
                cur += s[start];
                cur += s[start+1];
                int curi = stoi(cur);
                if(m.find(curi) != m.end())
                {
                    v[start] = getans(s,start+2,end,m,v) + getans(s,start+1,end,m,v);
                    return v[start];
                }
            }
        }
        
        v[start] = getans(s,start+1,end,m,v);
        return v[start];
    }
};