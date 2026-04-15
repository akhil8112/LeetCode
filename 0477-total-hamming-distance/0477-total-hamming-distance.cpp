class Solution {
public:

    int ham(int a, int b){
        int c=a^b;
       

        int bit=__builtin_popcount(c);

        return bit;
    }
    int totalHammingDistance(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                sum+=ham(nums[i],nums[j]);
            }
        }

        return sum;
    }
};