class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
                c=max(c,count);
            }else{
               
                    count=0;
            
            }
        }
               
        return c;
    }
};