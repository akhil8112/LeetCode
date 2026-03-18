class DSU{
    public:

    vector<int>rank,parent;
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUPar(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }

    void unionByRank(int u,int v){
        int pu=findUPar(u);
        int pv=findUPar(v);

        if(pu==pv) return;

        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        //each component has x1,x2,x3,----- vertex from reach component only 1 vertex remains else all removed 
        //so removed nodes= x1-1 + x2-1 + x3-1 + -------- (x1+x2+x3+----)-1-1-1-1-----
        //x1+x2+x3+----=n(all nodes)
        //n-(no. of component)
        int maxRows=0;
        int maxCol=0;
        for(int i=0;i<stones.size();i++){
            maxRows=max(maxRows,stones[i][0]);
            maxCol=max(maxCol,stones[i][1]);
        }


        DSU ds(maxRows + maxCol + 1);
        set<int>s;

        int c=0;
        for(int i=0;i<stones.size();i++){
            int u=stones[i][0];
            int v=stones[i][1] + maxRows + 1;
            ds.unionByRank(u,v);
            s.insert(u);
            s.insert(v);
        }
        for(int i : s){
            if(ds.findUPar(i)==i){
                c++;
            }
        }
        return stones.size()-c;
    }
};