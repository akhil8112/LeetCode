class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(auto &a:nums){
            auto lower=lower_bound(ans.begin(),ans.end(),a);
            if(lower==ans.end()){
                ans.push_back(a);
            }
            else{
                *lower=a;
            }
        }
        return ans.size();
    }
};