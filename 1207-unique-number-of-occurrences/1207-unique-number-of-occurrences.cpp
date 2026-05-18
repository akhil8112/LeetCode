class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;

        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }

        vector<int>ans(arr.size()+1,0);

        for(auto i : mp){
            if(ans[i.second]!=0) return false;
            ans[i.second]=1;
        }
        return true;
    }
};