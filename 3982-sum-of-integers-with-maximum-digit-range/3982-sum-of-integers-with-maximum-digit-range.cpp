class Solution {
public:
    int maxDigitRange(vector<int>& nums) {

        vector<int>a(nums.size(),-1);
        int s=0,r=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int x=nums[i],ma=INT_MIN, mi=INT_MAX;
            while(x!=0){
                ma=max(ma,x%10);
                mi=min(mi,x%10);
                x/=10;
            }
            r=max(r,ma-mi);
            a[i]=ma-mi; 
        }
        for(int i=0;i<nums.size();i++) if(a[i]==r) s+=nums[i];
        return s;
    }
};