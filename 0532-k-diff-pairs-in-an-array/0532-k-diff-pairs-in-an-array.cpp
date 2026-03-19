class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        int c=0;
        unordered_map<int,int>mp;
        for(auto i : nums){
            mp[i]++;
        }
        for(auto i : mp){
            if(k==0){
                if(i.second>1){
                    c++;
                }
            }else if(mp.find(i.first+k)!=mp.end()){
                c++;
            }
        }
        return c;
    }
};