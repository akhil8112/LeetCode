class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());

        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            vector<int>a=ans[ans.size()-1];
            ans.pop_back();
            int s=a[0];
            int e=a[1];

            int s1=intervals[i][0];
            int e1=intervals[i][1];

            if(s1<=e && e1<=e){
                ans.push_back({s,e});
            }
            else if(s1<=e){
                ans.push_back({s,e1});
            }
            else{
                ans.push_back({s,e});
                ans.push_back({s1,e1});

            }
        }

        return ans;
    }
};