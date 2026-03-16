class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>r(rooms.size(),false);
        vector<int>vis(rooms.size(),0);

        queue<int>q;
        q.push(0);
        r[0]=true;
        vis[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            r[node]=true;
            for(int it : rooms[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        for(int i=0;i<rooms.size();i++){
            if(!r[i]) return false;
        }
        return true;
    }
};