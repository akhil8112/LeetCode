class Solution {
public:
    bool validMountainArray(vector<int>& arr) {

        if(arr.size()==2 || arr.size()==1) return 0;
        if(arr[0]>arr[1]) return false;
        bool in=false;
        for(int i=1;i<arr.size();i++){
            if(arr[i]<=arr[i-1]){
                in=true;
            }
            if(in && arr[i]>=arr[i-1]){
                return 0;
            }
        }

        if(!in) return false;
        return 1;
    }
};