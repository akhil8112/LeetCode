class Solution {
public:
    int titleToNumber(string columnTitle) {
        int s=columnTitle.size()-1;
        int num=0;
        long long pro=1;

        for(int i=s;i>=0;i--){
            int x=columnTitle[i]-'A'+1;
            num += x*pro;
            pro *=26;
        }

        return num;
    }
};