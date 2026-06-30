class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;

        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }

        int round=0;

        for(auto i : mp){
            int a=i.second;
            if(a==1) return -1;
            if(a%3==0){
                round+=a/3;
            }
            else if(a%3!=0 && a%3==1){
                round+=(a-3)/3+2;
            }else{
                round+=a/3+1;
            }
        }
        return round;
    }
};