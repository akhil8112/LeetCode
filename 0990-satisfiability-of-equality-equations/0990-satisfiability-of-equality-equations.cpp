class DSU{
        vector<int> parent;
        vector<int> rank;
        public:
        
        
        DSU(int n){
            parent.resize(n);
            rank.resize(n, 0);
            for(int i=0;i<parent.size();i++){
                parent[i]=i;
            }
        }
        int findParent(int node){
            if(node==parent[node]){
                return parent[node]=node;
            }
            return parent[node]=findParent(parent[node]);
        }
        void unionRank(int u, int v){
            int pu=findParent(u);
            int pv=findParent(v);
            if(pu==pv){
                return;
            }
            
            if(rank[pu] > rank[pv]){
                parent[pv]=pu;
            }
            else if(rank[pu] < rank[pv]){
                parent[pu]=pv;
            }
            else{
                 parent[pv]=pu;
                 rank[pu]++;
            }
        }
        
        
    };
    class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        DSU dsu(26);

        for(string &s : equations){

            int u=s[0]-'a';
            int v=s[3]-'a';

            if(s[1]=='='){
                dsu.unionRank(u,v);
            }
        }

        for(string &s : equations){

            int u=s[0]-'a';
            int v=s[3]-'a';

            if(s[1]=='!'){

                if(dsu.findParent(u)==dsu.findParent(v)){
                    return false;
                }
            }
        }
        return true;
        

    }
};