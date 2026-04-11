class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> pos;

        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]] = i;
        }

        for (int i = 0; i < operations.size(); i++) {
            int oldVal = operations[i][0];
            int newVal = operations[i][1];

            int idx = pos[oldVal];
            nums[idx] = newVal;

            pos[newVal] = idx;
            pos.erase(oldVal);
        }

        return nums;
    }

};