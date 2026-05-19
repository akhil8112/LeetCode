class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int>mp;

        for(auto i : grid){
            mp[i]++;
        }
        int c=0;
        for(int i=0;i<grid.size();i++){
            vector<int>a;
            for(int j=0;j<grid.size();j++){
                a.push_back(grid[j][i]);
            }
            if(mp.find(a)!=mp.end()){
                c+=mp[a];
            }
        }
        return c;
    }
};