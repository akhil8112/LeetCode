class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n,0));
        int left=0;
        int right=matrix[0].size()-1;
        int top=0;
        int bottom=matrix.size()-1;
        int a=1;
        vector<int>ans;
        
        while(top<=bottom && left<=right){
            //top
            for(int i=left;i<=right;i++){
                matrix[top][i]=a;
                a++;
            }
            top++;

            //right
            for(int i=top;i<=bottom;i++){
                matrix[i][right]=a;
                a++;
            }
            right--;

            //bottom
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    matrix[bottom][i]=a;
                    a++;
                }
                bottom--;
            }

            //left
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    matrix[i][left]=a;
                    a++;
                }
                left++; 
            }
        }
        return matrix;
    }
};