class DSU{
    public:
    vector<int>rank,parent;
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for( int i = 0 ; i < n+1 ; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node==parent[node]) return node;

        return parent[node]=findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int up=findUPar(u);
        int vp=findUPar(v);

        if(up==vp) return;
        if(rank[up]<rank[vp]){
            parent[up]=vp;
        }
        else if(rank[vp]<rank[up]){
            parent[vp]=up;
        }else{
            parent[vp]=up;
            rank[up]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int c=0;
        DSU ds(n);

        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            if(ds.findUPar(u) == ds.findUPar(v)) c++;
            else{
                ds.unionByRank(u,v);
            }
        }
        int cmp=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) cmp++;
        }
        if(cmp-1<=c) return cmp-1;
        
        return -1;




    }
};