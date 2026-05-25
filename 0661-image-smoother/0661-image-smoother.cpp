class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int dx[]={-1,0,1,0,1,1,-1,-1};
        int dy[]={0,-1,0,1,1,-1,1,-1};

        int n=img.size();
        int m=img[0].size();

        vector<vector<int>>ans(n,vector<int>(m));
        
        for(int i=0;i<img.size();i++){
            for(int j=0;j<img[0].size();j++){

                int sum=img[i][j];
                int c=1;

                for(int k=0;k<8;k++){
                    int nr=i+dx[k];
                    int nc=j+dy[k];

                    if(nr>=0 && nc>=0 && nr<n && nc<m){
                        c++;
                        sum+=img[nr][nc];
                    }
                }
                ans[i][j]=floor(sum/c);
            }
        }

        return ans;
    }
};