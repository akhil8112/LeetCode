class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lefts=0;
        int rights=0;
        for(int i=0;i<k;i++){
            lefts+=cardPoints[i];
        }
        int point=lefts;
        int n=cardPoints.size()-1;
        for(int i=0;i<k;i++){
            lefts-=cardPoints[k-i-1];
            rights+=cardPoints[n-i];

            point=max(point,lefts+rights);
        }
        return point;
    }
};