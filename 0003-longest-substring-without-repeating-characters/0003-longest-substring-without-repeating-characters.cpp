class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>fre(255,0);
        int x=0;
        int ans=0;

        for(int i=0;i<s.size();i++){
            fre[s[i]]++;

            while(fre[s[i]]>1){
                fre[s[x]]--;
                x++;
            }
            ans=max(ans,i-x+1);
        }
        return ans;
    }
};