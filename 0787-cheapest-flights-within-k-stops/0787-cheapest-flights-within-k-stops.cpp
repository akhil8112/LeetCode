class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);

        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int wt=flights[i][2];
            adj[u].push_back({v,wt});
        }
        vector<int>dist(n,1e9);
        queue<pair<int,pair<int,int>>>q;
        q.push({src,{0,0}});
        dist[src]=0;
       
        while(!q.empty()){
    
            auto node=q.front();
            q.pop();
            int v=node.first;
            int wt=node.second.first;
            int st=node.second.second;

            if(st==k+1)break;

            for(auto it : adj[v]){
                int i=it.first;
                int w=it.second;
                if(dist[i]>wt+w){
                    dist[i]=wt+w;
                    q.push({i,{wt+w,st+1}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};