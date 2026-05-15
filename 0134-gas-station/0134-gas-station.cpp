class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int x=accumulate(gas.begin(), gas.end(), 0);
        int y=accumulate(cost.begin(), cost.end(), 0);

        if(x<y) return -1;

        int c=0;
        int r=0;
        for(int i=0;i<gas.size();i++){
            c=c+(gas[i]-cost[i]);

            if(c<0){
                c=0;
                r=i+1;
            }
        }
        return r;
    }
};