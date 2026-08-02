class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;

        for(int i = 0; i < n-1 ; i++) {
            int sum=nums[i]+nums[i+1];
            if (mp.find(sum) != mp.end()){
                return true;
            }
            mp[sum]++;
        }
        return false;
    }
};
