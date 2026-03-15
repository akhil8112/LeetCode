class Solution {
public:
    int countCommas(int n) {
         long long ans=0;

        vector<long long> start = {1000,1000000,1000000000};
        
        for (int i = 0;i<start.size();i++) {
            if (n>=start[i]){
                long long cnt = n-start[i]+1;
                ans+=cnt*(i+1);
            }
        }

        return ans;
    }
};