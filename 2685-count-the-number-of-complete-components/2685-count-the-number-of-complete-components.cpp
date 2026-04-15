class Solution {
public:

    void dfs(vector<vector<int>>& adj,vector<int>& vis,int& i, int &node, int &edge){
        vis[i]=1;
        node++;
        edge+=adj[i].size();
        for(int nbr : adj[i]){
            if(!vis[nbr]){
                dfs(adj,vis,nbr,node,edge);
            }
        }

    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n);
        int c=0;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int node=0;
                int edge=0;
                dfs(adj,vis,i,node,edge);
                
                if(edge/2==(node*(node-1)/2)) c++;
            }
        }

        return c++;

    }
};