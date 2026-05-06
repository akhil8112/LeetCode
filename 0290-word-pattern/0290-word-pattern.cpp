class Solution {
public:
    bool wordPattern(string pattern, string s) {
    
        unordered_map<char,string>mp;
        unordered_map<string,char>mp1;
        stringstream ss(s);
        stringstream ss1(s);
        int a=0;
        string w;
        while(ss1>>w){
            a++;
        }
        string word;
        for(int i=0;i<pattern.size();i++){
            if(ss >> word){
                if(mp.find(pattern[i])!=mp.end() && mp[pattern[i]]!=word || (mp1.find(word)!=mp1.end())&& mp1[word]!=pattern[i]){
                    return false;
                }
                else{
                    mp[pattern[i]]=word;
                    mp1[word]=pattern[i];

                }

            }
        }
        if(a!=pattern.size()) return false;
        return true;
    }
};