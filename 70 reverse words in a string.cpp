class Solution {
public:
    string reverseWords(string s) {
        
        int i=s.length();
        string ans= "";
        
        while(i>=0)
        {
            while(i>=0 && s[i]==' ' ) i--;
           int j=i;
            if(i<0) break;
            while(i>=0 && s[i]!=' ') i--;
            
            if(ans.isEmpty())
                    ans=ans.append(s.substr(i+1,j+1));
            else
                   ans=ans.append(' '+ s.substr(i+1, j+1));
        }
        return ans;
    }
};