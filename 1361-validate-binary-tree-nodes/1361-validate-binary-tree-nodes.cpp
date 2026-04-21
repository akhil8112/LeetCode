class Solution {
public:

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<vector<int>>adj(n);
        vector<bool>root(n,false);



        for(int i=0;i<n;i++){
            if(rightChild[i]!=-1){
                adj[i].push_back(rightChild[i]);
                root[rightChild[i]]=true;
            }
            if(leftChild[i]!=-1){
                adj[i].push_back(leftChild[i]);
                root[leftChild[i]]=true;
            }
            
        }
        int x=0;
        int start;
        for(int i=0;i<n;i++){
            if(!root[i]){
                x++;
                start=i;
            } 
        }

        if(x!=1) return false;

        vector<int>parent(n,-1);
        vector<int>vis(n,0);
        queue<int>q;
        q.push(start);
        vis[start]=1;

        while(!q.empty()){

            int node=q.front();
            q.pop();

            for(int nbr : adj[node]){
                if(!vis[nbr]){
                    vis[nbr]=1;
                    q.push(nbr);
                }
                    if(parent[nbr]!=-1){
                        return false;
                    }else{
                        parent[nbr]=node;
                    }
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
        }
        return true;

    }
};