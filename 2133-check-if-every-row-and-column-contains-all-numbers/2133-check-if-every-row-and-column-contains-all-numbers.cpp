class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int s=matrix.size();

        for(int i=0;i<s;i++){

            vector<bool>vis(s+1,false);
            for(int j=0;j<s;j++){
                if(vis[matrix[i][j]]==false){
                    vis[matrix[i][j]]=true;
                }else{
                    return false;
                }
            }
            
        }
        for(int i=0;i<s;i++){

            vector<bool>vis(s+1,false);
            for(int j=0;j<s;j++){
                if(vis[matrix[j][i]]==false){
                    vis[matrix[j][i]]=true;
                }else{
                    return false;
                }
            }
            
        }

        return true;
    }
};