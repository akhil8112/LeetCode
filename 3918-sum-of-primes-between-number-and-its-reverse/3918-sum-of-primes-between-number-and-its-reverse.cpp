class Solution {
public:
    int sumOfPrimesInRange(int n) {
        int re=0;

        int x=n;
        while(x!=0){
            int last=x%10;
            re=re*10+last;
            x/=10;
        }
        int low = min(n, re);
        int high = max(n, re);

        vector<bool>vis(high+1,true);
        vis[0] = vis[1] = false;
        for(int i=2;i*i<=high;i++){
            if(vis[i]==true){
                for(int j=i*i;j<=high;j+=i){
                    vis[j]=false;
                }

            }
        }
        int sum = 0;
        for (int i = low; i <= high; i++) {
            if (vis[i]) {
                sum += i;
            }
        }

        return sum;


    }
};