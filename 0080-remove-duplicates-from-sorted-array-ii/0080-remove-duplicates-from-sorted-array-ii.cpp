class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=1;
        int c=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]==nums[i]){
                c++;
            }else{
                c=0;
            }
            if(c<2){
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }
};