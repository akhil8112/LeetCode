class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s="";
        int n=word1.size(),m=word2.size();
        int i;
        for(i=0;i<min(n,m);i++){
            s+=word1[i];
            s+=word2[i];
        }
        if(n<m){
            for(int j=i;j<m;j++){
                s+=word2[j];
            }
        }else{
           for(int j=i;j<n;j++){
                s+=word1[j];
            } 
        }
        return s;

    }
};