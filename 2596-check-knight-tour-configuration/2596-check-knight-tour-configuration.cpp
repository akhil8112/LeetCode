class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int N = grid.size();
         if(N==1) return 0;
        
        queue<pair<int,int>>pq;
        vector<vector<int>>vis(N,vector<int>(N,0));
        
        pq.push({0,0});
        vis[0][0]=1;
        vector<vector<int>>arr={{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{-1,-2},{1,-2}};
        int c=1;

        while(!pq.empty()){
            auto a=pq.front(); pq.pop();
            int row=a.first;
            int col=a.second;
            bool f=false;

            
            for(int i=0;i<8;i++){
                int newr=row+arr[i][0];
                int newc=col+arr[i][1];
                
                if(newr>=0 && newc>=0 && newr<N && newc<N && vis[newr][newc]==0){
                    if(grid[newr][newc]==c){
                        f=true;
                        pq.push({newr,newc});
                        vis[newr][newc]=1;
                    }
                    
                }
            }
            if(!f) return false;
            c++;
            if(c==N*N) return true;
        }

        return true;
    }
};