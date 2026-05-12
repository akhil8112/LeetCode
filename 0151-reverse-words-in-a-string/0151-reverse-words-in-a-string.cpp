class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string w;
        string ans="";

        while(ss>>w){
            ans=w+" "+ans;
        }
        ans.pop_back();
        
        return ans;
        

        


    }
};