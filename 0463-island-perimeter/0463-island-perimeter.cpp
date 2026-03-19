class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size()-1;
        int cn=grid[0].size()-1;
        queue<pair<int,int>>q;
        bool found=false;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    found=true;
                    grid[i][j]=2;
                    break;
                }
            }
            if(found) break;
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int c=0;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int row=node.first;
            int col=node.second;
            for(int i=0;i<4;i++){
                int newr=row+dr[i];
                int newc=col+dc[i];
                if(newr<0 || newc<0 || newr>n || newc>cn || grid[newr][newc]==0){
                    c++;
                }else if(grid[newr][newc]==1){
                    grid[newr][newc]=2;
                    q.push({newr,newc});
                }
            }
        }
        return c;


    }
};