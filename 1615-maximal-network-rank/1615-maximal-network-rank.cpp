class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>indeg(n,0);
        vector<vector<int>>adj(n);

        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            indeg[u]++;
            indeg[v]++;
        }

        int maxi=INT_MIN;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i!=j){
                    int x=indeg[i]+indeg[j];

                    for(int nb : adj[i]){
                        if(nb==j) x--;
                    }
                    maxi=max(maxi,x);
                }
            }
        }
        return maxi;
    }
};