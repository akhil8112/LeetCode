class Solution {
public:
    bool backspaceCompare(string s, string t) {
       string a="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='#' ){
                if(a.size()!=0) a.pop_back();
            }else{    
                a=a+s[i];     
            }
        }
         string b="";
        for(int i=0;i<t.size();i++){
            if(t[i]=='#'){
                if(b.size()!=0) b.pop_back();
            }else{
                b=b+t[i];
            }
        }
       

        
        return a==b;

        
    }
};