class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<vector<int>>adj(n+1);

        for(int i=0;i<dislikes.size();i++){
            int u=dislikes[i][0];
            int v=dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>color(n+1,-1);
        for (int i = 1; i <= n; i++) {
            if (color[i] != -1) continue;
            color[i]=0;
            queue<int > q;
            q.push(i);

            while(!q.empty()){
                int node=q.front();
                q.pop();

                for(int it: adj[node]){
                    if(color[it]==-1){
                        color[it]=1-color[node];
                        q.push(it);
                    }else if(color[node]==color[it]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};