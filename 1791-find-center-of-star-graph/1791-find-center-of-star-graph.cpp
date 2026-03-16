class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>indeg(n+2,0);

        for(int i=0;i<edges.size();i++){
            indeg[edges[i][0]]++;
            indeg[edges[i][1]]++;
        }
        for(int i=1;i<=n+1;i++){
            if(indeg[i]==n) return i;
        }
        return -1;
    }
};