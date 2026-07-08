class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<vector<pair<int,int>>>adj(n);
        //node, color
        // int no=0;
        for(int i=0;i<redEdges.size();i++){
            int u=redEdges[i][0];
            int v=redEdges[i][1];
            adj[u].push_back({v,0});
            // no++;
            
        }
        for(int i=0;i<blueEdges.size();i++){
            int u=blueEdges[i][0];
            int v=blueEdges[i][1];

            adj[u].push_back({v,1});
            // no++;
        }
        vector<int>ans(n,-1);
        vector<vector<int>>vis(n,vector<int>(2,0));
        ans[0]=0;

        // for(int i=1;i<n;i++){
            queue<pair<int ,pair<int,int>>>q;
            //node,color,dist
            q.push({0,{-1,0}});
            // int j=0;
            while(!q.empty()){
                int node=q.front().first;
                int color=q.front().second.first;
                int dist=q.front().second.second;
                q.pop();

                // if( node==i){
                //     ans[node]=dist;
                //     break;
                // }
                // if(j==no*no) break;

                for(auto nbr : adj[node]){
                 
                    if(color==-1 && !vis[nbr.first][nbr.second]){
                        if(ans[nbr.first]== -1){
                            ans[nbr.first]=dist+1;
                        }
                        vis[nbr.first][nbr.second]=1;
                        q.push({nbr.first,{nbr.second,dist+1}});
                    }else if(color != nbr.second &&  !vis[nbr.first][nbr.second]){
                         if(ans[nbr.first]== -1){
                            ans[nbr.first]=dist+1;
                        }
                        q.push({nbr.first,{nbr.second,dist+1}});
                        vis[nbr.first][nbr.second]=1;
                    }
                }
                // j++;
            }

        // }
        return ans;
    }
};