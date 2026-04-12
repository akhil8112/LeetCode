class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V=points.size();
        vector<vector<pair<int,int>>>adj(V);
        
        for(int i=0;i<points.size();i++){
            int  x1=points[i][0];
            int y1=points[i][1];

            for(int j=0;j<points.size();j++){
                if(i!=j){
                    int x2=points[j][0];
                    int y2=points[j][1];

                    int wt=abs(x1-x2) +  abs(y1-y2);
                    adj[i].push_back({j,wt}); 
                    adj[j].push_back({i,wt}); 
                }
            }

        }

        vector<int>vis(V,0);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({0,0});
        int sum=0;
        
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int wt=it.first;
            
            if(vis[node]==1) continue;
            sum=sum+wt;
            vis[node]=1;
            for(auto i : adj[node]){
                if(!vis[i.first]){
                    pq.push({i.second,i.first}); 
                }
            }
        }
        return sum;
    }
};