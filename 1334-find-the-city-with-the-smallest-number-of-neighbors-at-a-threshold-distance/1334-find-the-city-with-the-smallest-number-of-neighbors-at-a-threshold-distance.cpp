class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>cost(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            cost[i][i]=0;
        }
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            cost[u][v]=wt;
            cost[v][u]=wt;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(cost[i][k]<1e9 && cost[k][j]<1e9){
                        cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
                    }
                }
            }
        }
        int city=0;
        int neigh=n+1;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(cost[i][j]<=distanceThreshold){
                    c++;
                }
            }
            if(c<=neigh){
                city=i;
                neigh=c;
            }
        }
        return city;
    }
};