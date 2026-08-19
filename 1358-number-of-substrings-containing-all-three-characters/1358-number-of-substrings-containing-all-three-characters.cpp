class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=0,b=0,c=0;
        int ans=0;
        int l=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a') a++;
            else if(s[i]=='b') b++;
            else if(s[i]=='c') c++;

            
            while(a>0 && b>0 && c>0){
                ans=ans+(s.size()-i);
                if(s[l]=='a') a--;
                else if(s[l]=='b') b--;
                else if(s[l]=='c') c--;

                l++;
            }
        }
        return ans;
    }
};