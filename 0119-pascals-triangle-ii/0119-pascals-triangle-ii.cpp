class Solution {
public:
    vector<int> getRow(int rowIndex) {

        if(rowIndex==0) return {1};
        if(rowIndex==1) return {1,1};
         vector<vector<int>>nums(rowIndex+1);

    
        nums[0].push_back(1);
        nums[1].push_back(1);
        nums[1].push_back(1);
        for(int i=2;i<=rowIndex;i++){
           
            nums[i].push_back(1);
            for(int j=0;j<i-1;j++){
                nums[i].push_back(nums[i-1][j]+nums[i-1][j+1]);
            }
            nums[i].push_back(1);


        }
        return nums[rowIndex];
    }
};