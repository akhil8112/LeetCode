class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);

        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int wt=times[i][2];
            adj[u].push_back({v,wt});
        }
        vector<int>dist(n+1,1e9);
        queue<pair<int,int>>q;
        q.push({k,0});
        dist[k]=0;
        dist[0]=0;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int v=node.first;
            int wt=node.second;
            for(auto it : adj[v]){
                int i=it.first;
                int w=it.second;
                if(dist[i]>wt+w){
                    dist[i]=wt+w;
                    q.push({i,wt+w});
                }
            }
        }
        for( auto i : dist){
            if(i==1e9){
                return -1;
            }
        }
        int m=*max_element(dist.begin(),dist.end());
        return m;
    }
};