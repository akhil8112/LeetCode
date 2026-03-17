class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>adj(n);
        int f=0;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double wt=succProb[i];
            if(u==end_node || v==end_node) f=1;
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        if(!f) return 0;
        

        queue<pair<double,int>>pq;

        pq.push({1,start_node});
        vector<double>p(n,0);
        p[start_node]=1;
        while(!pq.empty()){
            auto it=pq.front();
            pq.pop();
            int node=it.second;
            double prob=it.first;


            for(auto i : adj[node]){
                if(prob*i.second>p[i.first]){
                    p[i.first]=prob*i.second;
                    pq.push({prob*i.second,i.first});

                }
            }
        }
      
        return p[end_node];
    }
};