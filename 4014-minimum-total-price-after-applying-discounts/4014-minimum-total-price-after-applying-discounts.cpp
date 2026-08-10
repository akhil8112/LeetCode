class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end(),greater<>());
        sort(discounts.begin(),discounts.end(),greater<>());

        int l=min(discounts.size(),prices.size());
        double ans=0;
        int i;
        
        for(i=0;i<l;i++){
            double d=double(discounts[i]);
            double y= (double)((100-d)/100);
            double p=(double)prices[i];
            double x= p * y;
            ans+=x;
        }
        for(int j=i;j<prices.size();j++){
            ans+= (double)prices[j];
        }
        return ans;
    }
};