class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1 || n==2 ) return n;
        int minin;
        int maxin;

        int maxv=INT_MIN;
        int minv=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxv){
                maxv=nums[i];
                maxin=i;
            }
            if(nums[i]<minv){
                minv=nums[i];
                minin=i;
            }
        }

        int front=max(maxin,minin)+1;
        int back=n-min(maxin,minin);
        int both=min(maxin+1+n-minin,minin+1+n-maxin);

        return min(both,min(front,back));

    }

};
