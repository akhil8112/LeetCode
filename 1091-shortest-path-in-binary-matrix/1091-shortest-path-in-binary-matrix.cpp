class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1) return -1;
        vector<vector<int>>ans(n,vector<int>(n,1e9));
        
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,0}});
        ans[0][0]=0;
        int dr[]={-1,0,1,0,1,-1,1,-1};
        int dc[]={0,1,0,-1,1,-1,-1,1};

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int dist=it.first;
            int row=it.second.first;
            int col=it.second.second;

            for(int i=0;i<8;i++){
                int newr=row+dr[i];
                int newc=col+dc[i];

                if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==0 && dist+1<ans[newr][newc]){
                    ans[newr][newc]=dist+1;
                    q.push({dist+1,{newr,newc}});
                }
            }
        }
        if(ans[n-1][n-1]==1e9) return -1;
        return ans[n-1][n-1]+1;
    }
};