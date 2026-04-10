class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int close = INT_MAX;
        int gap= INT_MAX;

        for(int i=0;i<nums.size();i++){

            if(i>0 && nums[i]==nums[i-1]) continue;

            int l=i+1;
            int r=nums.size()-1;

            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(target==sum){
                    return sum;
                    
                } 

                
                else if(sum<target){
                    l++;
                }else{
                    r--;
                }
                if(abs(target-sum)<gap){
                    gap=abs(target-sum);
                    close=sum;
                }
            }
        }
        return close;
    }
};