class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int even=0;
        int odd=0;
        vector<int>ans;

        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]%2==0){
                ans.insert(ans.begin(),odd);
                even++;
            }else{
                ans.insert(ans.begin(),even);
                odd++;
            }
        }

        return ans;
    }
};