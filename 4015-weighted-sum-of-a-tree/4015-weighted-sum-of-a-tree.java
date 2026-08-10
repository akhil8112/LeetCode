class Solution {
  
    public int depth(int[] parent,int val, int[] dep){
        if(parent[val]==-1) return dep[val] = 1;
        if(dep[val]!=0) return dep[val];
        return dep[val] = 1 + depth(parent, parent[val], dep);
    }

    public long weightedSum(int[] parent, int[] nums) {
        int[] dep=new int[nums.length];
        int h=0;
        for(int i=0;i<nums.length;i++){
            depth(parent,i,dep);
            h=Math.max(h,dep[i]);
            
        }
        long ans=0;
        for(int i=0;i<nums.length;i++){
            long dp=dep[i];
            long x=nums[i] * (h-dp+1);
            ans+=x;
        }
        return ans;


    }
}