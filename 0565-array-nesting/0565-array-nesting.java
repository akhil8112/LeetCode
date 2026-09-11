class Solution {
    int ans=0;

    public void help(Set<Integer> s, int[] nums,int i,int j,int[] dp){
        if(s.contains(nums[i])){
            for (int x : s) { 
                dp[x] = s.size();
            }
            ans=Math.max(ans,s.size());
            return;
        }
        if(dp[nums[i]] != -1) {
            ans=Math.max(ans,s.size()+dp[nums[i]]);
            dp[j] = s.size() + dp[nums[i]];
            return;
        }
        s.add(nums[i]);
        help(s,nums,nums[i],j,dp);
    }
    public int arrayNesting(int[] nums) {

        int[] dp= new int[nums.length];
        Arrays.fill(dp,-1);
        Set<Integer> s= new HashSet<>();
        for(int i=0;i<nums.length;i++){
            if (dp[i] != -1) { 
                continue; 
            }
            help(s,nums,i,i,dp);
            s.clear();
        }
        return ans;
    }
}