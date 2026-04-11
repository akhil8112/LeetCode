class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int c=0;
        for( int n : nums){
            while(n!=0){
                int last=n%10;
                if(last==digit) c++;
                n=n/10;
            }
        }

        return c;
    }
};