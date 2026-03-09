class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int wt=roads[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<long long,int>,vector<pair<long long, int>>,greater<pair<long long,int>>>pq;
        vector<long long>dist(n,1e18);
        vector<int>ways(n,0);

        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        int mod=1e9+7;
        while(!pq.empty()){
            auto it = pq.top();
            long long dis=it.first;
            int node=it.second;
            pq.pop();

            for(auto it : adj[node]){
                int adjnode=it.first;
                long long wt=it.second;
                if(dis+wt<dist[adjnode]){
                    dist[adjnode]=dis+wt;
                    pq.push({dis+wt,adjnode});
                    ways[adjnode]=ways[node];
                }else if(dis+wt==dist[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                    
                }
            }
        }
        
        return (ways[n-1])%mod;

    }
};