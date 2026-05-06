class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int m=INT_MIN;
        int x=0;

        for(int i=0;i<gain.size();i++){

            m=max(m,x);
            x=x+gain[i];

        }
        m=max(m,x);
        return m;

    }
};