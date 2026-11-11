class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        using ll = long long;
        ll k = cost1*1LL*need1 + cost2*1LL*need2;
        ll l = min(need1,need2)*1LL*costBoth;
        ll m = max(need1,need2)*1LL*costBoth ;
        ll n = 0;
        if(need1 > need2){
            n = abs(need1-need2)*1LL*cost1;
        }
        else{
            n = abs(need2-need1)*1LL*cost2;
        }
        ll ans = min({k,l+n,m});
        return ans;
    }
};