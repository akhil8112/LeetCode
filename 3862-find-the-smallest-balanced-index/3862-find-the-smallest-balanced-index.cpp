class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        long long sum=0;
        for(int i : nums){
            sum+=i;
        }
        long long pr=1;
        // sum=sum-nums[nums.size()-1];
        for(int i=nums.size()-1;i>=0;i--){
            if(sum-nums[i]==pr){
                return i;
            }else if(pr>sum-nums[i]){
                return -1;
            }else{
                sum=sum-nums[i];
                pr=pr*nums[i];
            }
        }
        return -1;
        
    }
};