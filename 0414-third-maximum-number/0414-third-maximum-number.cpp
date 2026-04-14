class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int>s;
        for(int n : nums){
            s.insert(n);
        }

        priority_queue<int>pq;
        for(int n : s){
            pq.push(n);
        }
        int a=pq.top();
        for(int i=0;i<2;i++){
            pq.pop();
        }
        if(pq.empty()) return a;

        return pq.top();
    }
};