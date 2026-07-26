class Solution {
public:
    void help(vector<vector<int>>&ans,vector<int>&sub, vector<int>&nums, int i){
        if(i==nums.size()){
            ans.push_back(sub);
            return;
        }

        sub.push_back(nums[i]);
        help(ans,sub,nums,i+1);
        sub.pop_back();
        help(ans,sub,nums,i+1);


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>sub;
        help(ans,sub,nums,0);
        return ans;
    }
};