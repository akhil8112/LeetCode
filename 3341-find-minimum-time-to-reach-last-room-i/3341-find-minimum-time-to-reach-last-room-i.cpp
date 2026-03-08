class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();
        vector<vector<long long>>dist(n,vector<long long>(m,1e18));

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        pq.push({0,{0,0}});
        dist[0][0]=0;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int d=it.first;
            int row=it.second.first;
            int col=it.second.second;

            for(int i=0;i<4;i++){
                int newr=row+dr[i];
                int newc=col+dc[i];
                
                if(newr<n && newr>=0 && newc<m && newc>=0 ){
                    int newtime=max(moveTime[newr][newc],d)+1;
                    if(newtime<dist[newr][newc]){
                        dist[newr][newc]=newtime;
                        pq.push({newtime,{newr,newc}});
                    }
                }
            }
        }
        return (int)dist[n-1][m-1];
    }
};