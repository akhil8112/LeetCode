class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                mp[nums[i]]++;
            }
        }
        int it=0;
        int fre=0;
        if(mp.empty()) return -1;
        for(auto i : mp){
            if(i.second>fre){
                it=i.first;
                fre=i.second;
            }
            else if(i.second==fre && i.first<it){
                it=i.first;
                fre=i.second;

            }
        }
        return it;
        
    }
};