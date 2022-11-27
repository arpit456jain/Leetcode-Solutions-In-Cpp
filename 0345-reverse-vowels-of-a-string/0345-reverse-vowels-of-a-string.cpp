class Solution {
public:
    bool isVowel(char v)
    {
        if(v == 'a' or v == 'e' or v == 'i' or v=='o' or v=='u')
            return true;
        else if(v == 'A' or v == 'E' or v == 'I' or v=='O' or v=='U')
            return true;
        else
            return false;
    }
    string reverseVowels(string s1) {
        stack<int> s;
        string vowel = "";
        for(int i=0;i<s1.size();i++)
        {
            
            if(isVowel(s1[i]))
            {
               // cout<<i;
                s.push(i);
                vowel += s1[i];
            }
        }
        
        int cur = 0;
        while(!s.empty())
        {
            int top = s.top();
            s1[top] = vowel[cur++];
            s.pop();
        }
        return s1;
    }
};